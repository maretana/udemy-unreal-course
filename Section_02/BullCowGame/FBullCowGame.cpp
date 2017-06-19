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
    
    const FString HIDDEN_WORD = "ant";
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment the turn number
    MyCurrentTry++;
    
    //setup a return variable
    FBullCowCount BullCowCount;
	
	// loop through all letters in the guess
	int32 HiddenWordLength = (int32) MyHiddenWord.length();
	int32 GuessLength = (int32) Guess.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters againsts the hidden word.
		for (int32 GChar = 0; GChar < GuessLength; GChar++)
		{
			if (MyHiddenWord[MHWChar] == Guess[GChar])
			{
				if (MyHiddenWord[MHWChar] == Guess[MHWChar])
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
            }
        }
    }
    
    
    return BullCowCount;
}
