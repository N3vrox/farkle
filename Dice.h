#pragma once
class Dice
{
private:
	const int NUM_SIDES = 6;
	int value;
	bool isHeld = false;
	bool isHeldLastRoll = false;

public:
	Dice();
	~Dice();
	int GetNumSides();
	int GetValue();
	void SetValue(int value);
	int Roll();
	bool GetHeld();
	void SetHeld(bool isHeld);
	bool GetHeldLastRoll();
	void SetHeldLastRoll(bool isHeldLastRoll);
};

