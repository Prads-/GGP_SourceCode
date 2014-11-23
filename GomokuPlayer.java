package org.ggp.base.player.gamer.statemachine.sample;

import java.util.List;

import org.ggp.base.player.gamer.event.GamerSelectedMoveEvent;
import org.ggp.base.util.gdl.grammar.GdlPool;
import org.ggp.base.util.statemachine.Move;
import org.ggp.base.util.statemachine.StateMachine;
import org.ggp.base.util.statemachine.exceptions.GoalDefinitionException;
import org.ggp.base.util.statemachine.exceptions.MoveDefinitionException;
import org.ggp.base.util.statemachine.exceptions.TransitionDefinitionException;

public class GomokuPlayer extends SampleGamer {

	private char [][] board = new char[15][15];
	private char empty1 = 'b', empty2 = 'c';
	private String actionStr;

	@Override
	public void stateMachineMetaGame(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException {
		super.stateMachineMetaGame(timeout);
		empty1 = 'b';
		empty2 = 'c';
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				board[i][j] = empty1;
			}
		}
	}

	@Override
	public Move stateMachineSelectMove(long timeout)
			throws TransitionDefinitionException, MoveDefinitionException,
			GoalDefinitionException {
		long start = System.currentTimeMillis();
		StateMachine stateMachine = getStateMachine();
		List<Move> availableMoves = stateMachine.getLegalMoves(getCurrentState(), getRole());

		Move retMove = new Move(GdlPool.getConstant("NOOP"));

		if (availableMoves.size() > 1) {
			String moveStr = availableMoves.get(0).toString();
			int index = moveStr.indexOf(" ", 2);
			actionStr = moveStr.substring(2, index);

			findOpponentInput(availableMoves);

			if (board[7][7] == empty1) {
				board[7][7] = 'x';
				String moveString = makeMoveStr(7, 7);
				retMove = getMoveFromStr(availableMoves, moveString);
			} else {
				int [] x = new int[1], y = new int[1];
				if (!checkWin(x, y)) {
					getHighestThreatMove(x, y);
				}
				board[x[0]][y[0]] = 'x';
				String moveString = makeMoveStr(x[0], y[0]);
				retMove = getMoveFromStr(availableMoves, moveString);
			}
		}

		long stop = System.currentTimeMillis();
		notifyObservers(new GamerSelectedMoveEvent(availableMoves, retMove, stop - start));
		return retMove;
	}

	private String makeMoveStr(int x, int y) {
		return ("( " + actionStr + " " + (x + 1) + " " + (y + 1) + " )");
	}

	private void swapEmptyVar() {
		empty1 ^= empty2;
		empty2 ^= empty1;
		empty1 ^= empty2;
	}

	private void findOpponentInput(List<Move> legalMoves) {
		swapEmptyVar();
		for (Move move : legalMoves) {
			String moveStr = move.toString();
			int [] x = new int[1], y = new int[1];
			parseMoveStr(x, y, moveStr);
			board[x[0]][y[0]] = empty1;
		}
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				if (board[i][j] == empty2) {
					board[i][j] = 'o';
					return;
				}
			}
		}
	}

	private Move getMoveFromStr(List<Move> legalMoves, String moveStr) {
		for (Move move : legalMoves) {
			if (move.toString().equals(moveStr)) {
				return move;
			}
		}
		/*for (Move move : legalMoves) {
			System.out.println(move.toString());
		}
		System.out.println("Couldn't find move: " + moveStr + "\r\n");*/
		return new Move(GdlPool.getConstant("NOOP"));
	}

	private void parseMoveStr(int [] x, int [] y, String moveStr) {
		int index1 = moveStr.indexOf(" ", 2);
		++index1;
		int index2 = moveStr.indexOf(" ", index1);
		x[0] = Integer.parseInt(moveStr.substring(index1, index2)) - 1;
		++index2;
		index1 = moveStr.indexOf(" ", index2);
		y[0] = Integer.parseInt(moveStr.substring(index2, index1)) - 1;
	}

	private boolean checkWin(int [] x, int [] y) {
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				if (board[i][j] == empty1) {
					board[i][j] = 'x';
					if (checkWinStatus()) {
						x[0] = i;
						y[0] = j;
						return true;
					}
					board[i][j] = empty1;
				}
			}
		}
		return false;
	}

	private boolean checkWinStatus() {
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 10; ++j) {
				boolean win = true;
				for (int k = 0; k < 5 && win; ++k) {
					win = (board[i][j + k] == 'x');
				}
				if (win) {
					return true;
				}
			}
		}
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 15; ++j) {
				boolean win = true;
				for (int k = 0; k < 5 && win; ++k) {
					win = (board[i + k][j] == 'x');
				}
				if (win) {
					return true;
				}
			}
		}
		for (int i = 0; i <= 10; ++i) {
			for (int j = 4; j < 15; ++j) {
				boolean win = true;
				for(int k = 0; k < 5 && win; ++k) {
					win = (board[i + k][j - k] == 'x');
				}
				if(win) {
					return true;
				}
			}
		}
		for (int i = 0; i <= 10; ++i) {
			for (int j = 10; j >= 0; --j) {
				boolean win = true;
				for (int k = 0; k < 5 && win; ++k) {
					win = (board[i + k][j + k] == 'x');
				}
				if (win) {
					return true;
				}
			}
		}
		return false;
	}

	private void getHighestThreatMove(int [] x, int [] y) {
		int highestThreat = -1;
		x[0] = 0;
		y[0] = 0;
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 15; ++j) {
				if (board[i][j] == empty1) {
					int currentThreat = 0;
					for (int k = i + 1; k < 15; ++k) {
						if (board[k][j] == 'x') {
							++currentThreat;
						} else if (board[k][j] == empty1) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = i - 1; k >= 0; ++k) {
						if (board[k][j] == 'x') {
							++currentThreat;
						} else if (board[k][j] == empty1) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = j + 1; k < 15; ++k) {
						if (board[i][k] == 'x') {
							++currentThreat;
						} else if (board[i][k] == empty1) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = j - 1; k >= 0; ++k) {
						if (board[i][k] == 'x') {
							++currentThreat;
						} else if (board[i][k] == empty1) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = 1; i + k < 15 && j + k < 15; ++k) {
						if (board[i + k][j + k] == 'x') {
							++currentThreat;
						} else if (board[i + k][j + k] == empty1) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
						if (board[i - k][j - k] == 'x') {
							++currentThreat;
						} else if (board[i - k][j - k] == empty1) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = 1; i - k >= 0 && j + k < 15; ++k) {
						if (board[i - k][j + k] == 'x') {
							++currentThreat;
						} else if (board[i - k][j + k] == empty1) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;

					for (int k = 1; i + k < 15 && j - k >= 0; ++k) {
						if (board[i + k][j - k] == 'x') {
							++currentThreat;
						} else if (board[i + k][j - k] == empty1) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
				}
			}
		}
	}

	private int compareThreat(int [] x, int [] y, int i, int j, int currentThreat, int highestThreat) {
		if (currentThreat >= highestThreat) {
			x[0] = i;
			y[0] = j;
			return currentThreat;
		}
		return highestThreat;
	}
}