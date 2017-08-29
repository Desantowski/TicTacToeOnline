#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Board.h"

class Game
{
public:
	Game();
	~Game();

	void run();
private:
    std::unique_ptr<sf::RenderWindow> m_window;
	std::unique_ptr<Board> m_board;
    sf::Event event;
};

