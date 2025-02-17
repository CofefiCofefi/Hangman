#pragma once
#include "common.hpp"
#include <string>
#include <vector>

using std::string;

namespace io {
	GameDiff getGameDiff();
	string getWordToGuess();
	void displayLogo();
	char getNextLetter();
	void displayMistakes(int, GameDiff);
	void displayClue(const std::vector<char>&);
	void displayWrongLetters(const std::vector<char>&);
	void displayGuess(char);
	void displayWinMessage(string);
	void displayLoseMessage(string);
	void endLine();
}
