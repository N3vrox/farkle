#pragma once

#include<iostream>
#include<string>
#include<sstream>

class Player
{
#pragma region Private
private:

#pragma region Private Variables Declarations
	std::string name;
	int roundScore;
	int totalScore;
#pragma endregion
#pragma endregion

#pragma region Public
public:

#pragma region Constructors/Destructor
	Player();
	Player(std::string name);

	~Player();
#pragma endregion


#pragma region Getters/Setters

	std::string GetName();
	void SetName(std::string name);

	int GetRoundScore();
	void SetRoundScore(int tScore);

	int GetTotalScore();
	void SetTotalScore(int bScore);
#pragma endregion


#pragma region Methods
	void AddToRoundScore(int score);
	void AddToTotalScore(int score);
	void AddRoundToTotal();

	void ResetRoundScore();
	void ResetTotalScore();
};
#pragma endregion
#pragma endregion
