#pragma once
#include <memory>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

	void run();
private:
    std::unique_ptr<sf::RenderWindow> m_window;
    sf::Event event;
};

