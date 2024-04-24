#pragma once
#include "SFML/Graphics.hpp"

class Cell : public sf::RectangleShape
{
private:
    bool state;
    bool newState;
    sf::Vector2i coords;

public:
    sf::Color darkGray = sf::Color{38, 38, 38};
    sf::Color lightGray = sf::Color{79, 79, 79};
    sf::Color white = sf::Color{235, 230, 230};

public:
    Cell();

    using sf::RectangleShape::RectangleShape;
    bool GetState();
    bool GetNewState();
    void SetState(bool targetState);
    void SetNewState(bool targetState);
    void InvertState();

    bool isAlive();
    bool isDead();

    sf::Vector2i GetCoords();
    void SetCoords(sf::Vector2i newCoords);

};