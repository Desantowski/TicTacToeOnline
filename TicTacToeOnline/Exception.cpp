#include "Exception.h"

Exception::Exception(std::string errorMessage) : std::exception{ }
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