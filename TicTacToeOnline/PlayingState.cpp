#include "PlayingState.h"
#ifdef _DEBUG
#include <iostream>
#endif

template<class T>
void PlayingState<T>::enemyMove()
{
	throw UnknownEnemyTypeException();
}

template<>
void PlayingState<BotPlayer>::enemyMove()
{
	static std::default_random_engine generator;
	static std::uniform_real_distribution<float> distribution(0, 800);

	float f1 = distribution(generator), f2 = distribution(generator);

	if (m_board->makeMove(m_enemy->getType(), sf::Vector2f{ f1, f2 }))
		m_currentPlayer = m_player;
}

template<>
void PlayingState<Player>::enemyMove()
{

	static std::default_random_engine generator;
	static std::uniform_real_distribution<float> distribution(0, 800);

	float f1 = distribution(generator), f2 = distribution(generator);

	if (m_board->makeMove(m_enemy->getType(), sf::Vector2f{ f1, f2 } ))
		m_currentPlayer = m_player;
}