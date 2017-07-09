#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(const FString &Guess) const
{
	if (false) // the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(const FString &Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
	
	// loop through all letters in the hidden word
	int32 HiddenWordLength = (int32) MyHiddenWord.length();
	int32 GuessLength = (int32) Guess.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters againsts the guess.
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
