#include "PlayingState.h"


PlayingState::PlayingState(sf::Window & window) : m_board{ new Board{window.getSize()} }
{
}


PlayingState::~PlayingState()
{
}

void PlayingState::processEvents(sf::RenderWindow & source)
{
	while (source.pollEvent(m_event)) 
	{
		if (m_event.type == sf::Event::Closed)
		{
			source.close();
		}
	}
}

void PlayingState::processGraphic(sf::RenderTarget & target)
{
	m_board->draw(target);
}

void PlayingState::tick()
{
	return;
}