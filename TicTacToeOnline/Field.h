#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
class Field : public sf::Sprite
{
	enum Type
	{
		FIELD_O = Player::PLAYER_O,
		FIELD_X = Player::PLAYER_X,
		FIELD_NULL
	};

public:
	Field(unsigned char identifier, sf::FloatRect position, sf::Texture & texture);
	~Field();
};

