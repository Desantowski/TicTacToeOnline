#include "Field.h"

Field::Field(sf::FloatRect position, sf::Texture & texture) : sf::Sprite{ texture }, mType { FIELD_NULL }
{
	setPosition(position.left, position.top);
	setScale(sf::Vector2f{ position.height / texture.getSize().x,position.width / texture.getSize().y });
}

Field::~Field()
{
}

Field::Type Field::getType()
{
	return mType;
}

void Field::setType(Field::Type type)
{
	mType = type;
}