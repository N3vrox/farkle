#include "Dice.h"

#include <iostream>
#include <cstdlib>

using namespace std;

#pragma region Constructors/Destructor

Dice::Dice()
	: value(0), isHeld(false)
{
	srand(time(NULL));
}

Dice::~Dice()
{
	cout << "Dice destructor called." << endl;
}

#pragma endregion


#pragma region Getters/Setters

/*
* Function Name: GetNumSides
* Description: Returns the number of sides of the dice
* Parameters: None
* Returns: int - the number of sides of the dice
*/
int Dice::GetNumSides() 
{
	return this->NUM_SIDES;
}

/*
* Function Name: GetValue
* Description: Returns the value of the dice
* Parameters: None
* Returns: int - the value of the dice
*/
int Dice::GetValue() 
{
	return this->value;
}

/*
* Function Name: SetValue
* Description: Sets the value of the dice to the value passed in
* Parameters: int value - the value to set the dice to
* Returns: void
*/
void Dice::SetValue(int value) 
{
	this->value = value;
}

#pragma endregion


#pragma region Methods

/*
* Function Name: Roll
* Description: Rolls the individual dice and sets the value to a random number between 1 and the number of sides
* Parameters: None
* Returns: int - the value of the dice
*/
int Dice::Roll() 
{
	this->SetValue(rand() % GetNumSides() + 1);
	return this->GetValue();
}

/*
* Function Name: GetHeld
* Description: Returns the isHeld member variable
* Parameters: None
* Returns: bool - true if held, false if not
*/
bool Dice::GetHeld() 
{
	return this->isHeld;
}

/*
* Function Name: SetHeld
* Description: Sets the isHeld member variable to the value passed in
* Parameters: bool isHeld - true if held, false if not
* Returns: void
*/
void Dice::SetHeld(bool isHeld) 
{
	this->isHeld = isHeld;
}

/*
* Function Name: GetHeldLastRoll
* Description: Returns the isHeldLastRoll member variable
* Parameters: None
* Returns: bool - true if held last roll, false if not
*/
bool Dice::GetHeldLastRoll() 
{
	return this->isHeldLastRoll;
}

/*
* Function Name: SetHeldLastRoll
* Description: Sets the isHeldLastRoll member variable to the value passed in
* Parameters: bool isHeldLastRoll - true if held last roll, false if not
* Returns: void
*/
void Dice::SetHeldLastRoll(bool isHeldLastRoll) 
{
	this->isHeldLastRoll = isHeldLastRoll;
}

#pragma endregion
