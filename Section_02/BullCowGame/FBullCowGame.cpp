#include "FBullCowGame.h"

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// receives a VALID guess, increments turn, and returns count.
BullCowCount FBullCowGame::SubmitGuess(FString)
{
    return BullCowCount();
}
