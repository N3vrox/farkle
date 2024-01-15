#pragma region Preprocessor Directives
#include "Game.h"
#pragma endregion

#pragma region Namespace
using namespace std;
#pragma endregion

#pragma region Constructor/Destructor
Game::Game()
{
}

Game::~Game()
{
}
#pragma endregion

#pragma region Private Methods

/*
* Function Name: InitializePlayers
* Description: Initializes the players by setting the number of players and their names based on user input.
* Parameters: None
* Returns: None
*/
void Game::InitializePlayers() 
{
	numPlayers = 0;
	players.clear();

	while (true) 
	{
		cout << "Number of players: ";
		cin >> numPlayers;
		if (!ValidateNumPlayers(numPlayers)) 
		{
			continue;
		}
		else 
		{
			players.resize(numPlayers);
			// Setup player names
			system("cls");
			for (int i = 0; i < numPlayers; i++) 
			{
				string name;
				cout << "Enter player " << i + 1 << "'s name: ";
				cin >> name;
				if (!ValidateInput(name)) 
				{
					i--;
					continue;
				}
				else 
				{
					players[i].SetName(name);
				}
			}
			break;
		}
	}
}

/*
* Function Name: InitializeDice
* Description: Initializes the dice by setting their values to 0 and setting their held status to false.
* Parameters: None
* Returns: None
*/
void Game::InitializeDice() 
{
	dice.clear();
	dice.resize(NUM_DICE);
	for (int i = 0; i < NUM_DICE; i++) 
	{
		dice[i].SetValue(0);
		dice[i].SetHeld(false);
	}
}

/*
* Function Name: InitializeGame
* Description: Initializes the game by calling the InitializePlayers and InitializeDice methods.
* Parameters: None
* Returns: None
*/
void Game::InitializeGame() 
{
	InitializePlayers();
	InitializeDice();
}

/*
* Function Name: RollDice
* Description: Rolls the dice that are not held.
* Parameters: None
* Returns: None
*/
void Game::RollDice() 
{
	int j = 0;
	for (int i = 0; i < NUM_DICE; i++) 
	{
		if (dice[i].GetHeld()) 
		{
			continue;
		}
		else 
		{
			dice[i].Roll();
			handDice[j] = dice[i].GetValue();
			j++;
		}
	}
}

/*
* Function Name: DrawDice
* Description: Displays the current player's info and draws the visual representation of each die and shows whether each die is held or not
* Parameters: None
* Returns: None
*/
void Game::DrawDice() 
{
	system("cls");
	DisplayPlayerInfo();
	for (int i = 0; i < dice.size(); i++) 
	{
		if (!dice[i].GetHeld()) 
		{
			cout << "         ";
			continue;
		}
		else 
		{
			cout << "   HELD  ";
			continue;
		}
	}
	cout << endl;
	for (int i = 0; i < dice.size(); i++) 
	{
		cout << "  ------ ";
	}
	cout << endl;
	for (int i = 0; i < dice.size(); i++) 
	{
		cout << " |      |";
	}
	cout << endl;
	for (int i = 0; i < dice.size(); i++) 
	{
		cout << " |  " << dice[i].GetValue() << "   |";
	}
	cout << endl;
	for (int i = 0; i < dice.size(); i++) 
	{
		cout << " |      |";
	}
	cout << endl;
	for (int i = 0; i < dice.size(); i++) 
	{
		cout << "  ------ ";
	}
	cout << endl;
	for (int i = 0; i < dice.size(); i++) 
	{
		cout << " Dice #" << i + 1 << " ";
	}
	cout << endl << endl; 
}

/*
* Function Name: HoldDice
* Description: Allows the player to hold any dice they want to keep for the next roll.
* Parameters: None
* Returns: None
*/
void Game::HoldDice()
{
	int numHeld = 0;
	int numHand = handDice.size();
	bool isHeld = false;
	bool done = false;

	do 
	{
		cout << "\nWould you like to hold any dice? (y/n): ";
		char choice;
		cin >> choice;
		if (!ValidateInput(choice)) 
		{
			continue;
		}
		else 
		{
			switch (toupper(choice)) 
			{
			case 'Y':
				for (int i = 0; i <= NUM_DICE; i++) 
				{
					if (i < NUM_DICE) 
					{
						DrawDice();
						HoldDie(i);
	
						if (dice[i].GetHeldLastRoll())
						{
							continue;
						}
						else if (dice[i].GetHeld()) 
						{
							numHeld++;
							numHand--;
							continue;
						}
					}
					else 
					{
						DrawDice();
					}
				}
				done = true;
				break;
			case 'N':
				done = true;
				break;
			}
		}
	} while (!done);

	heldDice.resize(numHeld);
	handDice.resize(numHand);

	int heldIndex = 0;
	int handIndex = 0;
	for (int i = 0; i < NUM_DICE; i++) 
	{
		if (dice[i].GetHeldLastRoll())
		{
			continue;
		}
		else if (dice[i].GetHeld() && !dice[i].GetHeldLastRoll()) 
		{
			heldDice[heldIndex] = dice[i].GetValue();
			heldIndex++;
			dice[i].SetHeldLastRoll(true);
		}
		else 
		{
			handDice[handIndex] = dice[i].GetValue();
			handIndex++;
		}
	}
}

/*
* Function Name: HoldDie
* Description: Asks the player if they want to hold a specific die and sets the die's held status accordingly.
* Parameters: int i - the index of the die to be held
* Returns: None
*/
void Game::HoldDie(int i) 
{
	bool done = true;

	do 
	{
		if (dice[i].GetHeld()) 
		{
			break;
		}
		else 
		{
			cout << "\nHold dice #" << i + 1 << "? (y/n)" << endl;
			char choice;
			cin >> choice;
			if (!ValidateInput(choice)) 
			{
				continue;
			}
			else 
			{
				switch (toupper(choice)) 
				{
				case 'Y':
					if (ValidateHold(dice[i].GetValue()))
					{
						dice[i].SetHeld(true);
						done = true;
						break;
					}
					else
					{
						system("cls");
						DrawDice();
						cout << "\nYou cannot hold that die. It is not a scoring die." << endl;
						done = false;
						continue;
					}
				case 'N':
					dice[i].SetHeld(false);
					done = true;
					break;
				}
			}
		}
	} while (!done);
}

/*
* Function Name: CalculateScore
* Description: Calculates the player's score based on the dice they have held.
* Parameters: None
* Returns: int score - the player's score
*/
int Game::CalculateScore() 
{
	int score = 0;
	int numHeld = heldDice.size();
	int numHand = handDice.size();

	map<int, map<string, int>> diceMap;
	diceMap[1]["ONES"] = 0;
	diceMap[2]["TWOS"] = 0;
	diceMap[3]["THREES"] = 0;
	diceMap[4]["FOURS"] = 0;
	diceMap[5]["FIVES"] = 0;
	diceMap[6]["SIXES"] = 0;

	if (numHeld > 0)
	{
		for (int i = 0; i < numHeld; i++)
		{
			switch (heldDice[i])
			{
			case 1:
				diceMap[1]["ONES"]++;
				break;
			case 2:
				diceMap[2]["TWOS"]++;
				break;
			case 3:
				diceMap[3]["THREES"]++;
				break;
			case 4:
				diceMap[4]["FOURS"]++;
				break;
			case 5:
				diceMap[5]["FIVES"]++;
				break;
			case 6:
				diceMap[6]["SIXES"]++;
				break;
			default:
				cout << "Error: Invalid die value." << endl;
				break;
			}
		}

		score = ScoreDice(diceMap);
	}

	return score;
}

/*
* Function Name: ScoreDice
* Description: Totals the score of the dice held by the player, used by CalculateScore().
* Parameters: map<int, map<string, int>>& diceMap - a map of the dice held by the player
* Returns: int score - the player's score
*/
int Game::ScoreDice(map<int, map<string, int>>& diceMap)
{
	int score = 0;

	for (int i = 1; i <= diceMap.size(); i++)
	{
		for (auto& pair : diceMap[i])
		{
			while (pair.second > 0)
			{
				if ((pair.first == "ONES") && (pair.second >= 3))
				{
					cout << "3 ONES is 1000 points!" << endl;
					score += 1000;
					pair.second -= 3;
				}
				else if ((pair.first != "ONES") && (pair.second >= 3))
				{
					cout << "3 " << pair.first << " is " << (i * 100) << " points!" << endl;
					score += (i * 100);
					pair.second -= 3;
				}
				else if ((pair.first == "ONES") && (pair.second > 0))
				{
					cout << pair.second << " ONES is " << (pair.second * 100) << " points!" << endl;
					score += (pair.second * 100);
					pair.second -= pair.second;
				}
				else if ((pair.first == "FIVES") && (pair.second > 0))
				{
					cout << pair.second << " FIVES is " << (pair.second * 50) << " points!" << endl;
					score += (pair.second * 50);
					pair.second -= pair.second;
				}
			}
		}
	}

	return score;
}

/*
* Function Name: DisplayPlayerInfo
* Description: Displays the current player's name, round score, and total score.
* Parameters: None
* Returns: None
*/
void Game::DisplayPlayerInfo()
{
	int i = currentPlayer;
	cout << players[i].GetName() << "'s turn.\n" << endl;
	cout << "Current round score: " << players[i].GetRoundScore() << endl;
	cout << "Current total score: " << players[i].GetTotalScore() << "/" << WINNING_SCORE << endl << endl;
}

/*
* Function Name: PlayTurn
* Description: Plays a turn for the current player.
* Parameters: None
* Returns: None
*/
void Game::PlayTurn() 
{
	
	int score = 0;

	players[currentPlayer].ResetRoundScore();

	bool rollAgain = true;
	int p = currentPlayer;

	system("cls");

	DisplayPlayerInfo();
	
	ResetDice();

	do
	{
		RollDice();
		DrawDice();

		if (CheckForFarkle())
		{
			rollAgain = false;
			score = 0;
			players[p].ResetRoundScore();
			cout << "\nYou got a FARKLE! No points this turn." << endl;
			break;
		}

		HoldDice();

		score += CalculateScore();
		players[p].SetRoundScore(score);

		for (int i = 0; i < NUM_DICE; i++)
		{
			if (dice[i].GetHeld())
			{
				dice[i].SetHeldLastRoll(true);
			}
		}

		 system("cls");

		 DrawDice();

		if (handDice.size() == 0)
		{
			cout << "All dice held. The dice will be re-rolled." << endl;
			ResetDice();
			rollAgain = true;
			
			cout << "\nPress ENTER to continue..." << endl;
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "\nWould you like to roll again? (y/n): ";
			char choice;
			cin >> choice;

			if (!ValidateInput(choice)) 
			{
				continue;
			}
			else {
				switch (toupper(choice)) 
				{
				case 'Y':
					rollAgain = true;
					break;
				case 'N':
					rollAgain = false;
					players[p].SetTotalScore(players[p].GetTotalScore() + players[p].GetRoundScore());
					players[p].ResetRoundScore();
					DrawDice();
					break;
				}
			}
		}
	} while (rollAgain);

	if (winner == -1)
	{
		CheckForWinner();
	}
}

/*
* Function Name: PlayRound
* Description: Plays a round with each player getting a turn.
* Parameters: None
* Returns: None
*/
void Game::PlayRound() 
{
	for (int i = 0; i < numPlayers; i++) 
	{
		currentPlayer = i;
		int nextPlayer;

		if (i == numPlayers - 1) 
		{
			nextPlayer = 0;
		}
		else 
		{
			nextPlayer = i + 1;
		}

		PlayTurn();
		cout << "\n" << players[nextPlayer].GetName() << "'s turn is up next." << endl
			 << "\nPress ENTER to continue..." << endl;
		cin.ignore();
		cin.get();
	}
}

/*
* Function Name: LastRound
* Description: Plays the last round of the game.
* Parameters: None
* Returns: None
*/
void Game::LastRound()
{
	if (winner > -1)
	{
		for (int i = 0; i < numPlayers; i++)
		{
			if (i == winner)
			{
				continue;
			}
			else
			{
				for (int i = 0; i < numPlayers; i++)
				{
					currentPlayer = i;
					PlayTurn();
					cout << "\nPress ENTER to continue: ";
					cin.ignore();
					cin.get();
				}
			}
		}
	}
}

/*
* Function Name: CheckForWinner
* Description: Checks to see if the current player has a winning score
* Parameters: None
* Returns: Bool - true if the current player has a winning score, false if not
*/
bool Game::CheckForWinner()
{
	if (players[currentPlayer].GetTotalScore() >= WINNING_SCORE)
	{
		winner = currentPlayer;
		return true;
	}
	else 
	{
		return false;
	}
}

/*
* Function Name: EndGame
* Description: Displays the winner of the game.
* Parameters: None
* Returns: None
*/
void Game::EndGame()
{
	system("cls");
	cout << "********** CONGRATULATIONS! **********" << endl;
	cout << "\n" << players[winner].GetName() << " wins!" << endl;
	cout << "Total score: " << players[winner].GetTotalScore() << endl;
}

/*
* Function Name: ResetDice
* Description: Resets all the dice to be unheld.
* Parameters: None
* Returns: None
*/
void Game::ResetDice() 
{
	for (int i = 0; i < dice.size(); i++) 
	{
		dice[i].SetHeld(false);
		dice[i].SetHeldLastRoll(false);
		handDice.resize(NUM_DICE);
		heldDice.resize(0);
	}
}

/*
* Function Name: CheckForFarkle
* Description: Checks if the player's hand is a farkle (no points dice in hand).
* Parameters: nNone
* Returns: bool
*/
bool Game::CheckForFarkle()
{
	bool farkle = false;

	int ones = 0,
		twos = 0,
		threes = 0,
		fours = 0,
		fives = 0,
		sixes = 0;

	for (int i = 0; i < handDice.size(); i++)
	{
		switch (handDice[i])
		{
		case 1:
			ones++;
			break;
		case 2:
			twos++;
			break;
		case 3:
			threes++;
			break;
		case 4:
			fours++;
			break;
		case 5:
			fives++;
			break;
		case 6:
			sixes++;
			break;
		default:
			cout << "[Error]: Invalid die value." << endl;
			break;
		}
	}

	if ((ones == 0) && (twos < 3) && (threes < 3) && (fours < 3) && (fives == 0) && (sixes < 3))
	{
		farkle = true;
	}
	else
	{
		farkle = false;
	}

	return farkle;
}

/*
* Function Name: ValidateHold
* Description: Checks if the die the player wants to hold is a valid scoring die
* Parameters: int i
* Returns: bool
*/
bool Game::ValidateHold(int i)
{
	bool valid = true;
	int ones = 0,
		twos = 0,
		threes = 0,
		fours = 0,
		fives = 0,
		sixes = 0;

	for (int j = 0; j < handDice.size(); j++)
	{
		switch (handDice[j])
		{
		case 1:
			ones++;
			break;
		case 2:
			twos++;
			break;
		case 3:
			threes++;
			break;
		case 4:
			fours++;
			break;
		case 5:
			fives++;
			break;
		case 6:
			sixes++;
			break;
		default:
			cout << "[Error]: Invalid die value." << endl;
			break;
		}
	}

	if ((i == 2) && (twos != 0 && twos != 3 && twos != 6))
	{
		valid = false;
	}
	else if ((i == 3) && (threes != 0 && threes != 3 && threes != 6))
	{
		valid = false;
	}
	else if ((i == 4) && (fours != 0 && fours != 3 && fours != 6))
	{
		valid = false;
	}
	else if ((i == 6) && (sixes != 0 && sixes != 3 && sixes != 6))
	{
		valid = false;
	}
	else
	{
		valid = true;
	}

	return valid;
}

/*
* Function Name: ValidateInput
* Description: Validates the user's input.
* Parameters: string input
* Returns: bool
*/
bool Game::ValidateInput(string input) 
{
	// If input is empty then return false
	if (input.length() == 0) 
	{
		return false;
	}
	// If input is not empty then check each character to see if it is a number
	else 
	{
		for (int i = 0; i < input.length(); i++) 
		{
			// If the character is a number then return false
			if (isdigit(input[i])) 
			{
				return false;
			}
		}
	}
	return true;
}

/*
* Function Name: ValidateInput
* Description: Validates the user's input.
* Parameters: int input
* Returns: bool
*/
bool Game::ValidateInput(int input) 
{
	if (!cin) 
	{
		cin.clear();
		cin.ignore();
		return false;
	}
	else if (input < 0) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

/*
* Function Name: ValidateInput
* Description: Validates the user's input.
* Parameters: char input
* Returns: bool
*/
bool Game::ValidateInput(char input) 
{
	// Convert input to uppercase
	char upperInput = toupper(input);

	// If the input is not a letter then return false
	if (!cin) 
	{
		cin.clear();
		cin.ignore();
		cout << "\nInvalid input. Please enter either 'y' or 'n'." << endl;
		return false;
	}
	
	// If the input is not 'Y' or 'N' then return false
	else if (upperInput != 'Y' && upperInput != 'N') 
	{
		cout << "\nInvalid input. Please enter either 'y' or 'n'." << endl;
		return false;
	}

	// If the input is either 'Y' or 'N' then return true
	else 
	{
		return true;
	}
}

/*
* Function Name: ValidateNumPlayers
* Description: Validates the number of players the user entered.
* Parameters: int input
* Returns: bool
*/
bool Game::ValidateNumPlayers(int input) 
{
	// If the input is not a number then return false
	if (!cin) 
	{
		cin.clear();
		cin.ignore();
		system("cls");
		cout << "Invalid input. Please enter a number." << endl;
		return false;
	}
	// If the input is less than 1 then return false
	else if (input < 1) 
	{
		system("cls");
		cout << "Invalid input. Please enter a number greater than 0." << endl;
		return false;
	}
	// If the input is a number greater than 0 then return true
	else 
	{
		return true;
	}
}
#pragma endregion



#pragma region Public Methods
/*
* Function Name: Loop
* Description: Main game loop that initializes the game menu and game
* Parameters: None
* Returns: None
*/
void Game::Loop() 
{
	Menu menu;

	bool exit = false;

	// Main Loop
	while (!exit) 
	{
		// Menu Loop
		bool inGame = menu.Loop();

		// Make sure players vector is empty
		if (players.size() != 0) 
		{
			players.clear();
		}

		// Make sure dice vector is empty
		if (dice.size() != 0) 
		{
			dice.clear();
		}

		// Game Loop
		while (inGame) 
		{
			// Set up the game and players
			InitializeGame();

			// Play rounds until a player reaches 10,000 points
			do 
			{
				PlayRound();
			} while (winner == -1);

			// If a player reaches 10,000 points, play one last round
			if (winner > -1) 
			{
				LastRound();
			}

			// Display the winner
			EndGame();

			cout << "Press any key to return to the main menu: ";
			cin.ignore();
			cin.get();
			inGame = false;
			system("cls");
		}
	}
}
#pragma endregion
