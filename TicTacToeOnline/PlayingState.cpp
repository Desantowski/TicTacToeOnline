#include "PlayingState.h"

template<Player& EnemyType>
PlayingState<EnemyType>::PlayingState(sf::Window & window, EnemyType enemy) : m_board{ new Board{window.getSize()} },
	m_player{ new Player { Player::Type::PLAYER_O } }, 
	m_enemy{ new EnemyType{ enemy } }
{
}

template<Player& EnemyType>
PlayingState<EnemyType>::~PlayingState()
{
}

template<Player& EnemyType>
void PlayingState<EnemyType>::processEvents(sf::RenderWindow & source)
{
	while (source.pollEvent(m_event)) 
	{
		if (m_event.type == sf::Event::Closed)
		{
			source.close();
		}
	}
}

template<Player& EnemyType>
void PlayingState<EnemyType>::processGraphic(sf::RenderTarget & target)
{
	m_board->draw(target);
}

template<Player& EnemyType>
void PlayingState<EnemyType>::tick()
{
	return;
}