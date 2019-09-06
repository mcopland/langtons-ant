/*******************************************************************************
** This is the Ant class function specification (header) file. Contained within
** are the constructor, destructor, Ant movement functions, and a function to
** display the board with each step.
**
** The Ant follows these rules:
** - If the Ant is on a white space, turn right 90 degrees and change the space
**   to black.
** - If the Ant is on a black space, turn left 90 degrees and change the space
**   to white.
** - The Ant then moves to the next step and continue moving forward.
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>

using std::cout;
using std::endl;

class Ant {
private:
	char** antBoard;
	char locationColor;
	const char WHITE_SPACE = ' ';
	const char BLACK_SPACE = '#';
	const char ANT_SPACE = '*';

	// Keeps track of Ant's current facing direction
	enum Direction { NORTH,	EAST, SOUTH, WEST };
	enum Direction antDirection;

	int boardRows, boardColumns;
	int currentRow, currentCol;
	int currentSteps, maxSteps;

public:
	Ant(int boardRows, int boardColumns, int maxSteps,
		int currentRow, int currentCol);
	~Ant();

	void moveNorth();
	void moveSouth();
	void moveEast();
	void moveWest();
	bool takeStep();
	void displayBoard();
};

#endif