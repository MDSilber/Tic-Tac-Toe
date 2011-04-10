/*
 * TicTacToeBoard.h
 *
 *  Created on: Feb 2, 2011
 *      Author: MasonSilber
 */

#ifndef TICTACTOEBOARD_H_
#define TICTACTOEBOARD_H_

class TicTacToeBoard
{
public:
	TicTacToeBoard();

	~TicTacToeBoard();


	void move(int row, int column, int player);

	void printBoard();

	int getValues(int row, int column) const;

	const TicTacToeBoard& getBoard() const;


private:
	int newBoard[3][3];
};


#endif /* TICTACTOEBOARD_H_ */
