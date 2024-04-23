#pragma once
#include "SFML/Graphics.hpp"

class Cell : public sf::RectangleShape
{
private:
    bool state;
    sf::Vector2i coords;

public:
    using sf::RectangleShape::RectangleShape;
    bool GetState();
    void SetState(bool newState);
    void InvertState();

    sf::Vector2i GetCoords();
    void SetCoords(sf::Vector2i newCoords);

};