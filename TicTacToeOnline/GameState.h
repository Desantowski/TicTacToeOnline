 #pragma once
#include <SFML\Graphics.hpp>

class GameState
{
protected:
	sf::Event m_event;
public:
	GameState();
	virtual ~GameState();
	virtual void processGraphic(sf::RenderTarget & target) = 0;
	virtual void processEvents(sf::RenderWindow & source) = 0;
	virtual void tick() = 0;
};