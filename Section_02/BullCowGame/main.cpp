#include <iostream>
#include <string>

using namespace std;

void printIntro();
string getGuess();
void printGuess(string);

int main()
{
	constexpr int MAX_TRIES = 5;
	string guess;

	printIntro();

	for (int i = 0; i < MAX_TRIES; i++) {
		guess = getGuess();
		printGuess(guess);
	}

	return EXIT_SUCCESS;
}

// introduce the game
void printIntro() {
	constexpr int WORD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

// get a guess from the player
string getGuess() {
	string guess;
	cout << "Make a guess: ";
	getline(cin, guess);
	return guess;
}

// repeat the guess back to the player
void printGuess(string guess) {
	cout << "You guessed: " << guess << endl;
	cout << endl;
}
