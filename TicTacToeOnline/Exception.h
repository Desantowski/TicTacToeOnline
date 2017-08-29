#pragma once
#include <exception>
#include <string>
class Exception : public std::exception
{
	std::string mMessage;
public:
	Exception(std::string message);
	~Exception();
	std::string what();
};

class FileNotFoundException : public Exception
{
public:
	FileNotFoundException(std::string path);
	~FileNotFoundException();
};

class ClickedNotAtBoardException : public Exception
{
public:
	ClickedNotAtBoardException();
	~ClickedNotAtBoardException();
};
