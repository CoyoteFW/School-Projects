// CoxCasey_TicTacToe.cpp : Game of Tic-Tac-Toe.
//Write TTT
//Use two-dimensinoal string array with three rows and three columns as the game board
//Each element intitialized with an asterisk
//Program must run loop that:
//*Displays the contents of the board array.
//*Allows player 1 to select a location on the board for an X. The program should ask the user to enter the row and column number.
//*Allows player 2 to select a location on the board for an O. The program should ask the user to enter the row and column number.
//Determines whether a player has won, or a tie has occurred. If a player has won, the program should declare that player the winner and end. If a tie has occurred, the program should say so and end.
//Player 1 wins when there are three Xs in a row on the game board. THe Xs can appear in a row, in a column, or diagonally across the board. A tie occurs when all the locations on the board are full, but there is no winner.


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

const int SIZE = 3;

//Function Prototypes
void drawBoard(int &pWin1, int &pWin2);
void gamePlay(string board[SIZE][SIZE], int &pWin1, int &pWin2);
void testWin(string pboard[SIZE][SIZE], int &pWin1, int &pWin2);
void testTie(string pboard[SIZE][SIZE]);
void aiBoard();
void aiGameplay(string pboard[SIZE][SIZE]);
void testAIwin(string pboard[SIZE][SIZE], int &pWin, int &aiWin, int &check);
void aiWinCheck(string pboard[SIZE][SIZE], int &check);
void aiBlock(string pboard[SIZE][SIZE], int &check);
void aiFork(string pboard[SIZE][SIZE], int &check);
void aiBlockFork(string pboard[SIZE][SIZE], int &check);
void center(string pboard[SIZE][SIZE], int &check);
void oppCorner(string pboard[SIZE][SIZE], int &check);
void emptyCorner(string pboard[SIZE][SIZE], int &check);
void emptySide(string pboard[SIZE][SIZE], int &check);
void tttAdvanced();
void tttadvDraw(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE]);
void tttVSMode(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE]);
void winSubCheck(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE]);
void winMainCheck(string boardMain[SIZE][SIZE], int &pWin1, int &pWin2);
void tieCheck(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE]);



int main()
{
	int gameMode = 0;
	int pWin1 = 0;
	int pWin2 = 0;

	//Intro Text
	cout << "\t Welcome to Tic-Tac-Toe" << endl;
	cout << "\t The rules of the game:" << endl;
	cout << "One player can move at a time." << endl;
	cout << "The player selects the row and column position of the box they want." << endl;
	cout << "The two players switch sides until either one wins, or they draw." << endl;
	cout << "The board is made in such a way where the top left space is [0,0] and the bottom right being [2,2],\n with the first number representing the number of the row, and the second the number of the column. " << endl;
	cout << "Player 1 is [X] Player 2 is [O]" << endl;
	cout << " " << endl;
	cout << "NEW GAMEMODE: 9X9. Fight the AI or a friend in a 9X9 game of TTT." << endl;
	cout << "Each square of the Main board is its own self-contained game." << endl;
	cout << "To win the Main board, you have to win each individual game in a line." << endl;
	cout << "Press 0 to select Player vs. mode. Press 1 to select AI vs. mode." << endl;
	cout << "Press 2 to select 9X9 vs." << endl;
	cin >> gameMode;

	switch (gameMode)
	{
	case 0:
		drawBoard(pWin1, pWin2);
		break;
	case 1:
		aiBoard();
		break;
	case 2:
		tttAdvanced();
		break;
	}


	return 0;
}
void drawBoard(int &pWin1, int &pWin2) //board build
{
	//Board
	string board[SIZE][SIZE];

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			board[row][col] = "*";
		}
	}
	//move to gameplay
	gamePlay(board, pWin1, pWin2);
}
void gamePlay(string pboard[SIZE][SIZE], int &pWin1, int &pWin2)
{
	//Var. Declarations
	int row = 0;
	int col = 0;


	while (pWin1 != 1 && pWin2 != 1)
	{
		//print board
		for (int b = 0; b < SIZE; b++)
		{
			for (int c = 0; c < SIZE; c++)
			{
				cout << pboard[b][c];
			}
			cout << endl;
		}
		//player 1 input
		cout << "Player 1 indicate your row: " << endl;
		cin >> row;
		cout << "Player 1 indicate your column: " << endl;
		cin >> col;

		pboard[row][col] = "X";

		testWin(pboard, pWin1, pWin2);
		testTie(pboard);

		if (pWin1 == 1)
		{
			cout << "Player 1 has won." << endl;
		}
		else if (pWin2 == 1)
		{
			cout << "Player 2 has won." << endl;
		}

		//show player 1 input
		for (int b = 0; b < SIZE; b++)
		{
			for (int c = 0; c < SIZE; c++)
			{
				cout << pboard[b][c];
			}
			cout << endl;
		}

		//player 2 input
		cout << "Player 2 indicate your row: " << endl;
		cin >> row;
		cout << "Player 2 indicate your column: " << endl;
		cin >> col;

		pboard[row][col] = "O";

		testWin(pboard, pWin1, pWin2);
		testTie(pboard);
	}

}
void testWin(string board[SIZE][SIZE], int &pWin1, int &pWin2)
{
	//Tests for player one

	//verticals
	if (board[0][0] == "X" && board[0][1] == "X" && board[0][2] == "X")
	{
		pWin1 = 1;
	}
	else if (board[1][0] == "X" && board[1][1] == "X" && board[1][2] == "X")
	{
		pWin1 = 1;
	}
	else if (board[2][0] == "X" && board[2][1] == "X" && board[2][2] == "X")
	{
		pWin1 = 1;
	}
	//horizontals
	else if (board[0][0] == "X" && board[1][0] == "X" && board[2][0] == "X")
	{
		pWin1 = 1;
	}
	else if (board[0][1] == "X" && board[1][1] == "X" && board[2][1] == "X")
	{
		pWin1 = 1;
	}
	else if (board[0][2] == "X" && board[1][2] == "X" && board[2][2] == "X")
	{
		pWin1 = 1;
	}
	//diagonals
	else if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X")
	{
		pWin1 = 1;
	}
	else if (board[2][0] == "X" && board[1][1] == "X" && board[0][2] == "X")
	{
		pWin1 = 1;
	}
	//Tests for player two

	//verticals
	else if (board[0][0] == "O" && board[0][1] == "O" && board[0][2] == "O")
	{
		pWin2 = 1;
	}
	else if (board[1][0] == "O" && board[1][1] == "O" && board[1][2] == "O")
	{
		pWin2 = 1;
	}
	else if (board[2][0] == "O" && board[2][1] == "O" && board[2][2] == "O")
	{
		pWin2 = 1;
	}
	//horizontals
	else if (board[0][0] == "O" && board[1][0] == "O" && board[2][0] == "O")
	{
		pWin2 = 1;
	}
	else if (board[0][1] == "O" && board[1][1] == "O" && board[2][1] == "O")
	{
		pWin2 = 1;
	}
	else if (board[0][2] == "O" && board[1][2] == "O" && board[2][2] == "O")
	{
		pWin2 = 1;
	}
	//diagonals
	else if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O")
	{
		pWin2 = 1;
	}
	else if (board[2][0] == "O" && board[1][1] == "O" && board[0][2] == "O")
	{
		pWin2 = 1;
	}

	if (pWin1 == 1)
	{
		cout << "Player 1 has won." << endl;
		exit(1);

	}
	else if (pWin2 == 1)
	{
		cout << "Player 2 has won." << endl;
		exit(1);
	}

}
void testTie(string board[SIZE][SIZE])
{
	int test = 0;

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (board[row][col] == "*")
			{
				test += 1;
			}
		}
	}
	if (test == 0)
	{
		cout << "The game has ended in a tie. " << endl;
		cout << "Play again soon. " << endl;
		exit(1);
	}
}
void aiBoard()
{
	//Board
	string board[SIZE][SIZE];

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			board[row][col] = "*";
		}

	}
	//move to gameplay
	aiGameplay(board);
}
void aiGameplay(string pboard[SIZE][SIZE])
{
	//Var. Declarations
	int row = 0;
	int col = 0;
	int pWin = 0;
	int aiWin = 0;

	while (pWin != 1 && aiWin != 1)
	{
		//print board
		cout << endl;
		for (int b = 0; b < SIZE; b++)
		{
			for (int c = 0; c < SIZE; c++)
			{
				cout << pboard[b][c];
			}
			cout << endl;
		}
		//player 1 input
		cout << endl;
		cout << "Player 1 indicate your row: " << endl;
		cin >> row;
		cout << endl;
		cout << "Player 1 indicate your column: " << endl;
		cin >> col;
		cout << endl;

		pboard[row][col] = "X";

		testWin(pboard, pWin, aiWin);
		testTie(pboard);

		if (pWin == 1)
		{
			cout << "Player 1 has won." << endl;
		}
		else if (aiWin == 1)
		{
			cout << "Player 2 has won." << endl;
		}

		//show player 1 input
		/*for (int b = 0; b < SIZE; b++)
		{
		for (int c = 0; c < SIZE; c++)
		{
		cout << pboard[b][c];
		}
		cout << endl;
		}*/

		//AI input
		int check = 0; //ai move counter

		aiWinCheck(pboard, check);
		aiBlock(pboard, check);
		aiFork(pboard, check);
		aiBlockFork(pboard, check);
		center(pboard, check);
		oppCorner(pboard, check);
		emptyCorner(pboard, check);
		emptySide(pboard, check);

		testAIwin(pboard, pWin, aiWin, check);
		testTie(pboard);
	}
	if (pWin == 1)
	{
		cout << "Player 1 has won." << endl;
	}
	else if (aiWin == 1)
	{
		cout << "The AI has won." << endl;
	}
}
void testAIwin(string pboard[SIZE][SIZE], int &pWin, int &aiWin, int &check)
{
	//Tests for player one

	//verticals
	if (pboard[0][0] == "X" && pboard[0][1] == "X" && pboard[0][2] == "X")
	{
		pWin = 1;
	}
	else if (pboard[1][0] == "X" && pboard[1][1] == "X" && pboard[1][2] == "X")
	{
		pWin = 1;
	}
	else if (pboard[2][0] == "X" && pboard[2][1] == "X" && pboard[2][2] == "X")
	{
		pWin = 1;
	}
	//horizontals
	else if (pboard[0][0] == "X" && pboard[1][0] == "X" && pboard[2][0] == "X")
	{
		pWin = 1;
	}
	else if (pboard[0][1] == "X" && pboard[1][1] == "X" && pboard[2][1] == "X")
	{
		pWin = 1;
	}
	else if (pboard[0][2] == "X" && pboard[1][2] == "X" && pboard[2][2] == "X")
	{
		pWin = 1;
	}
	//diagonals
	else if (pboard[0][0] == "X" && pboard[1][1] == "X" && pboard[2][2] == "X")
	{
		pWin = 1;
	}
	else if (pboard[2][0] == "X" && pboard[1][1] == "X" && pboard[0][2] == "X")
	{
		pWin = 1;
	}
	//Tests for player two

	//verticals
	else if (pboard[0][0] == "O" && pboard[0][1] == "O" && pboard[0][2] == "O")
	{
		aiWin = 1;
	}
	else if (pboard[1][0] == "O" && pboard[1][1] == "O" && pboard[1][2] == "O")
	{
		aiWin = 1;
	}
	else if (pboard[2][0] == "O" && pboard[2][1] == "O" && pboard[2][2] == "O")
	{
		aiWin = 1;
	}
	//horizontals
	else if (pboard[0][0] == "O" && pboard[1][0] == "O" && pboard[2][0] == "O")
	{
		aiWin = 1;
	}
	else if (pboard[0][1] == "O" && pboard[1][1] == "O" && pboard[2][1] == "O")
	{
		aiWin = 1;
	}
	else if (pboard[0][2] == "O" && pboard[1][2] == "O" && pboard[2][2] == "O")
	{
		aiWin = 1;
	}
	//diagonals
	else if (pboard[0][0] == "O" && pboard[1][1] == "O" && pboard[2][2] == "O")
	{
		aiWin = 1;
	}
	else if (pboard[2][0] == "O" && pboard[1][1] == "O" && pboard[0][2] == "O")
	{
		aiWin = 1;
	}

}
void aiWinCheck(string pboard[SIZE][SIZE], int &check)
{
	//Horizontal Checks
	if (pboard[0][0] == "O" && pboard[0][1] == "O")//Row 0
	{
		if (pboard[0][2] == "*")
		{
			pboard[0][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][0] == "O" && pboard[0][2] == "O")//Row 0
	{
		if (pboard[0][1] == "*")
		{
			pboard[0][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][1] == "O" && pboard[0][2] == "O")//Row 0
	{
		if (pboard[0][0] == "*")
		{
			pboard[0][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][0] == "O" && pboard[1][1] == "O") //Row 1
	{
		if (pboard[1][2] == "*")
		{
			pboard[1][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][0] == "O" && pboard[1][2] == "O") //Row 1
	{
		if (pboard[1][1] == "*")
		{
			pboard[1][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][1] == "O" && pboard[1][2] == "O") //Row 1
	{
		if (pboard[1][0] == "*")
		{
			pboard[1][0] = "O";
			check++;
			return;
		}
	}
	else if (pboard[2][0] == "O" && pboard[2][1] == "O") //Row 2
	{
		if (pboard[2][2] == "*")
		{
			pboard[2][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[2][0] == "O" && pboard[2][2] == "O") //Row 2
	{
		if (pboard[2][1] == "*")
		{
			pboard[2][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[2][1] == "O" && pboard[2][2] == "O") //Row 2
	{
		if (pboard[2][0] == "*")
		{
			pboard[2][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	//Vertical Checks
	else if (pboard[0][0] == "O" && pboard[1][0] == "O") //Column 0
	{
		if (pboard[2][0] == "*")
		{
			pboard[2][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][0] == "O" && pboard[2][0] == "O") //Column 0
	{
		if (pboard[0][0] == "*")
		{
			pboard[0][0] == "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][0] == "O" && pboard[2][0] == "O") //Column 0
	{
		if (pboard[1][0] == "*")
		{
			pboard[1][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][1] == "O" && pboard[1][1] == "O") //Column 1
	{
		if (pboard[2][1] == "*")
		{
			pboard[2][1] = "O";
			check++;
			return;
		}
		else
			return;
	}
	else if (pboard[1][1] == "O" && pboard[2][1] == "O") //Column 1
	{
		if (pboard[0][1] == "*")
		{
			pboard[0][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][1] == "O" && pboard[2][1] == "O") //Column 1
	{
		if (pboard[1][1] == "*")
		{
			pboard[1][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][2] == "O" && pboard[1][2] == "O") //Column 2
	{
		if (pboard[2][2] == "*")
		{
			pboard[2][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][2] == "O" && pboard[2][2] == "O") //Column 2
	{
		if (pboard[1][2] == "*")
		{
			pboard[1][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][2] == "O" && pboard[2][2] == "O") //Column 2
	{
		if (pboard[0][2] == "*")
		{
			pboard[0][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}

	// Diagonals
	else if (pboard[0][0] == "O" && pboard[1][1] == "O") //Diagonal 00-22
	{
		if (pboard[2][2] == "*")
		{
			pboard[2][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][1] == "O" && pboard[2][2] == "O") //Diag 00-22
	{
		if (pboard[0][0] == "O" && pboard[0][0] == "O")
		{
			pboard[0][0] == "*";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][0] == "O" && pboard[2][2] == "O") //Diag 00-22
	{
		if (pboard[1][1] == "*")
		{
			pboard[1][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][2] == "O" && pboard[1][1] == "O") //Diag 20-02
	{
		if (pboard[2][0] == "*")
		{
			pboard[2][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[0][2] == "O" && pboard[2][0] == "O") //Diag 20-02
	{
		if (pboard[1][1] == "*")
		{
			pboard[1][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
	else if (pboard[1][1] == "O" && pboard[2][0] == "O") //Diag 20-02
	{
		if (pboard[0][2] == "*")
		{
			pboard[0][2] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}

	}
}
void aiBlock(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		//Horizontal Checks
		if (pboard[0][0] == "X" && pboard[0][1] == "X")//Row 0
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[0][2] == "X")//Row 0
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[0][2] == "X")//Row 0
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[1][1] == "X") //Row 1
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[1][2] == "X") //Row 1
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[1][2] == "X") //Row 1
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
		}
		else if (pboard[2][0] == "X" && pboard[2][1] == "X") //Row 2
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "X" && pboard[2][2] == "X") //Row 2
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][1] == "X" && pboard[2][2] == "X") //Row 2
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		//Vertical Checks
		else if (pboard[0][0] == "X" && pboard[1][0] == "X") //Column 0
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[2][0] == "X") //Column 0
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] == "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[2][0] == "X") //Column 0
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[1][1] == "X") //Column 1
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
				return;
		}
		else if (pboard[1][1] == "X" && pboard[2][1] == "X") //Column 1
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[2][1] == "X") //Column 1
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[1][2] == "X") //Column 2
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[2][2] == "X") //Column 2
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "X" && pboard[2][2] == "X") //Column 2
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}

		// Diagonals
		else if (pboard[0][0] == "X" && pboard[1][1] == "X") //Diagonal 00-22
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][2] == "X") //Diag 00-22
		{
			if (pboard[0][0] == "O" && pboard[0][0] == "O")
			{
				pboard[0][0] == "*";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[2][2] == "X") //Diag 00-22
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[1][1] == "X") //Diag 20-02
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[2][0] == "X") //Diag 20-02
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][0] == "X") //Diag 20-02
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
	}
}
void aiFork(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		if (pboard[1][1] == "O" && pboard[2][2] == "O") //set1
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][1] == "O" && pboard[2][2] == "O")//set1
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][1] == "O") //set1

		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][1] == "O") //set2
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][0] == "O") //set2
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][1] == "O" && pboard[2][0] == "O")//set2
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[1][1] == "O")//set3
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[0][1] == "O")//set3
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[0][1] == "O")//set3
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "O" && pboard[1][1] == "O")//set4
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][0] == "O")//set4
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "O" && pboard[2][0] == "O")//set4
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[0][1] == "O")//set5
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[1][1] == "O")//set5
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[1][1] == "O")//set5
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[1][1] == "O")//set5
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[1][1] == "O")//set6
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[0][2] == "O")//set6
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[0][2] == "O")//set6
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[1][2] == "O")//set7
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "O" && pboard[0][2] == "O")//set7
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[0][2] == "O")//set7
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[1][2] == "O")//set8
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][2] == "O")//set8
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "O" && pboard[2][2] == "O")//set8
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][0] == "O")//set9
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][2] == "O")//set9
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "O" && pboard[2][0] == "O")//set9
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[1][1] == "O")//set10
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][0] == "O")//set10
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[2][0] == "O")//set10
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[0][0] == "O")//set11
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[0][2] == "O")//set11
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[0][0] == "O")//set11
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[2][2] == "O")//set12
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][2] == "O")//set12
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[1][1] == "O")//set12
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[1][1] == "O")//set13
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][1] == "O")//set13
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[2][1] == "O")//set13
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[1][1] == "O")//set14
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][1] == "O")//set14
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[2][1] == "O")//set14
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "O" && pboard[1][1] == "O")//set15
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[0][2] == "O")//set15
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "O" && pboard[0][2] == "O")//set15
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "O" && pboard[1][1] == "O")//set16
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][2] == "O")//set16
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "O" && pboard[2][2] == "O")//set16
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[1][1] == "O")//set17
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][0] == "O")//set17
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[2][0] == "O")//set17
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[1][1] == "O")//set18
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[2][2] == "O")//set18
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "O" && pboard[2][2] == "O")//set18
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[1][1] == "O")//set19
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "O" && pboard[1][2] == "O")//set19
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[1][2] == "O")//set19
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "O" && pboard[1][1] == "O")//set20
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "O" && pboard[1][2] == "O")//set20
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "O" && pboard[1][1] == "O")//set20
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[2][0] == "O")//set21
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "O" && pboard[0][0] == "O")//set21
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "O" && pboard[2][0] == "O")//set21
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "O" && pboard[2][2] == "O")//set22
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "O" && pboard[0][2] == "O")//set22
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "O" && pboard[0][2] == "O")//set22
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[2][0] == "O")//set23
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[0][0] == "O")//set23
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "O" && pboard[2][0] == "O")//set23
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "O" && pboard[0][2] == "O")//set24
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "O" && pboard[0][0] == "O")//set24
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "O" && pboard[0][2] == "O")//set24
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
	}
}
void aiBlockFork(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		if (pboard[1][1] == "X" && pboard[2][2] == "X") //set1
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][1] == "X" && pboard[2][2] == "X")//set1
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][1] == "X") //set1

		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][1] == "X") //set2
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][0] == "X") //set2
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][1] == "X" && pboard[2][0] == "X")//set2
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[1][1] == "X")//set3
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[0][1] == "X")//set3
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[0][1] == "X")//set3
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[1][1] == "X")//set4
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][0] == "X")//set4
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[2][0] == "X")//set4
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[0][1] == "X")//set5
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[1][1] == "X")//set5
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[1][1] == "X")//set5
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[1][1] == "X")//set5
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[1][1] == "X")//set6
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[0][2] == "X")//set6
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[0][2] == "X")//set6
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[1][2] == "X")//set7
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "X" && pboard[0][2] == "X")//set7
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[0][2] == "X")//set7
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[1][2] == "X")//set8
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][2] == "X")//set8
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "X" && pboard[2][2] == "X")//set8
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][0] == "X")//set9
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][2] == "X")//set9
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X" && pboard[2][0] == "X")//set9
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[1][1] == "X")//set10
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][0] == "X")//set10
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[2][0] == "X")//set10
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[0][0] == "X")//set11
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[0][2] == "X")//set11
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[0][0] == "X")//set11
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[2][2] == "X")//set12
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][2] == "X")//set12
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[1][1] == "X")//set12
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[1][1] == "X")//set13
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][1] == "X")//set13
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[2][1] == "X")//set13
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[1][1] == "X")//set14
		{
			if (pboard[2][1] == "*")
			{
				pboard[2][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][1] == "X")//set14
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[2][1] == "X")//set14
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[1][1] == "X")//set15
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[0][2] == "X")//set15
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[0][2] == "X")//set15
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[1][1] == "X")//set16
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][2] == "X")//set16
		{
			if (pboard[1][0] == "*")
			{
				pboard[1][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][0] == "X" && pboard[2][2] == "X")//set16
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[1][1] == "X")//set17
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][0] == "X")//set17
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[2][0] == "X")//set17
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[1][1] == "X")//set18
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[2][2] == "X")//set18
		{
			if (pboard[0][1] == "*")
			{
				pboard[0][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][1] == "X" && pboard[2][2] == "X")//set18
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[1][1] == "X")//set19
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][1] == "X" && pboard[1][2] == "X")//set19
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[1][2] == "X")//set19
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "X" && pboard[1][1] == "X")//set20
		{
			if (pboard[1][2] == "*")
			{
				pboard[1][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "X" && pboard[1][2] == "X")//set20
		{
			if (pboard[1][1] == "*")
			{
				pboard[1][1] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[1][2] == "X" && pboard[1][1] == "X")//set20
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[2][0] == "X")//set21
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X" && pboard[0][0] == "X")//set21
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X" && pboard[2][0] == "X")//set21
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "X" && pboard[2][2] == "X")//set22
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "X" && pboard[0][2] == "X")//set22
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X" && pboard[0][2] == "X")//set22
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[2][0] == "X")//set23
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[0][0] == "X")//set23
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X" && pboard[2][0] == "X")//set23
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][0] == "X" && pboard[0][2] == "X")//set24
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X" && pboard[0][0] == "X")//set24
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X" && pboard[0][2] == "X")//set24
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
	}
}
void center(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		if (pboard[1][1] == "*")
		{
			pboard[1][1] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
}
void oppCorner(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		if (pboard[0][0] == "X")
		{
			if (pboard[2][2] == "*")
			{
				pboard[2][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][2] == "X")
		{
			if (pboard[0][0] == "*")
			{
				pboard[0][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[0][2] == "X")
		{
			if (pboard[2][0] == "*")
			{
				pboard[2][0] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
		else if (pboard[2][0] == "X")
		{
			if (pboard[0][2] == "*")
			{
				pboard[0][2] = "O";
				check++;
				return;
			}
			else
			{
				return;
			}
		}
	}
}
void emptyCorner(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		if (pboard[0][0] == "*")
		{
			pboard[0][0] = "O";
			check++;
			return;
		}
		else if (pboard[0][2] == "*")
		{
			pboard[0][2] = "O";
			check++;
			return;
		}
		else if (pboard[2][2] == "*")
		{
			pboard[2][2] = "O";
			check++;
			return;
		}
		else if (pboard[2][0] == "*")
		{
			pboard[2][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
}
void emptySide(string pboard[SIZE][SIZE], int &check)
{
	if (check > 0)
	{
		return;
	}
	else
	{
		if (pboard[0][1] == "*")
		{
			pboard[0][1] = "O";
			check++;
			return;
		}
		else if (pboard[2][1] == "*")
		{
			pboard[2][1] = "O";
			check++;
			return;
		}
		else if (pboard[1][2] == "*")
		{
			pboard[1][2] = "O";
			check++;
			return;
		}
		else if (pboard[1][0] == "*")
		{
			pboard[1][0] = "O";
			check++;
			return;
		}
		else
		{
			return;
		}
	}
}

void tttAdvanced()
{

	string boardMain[SIZE][SIZE];
	string subGame0[SIZE][SIZE];
	string subGame1[SIZE][SIZE];
	string subGame2[SIZE][SIZE];
	string subGame3[SIZE][SIZE];
	string subGame4[SIZE][SIZE];
	string subGame5[SIZE][SIZE];
	string subGame6[SIZE][SIZE];
	string subGame7[SIZE][SIZE];
	string subGame8[SIZE][SIZE];

	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			boardMain[row][col] = "*";
			subGame0[row][col] = "*";
			subGame1[row][col] = "*";
			subGame2[row][col] = "*";
			subGame3[row][col] = "*";
			subGame4[row][col] = "*";
			subGame5[row][col] = "*";
			subGame6[row][col] = "*";
			subGame7[row][col] = "*";
			subGame8[row][col] = "*";
		}
	}
	tttVSMode(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);
}
void tttadvDraw(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE])
{
	//9x9 Board Draw
	cout << endl;
	cout << "Main Board Display" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << boardMain[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 1" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame0[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 2" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame1[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 3" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame2[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 4" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame3[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 5" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame4[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 6" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame5[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 7" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame6[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 8" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame7[row][col];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Board 9" << endl;
	cout << endl;
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			cout << " ";
			cout << subGame8[row][col];
		}
		cout << endl;
	}
}
void tttVSMode(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE])
{
	cout << "These are all possible boards. Each cell is another board you must play to place a mark on the main board." << endl;

	tttadvDraw(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);

	//variable declarations
	int pWin1 = 0;
	int pWin2 = 0;
	int cell = 0;
	int row = 0;
	int col = 0;

	//game loop
	while (pWin1 != 1 && pWin2 != 1)
	{
		//player one turn
		cout << endl;
		cout << " Player 1 select a number from 1 - 9 to choose a board: ";
		cin >> cell;
		cout << endl;
		switch (cell)
		{
		case 1:
		{
			cout <<"Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a column number: ";
			cin >> col;
			cout << endl;

			subGame0[row][col] = "X";

			break;
		}
		case 2:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame1[row][col] = "X";

			break;
		}
		case 3:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame2[row][col] = "X";

			break;
		}
		case 4:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame3[row][col] = "X";

			break;
		}
		case 5:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame4[row][col] = "X";

			break;
		}
		case 6:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame5[row][col] = "X";

			break;
		}
		case 7:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame6[row][col] = "X";

			break;
		}
		case 8:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame7[row][col] = "X";

			break;
		}
		case 9:
		{
			cout << "Player 1 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 1 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame8[row][col] = "X";

			break;
		}
		default:
			break;
		}

		winSubCheck(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);
		tieCheck(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);
		winMainCheck(boardMain, pWin1, pWin2); //function call

		system("cls");
		cout << "Board Updates!" << endl << endl;
		tttadvDraw(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);

		//player two turn
		cout << endl;
		cout << " Player 2 select a number from 1 - 9 to choose a board: ";
		cin >> cell;
		cout << endl;
		switch (cell)
		{
		case 1:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame0[row][col] = "O";

			break;
		}
		case 2:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame1[row][col] = "O";

			break;
		}
		case 3:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame2[row][col] = "O";

			break;
		}
		case 4:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame3[row][col] = "O";

			break;
		}
		case 5:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame4[row][col] = "O";

			break;
		}
		case 6:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame5[row][col] = "O";

			break;
		}
		case 7:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame6[row][col] = "O";

			break;
		}
		case 8:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame7[row][col] = "O";

			break;
		}
		case 9:
		{
			cout << "Player 2 enter a row number: ";
			cin >> row;
			cout << endl;
			cout << "Player 2 enter a col number: ";
			cin >> col;
			cout << endl;

			subGame8[row][col] = "O";

			break;
		}
		default:
			break;
		}

		winSubCheck(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);
		tieCheck(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);
		winMainCheck(boardMain, pWin1, pWin2); //function call

		system("cls");
		cout << "Board Update" << endl << endl;
		tttadvDraw(boardMain, subGame0, subGame1, subGame2, subGame3, subGame4, subGame5, subGame6, subGame7, subGame8);

	}

	if (pWin1 == 1)
	{
		cout << "Player 1 you won!" << endl;
	}
	else if (pWin2 == 1)
	{
		cout << " Player 2 you won!" << endl;
	}
}
void winSubCheck(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE])
{
	//Board 1 Win Check
	if (subGame0[0][0] == "X" && subGame0[0][1] == "X" && subGame0[0][2] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[1][0] == "X" && subGame0[1][1] == "X" && subGame0[1][2] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[2][0] == "X" && subGame0[2][1] == "X" && subGame0[2][2] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[0][0] == "X" && subGame0[1][0] == "X" && subGame0[2][0] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[0][1] == "X" && subGame0[1][1] == "X" && subGame0[2][1] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[0][2] == "X" && subGame0[1][2] == "X" && subGame0[2][2] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[0][0] == "X" && subGame0[1][1] == "X" && subGame0[2][2] == "X")
	{
		boardMain[0][0] = "X";
	}
	else if (subGame0[2][0] == "X" && subGame0[1][1] == "X" && subGame0[0][2] == "X")
	{
		boardMain[0][0] = "X";
	}

	//Board 2 
	if (subGame1[0][0] == "X" && subGame1[0][1] == "X" && subGame1[0][2] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[1][0] == "X" && subGame1[1][1] == "X" && subGame1[1][2] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[2][0] == "X" && subGame1[2][1] == "X" && subGame1[2][2] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[0][0] == "X" && subGame1[1][0] == "X" && subGame1[2][0] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[0][1] == "X" && subGame1[1][1] == "X" && subGame1[2][1] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[0][2] == "X" && subGame1[1][2] == "X" && subGame1[2][2] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[0][0] == "X" && subGame1[1][1] == "X" && subGame1[2][2] == "X")
	{
		boardMain[0][1] = "X";
	}
	else if (subGame1[2][0] == "X" && subGame1[1][1] == "X" && subGame1[0][2] == "X")
	{
		boardMain[0][1] = "X";
	}

	//Board 3 
	if (subGame2[0][0] == "X" && subGame2[0][1] == "X" && subGame2[0][2] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[1][0] == "X" && subGame2[1][1] == "X" && subGame2[1][2] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[2][0] == "X" && subGame2[2][1] == "X" && subGame2[2][2] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[0][0] == "X" && subGame2[1][0] == "X" && subGame2[2][0] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[0][1] == "X" && subGame2[1][1] == "X" && subGame2[2][1] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[0][2] == "X" && subGame2[1][2] == "X" && subGame2[2][2] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[0][0] == "X" && subGame2[1][1] == "X" && subGame2[2][2] == "X")
	{
		boardMain[0][2] = "X";
	}
	else if (subGame2[2][0] == "X" && subGame2[1][1] == "X" && subGame2[0][2] == "X")
	{
		boardMain[0][2] = "X";
	}

	//Board 4 
	if (subGame3[0][0] == "X" && subGame3[0][1] == "X" && subGame3[0][2] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[1][0] == "X" && subGame3[1][1] == "X" && subGame3[1][2] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[2][0] == "X" && subGame3[2][1] == "X" && subGame3[2][2] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[0][0] == "X" && subGame3[1][0] == "X" && subGame3[2][0] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[0][1] == "X" && subGame3[1][1] == "X" && subGame3[2][1] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[0][2] == "X" && subGame3[1][2] == "X" && subGame3[2][2] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[0][0] == "X" && subGame3[1][1] == "X" &&subGame3[2][2] == "X")
	{
		boardMain[1][0] = "X";
	}
	else if (subGame3[2][0] == "X" && subGame3[1][1] == "X" && subGame3[0][2] == "X")
	{
		boardMain[1][0] = "X";
	}

	//Board 5 
	if (subGame4[0][0] == "X" && subGame4[0][1] == "X" && subGame4[0][2] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[1][0] == "X" && subGame4[1][1] == "X" && subGame4[1][2] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[2][0] == "X" && subGame4[2][1] == "X" && subGame4[2][2] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[0][0] == "X" && subGame4[1][0] == "X" && subGame4[2][0] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[0][1] == "X" && subGame4[1][1] == "X" && subGame4[2][1] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[0][2] == "X" && subGame4[1][2] == "X" && subGame4[2][2] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[0][0] == "X" && subGame4[1][1] == "X" &&subGame4[2][2] == "X")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[2][0] == "X" && subGame4[1][1] == "X" && subGame4[0][2] == "X")
	{
		boardMain[1][1] = "X";
	}

	//Board 6 
	if (subGame5[0][0] == "X" && subGame5[0][1] == "X" && subGame5[0][2] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[1][0] == "X" && subGame5[1][1] == "X" && subGame5[1][2] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[2][0] == "X" && subGame5[2][1] == "X" && subGame5[2][2] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[0][0] == "X" && subGame5[1][0] == "X" && subGame5[2][0] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[0][1] == "X" && subGame5[1][1] == "X" && subGame5[2][1] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[0][2] == "X" && subGame5[1][2] == "X" && subGame5[2][2] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[0][0] == "X" && subGame5[1][1] == "X" && subGame5[2][2] == "X")
	{
		boardMain[1][2] = "X";
	}
	else if (subGame5[2][0] == "X" && subGame5[1][1] == "X" && subGame5[0][2] == "X")
	{
		boardMain[1][2] = "X";
	}

	//Board 7 
	if (subGame6[0][0] == "X" && subGame6[0][1] == "X" && subGame6[0][2] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[1][0] == "X" && subGame6[1][1] == "X" && subGame6[1][2] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[2][0] == "X" && subGame6[2][1] == "X" && subGame6[2][2] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[0][0] == "X" && subGame6[1][0] == "X" && subGame6[2][0] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[0][1] == "X" && subGame6[1][1] == "X" && subGame6[2][1] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[0][2] == "X" && subGame6[1][2] == "X" && subGame6[2][2] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[0][0] == "X" && subGame6[1][1] == "X" && subGame6[2][2] == "X")
	{
		boardMain[2][0] = "X";
	}
	else if (subGame6[2][0] == "X" && subGame6[1][1] == "X" && subGame6[0][2] == "X")
	{
		boardMain[2][0] = "X";
	}

	//Board 8 
	if (subGame7[0][0] == "X" && subGame7[0][1] == "X" && subGame7[0][2] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[1][0] == "X" && subGame7[1][1] == "X" && subGame7[1][2] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[2][0] == "X" && subGame7[2][1] == "X" && subGame7[2][2] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[0][0] == "X" && subGame7[1][0] == "X" && subGame7[2][0] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[0][1] == "X" && subGame7[1][1] == "X" && subGame7[2][1] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[0][2] == "X" && subGame7[1][2] == "X" && subGame7[2][2] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[0][0] == "X" && subGame7[1][1] == "X" && subGame7[2][2] == "X")
	{
		boardMain[2][1] = "X";
	}
	else if (subGame7[2][0] == "X" && subGame7[1][1] == "X" && subGame7[0][2] == "X")
	{
		boardMain[2][1] = "X";
	}

	//Board 9 
	if (subGame8[0][0] == "X" && subGame8[0][1] == "X" && subGame8[0][2] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[1][0] == "X" && subGame8[1][1] == "X" && subGame8[1][2] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[2][0] == "X" && subGame8[2][1] == "X" && subGame8[2][2] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[0][0] == "X" && subGame8[1][0] == "X" && subGame8[2][0] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[0][1] == "X" && subGame8[1][1] == "X" && subGame8[2][1] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[0][2] == "X" && subGame8[1][2] == "X" && subGame8[2][2] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[0][0] == "X" && subGame8[1][1] == "X" && subGame8[2][2] == "X")
	{
		boardMain[2][2] = "X";
	}
	else if (subGame8[2][0] == "X" && subGame8[1][1] == "X" && subGame8[0][2] == "X")
	{
		boardMain[2][2] = "X";
	}

	//player 2  Board 1 
	if (subGame0[0][0] == "O" && subGame0[0][1] == "O" && subGame0[0][2] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[1][0] == "O" && subGame0[1][1] == "O" && subGame0[1][2] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[2][0] == "O" &&subGame0[2][1] == "O" && subGame0[2][2] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[0][0] == "O" && subGame0[1][0] == "O" && subGame0[2][0] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[0][1] == "O" && subGame0[1][1] == "O" && subGame0[2][1] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[0][2] == "O" && subGame0[1][2] == "O" && subGame0[2][2] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[0][0] == "O" && subGame0[1][1] == "O" && subGame0[2][2] == "O")
	{
		boardMain[0][0] = "O";
	}
	else if (subGame0[2][0] == "O" && subGame0[1][1] == "O" && subGame0[0][2] == "O")
	{
		boardMain[0][0] = "O";
	}

	//Board 2 
	if (subGame1[0][0] == "O" && subGame1[0][1] == "O" && subGame1[0][2] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[1][0] == "O" && subGame1[1][1] == "O" && subGame1[1][2] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[2][0] == "O" && subGame1[2][1] == "O" && subGame1[2][2] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[0][0] == "O" && subGame1[1][0] == "O" && subGame1[2][0] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[0][1] == "O" && subGame1[1][1] == "O" && subGame1[2][1] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[0][2] == "O" && subGame1[1][2] == "O" && subGame1[2][2] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[0][0] == "O" && subGame1[1][1] == "O" && subGame1[2][2] == "O")
	{
		boardMain[0][1] = "O";
	}
	else if (subGame1[2][0] == "O" && subGame1[1][1] == "O" && subGame1[0][2] == "O")
	{
		boardMain[0][1] = "O";
	}

	//Board 3 
	if (subGame2[0][0] == "O" && subGame2[0][1] == "O" && subGame2[0][2] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[1][0] == "O" && subGame2[1][1] == "O" && subGame2[1][2] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[2][0] == "O" && subGame2[2][1] == "O" && subGame2[2][2] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[0][0] == "O" && subGame2[1][0] == "O" && subGame2[2][0] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[0][1] == "O" && subGame2[1][1] == "O" && subGame2[2][1] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[0][2] == "O" && subGame2[1][2] == "O" && subGame2[2][2] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[0][0] == "O" && subGame2[1][1] == "O" && subGame2[2][2] == "O")
	{
		boardMain[0][2] = "O";
	}
	else if (subGame2[2][0] == "O" && subGame2[1][1] == "O" && subGame2[0][2] == "O")
	{
		boardMain[0][2] = "O";
	}

	//Board 4 
	if (subGame3[0][0] == "O" && subGame3[0][1] == "O" && subGame3[0][2] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[1][0] == "O" && subGame3[1][1] == "O" && subGame3[1][2] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[2][0] == "O" && subGame3[2][1] == "O" && subGame3[2][2] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[0][0] == "O" && subGame3[1][0] == "O" && subGame3[2][0] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[0][1] == "O" && subGame3[1][1] == "O" && subGame3[2][1] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[0][2] == "O" && subGame3[1][2] == "O" && subGame3[2][2] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[0][0] == "O" && subGame3[1][1] == "O" &&subGame3[2][2] == "O")
	{
		boardMain[1][0] = "O";
	}
	else if (subGame3[2][0] == "O" && subGame3[1][1] == "O" && subGame3[0][2] == "O")
	{
		boardMain[1][0] = "O";
	}

	//Board 5 
	if (subGame4[0][0] == "O" && subGame4[0][1] == "O" && subGame4[0][2] == "O")
	{
		boardMain[1][1] = "O";
	}
	else if (subGame4[1][0] == "O" && subGame4[1][1] == "O" && subGame4[1][2] == "O")
	{
		boardMain[1][1] = "O";
	}
	else if (subGame4[2][0] == "O" && subGame4[2][1] == "O" && subGame4[2][2] == "O")
	{
		boardMain[1][1] = "O";
	}
	else if (subGame4[0][0] == "O" && subGame4[1][0] == "O" && subGame4[2][0] == "O")
	{
		boardMain[1][1] = "O";
	}
	else if (subGame4[0][1] == "O" && subGame4[1][1] == "O" && subGame4[2][1] == "O")
	{
		boardMain[1][1] = "O";
	}
	else if (subGame4[0][2] == "O" && subGame4[1][2] == "O" && subGame4[2][2] == "O")
	{
		boardMain[1][1] = "X";
	}
	else if (subGame4[0][0] == "O" && subGame4[1][1] == "O" &&subGame4[2][2] == "O")
	{
		boardMain[1][1] = "O";
	}
	else if (subGame4[2][0] == "O" && subGame4[1][1] == "O" && subGame4[0][2] == "O")
	{
		boardMain[1][1] = "O";
	}

	//Board 6 
	if (subGame5[0][0] == "O" && subGame5[0][1] == "O" && subGame5[0][2] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[1][0] == "O" && subGame5[1][1] == "O" && subGame5[1][2] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[2][0] == "O" && subGame5[2][1] == "O" && subGame5[2][2] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[0][0] == "O" && subGame5[1][0] == "O" && subGame5[2][0] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[0][1] == "O" && subGame5[1][1] == "O" && subGame5[2][1] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[0][2] == "O" && subGame5[1][2] == "O" && subGame5[2][2] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[0][0] == "O" && subGame5[1][1] == "O" && subGame5[2][2] == "O")
	{
		boardMain[1][2] = "O";
	}
	else if (subGame5[2][0] == "O" && subGame5[1][1] == "O" && subGame5[0][2] == "O")
	{
		boardMain[1][2] = "O";
	}

	//Board 7 
	if (subGame6[0][0] == "O" && subGame6[0][1] == "O" && subGame6[0][2] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[1][0] == "O" && subGame6[1][1] == "O" && subGame6[1][2] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[2][0] == "O" && subGame6[2][1] == "O" && subGame6[2][2] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[0][0] == "O" && subGame6[1][0] == "O" && subGame6[2][0] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[0][1] == "O" && subGame6[1][1] == "O" && subGame6[2][1] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[0][2] == "O" && subGame6[1][2] == "O" && subGame6[2][2] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[0][0] == "O" && subGame6[1][1] == "O" && subGame6[2][2] == "O")
	{
		boardMain[2][0] = "O";
	}
	else if (subGame6[2][0] == "O" && subGame6[1][1] == "O" && subGame6[0][2] == "O")
	{
		boardMain[2][0] = "O";
	}

	//Board 8 
	if (subGame7[0][0] == "O" && subGame7[0][1] == "O" && subGame7[0][2] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[1][0] == "O" && subGame7[1][1] == "O" && subGame7[1][2] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[2][0] == "O" && subGame7[2][1] == "O" && subGame7[2][2] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[0][0] == "O" && subGame7[1][0] == "O" && subGame7[2][0] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[0][1] == "O" && subGame7[1][1] == "O" && subGame7[2][1] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[0][2] == "O" && subGame7[1][2] == "O" && subGame7[2][2] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[0][0] == "O" && subGame7[1][1] == "O" && subGame7[2][2] == "O")
	{
		boardMain[2][1] = "O";
	}
	else if (subGame7[2][0] == "O" && subGame7[1][1] == "O" && subGame7[0][2] == "O")
	{
		boardMain[2][1] = "O";
	}

	//Board 9 
	if (subGame8[0][0] == "O" && subGame8[0][1] == "O" && subGame8[0][2] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[1][0] == "O" && subGame8[1][1] == "O" && subGame8[1][2] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[2][0] == "O" && subGame8[2][1] == "O" && subGame8[2][2] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[0][0] == "O" && subGame8[1][0] == "O" && subGame8[2][0] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[0][1] == "O" && subGame8[1][1] == "O" && subGame8[2][1] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[0][2] == "O" && subGame8[1][2] == "O" && subGame8[2][2] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[0][0] == "O" && subGame8[1][1] == "O" && subGame8[2][2] == "O")
	{
		boardMain[2][2] = "O";
	}
	else if (subGame8[2][0] == "O" && subGame8[1][1] == "O" && subGame8[0][2] == "O")
	{
		boardMain[2][2] = "O";
	}
}
void tieCheck(string boardMain[SIZE][SIZE], string subGame0[SIZE][SIZE], string subGame1[SIZE][SIZE], string subGame2[SIZE][SIZE],
	string subGame3[SIZE][SIZE], string subGame4[SIZE][SIZE], string subGame5[SIZE][SIZE], string subGame6[SIZE][SIZE], string subGame7[SIZE][SIZE], string subGame8[SIZE][SIZE])
{
	int checkTie[10] = { 0,0,0,0,0,0,0,0,0,0 };

	//Board 1 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame0[row][col] == "*")
			{
				checkTie[0] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[0][0] = "T";
	}
	//Board 2 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame1[row][col] == "*")
			{
				checkTie[1] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[0][1] = "T";
	}
	//Board 3 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame2[row][col] == "*")
			{
				checkTie[2] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[0][2] = "T";
	}
	//Board 4 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame3[row][col] == "*")
			{
				checkTie[3] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[1][0] = "T";
	}
	//Board 5 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame4[row][col] == "*")
			{
				checkTie[4] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[1][1] = "T";
	}
	//Board 6 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame5[row][col] == "*")
			{
				checkTie[5] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[1][2] = "T";
	}
	//Board 7 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame6[row][col] == "*")
			{
				checkTie[6] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[2][0] = "T";
	}
	//Board 8 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame7[row][col] == "*")
			{
				checkTie[7] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[2][1] = "T";
	}
	//Board 9 Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (subGame8[row][col] == "*")
			{
				checkTie[8] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[0] == 0)
	{
		boardMain[2][2] = "T";
	}
	//Main Board Check
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			if (boardMain[row][col] == "*")
			{
				checkTie[9] += 1; //If empty space, increment. Otherwise, tie state.
			}
		}
	}
	if (checkTie[9] == 0)
	{
		cout << "Main Board has ended in a tie" << endl;
		exit(1);
	}
}
void winMainCheck(string boardMain[SIZE][SIZE], int &pWin1, int &pWin2)
{
	//Tests for player one

	//verticals
	if (boardMain[0][0] == "X" && boardMain[0][1] == "X" && boardMain[0][2] == "X")
	{
		pWin1 = 1;
	}
	else if (boardMain[1][0] == "X" && boardMain[1][1] == "X" && boardMain[1][2] == "X")
	{
		pWin1 = 1;
	}
	else if (boardMain[2][0] == "X" && boardMain[2][1] == "X" && boardMain[2][2] == "X")
	{
		pWin1 = 1;
	}
	//horizontals
	else if (boardMain[0][0] == "X" && boardMain[1][0] == "X" && boardMain[2][0] == "X")
	{
		pWin1 = 1;
	}
	else if (boardMain[0][1] == "X" && boardMain[1][1] == "X" && boardMain[2][1] == "X")
	{
		pWin1 = 1;
	}
	else if (boardMain[0][2] == "X" && boardMain[1][2] == "X" && boardMain[2][2] == "X")
	{
		pWin1 = 1;
	}
	//diagonals
	else if (boardMain[0][0] == "X" && boardMain[1][1] == "X" && boardMain[2][2] == "X")
	{
		pWin1 = 1;
	}
	else if (boardMain[2][0] == "X" && boardMain[1][1] == "X" && boardMain[0][2] == "X")
	{
		pWin1 = 1;
	}
	//Tests for player two

	//verticals
	else if (boardMain[0][0] == "O" && boardMain[0][1] == "O" && boardMain[0][2] == "O")
	{
		pWin2 = 1;
	}
	else if (boardMain[1][0] == "O" && boardMain[1][1] == "O" && boardMain[1][2] == "O")
	{
		pWin2 = 1;
	}
	else if (boardMain[2][0] == "O" && boardMain[2][1] == "O" && boardMain[2][2] == "O")
	{
		pWin2 = 1;
	}
	//horizontals
	else if (boardMain[0][0] == "O" && boardMain[1][0] == "O" && boardMain[2][0] == "O")
	{
		pWin2 = 1;
	}
	else if (boardMain[0][1] == "O" && boardMain[1][1] == "O" && boardMain[2][1] == "O")
	{
		pWin2 = 1;
	}
	else if (boardMain[0][2] == "O" && boardMain[1][2] == "O" && boardMain[2][2] == "O")
	{
		pWin2 = 1;
	}
	//diagonals
	else if (boardMain[0][0] == "O" && boardMain[1][1] == "O" && boardMain[2][2] == "O")
	{
		pWin2 = 1;
	}
	else if (boardMain[2][0] == "O" && boardMain[1][1] == "O" && boardMain[0][2] == "O")
	{
		pWin2 = 1;
	}
}