#pragma once
#include <vector>
#include <map>
#include "pos.h"
#include "colors.h"

class Block{
    private:    
        int cellSize;
        int rotationState;   
        std::vector<Color> colors;
        int rowOffset;
        int colOffset;
    public:
        Block();
        void draw(int offx, int offy);
        void Move(int rowOffset, int colOffset);
        void rotate();
        void undoRotate();
        std::vector<Position> getCellPositions();
        int id;
        std::map<int, std::vector<Position>> cells;
        

};

