#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Exception.h"

int main()
{
	try
	{
		Board::prepareBoard();
		Game m_game;
		m_game.run();
	}
	catch (Exception & e)
	{
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
    return EXIT_SUCCESS;
}
