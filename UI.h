#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

class UI { 

	/// this class is made to create different types of screens
	// such as 
	// 1. Loading Screen
	// 2. Pause Screen
	// 3. Game Over Screen
	// 4. Winning screen
	// 5. Life Screen
	// 6. Score Screen


	bool isPaused;
	bool isGameOver;
	bool isLoading;
	bool isWinning;
	bool inGame;

public :

	UI() : isPaused(false), isGameOver(false), isLoading(false), isWinning(false), inGame(false) {
	
		CreateLoadingScreen();
		CreatePauseScreen();
		CreateGameOverScreen();
		CreateWinningScreen();
		CreateLifeScreen();
		CreateScoreScreen();
	
	}

	void setPaused(bool paused) { isPaused = paused; }
	bool getPaused() const { return isPaused; }
	
	void setGameOver(bool gameOver) { isGameOver = gameOver; }
	bool getGameOver() const { return isGameOver; }

	void setLoading(bool loading) { isLoading = loading; }
	bool getLoading() const { return isLoading; }

	void setWinning(bool winning) { isWinning = winning; }
	bool getWinning() const { return isWinning; }

	void setInGame(bool inGame) { this->inGame = inGame; }
	bool getInGame() const { return inGame; }

	// Add methods to render different screens as needed

	void CreateLoadingScreen() {
		// Implement loading screen rendering logic
	}

	void CreatePauseScreen() {
		// Implement pause screen rendering logic
	}

	void CreateGameOverScreen() {
		// Implement game over screen rendering logic
	}

	void CreateWinningScreen() {
		// Implement winning screen rendering logic
	}

	void CreateLifeScreen() {
		// Implement life screen rendering logic
	}

	void CreateScoreScreen() {
		// Implement score screen rendering logic
	}


	void RenderUI(Window& window) {
		if (isLoading) {
			CreateLoadingScreen();
		}
		else if (isPaused) {
			CreatePauseScreen();
		}
		else if (isGameOver) {
			CreateGameOverScreen();
		}
		else if (isWinning) {
			CreateWinningScreen();
		}
		else if (inGame) {
			CreateLifeScreen();
			CreateScoreScreen();
		}
		// Render the current UI state
		window.display();

	}
};
