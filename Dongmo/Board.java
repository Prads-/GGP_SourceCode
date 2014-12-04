package org.ggp.base.player.gamer.statemachine.gomoku;
/*
 *
 *  Created on: 28/11/2014
 *      Author: dongmo
 */

public class Board
{
private	int m,k;
private	int turn=1; //1 = black; -1 = while
private int[][]  grid; // 1 = black; -1 = white; 0 = empty

public	Board(int mm, int kk) {
		m = mm;
		k = kk;
		grid = new int[m][m];
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++)
			  grid[i][j] = 0;

    	turn = 1; // black has the first turn
	}

public Board(Board b) {
	m = b.getM();
	k = b.getK();

	grid = new int[m][m];

	for (int i = 0; i< m; i++)
		for (int j=0;j<m;j++)
			grid[i][j] = b.getGrid(i,j);

	turn = b.getTurn();
}

public	int getM() {return m;}

public	int getK() {return k;}

public	int getGrid(int x, int y) {return grid[x][y];}

public	boolean isGridEmpty(int x, int y) {
	return grid[x][y]==0?true:false;
}

// 0<= x, y < m

public	int getTurn() {return turn;}

public	void switchTurn() { turn = -1*turn;}

public boolean addMove(int player, int x, int y)
{
	if( x < 0 || y < 0 || x >= m || y >= m) {
		System.out.println("Move (" + (x+1) + ", " + (y+1) + ") out of range!");
		return false;
	}

	if( player != turn) {
//		System.out.println("It is not player " + player + "'s turn!");
		return false;
	}

	if( grid[x][y]!= 0) {
//		System.out.println("Position (" + (x+1) + ", " + (y+1) + ") has been occupied!");
		return false;
	}

	if(checkWinningStatus() != 0 || isBoardFull()) {
		System.out.println( "Game is over!");
		return false;
	}

	grid[x][y] = player;

	turn = -1* turn;

	return true;
}

public int checkWinningStatus() {
	return checkWinningStatus(1, k);
}

public int checkWinningStatus(int player, int length) {
	//check rows
	for( int i = 0; i < m; i++ )	{
		for( int j = 0; j <= m-length; j++ )	{
			boolean win = true;
			for(int l = 0; l<length && win;l++)
				win = (grid[i][j+l] == player);

			if(win) {
				return player;
			}
		}
	}

	//check column
	for( int j = 0; j < m; j++ )	{
		for( int i = 0; i <= m-length; i++ )	{
			boolean win = true;
			for(int l = 0; l<length && win; l++)
				win = (grid[i+l][j] == player);

			if(win) return player;
		}
	}

	//check forward diagonal
	for( int i = 0; i <= m-length; i++ )	{
		for( int j = length-1; j < m; j++ )	{
			boolean win = true;
			for(int l = 0; l<length && win; l++)
				win = (grid[i+l][j-l] == player);

			if(win) return player;
		}
	}

	//check backward diagonal
	for( int i = 0; i <= m-length; i++ )	{
		for( int j = m-length; j >= 0; j-- )	{
			boolean win = true;
			for(int l = 0; l<length && win; l++)
				win = (grid[i+l][j+l] == player);

			if(win) return player;
		}
	}

	return 0;
}


public boolean checkPoint(int player, int x, int y, int length) {

	if(grid[x][y]!=0) return false;

	int count = 0;
    int extra = 0;
	//check rows
	if(y+1<m) {
		int j = y+1;
		for( ; j<m; j++ )	{
			if(grid[x][j] != player) break;
			else count++;
		}
		if(j<m && grid[x][j]==0)
			extra++;
	}


	if( y-1>=0) {
		int j = y-1;
		for( ; j>=0; j-- )	{
			if(grid[x][j] != player) break;
			else count++;
		}
		if(j>=0 && grid[x][j]==0)
			extra++;
	}

	count += extra;

	if (count >= length )
		return true;
	else {
		count = 0;


		extra = 0;
	}

	//check column
	if(x+1<m) {
		int i = x+1;
		for( ; i<m; i++ )	{
			if(grid[i][y] != player) break;
			else count++;
		}
		if(i+1<m && grid[i+1][y]==0)
			extra++;
	}

	if(x-1>=0) {
		int i = x-1;
		for( ; i>=0; i-- )	{
			if(grid[i][y] != player) break;
			else count++;
		}
		if(i>=0 && grid[i][y]==0)
			extra++;
	}

	count += extra;

	if (count >= length )
		return true;
	else {
		count = 0;
		extra = 0;
	}

	//check forward diagonal
	if(x-1>=0 && y+1<m) {
		int l=1;
		for( ; x-l>=0 && y+l <m; l++ )	{
			if(grid[x-l][y+l] != player) break;
			else count++;
		}
		if(x-l>=0 && y+l<m && grid[x-l][y+l]==0)
			extra++;
	}

	if(x+1<m && y-1>=0) {
		int l=1;
		for( ; x+l<m && y-l>=0; l++ )	{
			if(grid[x+l][y-l] != player) break;
			else count++;
		}
		if(x+l < m && y-l>=0 && grid[x+l][y-l]==0)
			extra++;
	}

	count += extra;

	if (count >= length )
		return true;
	else {
		count = 0;
		extra = 0;
	}

	//check backward diagonal
	if(x+1<m && y+1<m) {
		int l = 1;
		for( ; x+l <m && y+l <m; l++ )	{
			if(grid[x+l][y+l] != player) break;
			else count++;
		}
		if(x+l < m && y+l <m && grid[x+l][y+l]==0)
			extra++;
	}

	if(x-1>=0 && y-1>=0) {
		int l = 1;
		for( ; x-l >= 0 && y-l>=0; l++ )	{
			if(grid[x-l][y-l] != player) break;
			else count++;
		}
		if(x-l>=0 && y-l>=0 && grid[x-l][y-l]==0)
			extra++;
	}

	count += extra;

	if (count>= length )
		return true;

	return false;
}

public boolean isBoardFull() {
	boolean full = true;

	for( int i = 0; i < m && full; i++ ) {
		for( int j = 0; j < m && full; j++ ) {
			full = ( grid[i][j] != 0 );
		}
	}
	return full;
}

public void printBoard()
{
	String ss = "   ";
	for( int j = 0; j < m; j++ )	{
		if(j<9)
			ss += (j+1) + "   ";
		else
			ss += (j+1) + "  ";
	}
	ss += "\n";

	for( int i = 0; i < m; i++ )	{
		if( i<9)
			ss += " " + (i+1) + " ";
		else
			ss += (i+1) + " ";

		for( int j = 0; j < m; j++ )		{
			if(grid[i][j] == 0) {
				if(j==0) {
					ss += " ";
				} else {
				   ss += "--- ";
				}
			}  else if (grid[i][j] == 1) {
				if(j==0) {
					ss += "X";
				} else {
				    ss += "---X";
				}
			} else {
				if(j==0) {
					ss += "O";
				} else {
				   ss += "---O";
				}
			}
		}
		ss += "\n";

		if(i<m-1) {
			ss += "   ";
			for( int j = 0; j < m; j++ ) {
				if(j==0) {
					ss += "|";
				} else {
					ss += "   |";
				}
			}
		}
		ss += "\n";
	}
	ss += "\n";

	System.out.println(ss);
}
}

