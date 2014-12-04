package org.ggp.base.player.gamer.statemachine.gomoku;


public class MoveMaker {

private	int defenceLevel=1;

public Position getMove(Board board, int player) {
	int m = board.getM();
	int k = board.getK();
	int midX = m/2;
	int midY = m/2;
	Position p = new Position(midX, midY);

	//board.printBoard();

	//Strategy 1: fill center
	if(board.getGrid(midX, midY) == 0) {
		return p;
	}

	//Strategy 2: Check if I can win now
    if(checkWin(board, p, player)) {
    	System.out.println("I win at (" + (p.x+1) + ", " + (p.y+1) + ") ");
     	return p;
	}

    //Strategy 3: Check if the opponent can win
    {	p.x = midX; p.y = midY;
    	Board interboard= new Board(board);
    	interboard.switchTurn();
    	if(checkWin(interboard,p, -1*player)) {
    		System.out.println("Protect at (" + (p.x+1) + ", " + (p.y+1) + ") ");
    		return p;
    	}
	}

	//Strategy 4: Make a threat
    if(checkThreat(board, p, player, 0)) {
    	System.out.println("threat at (" + (p.x+1) + ", " + (p.y+1) + ") at level " + 0);
     	return p;
	}

    //Strategy 5: Defence
	for(int t=0; t < k-defenceLevel; t++) {
			Board boardPtr = new Board(board);
			boardPtr.switchTurn();
			int opponent = -1*player;
			if(checkThreat(boardPtr, p, opponent, t)) {
				System.out.println( "defense at (" + (p.x+1) + ", " + (p.y+1) + ") for level " + t);
				return p;
			}
		}

    //Strategy 6: Do whatever close to myself
	for(int t=1; t<k-1;t++) {
		if(checkThreat(board, p, player, t)) {
	    	System.out.println("Create " + (k-t-1));
			return p;
		}
	}

	if(firstAvailable(board, p, player)) {
		return p;
	}

	System.out.println("Can't move!");
	p.x = -1;
	p.y = -1;
	return p;
}

public boolean checkWin(Board board, Position p, int player) {
	int m = board.getM();
	int k = board.getK();

    for(int i = 0;i<m ;i++)  {
    	for(int j=0; j<m;j++) {
    		Board boardPtr = new Board(board);
    		boardPtr.addMove(player, i, j);
    		if(boardPtr.checkWinningStatus(player, k)==player) {
    			p.x = i; p.y = j;
    			return true;
    		}
    	}
    }
    return false;
}


public boolean checkThreat(Board board, Position p, int player, int level) {
	int m = board.getM();
	int k = board.getK()-level;
	int midX = m/2;
	int midY = m/2;

    for(int i = midX ;i>=0 ;i--)  {
    	for(int j= midY; j>=0;j--) {
    		if(board.checkPoint(player,i,j, k)) {
    			p.x = i; p.y = j;
    			return true;
    		}
    	}

    	for(int j= midY+1; j<m;j++) {
       		if(board.checkPoint(player, i,j, k)) {
        			p.x = i; p.y = j;
        			return true;
        	}
    	}
    }

    for(int i = midX+1;i<m ;i++) {
    	for(int j= midY; j>=0;j--) {
       		if(board.checkPoint(player, i,j, k)) {
        			p.x = i; p.y = j;
        			return true;
       		}
    	}
      	for(int j= midY+1; j<m;j++) {
       		if(board.checkPoint(player, i,j, k)) {
        			p.x = i; p.y = j;
        			return true;
        	}
      	}
    }

	return false;
}

public boolean firstAvailable(Board board, Position p, int player) {
	int m = board.getM();

    for(int i = m/2;i<m ;i++) {
     	for(int j= m/2; j<m; j++) {
    		if(board.getGrid(i,j) == 0) {
     			p.x = i; p.y=j;
     			return true;
     		}
     	}
     	for(int j= m/2-1; j>=0 ; j--) {
    		if(board.getGrid(i,j) == 0) {
     			p.x = i; p.y=j;
     			return true;
     		}
     	}
     }

    for(int i = m/2-1;i>=0 ;i--) {
     	for(int j= m/2; j<m; j++) {
    		if(board.getGrid(i,j) == 0) {
     			p.x = i; p.y=j;
     			return true;
     		}
     	}

     	for(int j= m/2-1; j>=0; j--) {
    		if(board.getGrid(i,j) == 0) {
     			p.x = i; p.y=j;
     			return true;
     		}
     	}
    }

    return false;
}

}
