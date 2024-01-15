#include "Menu.h"

using namespace std;

/*
* Function Name: Loop
* Description: Menu loop that displays the main menu and handles user input
* Parameters: None
* Returns: bool - true if new game, false if exit
*/
bool Menu::Loop()
{
	bool exit = false;
	bool newGame = false;

	do
	{
		DisplayMainMenu();
		int choice = GetInput();

		if (!cin) 
		{
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "Invalid input. Please try again.\n" << endl;
			continue;
		}
		else if (choice < 0 || choice > 3) 
		{
			system("cls");
			cout << "Invalid input. Please try again.\n" << endl;
			continue;
		}
		else 
		{
			switch (choice) 
			{
			case 1:
				// Play
				newGame = true;
				system("cls");
				return newGame;
			case 2:
				// Rules
				DisplayRules();
				system("cls");
				break;
			case 3:
				// Credits
				DisplayCredits();
				system("cls");
				break;
			case 0:
				// Exit
				bool exitMenu = true;
				system("cls");
				do 
				{
					cout << "Are you sure you want to exit? (y/n): ";
					char input;
					cin >> input;
					switch (toupper(input)) 
					{
					case 'Y':
						Exit();
						exit = true;
						exitMenu = false;
						break;
					case 'N':
						exitMenu = false;
						system("cls");
						break;
					default:
						system("cls");
						cout << "Invalid input. Please try again.\n" << endl;
						continue;
					}
				} while (exitMenu);
			}
		}
	} while (!newGame);
}

/*
* Function Name: DisplayMainMenu
* Description: Displays the main menu
* Parameters: None
* Returns: None
*/
void Menu::DisplayMainMenu()
{
	cout << "Welcome to Farkle!\n" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. Rules" << endl;
	cout << "3. Credits" << endl;
	cout << "0. Exit" << endl;
	cout << "\nPlease enter your choice: ";
}

/*
* Function Name: DisplayRules
* Description: Displays the rules from a text file
* Parameters: None
* Returns: None
*/
void Menu::DisplayRules()
{
	ifstream rulesFile;
	string line;
	rulesFile.open("Rules.txt");
	if (rulesFile.is_open())
	{
		system("cls");
		while (getline(rulesFile, line))
		{
			cout << line << endl;
		}
		rulesFile.close();

		ReturnFromFile();
	}
	else
	{
		system("cls");
		cout << "Unable to open file" << endl;

		ReturnFromFile();
	}
}

/*
* Function Name: DisplayCredits
* Description: Displays the credits
* Parameters: None
* Returns: None
*/
void Menu::DisplayCredits()
{
	ifstream creditsFile;
	string line;
	creditsFile.open("Credits.txt");
	if (creditsFile.is_open())
	{
		system("cls");
		while (getline(creditsFile, line))
		{
			cout << line << endl;
		}
		creditsFile.close();

		ReturnFromFile();
	}
	else
	{
		system("cls");
		cout << "Unable to open file" << endl;

		ReturnFromFile();
	}
}

/*
* Function Name: ReturnFromFile
* Description: Returns to the main menu after displaying a file
* Parameters: None
* Returns: None
*/
void Menu::ReturnFromFile() 
{
	cout << "\nPress ENTER to return to the main menu... ";
	cin.ignore();
	cin.get();
}

/*
* Function Name: Exit
* Description: Exits the program
* Parameters: None
* Returns: None
*/
void Menu::Exit()
{
	system("cls");
	cout << "Thank you for playing!\nGoodbye!" << endl;
	exit(1);
}

/*
* Function Name: GetInput
* Description: Gets menu input from the user
* Parameters: None
* Returns: int
*/
int Menu::GetInput() 
{
	int input;
	cin >> input;
	return input;
}

/*
* Function Name: ValidateInput
* Description: Validates user menu input
* Parameters: int input
* Returns: bool
*/
bool Menu::ValidateInput(int input) 
{
	if (!cin)
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Invalid input. Please try again.\n" << endl;
		return false;
	}
	else if (input < 0 || input > 3)
	{
		system("cls");
		cout << "Invalid input. Please try again.\n" << endl;
		return false;
	}
	else
	{
		return true;
	}
}