#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
private:
    sf::RenderWindow * m_window;
    sf::Event event;
};

