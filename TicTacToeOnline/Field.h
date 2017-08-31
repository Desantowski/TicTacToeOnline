#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class Field : public sf::Sprite
{
public:
	enum Type
	{
		FIELD_O = Player::PLAYER_O,
		FIELD_X = Player::PLAYER_X,
		FIELD_NULL
	};

	Field(sf::FloatRect position, sf::Texture & texture);
	~Field();

	Type getType();
	void setType(Type);

private:
	Type mType;
};

