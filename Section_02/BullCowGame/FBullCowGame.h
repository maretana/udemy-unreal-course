#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();

	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
