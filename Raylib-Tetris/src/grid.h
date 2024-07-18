#pragma once //program for only included once 
#include <vector>
#include <raylib.h>

class Grid{
    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors; //Array that houses vector of colors
        bool isRowFull(int row);
        
        void moveRowDown(int row, int compRows);

    public:
        Grid();
        void clearRow(int row); //IS PRIVATE IN TUTORIAL
        void Initialize();
        void print();
        void draw();
        bool isCellOutside(int row, int col);
        bool IsCellEmpty(int row, int col);
        int ClearFullRows();
        int grid[20][10]; // 20 cols, 10 rows
};