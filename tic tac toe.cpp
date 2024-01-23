#include <iostream>
#include <string>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

//run the game
void runGame();

//initialize the game board
void initializeGameBoard(string gameBoard[ROWS][COLS]);

//print board
void printCurrentBoard(string gameBoard[ROWS][COLS]);

//recieve user input 
void getUserInput(bool xTurn, string gameBoard[ROWS][COLS]);

//Tells user if the current cell is already occupied
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]);

//Tells user the winner
string getWinner(string gameBoard[ROWS][COLS]);

//Tells user if the board is full
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

	initializeGameBoard(gameBoard);

	printCurrentBoard(gameBoard);

	while (winner == "") {
		if (xTurn) {
			cout << "X turn" << endl;
		}
		else {
			cout << "O turn" << endl;
		}
		getUserInput(xTurn, gameBoard);
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
	int row = -1, col = -1;

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

	// Set the cell value based on the player's turn
	if (xTurn) {
		gameBoard[row][col] = "X";
	}
	else {
		gameBoard[row][col] = "O";
	}
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