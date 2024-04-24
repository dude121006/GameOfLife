#pragma once
#include "SFML/Graphics.hpp"

class Cell : public sf::RectangleShape
{
private:
    bool state;
    bool newState;
    sf::Vector2i coords;

public:
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