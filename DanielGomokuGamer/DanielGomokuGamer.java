package org.ggp.base.player.gamer.statemachine.sample;

import java.util.ArrayList;
import java.util.List;

import org.ggp.base.apps.player.detail.DetailPanel;
import org.ggp.base.apps.player.detail.SimpleDetailPanel;
import org.ggp.base.player.gamer.event.GamerSelectedMoveEvent;
import org.ggp.base.player.gamer.exception.GamePreviewException;
import org.ggp.base.player.gamer.statemachine.StateMachineGamer;
import org.ggp.base.util.game.Game;
import org.ggp.base.util.gdl.grammar.GdlPool;
import org.ggp.base.util.statemachine.Move;
import org.ggp.base.util.statemachine.StateMachine;
import org.ggp.base.util.statemachine.cache.CachedStateMachine;
import org.ggp.base.util.statemachine.exceptions.GoalDefinitionException;
import org.ggp.base.util.statemachine.exceptions.MoveDefinitionException;
import org.ggp.base.util.statemachine.exceptions.TransitionDefinitionException;
import org.ggp.base.util.statemachine.implementation.prover.ProverStateMachine;

/**

 */
public final class DanielGomokuGamer extends StateMachineGamer
{
    private final int  M = 15;
    private final int K = 5;
    private int[][] board = new int[M][M];
    private String moveWord;
    private int moveX, moveY;
    private boolean iWin = false;

    @Override
    public void stateMachineMetaGame(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException
    {
        // Do nothing.
    }



    @Override
    public Move stateMachineSelectMove(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException
    {
        StateMachine theMachine = getStateMachine();
        long start = System.currentTimeMillis();
        //long finishBy = timeout - 1000;
        List<Move> moves = theMachine.getLegalMoves(getCurrentState(), getRole());
        Move selection = (moves.get(0));
        if (moves.size() > 1)
        {
            moveWord = extractMoveWord(selection);
            ArrayList<Cell> moveCells = extractCells(moves);
            updateBoard(moveCells);
            if (board[(M/2)][M/2] == 0){
                moveX = M/2;
                moveY = M/2;
            } else {
                findBestMove(moveCells);
            }
            board[moveX][moveY] = 1;
            selection = findMoveMatch(makeMoveString(moveWord, moveX+1, moveY+1), moves);
        }

        long stop = System.currentTimeMillis();

        notifyObservers(new GamerSelectedMoveEvent(moves, selection, stop - start));
        return selection;
    }

    /**
     * finds the best move according to the weighting algorithm and stores the results in the class fields moveX & moveY
     * @param openCells
     */
    private void findBestMove(List<Cell> openCells) {
            int bestMoveWeight = 0;
            for (Cell cell : openCells) {
                int moveWeight = 0;
                moveWeight+=calculateHorizontalMoveWeight(cell.x, cell.y);
                moveWeight+=calculateVerticalMoveWeight(cell.x, cell.y);
                moveWeight+=calculateDiagonalMoveWeight1(cell.x, cell.y);
                moveWeight+=calculateDiagonalMoveWeight2(cell.x, cell.y);
                if(iWin){
                    moveX = cell.x;
                    moveY = cell.y;
                    break;
                } else if(moveWeight > bestMoveWeight){
                    bestMoveWeight = moveWeight;
                    moveX = cell.x;
                    moveY = cell.y;
                }
            }
        }


    /**
     * Moves seem to have a random string "word" (assigned to each player I believe) followed by (for Gomoku) cell coordinates. This method returns the "word"
     * @param move a Move
     * @return moveName
     */
    private String extractMoveWord(Move move) {
        return move.toString().split(" ")[1];
    }

    /**
     * Handles changing our internal board model to match the current game state by filling all empty spaces with opponent's piece then clearing the ones the server lists as open
     * There might be a more efficient way to do this but I can't think of one right now and it is 11 PM on Sunday and I am tired.
     * @param openCells
     */
    private void updateBoard(List<Cell> openCells) {
        for (int i = 0; i < M; i++){
            for (int j = 0; j < M; j++){
                if (board[i][j] == 0)
                    board[i][j] = 2;
            }
        }
        for (Cell cell: openCells){
            board[cell.x][cell.y] = 0;
        }
    }

    /**
     * Extracts the coordinate values of a list of moves and places them in Cells
     * @param moves
     * @return A List of Cells
     */
    private ArrayList<Cell> extractCells(List<Move> moves){
        ArrayList<Cell> returnCells = new ArrayList<Cell>();
        int tempX, tempY;
        for(Move move : moves){
            tempX = Integer.parseInt(move.toString().split(" ")[2]) -1;
            tempY = Integer.parseInt(move.toString().split(" ")[3]) -1;
            returnCells.add(new Cell(tempX, tempY));
        }
        return returnCells;
    }

    /**
     * Gets the length of a sequence on the board
     * @param sequenceVal the value of the piece to search for
     * @param x the starting x coordinate on the board
     * @param y the starting y coordinate on the board
     * @param changeX the offset to change x by each step in the sequence
     * @param changeY the offset to change y by each step in the sequence
     * @return
     */
    private int getSequenceLength(int sequenceVal, int x, int y, int changeX, int changeY){
        int length = 1;
        while (withinBounds(x, y)) {
            if (board[x][y] == sequenceVal){
                length++;
                x+=changeX;
                y+=changeY;
            } else {
                break;
            }
        }

        return length;
    }

    /**
     * Checks if the space board[x][y] is in fact within the bounds of board
     * @param x
     * @param y
     * @return Boolean
     */
    private boolean withinBounds(int x, int y){
        return (x >=0 && x < M && y >=0 && y < M);
    }

    /**
     * Calculates the Horizontal weight of a move
     * @param x
     * @param y
     * @return integer weight
     */
    private int calculateHorizontalMoveWeight(int x, int y) {
        int returnWeight = 0;
        int leftSearchVal = 0;
        int leftLength = 0;
        int rightSearchVal = 0;
        int rightLength = 0;
        if (withinBounds(x-1, y)){ //Check sequence length of cells left of (x, y)
            leftSearchVal = board[x-1][y];
            if (leftSearchVal != 0){
                leftLength = getSequenceLength(leftSearchVal, x-1, y, -1, 0);
            }
        }

        if (withinBounds(x+1, y)){ //Check sequence length of cells right of (x, y)
            rightSearchVal = board[x+1][y];
            if (rightSearchVal != 0){
                rightLength = getSequenceLength(leftSearchVal, x+1, y, 1, 0);
            }
        }
        returnWeight = leftLength + rightLength;
        if ( leftSearchVal == rightSearchVal && (leftLength + rightLength >= K-1) ){ //If position allows a win for someone
            if (leftSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (leftLength >= K-1) {
            if (leftSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (rightLength >=K) {
            if (rightSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        }

        return returnWeight;
    }

    /**
     * Calculates the Vertical weight of a move
     * @param x
     * @param y
     * @return integer weight
     */
    private int calculateVerticalMoveWeight(int x, int y) {
        int returnWeight = 0;
        int upSearchVal = 0;
        int upLength = 0;
        int downSearchVal = 0;
        int downLength = 0;
        if (withinBounds(x, y-1)){ //Check sequence length of cells above (x, y)
            upSearchVal = board[x][y-1];
            if (upSearchVal != 0){
                upLength = getSequenceLength(upSearchVal, x, y-1, 0, -1);
            }
        }

        if (withinBounds(x, y+1)){ //Check sequence length of cells under of (x, y)
            downSearchVal = board[x][y+1];
            if (downSearchVal != 0){
                downLength = getSequenceLength(downSearchVal, x+1, y, 1, 0);
            }
        }
        returnWeight = upLength + downLength;
        if ( upSearchVal == downSearchVal && (upLength + downLength >= K-1) ){ //If position allows a win for someone
            if (upSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (upLength >= K) {
            if (upSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (downLength >=K) {
            if (downSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        }
        return returnWeight;
    }

    /**
     * Calculates the Diagonal weight of a move on one diagonal axis
     * @param x
     * @param y
     * @return integer weight
     */
    private int calculateDiagonalMoveWeight1(int x, int y) {
        int returnWeight = 0;
        int upSearchVal = 0;
        int upLength = 0;
        int downSearchVal = 0;
        int downLength = 0;
        if (withinBounds(x-1, y-1)){ //Check sequence length of cells above and left of (x, y)
            upSearchVal = board[x-1][y-1];
            if (upSearchVal != 0){
                upLength = getSequenceLength(upSearchVal, x, y-1, -1, -1);
            }
        }

        if (withinBounds(x+1, y+1)){ //Check sequence length of cells under and right of (x, y)
            downSearchVal = board[x+1][y+1];
            if (downSearchVal != 0){
                downLength = getSequenceLength(downSearchVal, x+1, y+1, 1, 1);
            }
        }
        returnWeight = upLength + downLength;
        if ( upSearchVal == downSearchVal && (upLength + downLength >= K-1) ){ //If position allows a win for someone
            if (upSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (upLength >= K) {
            if (upSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (downLength >=K) {
            if (downSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        }
        return returnWeight;
    }

    /**
     * Calculates the Diagonal weight of a move on the other diagonal axis
     * @param x
     * @param y
     * @return integer weight
     */
    private int calculateDiagonalMoveWeight2(int x, int y) {
        int returnWeight = 0;
        int upSearchVal = 0;
        int upLength = 0;
        int downSearchVal = 0;
        int downLength = 0;
        if (withinBounds(x-1, y+1)){ //Check sequence length of cells above and right of (x, y)
            upSearchVal = board[x-1][y+1];
            if (upSearchVal != 0){
                upLength = getSequenceLength(upSearchVal, x, y-1, -1, 1);
            }
        }

        if (withinBounds(x+1, y-1)){ //Check sequence length of cells under and left of (x, y)
            downSearchVal = board[x+1][y-1];
            if (downSearchVal != 0){
                downLength = getSequenceLength(downSearchVal, x+1, y+1, 1, -1);
            }
        }
        returnWeight = upLength + downLength;
        if ( upSearchVal == downSearchVal && (upLength + downLength >= K-1) ){ //If position allows a win for someone
            if (upSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (upLength >= K-1) {
            if (upSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        } else if (downLength >=K) {
            if (downSearchVal == 1) { //if I am winner
                iWin = true;
            }
            else { //if opponent could win
                returnWeight +=100;
            }
        }
        return returnWeight;
    }

    /**
     * Creates a full gomoku move string
     * @param moveWord
     * @param x
     * @param y
     * @return
     */
    private String makeMoveString(String moveWord, int x, int y) {
        return ( "( "+ moveWord + " " + x + " " + y + " )" );
    }

    private Move findMoveMatch(String searchString, List<Move> moveList){
        for (Move move : moveList){
            if (move.toString().equals(searchString))
                return move;
        }
        return new Move(GdlPool.getConstant("NOOP"));
    }

    @Override
    public void stateMachineStop() {
        // Do nothing.
    }
    /**
     * Uses a CachedProverStateMachine
     */
    @Override
    public StateMachine getInitialStateMachine() {
        return new CachedStateMachine(new ProverStateMachine());
    }

    @Override
    public String getName() {
        return "GomokuGamer";
    }

    @Override
    public DetailPanel getDetailPanel() {
        return new SimpleDetailPanel();
    }

    @Override
    public void preview(Game g, long timeout) throws GamePreviewException {
        // Do nothing.
    }

    @Override
    public void stateMachineAbort() {
        // Do nothing.
    }

    class Cell{
        public int x, y;
        Cell(int i, int j) {
            x = i;
            y = j;
        }
    }
}
