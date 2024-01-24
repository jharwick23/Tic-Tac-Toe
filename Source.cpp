#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

struct WinningPosition {
	int A1, A2, B1, B2;
};

void runGame();

void initializeGameBoard(string gameBoard[ROWS][COLS]);

void printCurrentBoard(string gameBoard[ROWS][COLS]);

void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);

void getComputerInput(bool xTurn, string gameBoard[ROWS][COLS], int turn);

bool checkWinningMove(int& row, int& col, int& rowTwo, int& colTwo, string gameBoard[ROWS][COLS]);

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);

string getWinner(string gameBoard[ROWS][COLS]);

bool isBoardFull(string gameBoard[ROWS][COLS]);

int main() {
	runGame();

	return 0;
}

//run the game
void runGame() {
	string winner = "";
	bool xTurn = true; //start with X
	string gameBoard[ROWS][COLS];
	int turn = 0;

	initializeGameBoard(gameBoard);

	printCurrentBoard(gameBoard);

	while (winner == "") {
		if (xTurn) {
			cout << "X turn" << endl;
			getUserInput(xTurn, gameBoard);
		}
		else {
			cout << "O turn" << endl;
			getComputerInput(xTurn, gameBoard, turn);
		}
		cout << endl;
		printCurrentBoard(gameBoard);
		winner = getWinner(gameBoard);
		xTurn = !xTurn;

		if (winner == "" && isBoardFull(gameBoard)) {
			winner = "C";
			break;
		}
	}

	cout << endl;
	if (winner == "C") {
		cout << "Cat's Game!" << endl;
	}
	cout << "The winner is " << winner << endl;
	cout << endl;
}
//initialize the game board
void initializeGameBoard(string gameBoard[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			gameBoard[i][j] = " ";
		}
	}
}
//print board
void printCurrentBoard(string gameBoard[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << gameBoard[i][j];
			if (j < 2) { //print the columns
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2) { //prints the rows
			cout << "- - - - -" << endl;
		}
	}

	cout << endl;
}
//recieve user input 
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]) {
	int row = 0, col = 0;

	cout << "Enter the row and column you would like to occupy: " << endl;
	cin >> row >> col;

	// Validate row input
	while (row < 0 || row > 2) {
		cout << "Please enter the row from 0 - 2: " << endl;
		cin >> row;
	}

	// Validate col input
	while (col < 0 || col > 2) {
		cout << "Please enter the col from 0 - 2: " << endl;
		cin >> col;
	}

	// Check if the cell is already occupied
	while (cellAlreadyOccupied(row, col, gameBoard)) {
		cout << "That cell is already occupied. Please enter the row and column again: " << endl;
		cin >> row >> col;
	}
	gameBoard[row][col] = "X";

}
//receive computer input
void getComputerInput(bool xTurn, string gameBoard[ROWS][COLS], int turn) {
	int row = 1, col = 1;
	int rowTwo = 0, colTwo = 0;

	turn++;

	if (turn == 1) { //On the computer's first turn
		if (!cellAlreadyOccupied(1, 1, gameBoard)) {
			gameBoard[row][col] = "O";
			return;
		}
		else {
			if (!cellAlreadyOccupied(0, 0, gameBoard)) {
				row = 0;
				col = 0;
			}
			else if (!cellAlreadyOccupied(0, 2, gameBoard)) {
				row = 0;
				col = 2;
			}
			else if (!cellAlreadyOccupied(2, 2, gameBoard)) {
				row = 2;
				col = 2;
			}
			else if (!cellAlreadyOccupied(2, 0, gameBoard)) {
				row = 2;
				col = 0;
			}
			gameBoard[row][col] = "O";
			return;
		}
	}

	if (checkWinningMove(row, col, rowTwo, colTwo, gameBoard)) {

	}

	gameBoard[row][col] = "O";
}
//Computer checks if there is a winning move to be made
bool checkWinningMove(int& row, int& col, int& rowTwo, int& colTwo, string gameBoard[ROWS][COLS]) {
	if ((gameBoard[0][0] == "O" && gameBoard[1][0] == "O") || (gameBoard[1][0] == "O" && gameBoard[2][0] == "O") || (gameBoard[0][1] == "O" && gameBoard[1][1] == "O") ||
		(gameBoard[1][1] == "O" && gameBoard[2][1] == "O") || (gameBoard[0][2] == "O" && gameBoard[1][2] == "O") || (gameBoard[1][2] == "O" && gameBoard[2][2] == "O") ||
		(gameBoard[0][0] == "O" && gameBoard[0][1] == "O") || (gameBoard[0][1] == "O" && gameBoard[0][2] == "O") || (gameBoard[1][0] == "O" && gameBoard[1][1] == "O") ||
		(gameBoard[1][1] == "O" && gameBoard[1][2] == "O") || (gameBoard[2][0] == "O" && gameBoard[2][1] == "O") || (gameBoard[2][1] == "O" && gameBoard[2][2] == "O") ||
		(gameBoard[0][0] == "O" && gameBoard[1][1] == "O") || (gameBoard[1][1] == "O" && gameBoard[2][2] == "O") || (gameBoard[0][2] == "O" && gameBoard[1][1] == "O") ||
		(gameBoard[1][1] == "O" && gameBoard[2][0] == "O")) {

		for (int i = 0; i < 3; i++) {
			if ()
			for (int j = 0; j < 3; j++) {
				
			}
		}

		return true;
	}
	return false;
}
//Tells user if the current cell is already occupied
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]) {
	return gameBoard[row][col] != " ";
}
//Tells user the winner
string getWinner(string gameBoard[ROWS][COLS]) {
	if (gameBoard[0][0] == "O" && gameBoard[1][0] == "O" && gameBoard[2][0] == "O") {
		return "O";
	}
	else if (gameBoard[0][1] == "O" && gameBoard[1][1] == "O" && gameBoard[2][1] == "O") {
		return "O";
	}
	else if (gameBoard[0][2] == "O" && gameBoard[1][2] == "O" && gameBoard[2][2] == "O") {
		return "O";
	}
	else if (gameBoard[0][0] == "O" && gameBoard[0][1] == "O" && gameBoard[0][2] == "O") {
		return "O";
	}
	else if (gameBoard[1][0] == "O" && gameBoard[1][1] == "O" && gameBoard[1][2] == "O") {
		return "O";
	}
	else if (gameBoard[2][0] == "O" && gameBoard[2][1] == "O" && gameBoard[2][2] == "O") {
		return "O";
	}
	else if (gameBoard[0][0] == "O" && gameBoard[1][1] == "O" && gameBoard[2][2] == "O") {
		return "O";
	}
	else if (gameBoard[0][2] == "O" && gameBoard[1][1] == "O" && gameBoard[2][0] == "O") {
		return "O";
	}

	if (gameBoard[0][0] == "X" && gameBoard[1][0] == "X" && gameBoard[2][0] == "X") {
		return "X";
	}
	else if (gameBoard[0][1] == "X" && gameBoard[1][1] == "X" && gameBoard[2][1] == "X") {
		return "X";
	}
	else if (gameBoard[0][2] == "X" && gameBoard[1][2] == "X" && gameBoard[2][2] == "X") {
		return "X";
	}
	else if (gameBoard[0][0] == "X" && gameBoard[0][1] == "X" && gameBoard[0][2] == "X") {
		return "X";
	}
	else if (gameBoard[1][0] == "X" && gameBoard[1][1] == "X" && gameBoard[1][2] == "X") {
		return "X";
	}
	else if (gameBoard[2][0] == "X" && gameBoard[2][1] == "X" && gameBoard[2][2] == "X") {
		return "X";
	}
	else if (gameBoard[0][0] == "X" && gameBoard[1][1] == "X" && gameBoard[2][2] == "X") {
		return "X";
	}
	else if (gameBoard[0][2] == "X" && gameBoard[1][1] == "X" && gameBoard[2][0] == "X") {
		return "X";
	}
	return "";
}
//Tells user if the board is full
bool isBoardFull(string gameBoard[ROWS][COLS]) {
	int count = 0;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			if (gameBoard[i][j] != " ") {
				count++;
			}
		}
	}

	if (count == 9) {
		return true;
	}

	return false;
}
