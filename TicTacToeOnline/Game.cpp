#include "Game.h"

Game::Game() : m_window(new sf::RenderWindow(sf::VideoMode(800, 600), "Tic Tac Toe Online"))
{
    m_window->setFramerateLimit(30);

    while (m_window->isOpen())
	{
		while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
		}

		m_window->clear(sf::Color::White);
		m_window->display();
    }
}

Game::~Game()
{
}
