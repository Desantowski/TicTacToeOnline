#include "Board.h"

const std::unique_ptr<sf::Texture> Board::mFieldNullPtr{ std::make_unique<sf::Texture>() };
const std::unique_ptr<sf::Texture> Board::mFieldOPtr{ std::make_unique<sf::Texture>() };
const std::unique_ptr<sf::Texture> Board::mFieldXPtr{ std::make_unique<sf::Texture>() };

void Board::prepareBoard()
{
	if (!mFieldOPtr->loadFromFile("img/o.bmp")) throw FileNotFoundException("img/o.bmp");
	if (!mFieldXPtr->loadFromFile("img/x.bmp")) throw FileNotFoundException("img/x.bmp");
	if (!mFieldNullPtr->loadFromFile("img/nic.bmp")) throw FileNotFoundException("img/nic.bmp");
}


Board::Board(sf::Vector2u windowSize)
{
	mLeftTop.x = ((static_cast<float>(windowSize.x) - (3*mFieldHeight)) / 2);
	mLeftTop.y = ((static_cast<float>(windowSize.y) - (3*mFieldWidth)) / 2) + (static_cast<float>(windowSize.y) / 8);
	for (int i = 0; i < 9; i++)
	{
		sf::FloatRect pos{mLeftTop.x+(mFieldHeight * (i%3)),mLeftTop.y+(mFieldWidth * static_cast<float>(std::floor(i/3))), mFieldHeight, mFieldWidth};
		mFields.push_back(Field{ pos,*mFieldNullPtr });
	}
}

Board::~Board()
{
}


void Board::draw(sf::RenderTarget & target)
{
	for (Field & i : mFields) target.draw(i);
}

bool Board::makeMove(Player::Type playerType, sf::Vector2f position)
{
	try
	{
		Field & moveField = getFieldByPosition(position);
		if (moveField.getType() != Field::Type::FIELD_NULL)
			throw std::exception();
		moveField.setTexture(getTextureByType(playerType));
		moveField.setType(static_cast<Field::Type>(playerType));
		return true;
	}
	catch (...)
	{
		return false;
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
		throw ClickedNotAtBoardException();
	auto row = static_cast<int>(std::floor((position.x - mLeftTop.x) / mFieldWidth));
	auto column = static_cast<int>(std::floor((position.y - mLeftTop.y) / mFieldHeight));
	return mFields[(column * 3) + row];
}

Field::Type Board::getWinnerType()
{
	for (int i = 0; i < 3; i++)
	{
		Field::Type winner = mFields[i].getType();
		if (winner == Field::Type::FIELD_NULL) continue;
		for (int j = 1; j < 3; j++)
		{
			if (mFields[(j * 3) + i].getType() != winner)
				winner = Field::Type::FIELD_NULL;
		}
		if (winner != Field::Type::FIELD_NULL) return winner;
		else
		{
			winner = mFields[i].getType();
			for (int j = 1; j < 3; j++)
			{
				if (mFields[(i * 3) + j].getType() != winner)
					winner = Field::Type::FIELD_NULL;
			}
			if (winner != Field::Type::FIELD_NULL) return winner;
		}
	}
	if (mFields[0].getType() == mFields[4].getType() && mFields[0].getType() == mFields[8].getType() && mFields[0].getType() != Field::Type::FIELD_NULL) return mFields[0].getType();
	else return Field::Type::FIELD_NULL;
}