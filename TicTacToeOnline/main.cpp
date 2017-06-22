#include <SFML\Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(800, 600), "Test");
	while (window->isOpen()) { std::cout << "Y\n"; }
}