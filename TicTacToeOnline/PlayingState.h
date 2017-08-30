#pragma once
#include <memory>
#include "GameState.h"
#include "Board.h"

class PlayingState : public GameState
{
	std::unique_ptr<Board> m_board;

public:
	virtual void processEvents(sf::RenderWindow & source) override;
	virtual void processGraphic(sf::RenderTarget & target) override;
	virtual void tick() override;
	PlayingState(sf::Window  & window);
	~PlayingState();
};