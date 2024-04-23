#include "cell.h"


bool Cell::GetState()
{
    return state;
}

void Cell::SetState(bool newState)
{
    state = newState;
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