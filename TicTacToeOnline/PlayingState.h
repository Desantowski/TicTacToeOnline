#pragma once
#include <memory>
#include <random>
#include "GameState.h"
#include "Player.h"
#include "BotPlayer.h"
#include "Board.h"

template<class EnemyType>
class PlayingState : public GameState
{
	std::unique_ptr<Board> m_board;

	std::shared_ptr<Player> m_player;
	std::shared_ptr<EnemyType> m_enemy;
	std::shared_ptr<Player> m_currentPlayer;
	std::shared_ptr<Player> m_winner;
	std::unique_ptr<sf::Sprite> m_winnerSprite;
	std::unique_ptr<sf::Texture> m_winnerTexture;
	
	std::unique_ptr<sf::Event> m_playerClick;

	bool playerMove()
	{
		auto result = m_board->makeMove(m_currentPlayer->getType(), sf::Vector2f{ static_cast<float>(m_playerClick->mouseButton.x), static_cast<float>(m_playerClick->mouseButton.y) });
		m_playerClick = nullptr;
		return result;
	}

	void enemyMove();

	void endTick(sf::RenderWindow & window)
	{
		if (m_winner != nullptr && m_winnerSprite == nullptr)
		{
			m_winnerTexture = std::make_unique<sf::Texture>();
			if (m_winner->getType() == Player::Type::PLAYER_O) m_winnerTexture->loadFromFile("img/osmall.bmp");
			else  m_winnerTexture->loadFromFile("img/xsmall.bmp");
			m_winnerSprite = std::make_unique<sf::Sprite>(*m_winnerTexture);

			sf::Vector2f pos(window.getSize());
			pos.x /= 2;
			pos.x -= m_winnerTexture->getSize().x / 2;
			pos.y /= 8;

			m_winnerSprite->setPosition(pos);
		}
	}

public:
	virtual void processEvents(sf::RenderWindow & source) override
	{
		while (source.pollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
			{
				source.close();
			}
			else if (m_event.type == sf::Event::MouseButtonPressed && m_event.mouseButton.button == sf::Mouse::Button::Left)
			{
				m_playerClick = std::make_unique<sf::Event>( m_event );
			}
			else if (m_event.type == sf::Event::KeyPressed && m_winner != nullptr && m_event.key.code == sf::Keyboard::Return)
			{
				delete this;
			}
		}
	}

	virtual void processGraphic(sf::RenderTarget & target) override
	{
		m_board->draw(target);
		if (m_winnerSprite   != nullptr) target.draw(*m_winnerSprite);
	}

	virtual void tick(sf::RenderWindow & window) override
	{
		if (m_winner != nullptr)
		{
			endTick(window);
			return;
		}
		if (m_currentPlayer == m_player)
		{
			if (m_playerClick != nullptr)
			{
				if (playerMove()) m_currentPlayer = m_enemy;
			}
		}
		else enemyMove();
		if (m_board->getWinnerType() != Field::Type::FIELD_NULL) m_winner = std::make_shared<Player>(*m_currentPlayer);
		return;
	}

	PlayingState(sf::Window & window, EnemyType enemy) : m_board{ new Board{ window.getSize() } },
		m_player{ new Player{ Player::Type::PLAYER_O } },
		m_enemy{ new EnemyType { enemy } },
		m_currentPlayer { m_player }
	{
	}

	~PlayingState()
	{
	}
};