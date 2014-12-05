package org.ggp.base.player.gamer.statemachine.gomoku;

import java.util.List;

import org.ggp.base.apps.player.detail.DetailPanel;
import org.ggp.base.apps.player.detail.SimpleDetailPanel;
import org.ggp.base.player.gamer.event.GamerSelectedMoveEvent;
import org.ggp.base.player.gamer.exception.GamePreviewException;
import org.ggp.base.player.gamer.statemachine.StateMachineGamer;
import org.ggp.base.util.game.Game;
import org.ggp.base.util.gdl.grammar.GdlPool;
import org.ggp.base.util.gdl.grammar.GdlTerm;
import org.ggp.base.util.statemachine.Move;
import org.ggp.base.util.statemachine.Role;
import org.ggp.base.util.statemachine.StateMachine;
import org.ggp.base.util.statemachine.cache.CachedStateMachine;
import org.ggp.base.util.statemachine.exceptions.GoalDefinitionException;
import org.ggp.base.util.statemachine.exceptions.MoveDefinitionException;
import org.ggp.base.util.statemachine.exceptions.TransitionDefinitionException;
import org.ggp.base.util.statemachine.implementation.prover.ProverStateMachine;

public class DongmoGomoku extends StateMachineGamer {

    private Role myRole;
    private char player = 'x';
    private int playerId = 0;

	private Board board;
	private MoveMaker movemaker;

	private StateMachine localStateMachine;

	private String actionStr;

	@Override
	public void stateMachineMetaGame(long timeout) throws TransitionDefinitionException, MoveDefinitionException,
														  GoalDefinitionException {
		myRole = getRole();

		player = myRole.toString().equals("xplayer")?'x':'o';

		playerId = player=='x'?1:-1;

		System.out.println("I am " + myRole.toString() + " ");

		board = new Board(15, 5);
		movemaker = new MoveMaker();
	}

	@Override
	public String getName() {
		return getClass().getSimpleName();
	}

	// This is the default State Machine
	@Override
	public StateMachine getInitialStateMachine() {
		return new CachedStateMachine(new ProverStateMachine());
	}

	// This is the defaul Sample Panel
	@Override
	public DetailPanel getDetailPanel() {
		return new SimpleDetailPanel();
	}

	@Override
	public void stateMachineStop() {
		// do no special cleanup when the match ends normally.
	}

	@Override
	public void stateMachineAbort() {
		// do no special cleanup when the match ends abruptly.
	}

	@Override
	public void preview(Game g, long timeout) throws GamePreviewException {
		// do no game previewing.
	}

	@Override
	public Move stateMachineSelectMove(long timeout)
			throws TransitionDefinitionException, MoveDefinitionException,
			GoalDefinitionException {
/*
		Set<GdlSentence> initialState =getStateMachine().getInitialState().getContents();
        for(GdlSentence term: initialState)
		System.out.println(term.toString());
*/
		long start = System.currentTimeMillis();
		StateMachine stateMachine = getStateMachine();

		List<Move> availableMoves = stateMachine.getLegalMoves(getCurrentState(), getRole());

		int myTurn = 1;
		if(availableMoves.get(0).toString()=="noop" || availableMoves.get(0).toString()=="NOOP") {
			myTurn = -1;
		}

		List<GdlTerm> lastMoves = getMatch().getMostRecentMoves();
//		List<Role> roles = stateMachine.getRoles();

		if(lastMoves!=null) {
        	Position p = new Position(-1,-1);
        	for (GdlTerm term : lastMoves) {
        		if(term.toString()=="noop"||term.toString()=="NOOP")
        			continue;

        		parseMoveStr(p, term.toString());

        		if(board.getTurn()==myTurn*playerId)
        			board.switchTurn();

        		if(board.getGrid(p.x, p.y) != -1*myTurn*playerId) {
        			board.addMove(-1*playerId*myTurn, p.x, p.y);
        			System.out.println("Opponent's move: (" + (p.x+1) +", "+ (p.y+1) +")");
 //       			board.printBoard();
        		}
        	}
		}

   		Move retMove;

		if(myTurn == 1) {
			String moveStr = availableMoves.get(0).toString();
			int index = moveStr.indexOf(" ", 2);
			actionStr = moveStr.substring(2, index);

			Position p = movemaker.getMove(board, playerId);
			System.out.println("My move 1: " + p.toString());

			String moveString = "( " + actionStr + " " + (p.x + 1) + " " + (p.y + 1) + " )";

			retMove = getMoveFromStr(availableMoves, moveString);

			if(board.getTurn()!=playerId)  {
					board.switchTurn();
			}
			board.addMove(playerId, p.x, p.y);
  //      	board.printBoard();
		} else {
			retMove = new Move(GdlPool.getConstant("noop"));
		}

		System.out.println("My move 2: " + retMove.toString());


		long stop = System.currentTimeMillis();
		notifyObservers(new GamerSelectedMoveEvent(availableMoves, retMove, stop - start));
		return retMove;
	}

	private Move getMoveFromStr(List<Move> legalMoves, String moveStr) {
		for (Move move : legalMoves) {
			if (move.toString().equals(moveStr)) {
				return move;
			}
		}

		System.out.println("Couldn't find move: " + moveStr + "\r\n");
		return new Move(GdlPool.getConstant("noop"));
	}

	private void parseMoveStr(Position p, String moveStr) {
		int index1 = moveStr.indexOf(" ", 2);
		++index1;
		int index2 = moveStr.indexOf(" ", index1);
		p.x = Integer.parseInt(moveStr.substring(index1, index2)) - 1;
		++index2;
		index1 = moveStr.indexOf(" ", index2);
		p.y = Integer.parseInt(moveStr.substring(index2, index1)) - 1;
	}

}
