/*******************************************************************************
** This is the langtonsAnt main file. This program simulates Langton's Ant. The
** user sets the size of the board and either chooses the Ant starting point or
** sets it to random. Contained within this file are functions meant to validate
** int input and to start the simulation based on a boolean random position
** start.
*******************************************************************************/

#include "Ant.hpp"
#include "Menu.hpp"

#include <iostream>
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()
#include <ios>      // for <streamsize> 
#include <limits>    // for numeric_limits

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

//Function prototypes
int getValidInt(string prompt);
void startSim(bool randomStart);

int main() {
	srand(time(0));

	int userMenuChoice;
	bool programExit = false;

	// Create a menu and add options
	Menu antMenu;
	antMenu.addOption("Langton's Ant simulation");
	antMenu.addOption("Langton's Ant simulation with random starting location");
	antMenu.addOption("Quit");

	// Loop program until the user terminates
	while (!programExit) {
		antMenu.printMenu();

		userMenuChoice = getValidInt("Select an option: ");

		// Input validation
		while (!antMenu.validChoice(userMenuChoice)) {
			userMenuChoice =
            getValidInt("Please select a valid option: ");
		}

		// Start simulation based on user choice
		switch (userMenuChoice) {
		case 1:
			// Regular start
			startSim(false);
			break;
		case 2:
			// Start with random location
			startSim(true);
			break;
		case 3:
			// Exit program
			programExit = true;
			break;
		default:
			break;
		}
	}

	return 0;
}

/*
 * Function used to validate int values entered by user.
 *
 * @param string  Given prompt for different validations.
*/
int getValidInt(string prompt) {
    int userInt;
    cout << prompt;
    cin >> userInt;

    // Input validation
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter a valid option.\n";
        cout << prompt;
        cin >> userInt;
    }
    
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    return userInt;
}

/*
 * Starts simulation by determining size of the board, number of
 * steps, and starting position of the Ant.
 *
 * @param bool  Indicates if starting position is random.
*/
void startSim(bool randomStart) {
	int boardRows, boardColumns,
		startRow, startCol,
		antSteps;

	// Prompt for number of rows
	boardRows = getValidInt("Number of rows: ");
	while (boardRows <= 0) {
		boardRows = getValidInt("Number must be greater than 0: ");
	}

	// Prompt for number of columns
	boardColumns = getValidInt("Number of columns: ");
	while (boardColumns <= 0) {
		boardColumns = getValidInt("Number must be greater than 0: ");
	}

	// Prompt for number of steps
	antSteps = getValidInt("Number of steps for the ant to take: ");
	while (antSteps < 0) {
		antSteps =
        getValidInt("Number must be greater than or equal to 0: ");
	}

	// Sets random starting position or sets user input
	if (randomStart) {
		startRow = rand() % boardRows;
		startCol = rand() % boardColumns;
	}
	else {
		startRow = getValidInt("Starting row for Ant: ");
		while (startRow >= boardRows || startRow < 0) {
			startRow =
            getValidInt("Out of bounds! Please try again: ");
		}

		startCol = getValidInt("Starting column for Ant: ");
		while (startCol >= boardColumns || startCol < 0) {
			startCol =
            getValidInt("Out of bounds! Please try again: ");
		}
	}

	// Create an Ant object with the ints provided
	Ant userAnt(boardRows, boardColumns, antSteps,
		        startRow, startCol);

	// Displays board with Ant's starting position
	cout << "\nStarting position:" << endl;
	userAnt.displayBoard();
	cout << endl;

	/* While the max step count has not been reached, the Ant takes
	another step and the board is printed to the terminal. */
	while (userAnt.takeStep()) {
		userAnt.displayBoard();
		cout << endl;
	}
}