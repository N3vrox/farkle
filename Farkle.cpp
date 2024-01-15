// Farkle.cpp : This is the main file for the Farkle game. It creates a Game object and starts the main loop.
// Farkle is a dice game where players roll 6 dice and try to score points. The first player to 10,000 points wins.
// It is a turn-based game where each player takes a turn rolling the dice and scoring points. The player can choose to hold dice and roll the remaining dice.
// If the player scores points with all 6 dice, they can roll all 6 dice again. 
// If the player does not score points with any of the dice, they Farkle and lose all points for that turn.
//
// Author: Kyle Wheatley
// School: Southern New Hampshire University
// Class: IT-312 Software Development with C++
// Professor: Dr. Alex Thames
// Date: 06/25/2023
//

#include "Game.h"

#include <iostream>

using namespace std;

int main()
{
	// Create Game object
	Game game;

	// Start Main Loop
	game.Loop();
 
	return 0;
}