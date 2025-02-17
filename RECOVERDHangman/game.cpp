//Where the acual code is
#include "game.hpp"
#include <string>
#include "common.hpp"

using std::string;
using namespace io;

namespace hangman {

	void StartGame() {

		HangmanGame game;
		GameDiff gameDiff = getGameDiff();
		string wordToGuess = getWordToGuess();
		displayLogo();
		game.init(gameDiff, wordToGuess);
		game.play();
	}
};