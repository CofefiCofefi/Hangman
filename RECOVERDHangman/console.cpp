#include "console.hpp"
#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::string;

namespace io {

	GameDiff getGameDiff() {
		string gameDiff;
		cin >> gameDiff;

		for (int i = 0; i < gameDiff.size(); i++) {
			gameDiff.at(i) = toupper(gameDiff.at(i));
		}

		if (gameDiff == "EASY") {
			return easy;
		}
		else if (gameDiff == "REGULAR") {
			return regular;
		}
		else { //Instructions said there was no need for error checking...
			return hard;
		}
	};

	string getWordToGuess() {
		string userEnterdWord;
		cin >> userEnterdWord;

		for (int i = 0; i < userEnterdWord.size(); i++) {
			userEnterdWord.at(i) = toupper(userEnterdWord.at(i));
		}
		return userEnterdWord;
	};

	char getNextLetter() {
		char guessedLetter;
		cin >> guessedLetter;
		guessedLetter = toupper(guessedLetter);
		return guessedLetter;
	};

	void endLine() {
		cout << endl;
	};

	void displayGuess(char guessedLetter) {
		cout << "Guess: " << guessedLetter << endl;
		cout << endl;
	};

	void displayLogo() {
		cout << "Hangman" << endl;
		cout << "-------" << endl;
		cout << endl;
	};

	void displayMistakes(int numOfMistakes, GameDiff gameDiff) {
		if (gameDiff == hard) {
			cout << "Mistakes: " << numOfMistakes << "/6" << endl;
		}
		else {
			cout << "Mistakes: " << numOfMistakes << "/9" << endl;
		}
	};

	void displayClue(const std::vector<char>& clue) {
		cout << "Clue:     ";
		for (int i = 0; i < clue.size(); i++) {
			cout << clue.at(i);
		}
		cout << endl;
	};

	void displayWrongLetters(const std::vector<char>& wrongLetters) {
		cout << "Wrong:    ";
		for (int i = 0; i < wrongLetters.size(); i++) {
			cout << wrongLetters.at(i);
		}
		cout << endl;
	};

	void displayWinMessage(string word) {
		cout << "You won!" << endl;
		cout << "The word was: " << word << endl;
	};

	void displayLoseMessage(string word) {
		cout << "You lost." << endl;
		cout << "The word was: " << word << endl;
	};

}