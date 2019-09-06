/*******************************************************************************
** This is the Ant class function implementation file. Contained within are the
** constructor, destructor, Ant movement functions, and a function to display
** the board with each step.
**
** The Ant follows these rules:
** - If the Ant is on a white space, turn right 90 degrees and change the space
**   to black.
** - If the Ant is on a black space, turn left 90 degrees and change the space
**   to white.
** - The Ant then moves to the next step and continue moving forward.
*******************************************************************************/

#include "Ant.hpp"

/*
 * Ant constructor.
 *
 * @param int  Number of rows on the board.
 * @param int  Number of columns on the board.
 * @param int  The maximum number of steps to take.
 * @param int  The Ant's current row.
 * @param int  The Ant's current column.
*/
Ant::Ant(int boardRows, int boardColumns, int maxSteps,
	     int currentRow, int currentCol) {
	this->boardRows = boardRows;
	this->boardColumns = boardColumns;
	this->maxSteps = maxSteps;
	this->currentRow = currentRow;
	this->currentCol = currentCol;

	currentSteps = 0;
	locationColor = WHITE_SPACE;
	antDirection = NORTH;

	// Allocate array for board
	antBoard = new char*[boardRows];
	for (int i = 0; i < boardRows; ++i) {
		antBoard[i] = new char[boardColumns];
	}
	
	// Fill 2D array with white spaces
	for (int i = 0; i < boardRows; ++i) {
		for (int j = 0; j < boardColumns; ++j) {
			antBoard[i][j] = WHITE_SPACE;
		}
	}

	// Filled by either the user or by random
	antBoard[currentRow][currentCol] = ANT_SPACE;
}

/*
 * Ant deconstructor deallocates the memory taken by the array
*/
Ant::~Ant() {
	for (int i = 0; i < boardRows; ++i) {
		delete[] antBoard[i];
	}

	delete[] antBoard;
}

/*
 * Updates the Ant's direction to NORTH.
*/
void Ant::moveNorth() {
	antDirection = NORTH;

	// If Ant is in the top row, it will wrap around the board
	if (currentRow == 0) {
		locationColor = antBoard[boardRows - 1][currentCol];
		antBoard[boardRows-1][currentCol] = ANT_SPACE;
		currentRow = boardRows-1;
	}
	else {
		locationColor = antBoard[currentRow-1][currentCol];
		antBoard[currentRow-1][currentCol] = ANT_SPACE;
		currentRow--;
	}
}

/*
 * Updates the Ant's direction to SOUTH.
*/
void Ant::moveSouth() {
	antDirection = SOUTH;
	// If Ant is in the bottom row, it will wrap around the board
	if (currentRow+1 >= boardRows) {
		locationColor = antBoard[0][currentCol];
		antBoard[0][currentCol] = ANT_SPACE;
		currentRow = 0;
	}
	else {
		locationColor = antBoard[currentRow+1][currentCol];
		antBoard[currentRow+1][currentCol] = ANT_SPACE;
		currentRow++;
	}
}

/*
 * Updates the Ant's direction to EAST.
*/
void Ant::moveEast() {
	antDirection = EAST;

	/* If Ant is in the furthest right column, it will wrap around
	   the board */
	if (currentCol+1 >= boardColumns) {
		locationColor = antBoard[currentRow][0];
		antBoard[currentRow][0] = ANT_SPACE;
		currentCol = 0;
	}
	else {
		locationColor = antBoard[currentRow][currentCol+1];
		antBoard[currentRow][currentCol+1] = ANT_SPACE;
		currentCol++;
	}
}

/*
 * Updates the Ant's direction to WEST.
*/
void Ant::moveWest() {
	antDirection = WEST;

	// If Ant is in the first column, it will wrap around the board
	if (currentCol == 0) {
		locationColor = antBoard[currentRow][boardColumns - 1];
		antBoard[currentRow][boardColumns - 1] = ANT_SPACE;
		currentCol = boardColumns - 1;
	}
	else {
		locationColor = antBoard[currentRow][currentCol - 1];
		antBoard[currentRow][currentCol - 1] = ANT_SPACE;
		currentCol--;
	}
}

/*
 * Updates the Ant's position based on its direction (determined by
 * the above functions).
 *
 * @return  Returns true if currentSteps hasn't reached maxSteps.
*/
bool Ant::takeStep() {
	// Returns false once the maximum number of steps is reached
	if (currentSteps >= maxSteps) {
		return false;
	}

	cout << "Step " << currentSteps+1 << ":" << endl;

	/* Checks which direction the Ant is facing, then determines what
	   color square the Ant is on. This sets the next color and move
	   function. */
	switch (antDirection) {

	case NORTH:
		if (locationColor == WHITE_SPACE) {
			antBoard[currentRow][currentCol] = BLACK_SPACE;
			moveEast();
		}
		else {
			antBoard[currentRow][currentCol] = WHITE_SPACE;
			moveWest();
		}
		break;

	case SOUTH:
		if (locationColor == WHITE_SPACE) {
			antBoard[currentRow][currentCol] = BLACK_SPACE;
			moveWest();
		}
		else {
			antBoard[currentRow][currentCol] = WHITE_SPACE;
			moveEast();
		}
		break;

	case EAST:
		if (locationColor == WHITE_SPACE) {
			antBoard[currentRow][currentCol] = BLACK_SPACE;
			moveSouth();
		}
		else {
			antBoard[currentRow][currentCol] = WHITE_SPACE;
			moveNorth();
		}
		break;

	case WEST:
		if (locationColor == WHITE_SPACE) {
			antBoard[currentRow][currentCol] = BLACK_SPACE;
			moveNorth();
		}
		else {
			antBoard[currentRow][currentCol] = WHITE_SPACE;
			moveSouth();
		}
		break;

	default:
		break;
	}

	// Increment the number of steps, then return true
	currentSteps++;
	return true;
}

/*
 * Displays the board to the terminal.
*/
void Ant::displayBoard() {
	for (int i = 0; i < boardRows; ++i) {
		for (int j = 0; j < boardColumns; ++j) {
			cout << "|" << antBoard[i][j];
		}

		cout << "|\n";
	}
}