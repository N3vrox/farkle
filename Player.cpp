#include "Player.h"

using namespace std;

#pragma region Constructors/Destructor

Player::Player()
	: name("NONE"), roundScore(0), totalScore(0) {}

Player::Player(string name)
	: name(name), roundScore(0), totalScore(0) {}

Player::~Player()
{
	cout << "Player destructor called." << endl;
}
#pragma endregion



#pragma region Getters/Setters

/*
* Function Name: GetName
* Description: Returns the name of the player
* Parameters: None
* Returns: string - the name of the player
*/
string Player::GetName()
{
	return this->name;
}

/*
* Function Name: SetName
* Description: Sets the name of the player to the name passed in
* Parameters: string name - the name to set the player's name to
* Returns: void
*/
void Player::SetName(string name)
{
	this->name = name;
}

/*
* Function Name: GetRoundScore
* Description: Returns the round score of the player
* Parameters: None
* Returns: int - the round score of the player
*/
int Player::GetRoundScore()
{
	return this->roundScore;
}

/*
* Function Name: SetRoundScore
* Description: Sets the round score of the player to the score passed in
* Parameters: int rScore - the score to set the round score to
* Returns: void
*/
void Player::SetRoundScore(int rScore)
{
	this->roundScore = rScore;
}

/*
* Function Name: GetTotalScore
* Description: Returns the total score of the player
* Parameters: None
* Returns: int - the total score of the player
*/
int Player::GetTotalScore()
{
	return this->totalScore;
}

/*
* Function Name: SetTotalScore
* Description: Sets the total score of the player to the score passed in
* Parameters: int tScore - the score to set the total score to
* Returns: void
*/
void Player::SetTotalScore(int tScore)
{
	this->totalScore = tScore;
}

#pragma endregion



#pragma region Methods
/*
* Function Name: AddToRoundScore
* Description: Adds the score passed in to the round score of the player
* Parameters: int score - the score to add to the round score
* Returns: void
*/
void Player::AddToRoundScore(int score)
{
	SetRoundScore(GetRoundScore() + score);
}

/*
* Function Name: AddToTotalScore
* Description: Adds the score passed in to the total score of the player
* Parameters: int score - the score to add to the total score
* Returns: void
*/
void Player::AddToTotalScore(int score)
{
	SetTotalScore(GetTotalScore() + score);
}

/*
* Function Name: AddRoundToTotal
* Description: Adds the round score to the total score
* Parameters: None
* Returns: void
*/
void Player::AddRoundToTotal()
{
	SetTotalScore(GetTotalScore() + GetRoundScore());
}

/*
* Function Name: ResetRoundScore
* Description: Resets the round score of the player to 0
* Parameters: None
* Returns: void
*/
void Player::ResetRoundScore()
{
	SetRoundScore(0);
}

/*
* Function Name: ResetTotalScore
* Description: Resets the total score of the player to 0
* Parameters: None
* Returns: void
*/
void Player::ResetTotalScore()
{
	SetTotalScore(0);
}
#pragma endregion