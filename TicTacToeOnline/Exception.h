#pragma once
#include <exception>
#include <string>
class Exception : public std::exception
{
public:
	Exception(std::string message);
	~Exception();
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
