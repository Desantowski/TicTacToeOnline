#include <iostream>
#include "Game.h"
#include "Board.h"

int main()
{
	Board::prepareBoard();
    Game m_game;
    m_game.run();
    return EXIT_SUCCESS;
}
