#include "cell.h"

Cell::Cell()
{
    SetState(0);
    SetNewState(0);
    setFillColor(sf::Color::Black);
    setOutlineColor(sf::Color::White);
    setOutlineThickness(1);
}

bool Cell::GetState()
{
    return state;
}

bool Cell::GetNewState()
{
    return newState;
}

void Cell::SetState(bool targetState)
{
    state = targetState;
}

void Cell::SetNewState(bool targetState)
{
    newState = targetState;
}

void Cell::InvertState()
{
    state = !state;
}

sf::Vector2i Cell::GetCoords()
{
    return coords;
}

void Cell::SetCoords(sf::Vector2i newCoords)
{
    coords = newCoords;
}

bool Cell::isAlive()
{
    return true ? state == 1 : false;
}

bool Cell::isDead()
{
    return true ? state == 0 : false;
}