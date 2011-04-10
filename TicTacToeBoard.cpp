/*
 * TicTacToeBoard.cpp
 *
 *  Created on: Feb 2, 2011
 *      Author: MasonSilber
 */

#include "TicTacToeBoard.h"
#include <iostream>
using namespace std;


	TicTacToeBoard::TicTacToeBoard()
	{
		for(int i = 0; i<3;i++)
		{
			for(int j = 0; j<3; j++)
			{
				newBoard[i][j] = 0;
			}
		}
	}

	TicTacToeBoard::~TicTacToeBoard()
	{
	}

	void TicTacToeBoard::move(int row, int column, int player)
	{
		if(player == 1)
		{
			newBoard[row-1][column-1] = 1;
		}
		else
		{
			newBoard[row-1][column-1] = 2;
		}
	}

	void TicTacToeBoard::printBoard()
	{
		cout<< "Current board: \n";
		for(int i = 0; i<3;i++)
		{
			for(int j = 0; j<3;j++)
			{
				if(newBoard[i][j] == 1)
				{
					cout << "X" << " ";
				}

				if(newBoard[i][j] == 2)
				{
					cout << "O" << " ";
				}

				if(newBoard[i][j] != 1 && newBoard[i][j] != 2)
				{
					cout << "-" << " ";
				}
			}
			cout << "\n";
		}
	}

	int TicTacToeBoard::getValues(int row, int column) const
	{
		return newBoard[row][column];
	}

