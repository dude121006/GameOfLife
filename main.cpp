
#include <iostream>
#include "src/include/SFML/Graphics.hpp"
//#include "Graphics.hpp"
#include "board.h"

#define Log(x) std::cout << x << std::endl;

int main()
{
    // window stuff
    sf::RenderWindow window(sf::VideoMode(800, 800), "GameOfLife");
    const int dimension = 16;

    // game stuff
    Board board(dimension, window.getSize().x);
    bool isRunning = false;

    sf::Clock clock;
    float timeElapsed;
    clock.restart();

    sf::Vector2f worldPos;

  //* ----------------------------------------------------------------------------------
    //* ----------------------------------------------------------------------------------

    // main game loop
    while (window.isOpen())
    {
        // time stuff
        timeElapsed = clock.getElapsedTime().asSeconds();
        if (timeElapsed >= 0.5f && isRunning)
        {
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
            {
                isRunning = false;
                board.ClearBoard();
            }

            else if (event.key.code == sf::Keyboard::Enter)
            {
                clock.restart();
                isRunning = true;
            }

            else if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                worldPos = window.mapPixelToCoords(mousePos);
            }

            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (!isRunning)
                {
                    board.GetCellWithMousePos(worldPos)->InvertState();
                    board.UpdateBoard();
                    Log("state inverted")
                }
            }
            // handle window resizing
            // else if (event.type == sf::Event::Resized)
            // {

            //     sf::Vector2u newSize(event.size.width, event.size.height);

            //     // Make sure the window remains square
            //     if (newSize.x != newSize.y)
            //     {
            //         // Choose the smallest dimension as the new size
            //         unsigned int newSizeMin = std::min(newSize.x, newSize.y);
            //         newSize.x = newSizeMin;
            //         newSize.y = newSizeMin;

            //         // Resize the window
            //         window.setSize(newSize);
            //     }
            //     board.DestroyBoard();
            //     board.CreateBoard(dimension, window.getSize().x);
            // }
        }

        window.clear();

        // render stuff to window
        board.Render(window);

        window.display();
    }
    return 0;
}
