package org.ggp.base.player.gamer.statemachine.gomoku;

public class Position {
   	public int x;
	public int y;
	public Position(int xx, int yy) {x=xx;y=yy;}
	@Override
	public String toString() {
		String ss="(" +x +", "+ y+ ") ";
		return ss;
	}
}
