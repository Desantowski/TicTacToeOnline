#pragma once
#include <SFML\Graphics.hpp>
#include <array>
#include "Player.h"
#include "Field.h"

class Board
{
	Field& getFieldByPosition(sf::Vector2f position);
	sf::Texture& getTextureByType(Player::Type playerType);

	static const std::unique_ptr<sf::Texture> mFieldXPtr;
	static const std::unique_ptr<sf::Texture> mFieldOPtr;
	static const std::unique_ptr<sf::Texture> mFieldNullPtr;

	std::vector<Field> mFields;
	sf::Vector2f mLeftTop{ 300,400 };

public:
	void draw(sf::RenderTarget & target);
	void makeMove(Player::Type playerType, sf::Vector2f position);
	Board(sf::Vector2f windowSize);
	~Board();
};