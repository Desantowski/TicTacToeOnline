#pragma once
#include <SFML\Graphics.hpp>
#include <array>
#include "Player.h"

class Board
{
	std::array<Field, 9> fields;
public:
	void draw(sf::RenderTarget & target);
	void makeMove(Player::Type playerType, sf::Vector2f position);
	Board();
	~Board();
};