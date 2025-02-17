#include "console.hpp"
#include <string>
#include "state.hpp"
#include <algorithm>

using namespace io;

namespace hangman {
	void HangmanGame::init(GameDiff diff, std::string word) {
		gameDiff = diff;
		wordToGuess = word;
		numOfMistakes = 0;
		clue = std::vector<char>(word.size(), '_');
		isWin = false;
		isGameOver = false;

		if (diff == hard) {
			maxAttempts = 6;
		}
		else {
			maxAttempts = 9;
		}
	}

	void HangmanGame::play() {
		char charGuessed;
		bool correctGuess = false;

		while (!isGameOver) {
			displayMistakes(numOfMistakes, gameDiff);
			displayClue(clue);
			if (wrongLetters.size() > 0) {
				std::sort(wrongLetters.begin(), wrongLetters.end());
				displayWrongLetters(wrongLetters);
				endLine();
			}
			else {
				endLine();
			}

			charGuessed = getNextLetter();
			displayGuess(charGuessed);

			bool dupGuess = isDupGuess(clue, wrongLetters, charGuessed);

			if (dupGuess && gameDiff != easy) {
				numOfMistakes++;
			}

			for (int pos = 0; pos < wordToGuess.size(); pos++) {
				if (charGuessed == wordToGuess.at(pos)) {
					clue.at(pos) = charGuessed;
					correctGuess = true;
				}
			}

			if (!correctGuess && !dupGuess) {
				numOfMistakes++;
				wrongLetters.push_back(charGuessed);
			}

			isGameOver = checkForWin(clue, wordToGuess);
			correctGuess = false;
		}
	}


	bool HangmanGame::checkForWin(const std::vector<char>& clue, std::string wordToGuess) {
		if (numOfMistakes >= maxAttempts) {
			displayLoseMessage(wordToGuess);
			return true;
		}

		for (size_t pos = 0; pos < wordToGuess.size(); pos++) {
			if (clue[pos] != wordToGuess[pos]) {
				return false;
			}
		}
		displayWinMessage(wordToGuess);
		return true;
	}

	bool HangmanGame::isDupGuess(const std::vector<char>& clue, const std::vector<char>& wrongLetters, char charGuessed) {
		for (char c : clue) {
			if (c == charGuessed) {
				return true;
			}
		}

		for (char c : wrongLetters) {
			if (c == charGuessed) {
				return true;
			}
		}

		return false;
	}
}
