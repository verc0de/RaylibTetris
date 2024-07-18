#include <iostream>
#include "grid.h"
#include "colors.h"
// THINGS TO ADD:
// Back-to-back's
// Finish SFX
// Color changes

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 29; //30 px
    Initialize();
    colors = getCellColors();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
                grid[row][col] = 0;
        }
    }
}

void Grid::print()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            std::cout<< grid[row][col] <<" ";
        }
        std::cout<<std::endl;
    }
}


void Grid::draw()
{
    for(int row=0; row<numRows; row++)
    {
        for (int col=0; col<numCols; col++)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 10, row * cellSize +10 ,  cellSize-1, cellSize-1, colors[cellValue]);     //Args: x pos, y pos, width, height, color
        }
    }

}

bool Grid::isCellOutside(int row, int col)
{
    if(row >= 0 && row < numRows && col >=0 && col < numCols)
    {
       return false; 
    }
    else
    {
        return true;
    }
    
}

bool Grid::IsCellEmpty(int row, int col)
{
    if(grid[row][col]==0)
    {
        return true;
    }
    else
    {
        return false; 
    }
    
}

int Grid::ClearFullRows()
{
    int completed = 0;

    for(int row = numRows-1; row>=0; row--)//Parses through rows down up( remember: the bottom-right square = Pos(20,10))
    {
        if(isRowFull(row))
        {
            clearRow(row);
            completed++;
        }
        else if(completed > 0)
        {
            moveRowDown(row,completed);//Moves down this row, by # of completed rows before it
        }
    }
    return  completed;
}

bool Grid::isRowFull(int row)
{
    for(int col = 0; col < numCols; col++)//Iterates through every block state in a row: if any state in the row==0, outputs false
    {
        if(grid[row][col]==0)
        {
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row][col]=0;
        
    }
}

void Grid::moveRowDown(int row, int compRows)
{
    for(int col = 0; col < numCols; col++)
    {
        grid[row+compRows][col] = grid[row][col];  //Moves rows down by # of completed rows (compRows), copies the non-completed rows to the positions of the just completed rows
        grid[row][col] = 0;//Clears completed row
        
        
    }
}