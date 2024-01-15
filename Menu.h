#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

class Menu
{
public:
	bool Loop();
	static void DisplayMainMenu();
	static void DisplayPausedMenu();
	static void DisplayRules();
	static void DisplayCredits();
	static void ReturnFromFile();
	void Exit();
	int GetInput();
	bool ValidateInput(int input);
};

