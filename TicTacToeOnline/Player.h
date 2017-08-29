#pragma once
#include <memory>
#include <SFML\Graphics.hpp>

class Player
{
public:
	enum Type
	{
		PLAYER_O,
		PLAYER_X,
	};

	Player(Type _type);
	~Player();

	Type getType();

private:
	Type mType;
	std::unique_ptr<sf::Texture> mTexturePtr;
};