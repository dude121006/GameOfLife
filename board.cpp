#include "board.h"

Board::Board(int numCells, int windowDimension)
{
    boardLength = numCells;
    board = CreateBoard(numCells, windowDimension);
    srand(time(nullptr));
}

std::vector<std::vector<Cell>> Board::CreateBoard(int numCells, int windowDimension)
{
    board = std::vector<std::vector<Cell>>(numCells, std::vector<Cell>(numCells));

    sf::Vector2f currentPos = sf::Vector2f(0, 0);

    for (int x = 0; x < numCells; x++)
    {
        for (int y = 0; y < numCells; y++)
        {
            sf::Vector2f cellSize = sf::Vector2f(windowDimension / numCells, windowDimension / numCells);
            board[x][y].SetState(0);
            board[x][y].setSize(cellSize);
            board[x][y].setFillColor(sf::Color::Black);
            board[x][y].setOutlineColor(sf::Color::White);
            board[x][y].setOutlineThickness(1);
            board[x][y].setPosition(sf::Vector2f(cellSize.x * x, cellSize.y * y));
        }
    }
    // RandomStarterCell();
    UpdateBoard();
    return board;
}

// updates board
void Board::UpdateBoard()
{
    for (int x = 0; x < boardLength; x++)
    {
        for (int y = 0; y < boardLength; y++)
        {
            if (board[x][y].GetState())
            {
                board[x][y].setFillColor(sf::Color::White);
                board[x][y].setOutlineColor(sf::Color::Black);
            }
            else
            {
                board[x][y].setFillColor(sf::Color::Black);
                board[x][y].setOutlineColor(sf::Color::White);
            }
        }
    }
}

// draws board on the given window
void Board::Render(sf::RenderWindow &window)
{
    for (int x = 0; x < boardLength; x++)
    {
        for (int y = 0; y < boardLength; y++)
        {
            window.draw(board[x][y]);
        }
    }
}

int Board::getRandomInt(int maxValue)
{
    return rand() % maxValue;
}

bool Board::IsEdge(sf::Vector2i coords)
{
    if (IsCorner(coords))
        return false;
    else if (coords.x == 0 || coords.x == boardLength || coords.y == 0 || coords.y == boardLength)
        return true;
    return false;
}

bool Board::IsCorner(sf::Vector2i coords)
{
    if (coords == sf::Vector2i(0, 0) || coords == sf::Vector2i(0, boardLength) || coords == sf::Vector2i(boardLength, 0) || coords == sf::Vector2i(boardLength, boardLength))
        return true;
    else
        return false;
}

bool Board::IsNotEdgeOrCorner(sf::Vector2i coords)
{
    if (IsEdge(coords) || IsCorner(coords))
        return false;
    else
        return true;
}

// return an array of pointers to nearby cells of a given cell coords
std::vector<Cell *> Board::GetNeighboringCells(sf::Vector2i coords)
{
    std::vector<sf::Vector2i> allNearbyCellCoords{};

    // filter invalid cell coords
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            if (x == 0 && y == 0)
            {
                continue;
            }
            allNearbyCellCoords.push_back(coords + sf::Vector2i(x, y));
        }
    }
    std::vector<sf::Vector2i> filteredCellCoords = FilterCellCoords(allNearbyCellCoords);
    std::vector<Cell *> neighborCells = GetCellsWithCoords(filteredCellCoords);
    return neighborCells;
}

// removes invalid cell coords from given array and returns an array of valid cell coords
std::vector<sf::Vector2i> Board::FilterCellCoords(std::vector<sf::Vector2i> allCells)
{
    std::vector<sf::Vector2i> finalCells{};
    for (int i = 0; i < allCells.size(); i++)
    {
        if (allCells[i].x < 0 || allCells[i].x >= boardLength)
            continue;
        else if (allCells[i].y < 0 || allCells[i].y >= boardLength)
            continue;
        finalCells.push_back(allCells[i]);
    }
    return finalCells;
}

// return an array of pointers to the cells of the given coords
std::vector<Cell *> Board::GetCellsWithCoords(std::vector<sf::Vector2i> cellCoords)
{
    std::vector<Cell *> finalCells{};
    for (int i = 0; i < cellCoords.size(); i++)
    {
        finalCells.push_back(&board[cellCoords[i].x][cellCoords[i].y]);
    }
    return finalCells;
}

// return a pointer to the cell of the given coords
Cell *Board::GetCellWithCoords(sf::Vector2i cellCoords)
{
    return &board[cellCoords.x][cellCoords.y];
}

// makes a random cell alive at game start
void Board::RandomStarterCell()
{
    int randX = getRandomInt(boardLength);
    int randY = getRandomInt(boardLength);
    board[randX][randY].SetState(1);
}

void Board::Test()
{
    Log(board[3][3].GetState())
}