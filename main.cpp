#include <iostream>
#include "SFML/Graphics.hpp"
#include "board.h"

#define Log(x) std::cout << x << std::endl;

int main()
{
    // window stuff
    sf::RenderWindow window(sf::VideoMode(800, 800), "GameOfLife");
    const int dimension = 16;

    // game stuff
    Board board(dimension, window.getSize().x);
    bool isStarted = false;

    sf::Clock clock;
    float timeElapsed;
    clock.restart();

    sf::Vector2f worldPos;

    //* ----------------------------------------------------------------------------------
    // board.GetCellWithCoords(sf::Vector2i(1, 0))->SetState(1);
    // board.GetCellWithCoords(sf::Vector2i(1, 1))->SetState(1);
    // board.GetCellWithCoords(sf::Vector2i(2, 0))->SetState(1);
    board.UpdateBoard();

    //* ----------------------------------------------------------------------------------

    // main game loop
    while (window.isOpen())
    {
        // time stuff
        timeElapsed = clock.getElapsedTime().asSeconds();
        if (timeElapsed >= 1.0f && isStarted) {
            board.EvolveBoard();
            clock.restart();
        }


        // event stuff
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            else if (event.key.code == sf::Keyboard::Space)
                board.EvolveBoard();

            else if (event.key.code == sf::Keyboard::Enter)
            {
                clock.restart();
                isStarted = true;
            }

            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                worldPos = window.mapPixelToCoords(mousePos);
            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (!isStarted)
                {
                    board.GetCellWithMousePos(worldPos)->InvertState();
                    board.UpdateBoard();
                    Log("state inverted")
                }
            }
        }

        window.clear();

        // render stuff to window
        board.Render(window);

        window.display();
    }
    return 0;
}
