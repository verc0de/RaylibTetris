#include "block.h"

Block::Block()
{
    cellSize = 29;
    rotationState = 0;
    colors = getCellColors(); 
    rowOffset = 0;
    colOffset = 0;
}

void Block::draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = getCellPositions(); //Calculates position
    for(Position item : tiles)
    {
        DrawRectangle(item.col * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize -1, colors[id]);
    }
}

void Block::Move(int rows, int cols)
{
    rowOffset += rows;
    colOffset += cols;
}

void Block::rotate()
{
    rotationState++;
    if(rotationState == (int)cells.size())//cast cells.size to an int
    {
        rotationState = 0;          //sets the rotation state back to 0 to loop
    }
}

void Block::undoRotate()
{
    rotationState--;
    if(rotationState==-1)
    {
        rotationState = (cells.size()-1);
    }
}

std::vector<Position> Block::getCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];     //Calculates  position of block
    std::vector<Position> movedTiles;                       //Calculates already moved blocks.

    for(Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.col +colOffset);      //Does the actual moving of blocks
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}