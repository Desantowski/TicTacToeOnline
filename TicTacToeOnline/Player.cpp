#include "Player.h"


Player::Player(Type type) : mType{ type }
{
}

Player::~Player()
{
}

Player::Type Player::getType()
{
	return mType;
}