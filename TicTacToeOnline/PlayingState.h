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
	virtual void processEvents(sf::RenderWindow & source) override;
	virtual void processGraphic(sf::RenderTarget & target) override;
	virtual void tick() override;
	PlayingState(sf::Window & window, EnemyType enemy);
	~PlayingState();
};