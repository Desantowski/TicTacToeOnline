#include "Player.h"


Player::Player(Type _type) : mType{ _type }
{
}

Player::~Player()
{
}

Player::Type Player::getType()
{
	return mType;
}