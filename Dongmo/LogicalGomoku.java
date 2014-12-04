package org.ggp.base.player.gamer.statemachine.gomoku;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import org.ggp.base.apps.player.detail.DetailPanel;
import org.ggp.base.apps.player.detail.SimpleDetailPanel;
import org.ggp.base.player.gamer.event.GamerSelectedMoveEvent;
import org.ggp.base.player.gamer.exception.GamePreviewException;
import org.ggp.base.player.gamer.statemachine.StateMachineGamer;
import org.ggp.base.util.game.Game;
import org.ggp.base.util.statemachine.MachineState;
import org.ggp.base.util.statemachine.Move;
import org.ggp.base.util.statemachine.StateMachine;
import org.ggp.base.util.statemachine.cache.CachedStateMachine;
import org.ggp.base.util.statemachine.exceptions.GoalDefinitionException;
import org.ggp.base.util.statemachine.exceptions.MoveDefinitionException;
import org.ggp.base.util.statemachine.exceptions.TransitionDefinitionException;
import org.ggp.base.util.statemachine.implementation.prover.ProverStateMachine;

public final class LogicalGomoku extends StateMachineGamer
{
	@Override
	public void stateMachineMetaGame(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException
	{
		// Do nothing.
	}

	private Random theRandom = new Random();

	@Override
	public Move stateMachineSelectMove(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException
	{
	    StateMachine theMachine = getStateMachine();
		long start = System.currentTimeMillis();
		long finishBy = timeout - 1000;

		List<Move> moves = theMachine.getLegalMoves(getCurrentState(), getRole());

		List<Move> refinedMoves = new ArrayList<Move>();
		for(Move move : moves) {
		  refinedMoves.add(move);
		}

		Move selection = (moves.get(new Random().nextInt(moves.size())));

		boolean reasonableMoveFound = false;
		for(Move move : moves) {
			for(List<Move> jointMove : theMachine.getLegalJointMoves(getCurrentState(),getRole(), move)) {
				MachineState nextState = theMachine.getNextState(getCurrentState(), jointMove);
				if(theMachine.isTerminal(nextState)) {
					if(theMachine.getGoal(nextState, getRole()) == 100) {
						selection = move;
						reasonableMoveFound = true;
//						System.out.println("Find an immediate winning move " + move.toString());
						break;
					} else if(theMachine.getGoal(nextState, getRole()) == 0) {
						if(refinedMoves.remove(move))
							break;
					}
				} else {
					for(List<Move> nextJointMove : theMachine.getLegalJointMoves(nextState)) {
						MachineState nextNextState = theMachine.getNextState(nextState, nextJointMove);
						if(theMachine.isTerminal(nextNextState)) {
							if(theMachine.getGoal(nextNextState, getRole()) == 100) {
								selection = move;
								reasonableMoveFound = true;
//								System.out.println("Find a winning move in second step: " + move.toString());
								break;
							} else if(theMachine.getGoal(nextNextState, getRole()) == 0) {
								if(refinedMoves.remove(move)) {
									//System.out.println("Find a bad move " + move.toString());
								}
							}
						}
					}
					if(reasonableMoveFound)
						break;
				}
		    }
		}

        if(!reasonableMoveFound && !refinedMoves.isEmpty()) {
        	selection = refinedMoves.get(0);
        }

		/*
		int maxGoal = 0;
        if(!reasonableMoveFound) {
			for(Move moveUnderConsideration : movesInRandomOrder) {
				MachineState nextState = theMachine.getNextState(getCurrentState(),
						theMachine.getRandomJointMove(getCurrentState(), getRole(), moveUnderConsideration));
				if (theMachine.getGoal(nextState, getRole()) > maxGoal)
				{
					selection = moveUnderConsideration;
					maxGoal = theMachine.getGoal(nextState, getRole());
				}
        	}
		}
*/

		long stop = System.currentTimeMillis();
		System.out.println("Next move " + selection.toString());
		notifyObservers(new GamerSelectedMoveEvent(moves, selection, stop - start));
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
	}

	@Override
	public String getName() {
		return "LogicalPlayer";
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
