#pragma once
#include <SFML\Graphics.hpp>
#include <array>
#include <cmath>
#include "Player.h"
#include "Field.h"

class Board
{
	static const std::unique_ptr<sf::Texture> mFieldXPtr;
	static const std::unique_ptr<sf::Texture> mFieldOPtr;
	static const std::unique_ptr<sf::Texture> mFieldNullPtr;
	static constexpr float mFieldHeight{ 100 }, mFieldWidth{ 100 };

	Field& getFieldByPosition(sf::Vector2f position);
	sf::Texture& getTextureByType(Player::Type playerType);

	std::vector<Field> mFields;
	sf::Vector2f mLeftTop{ 300,400 };

public:
	static void prepareBoard();

	
	void draw(sf::RenderTarget & target);
	void makeMove(Player::Type playerType, sf::Vector2f position);
	Board(sf::Vector2f windowSize);
	~Board();
};