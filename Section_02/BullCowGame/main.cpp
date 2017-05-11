#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
void PrintGuess(const string &);
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
	string Guess;

	for (int i = 0; i < NUMBER_OF_TURNS; i++) {
		Guess = GetGuess();
		PrintGuess(Guess);
	}
}

// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

// get a guess from the player
string GetGuess()
{
	string Guess;
	cout << "Make a guess: ";
	getline(cin, Guess);
	return Guess;
}

// repeat the guess back to the player
void PrintGuess(const string &Guess)
{
	cout << "You guessed: " << Guess << endl;
	cout << endl;
}

bool AskToPlayAgain()
{
	string Response;
	cout << "Do you want to play again? ";
	getline(cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}
