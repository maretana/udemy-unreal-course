/* This is the console executable, that makes use of the BullCow class
 This acts as the view in a MVC pattern, and is responsible for all
 user interaction. For game logic see the FBullCowGame class.
 */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuessResult(const FBullCowCount &);
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while(bPlayAgain);
	return EXIT_SUCCESS;
}

// loop for the number of turns asking for guesses.
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess;
	FBullCowCount BullCowCount;
	EGuessStatus Status;

	for (int32 i = 0; i < MaxTries; i++) {
		Guess = GetGuess();
		Status = BCGame.CheckGuessValidity(Guess);
		BullCowCount = BCGame.SubmitGuess(Guess);
		PrintGuessResult(BullCowCount);
	}
}

// introduce the game
void PrintIntro()
{
	int32 HiddenWordLength = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << HiddenWordLength;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// get a guess from the player
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess;
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

// Prints user's guess result
void PrintGuessResult(const FBullCowCount &BullCowCount)
{
    std::cout << "Bulls = " << BullCowCount.Bulls;
    std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	FText Response;
	std::cout << "Do you want to play again? ";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}
