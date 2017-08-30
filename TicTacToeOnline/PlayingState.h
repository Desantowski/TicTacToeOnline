#pragma once
#include <memory>
#include "GameState.h"
#include "Player.h"
#include "Board.h"

template<class EnemyType>
class PlayingState : public GameState
{
	std::unique_ptr<Board> m_board;

	std::shared_ptr<Player> m_player;
	std::shared_ptr<EnemyType> m_enemy;

	std::shared_ptr<Player> m_currentPlayer;

public:

	virtual void processEvents(sf::RenderWindow & source) override
	{
		while (source.pollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
			{
				source.close();
			}
		}
	}

	virtual void processGraphic(sf::RenderTarget & target) override
	{
		m_board->draw(target);
	}

	virtual void tick() override
	{
		return;
	}


	PlayingState(sf::Window & window, EnemyType enemy) : m_board{ new Board{ window.getSize() } },
		m_player{ new Player{ Player::Type::PLAYER_O } },
		m_enemy{ new EnemyType { enemy } }
	{
	}

	~PlayingState()
	{
	}
};