#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <thread>
#include "PlayingState.h"
#include "BotPlayer.h"

class Game
{
public:
	Game();
	~Game();
	void run();

private:
    std::unique_ptr<sf::RenderWindow> m_window;
	std::unique_ptr<GameState> m_state;
};

