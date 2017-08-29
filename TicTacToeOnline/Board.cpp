#include "Board.h"

const std::unique_ptr<sf::Texture> Board::mFieldNullPtr{ std::make_unique<sf::Texture>() };
const std::unique_ptr<sf::Texture> Board::mFieldOPtr{ std::make_unique<sf::Texture>() };
const std::unique_ptr<sf::Texture> Board::mFieldXPtr{ std::make_unique<sf::Texture>() };

void Board::prepareBoard()
{
	if (!mFieldOPtr->loadFromFile("img/o.bmp")) throw std::exception("Loading failed: img/o.bmp");
	if (!mFieldXPtr->loadFromFile("img/x.bmp")) throw std::exception("Loading failed: img/x.bmp");
	if (!mFieldNullPtr->loadFromFile("img/nic.bmp")) throw std::exception("Loading failed: img/nic.bmp");
}


Board::Board(sf::Vector2f windowSize) 
{
	for (unsigned char i = 0; i < 9; i++)
	{
		sf::FloatRect pos{mLeftTop.x+(mFieldHeight * (i%3)),mLeftTop.y+(mFieldWidth * static_cast<float>(std::floor(i/3))), mFieldHeight, mFieldWidth};
		mFields.push_back(Field{ i,pos,*mFieldNullPtr });
	}
}

Board::~Board()
{
}


void Board::draw(sf::RenderTarget & target)
{
	for (Field & i : mFields)
		target.draw(i);
}

void Board::makeMove(Player::Type playerType, sf::Vector2f position)
{
	try
	{
		return getFieldByPosition(position).setTexture(getTextureByType(playerType));
	}
	catch (...)
	{
		return;
	}
}

sf::Texture& Board::getTextureByType(Player::Type playerType)
{
	switch (playerType)
	{
	case Player::PLAYER_O: return *mFieldOPtr;
	case Player::PLAYER_X: return *mFieldXPtr;
	default: return *mFieldNullPtr;
	}
}

Field& Board::getFieldByPosition(sf::Vector2f position)
{
	auto clickedNotAtBoard = (position.x < mLeftTop.x || position.y < mLeftTop.y || position.x >(mLeftTop.x + 3 * mFieldWidth) || position.y >(mLeftTop.y + 3 * mFieldHeight));
	if (clickedNotAtBoard)
		throw std::exception("");
	auto row = static_cast<int>(std::floor((position.x - mLeftTop.x) / mFieldWidth));
	auto column = static_cast<int>(std::floor((position.y - mLeftTop.y) / mFieldHeight));
	return mFields[(row * 3) + column];
}