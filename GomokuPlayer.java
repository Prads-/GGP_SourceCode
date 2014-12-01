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

	private char [][] board;
	private int width, height, k;
	private char empty1 = 'b', empty2 = 'c';
	private String actionStr;
	private boolean boardInitialised;

	@Override
	public void stateMachineMetaGame(long timeout) throws TransitionDefinitionException, MoveDefinitionException, GoalDefinitionException {
		super.stateMachineMetaGame(timeout);
		empty1 = 'b';
		empty2 = 'c';
		boardInitialised = false;
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
			if (!boardInitialised) {
				boardInitialised = true;
				initialiseBoard(availableMoves);
			}

			String moveStr = availableMoves.get(0).toString();
			int index = moveStr.indexOf(" ", 2);
			actionStr = moveStr.substring(2, index);

			findOpponentInput(availableMoves);

			if (board[width / 2][height / 2] == empty1) {
				board[width / 2][height / 2] = 'x';
				String moveString = makeMoveStr(width / 2, height / 2);
				retMove = getMoveFromStr(availableMoves, moveString);
			} else {
				int [] x = new int[1], y = new int[1];
				if (!checkWin(x, y, 'x')) {
					if (!checkWin(x, y, 'o')) {
						int [] myX = new int[1], myY = new int[1],
								oppX = new int[1], oppY = new int[1];
						int myThreat = getHighestThreatMove(myX, myY, 'x');
						int oppThreat = getHighestThreatMove(oppX, oppY, 'o');
						System.out.println("My threat: " + myThreat);
						System.out.println("Opponent threat: " + oppThreat);
						if (oppThreat > myThreat || oppThreat == k - 1) {
							System.out.println("Blocking opponent");
							x = oppX;
							y = oppY;
						} else {
							x = myX;
							y = myY;
							System.out.println("Offensive move");
						}
					}
				}
				board[x[0]][y[0]] = 'x';
				String moveString = makeMoveStr(x[0], y[0]);
				retMove = getMoveFromStr(availableMoves, moveString);
			}
			printBoard();
		}

		long stop = System.currentTimeMillis();
		notifyObservers(new GamerSelectedMoveEvent(availableMoves, retMove, stop - start));

		return retMove;
	}

	private void initialiseBoard(List<Move> availableMoves) {
		int [] x = new int[1], y = new int[1];

		x[0] = 0;
		y[0] = 0;
		for (Move move : availableMoves) {
			int [] tempX = new int[1], tempY = new int[1];
			parseMoveStr(tempX, tempY, move.toString());
			if (tempX[0] > x[0]) {
				x[0] = tempX[0];
			}
			if (tempY[0] > y[0]) {
				y[0] = tempY[0];
			}
		}
		width = x[0] + 1;
		height = y[0] + 1;

		System.out.println("Width: " + width);
		System.out.println("Height: " + height);
		board = new char[width][height];
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				board[i][j] = empty1;
			}
		}

		if (width == 3 && height == 3) {	//tic-tac-toe
			k = 3;
		} else {	//gomoku
			k = 5;
		}
	}

	private String makeMoveStr(int x, int y) {
		return ("( " + actionStr + " " + (y + 1) + " " + (x + 1) + " )");
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
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
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
		return new Move(GdlPool.getConstant("NOOP"));
	}

	private void parseMoveStr(int [] x, int [] y, String moveStr) {
		int index1 = moveStr.indexOf(" ", 2);
		++index1;
		int index2 = moveStr.indexOf(" ", index1);
		y[0] = Integer.parseInt(moveStr.substring(index1, index2)) - 1;
		++index2;
		index1 = moveStr.indexOf(" ", index2);
		x[0] = Integer.parseInt(moveStr.substring(index2, index1)) - 1;
	}

	private boolean checkWin(int [] x, int [] y, char mark) {
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				if (board[i][j] == empty1) {
					board[i][j] = mark;
					if (checkWinStatus(mark)) {
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

	private boolean checkWinStatus(char mark) {
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j <= height - k; ++j) {
				boolean win = true;
				for (int k = 0; k < this.k && win; ++k) {
					win = (board[i][j + k] == mark);
				}
				if (win) {
					return true;
				}
			}
		}
		for (int i = 0; i <= width - k; ++i) {
			for (int j = 0; j < height; ++j) {
				boolean win = true;
				for (int k = 0; k < this.k && win; ++k) {
					win = (board[i + k][j] == mark);
				}
				if (win) {
					return true;
				}
			}
		}
		for (int i = 0; i <= width - k; ++i) {
			for (int j = k - 1; j < height; ++j) {
				boolean win = true;
				for(int k = 0; k < this.k && win; ++k) {
					win = (board[i + k][j - k] == mark);
				}
				if(win) {
					return true;
				}
			}
		}
		for (int i = 0; i <= width - k; ++i) {
			for (int j = height - k; j >= 0; --j) {
				boolean win = true;
				for (int k = 0; k < this.k && win; ++k) {
					win = (board[i + k][j + k] == mark);
				}
				if (win) {
					return true;
				}
			}
		}
		return false;
	}

	private int getHighestThreatMove(int [] x, int [] y, char mark) {
		int highestThreat = -1;
		x[0] = 0;
		y[0] = 0;
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				if (board[i][j] == empty1) {
					int currentThreat = 0;
					boolean wasThreat = false;
					for (int k = i + 1; k < width; ++k) {
						if (board[k][j] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[k][j] == empty1 && wasThreat) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					wasThreat = false;
					for (int k = i - 1; k >= 0; --k) {
						if (board[k][j] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[k][j] == empty1 && wasThreat) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;
					wasThreat = false;

					for (int k = j + 1; k < height; ++k) {
						if (board[i][k] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[i][k] == empty1 && wasThreat) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					wasThreat = false;
					for (int k = j - 1; k >= 0; --k) {
						if (board[i][k] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[i][k] == empty1 && wasThreat) {
							++currentThreat;
							break;
						} else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;
					wasThreat = false;

					for (int k = 1; i + k < width && j + k < height; ++k) {
						if (board[i + k][j + k] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[i + k][j + k] == empty1 && wasThreat) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					wasThreat = false;
					for (int k = 1; i - k >= 0 && j - k >= 0; ++k) {
						if (board[i - k][j - k] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[i - k][j - k] == empty1 && wasThreat) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					highestThreat = compareThreat(x, y, i, j, currentThreat, highestThreat);
					currentThreat = 0;
					wasThreat = false;

					for (int k = 1; i - k >= 0 && j + k < height; ++k) {
						if (board[i - k][j + k] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[i - k][j + k] == empty1 && wasThreat) {
							++currentThreat;
							break;
						}  else {
							break;
						}
					}
					wasThreat = false;
					for (int k = 1; i + k < width && j - k >= 0; ++k) {
						if (board[i + k][j - k] == mark) {
							++currentThreat;
							wasThreat = true;
						} else if (board[i + k][j - k] == empty1 && wasThreat) {
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
		return highestThreat;
	}

	private int compareThreat(int [] x, int [] y, int i, int j, int currentThreat, int highestThreat) {
		if (currentThreat >= highestThreat) {
			x[0] = i;
			y[0] = j;
			return currentThreat;
		}
		return highestThreat;
	}

	private void printBoard() {
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height; ++j) {
				if (board[i][j] != 'x' && board[i][j] != 'o') {
					System.out.print(".");
				} else {
					System.out.print(board[i][j]);
				}
			}
			System.out.println("");
		}
		System.out.println("");
	}
}