/*******************************************************************************
** This is the Menu class function specification (header) file. The Menu is
** modular, allowing multiple options to be added from the main file.
*******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Menu {
private:
	vector<string> menuOptions;
public:
	Menu();
	bool validChoice(int);
	void addOption(string);
	void printMenu();
};

#endif