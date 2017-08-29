#include "Game.h"

Game::Game() : m_window{ new sf::RenderWindow{sf::VideoMode{ 800, 600 }, "Tic Tac Toe Online"} }, m_board{ new Board{sf::Vector2f{800.f,600.f}} }
{
	m_window->setFramerateLimit(30);
}

Game::~Game()
{
}

void Game::run() {

    while (m_window->isOpen())
	{
		while (m_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window->close();
		}

		m_window->clear(sf::Color::White);
		m_board->draw(*m_window);
		m_window->display();
    }
}
