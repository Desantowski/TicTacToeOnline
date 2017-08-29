#include "Exception.h"

Exception::Exception(std::string message) : std::exception{ message.c_str() }
{
}


Exception::~Exception()
{
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