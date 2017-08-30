#include "Game.h"

Game::Game() : m_window{ new sf::RenderWindow{sf::VideoMode{ 800, 600 }, "Tic Tac Toe Online"} }, m_state{ new PlayingState{ *m_window } }
{
	m_window->setFramerateLimit(30);
}

Game::~Game()
{
}

void Game::run() {
    while (m_window->isOpen())
	{
		m_state->processEvents(*m_window);
		m_state->tick();

		m_window->clear(sf::Color::White);
		m_state->processGraphic(*m_window);
		m_window->display();
    }
}
