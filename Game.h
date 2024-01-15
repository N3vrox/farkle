#pragma once

#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<map>

#include "Player.h"
#include "Menu.h"
#include "Dice.h"

class Game
{
private:

	std::vector<Player> players;
	std::vector<Dice> dice;
	std::vector<int> heldDice;
	std::vector<int> handDice;

	// Constants
	const int NUM_DICE = 6;
	const int WINNING_SCORE = 10000;

	// Member variables
	int numPlayers = 0;
	int currentPlayer = 0;
	int currentRound = 0;
	int turnScore = 0;

	int winner = -1;

	void InitializePlayers();
	void InitializeDice();

	void InitializeGame();

	void RollDice();
	void DrawDice();
	void HoldDice();
	void HoldDie(int i);

	int CalculateScore();
	int ScoreDice(std::map<int, std::map<std::string, int>> &diceMap);

	void DisplayPlayerInfo();

	void PlayTurn();
	void PlayRound();
	void LastRound();

	bool CheckForWinner();

	void EndGame();

	void ResetDice();

	bool CheckForFarkle();

	bool ValidateHold(int i);

	bool ValidateInput(std::string input);
	bool ValidateInput(int input);
	bool ValidateInput(char input);
	bool ValidateNumPlayers(int input);

public:

	#pragma region Constructors/Destructor
	Game();
	~Game();
	#pragma endregion

	#pragma region Methods

	void Loop();
	#pragma endregion

};

