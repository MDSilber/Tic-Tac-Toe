/*
 * PlayTicTacToe.cpp
 *
 *  Created on: Feb 2, 2011
 *      Author: MasonSilber
 */

#include <iostream>
#include "TicTacToeBoard.h"

using namespace std;

void checkGame(TicTacToeBoard, int);

bool doneGame;
int moveCounter = 0;

int main(int argc, char* argv)
{
	TicTacToeBoard board;
	int player1 = 1;
	int player2 = 2;
	int row, column;
	doneGame = false;

	cout << "\nWelcome to the Tic Tac Toe game!\n";
	cout << "This is a two player game.\n";
	cout << "Player one's mark is 'X', player two's mark is 'O', \nand an empty space is labeled with '-'.\n";
	board.printBoard();

	cout << "\nPlayer one goes first.";
	while(!doneGame)
	{
		cout << "\nPlayer one: enter the row and column where you would like to place your mark.\n";
		cin >> row; cin >> column;
		board.move(row, column, player1);
		moveCounter++;
		cout << "Moves made: " << moveCounter << "\n";
		board.printBoard();
		//No need to check unless player one has taken at least three moves
		if(moveCounter >4)
		{
			checkGame(board, moveCounter);
		}

		while(!doneGame)
		{
			cout << "\nPlayer two: enter the row and column where you would like to place your mark.\n";
			cin >> row; cin >> column;
			board.move(row, column, player2);
			moveCounter++;
			board.printBoard();
			//No need to check unless player two has taken at least three moves
			if(moveCounter > 5)
			{
				checkGame(board, moveCounter);
			}
			break;
		}
	}

	return 0;
}

void checkGame(TicTacToeBoard gameBoard, int movesMade)
{
	//Rows
	while(!doneGame)
	{
		for(int i = 0; i<3;i++)
		{
			if((gameBoard.getValues(i,0) == gameBoard.getValues(i,1) && gameBoard.getValues(i,1) == gameBoard.getValues(i,2)) && (gameBoard.getValues(i,0) == 2 || gameBoard.getValues(i,0) == 1))
			{
				/*cout << "Row: " << i;
				cout << "First slot : " << gameBoard.getValues(i,0) << " Second Slot : " << gameBoard.getValues(i,1) << " Third Slot : " << gameBoard.getValues(i,2) ;*/
				doneGame = true;
				if(gameBoard.getValues(i,0) == 1)
				{
					cout << "\nPlayer 1 wins!\n";
				}
				else
				{
					cout << "\nPlayer 2 wins!\n";
				}
				return;
			}
		}

		//Columns
		for(int i = 0; i<3; i++)
		{
			if((gameBoard.getValues(0,i) == gameBoard.getValues(1,i) && gameBoard.getValues(1,i) == gameBoard.getValues(2,i)) && (gameBoard.getValues(0,i) == 2 || gameBoard.getValues(0,i) == 1))
			{
				/*cout << "Column : " << i;
				cout << " First slot : " << gameBoard.getValues(0,i) << " Second Slot : " << gameBoard.getValues(1,i) << " Third Slot : " << gameBoard.getValues(2,i) ;*/

				doneGame = true;
				if(gameBoard.getValues(0,i) == 1)
				{
					cout << "\nPlayer 1 wins!\n";
				}
				else
				{
					cout << "\nPlayer 2 wins!\n";
				}
				return;
			}
		}

		//Left to right diagonal
		if((gameBoard.getValues(0,0) == gameBoard.getValues(1,1) && gameBoard.getValues(1,1) == gameBoard.getValues(2,2)) && (gameBoard.getValues(0,0) == 2 || gameBoard.getValues(0,0) == 1))
		{
			/*cout << "Left to right diagonal";
			cout << "First slot : " << gameBoard.getValues(0,0) << " Second Slot : " << gameBoard.getValues(1,1) << " Third Slot : " << gameBoard.getValues(2,2) ;*/
			doneGame = true;
			if(gameBoard.getValues(0,0) == 1)
			{
				cout << "\nPlayer 1 wins!\n";
			}
			else
			{
				cout << "\nPlayer 2 wins!\n";
			}
			return;
		}

		//Right to left diagonal
		if((gameBoard.getValues(0,2) == gameBoard.getValues(1,1) && gameBoard.getValues(1,1) == gameBoard.getValues(2,0)) && (gameBoard.getValues(0,2) == 2 || gameBoard.getValues(0,2) == 1))
		{
			/*cout << "Right to left diagonal";
			cout << "First slot : " << gameBoard.getValues(0,2) << " Second Slot : " << gameBoard.getValues(1,1) << " Third Slot : " << gameBoard.getValues(2,0) ;*/
			doneGame = true;
			if(gameBoard.getValues(0,2) == 1)
			{
				cout << "\nPlayer 1 wins!\n";
			}
			else
			{
				cout << "\nPlayer 2 wins!\n";
			}
			return;
		}

		//Draw
		if(movesMade == 9 && doneGame == false)
		{
			doneGame = true;
			cout << "\nThe game ended in a draw.\n\n";
			return;
		}

		break;
	}
}
