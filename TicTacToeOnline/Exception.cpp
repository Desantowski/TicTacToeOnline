#include "Exception.h"

Exception::Exception(std::string errorMessage) : mMessage{ errorMessage }, std::exception{ }
{
}


Exception::~Exception()
{
}

std::string Exception::what()
{
	return mMessage;
}

FileNotFoundException::FileNotFoundException(std::string path) : Exception{ "File not found: " + path }
{
}


FileNotFoundException::~FileNotFoundException()
{
}

ClickedNotAtBoardException::ClickedNotAtBoardException() : Exception{ "Clicked not at board" }
{
}


ClickedNotAtBoardException::~ClickedNotAtBoardException()
{
}

UnknownEnemyTypeException::UnknownEnemyTypeException() : Exception{ "Unknown enemy type!" }
{
}


UnknownEnemyTypeException::~UnknownEnemyTypeException()
{
}