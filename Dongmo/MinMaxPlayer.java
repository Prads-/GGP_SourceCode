package org.ggp.base.player.gamer.statemachine.gomoku;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;

import org.ggp.base.apps.player.detail.DetailPanel;
import org.ggp.base.apps.player.detail.SimpleDetailPanel;
import org.ggp.base.player.gamer.event.GamerSelectedMoveEvent;
import org.ggp.base.player.gamer.exception.GamePreviewException;
import org.ggp.base.player.gamer.statemachine.StateMachineGamer;
import org.ggp.base.player.gamer.statemachine.strategies.Strategies;
import org.ggp.base.player.gamer.statemachine.strategies.Strategies;
import org.ggp.base.util.game.Game;
import org.ggp.base.util.statemachine.MachineState;
import org.ggp.base.util.statemachine.Move;
import org.ggp.base.util.statemachine.Role;
import org.ggp.base.util.statemachine.StateMachine;
import org.ggp.base.util.statemachine.cache.CachedStateMachine;
import org.ggp.base.util.statemachine.exceptions.GoalDefinitionException;
import org.ggp.base.util.statemachine.exceptions.MoveDefinitionException;
import org.ggp.base.util.statemachine.exceptions.TransitionDefinitionException;
import org.ggp.base.util.statemachine.implementation.prover.ProverStateMachine;

public final class MinMaxPlayer extends StateMachineGamer {

    private StateMachine stateMachine;

    private Strategies strategy;

    private Game game;

    private Role myRole;

//    private const int minimalUtility = 1;
    @Override
    public void stateMachineMetaGame(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException {
        stateMachine = getStateMachine();
        game = getMatch().getGame();
        myRole = getRole();
        System.out.println("MinMaxPlayer! Game starts.");
    }

    private Random theRandom = new Random();

    @Override
    public Move stateMachineSelectMove(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException {
        long start = System.currentTimeMillis();
        MachineState currentState = getCurrentState();
        stateMachine.updateRoot(currentState);

        List<Move> moves = stateMachine.getLegalMoves(currentState, myRole);

        Move selection = moves.get(new Random().nextInt(moves.size()));

        if (moves.size() < 1 || stateMachine.isTerminal(currentState)) {
            System.out.println("No available action.");
            return null;
        } else if (moves.size() == 1) {
            //No other option but do it.
            selection = moves.get(0);
        } else {

            Map<Move, Integer> utility = new HashMap();
            Map<Move, List<MachineState>> nextStates = stateMachine.getNextStates(currentState, myRole);

            boolean winningMove = false;
            winpoint:
            for (Move move : moves) {
                int minGoal = stateMachine.getGoal(nextStates.get(move).get(0), myRole);
                for (MachineState nextState : nextStates.get(move)) {
                    int currentGoal = stateMachine.getGoal(nextState, myRole);
                    if (stateMachine.isTerminal(nextState) && currentGoal == 100) {
                        selection = move;
                        winningMove = true;
                        utility.put(move, 100);
                        break winpoint;
                    }
                    if (currentGoal < minGoal) {
                        minGoal = currentGoal;
                    }

                    for (MachineState nextNextState : stateMachine.getNextStates(nextState)) {
                        if (stateMachine.getGoal(nextNextState, myRole) < minGoal) {
                            minGoal = stateMachine.getGoal(nextNextState, myRole);
                        }
                    }
                }
                utility.put(move, minGoal);
            }

            if (!winningMove) {
                int maxUtility = 0;
                for (Move move : moves) {
                    if (utility.get(move) > maxUtility) {
                        maxUtility = utility.get(move);
                        selection = move;
                    }
                }
            }
            System.out.println("MinMax move " + selection.toString() + " with goal value " + utility.get(selection));
        }

        long stop = System.currentTimeMillis();

        notifyObservers(new GamerSelectedMoveEvent(stateMachine.getLegalMoves(getCurrentState(), myRole), selection, stop - start));
        return selection;
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
        //       return new CachedStateMachine(new AdvancedProverStateMachine());
    }

    @Override
    public String getName() {
        return "MiniMaxPlayer";
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
}
