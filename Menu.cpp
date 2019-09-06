/*******************************************************************************
** This is the Menu class function implementation file. The Menu is modular,
** allowing multiple options to be added from the main file.
*******************************************************************************/

#include "Menu.hpp"

/*
 * Default Menu constructor. Options are added in main.
*/
Menu::Menu() {
}

/*
 * Determines if the user's choice is within the Menu's range.
 *
 * @param int  User's input for Menu choice.
*/
bool Menu::validChoice(int choice) {
	if (choice < 1 || choice > menuOptions.size()) {
		return false;
	}
	
	return true;
}

/*
 * Add options to the created Menu.
 *
 * @param string  A string that contains the text following the menu
 *                choice number.
*/
void Menu::addOption(string prompt) {
	menuOptions.push_back(prompt);
}

/*
 * Prints the Menu.
*/
void Menu::printMenu() {
	for (int i = 0; i < menuOptions.size(); ++i) {
		cout << i+1 << ". " << menuOptions[i] << endl;
	}

	cout << endl;
}