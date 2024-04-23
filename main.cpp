#include <iostream>
#include "SFML/Graphics.hpp"
#include "board.h"

#define Log(x) std::cout << x << std::endl;

int main()
{
    // window stuff
    sf::RenderWindow window(sf::VideoMode(800, 800), "GameOfLife");
    const int dimension = 16;

    Board board(dimension, window.getSize().x);

    //* ----------------------------------------------------------------------------------
    std::vector<Cell*> nearCells = board.GetNeighboringCells(sf::Vector2i(4, 3));
    for(int i = 0; i < nearCells.size(); i++)
    {
        nearCells[i]->SetState(1);
    }
    board.UpdateBoard();
    //* ----------------------------------------------------------------------------------

    // main game loop
    while (window.isOpen())
    {

        // event stuff
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // render stuff to window
        board.Render(window);

        window.display();
    }
    return 0;
}
