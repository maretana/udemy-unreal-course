#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuess(const std::string &);
bool AskToPlayAgain();

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
	constexpr int NUMBER_OF_TURNS = 5;
	std::string Guess;

	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		Guess = GetGuess();
		PrintGuess(Guess);
	}
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// get a guess from the player
std::string GetGuess()
{
	std::string Guess;
	std::cout << "Make a guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

// repeat the guess back to the player
void PrintGuess(const std::string &Guess)
{
	std::cout << "You guessed: " << Guess << std::endl;
	std::cout << std::endl;
}

bool AskToPlayAgain()
{
	std::string Response;
	std::cout << "Do you want to play again? ";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}
