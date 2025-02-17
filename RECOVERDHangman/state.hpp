#pragma once
#include "common.hpp"
#include <string>
#include <vector>

namespace hangman {
	class HangmanGame {
	private:
		int numOfMistakes;
		int maxAttempts;
		std::string wordToGuess;
		std::vector<char> guessedLetters;
		std::vector<char> wrongLetters;
		std::vector<char> clue;
		GameDiff gameDiff;
		bool isGameOver;
		bool isWin;

	public:
		void init(GameDiff, std::string);
		void play();
		bool isDupGuess(const std::vector<char>&, const std::vector<char>&, char);
		bool checkForWin(const std::vector<char>&, std::string);
	};
}
