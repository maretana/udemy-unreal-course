#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

    MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(const FString &Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
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

	bGameIsWon = BullCowCount.Bulls == HiddenWordLength;

    return BullCowCount;
}

bool FBullCowGame::IsIsogram(const FString &Guess) const
{
	if (Guess.length() <= 1) return true;

	TMap<char, bool> LetterSeen;
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) return false;
		LetterSeen[Letter] = true;
	}
	return true;
}

bool FBullCowGame::IsLowercase(const FString &Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) return false;
	}
	return true;
}
