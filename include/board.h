#pragma once
#include "cell.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

#define Log(x) std::cout << x << std::endl;

class Board
{
private:
    std::vector<std::vector<Cell>> board;
    int boardLength;
    int cellLength;

public:
    Board(int numCells, int windowDimension);

    void Test();

    std::vector<std::vector<Cell>> CreateBoard(int numCells, int windowDimension);
    void UpdateBoard();
    void UpdateCellStates();
    void Render(sf::RenderWindow& window);
    void PrintStates();
    int getRandomInt(int maxValue);
    void RandomStarterCell();

    bool IsEdge(sf::Vector2i coords);
    bool IsCorner(sf::Vector2i coords);
    bool IsNotEdgeOrCorner(sf::Vector2i coords);

    std::vector<Cell*> GetNeighboringCells(sf::Vector2i coords);
    std::vector<Cell*> GetCellsWithCoords(std::vector<sf::Vector2i> cellCoords);
    Cell* GetCellWithCoords(sf::Vector2i cellCoords);
    Cell* GetCellWithMousePos(sf::Vector2f mousePosition);
    std::vector<sf::Vector2i> FilterCellCoords(std::vector<sf::Vector2i> allCells);

    int CountNeighboringCells(sf::Vector2i cellCoords);

    void EvolveBoard();

};