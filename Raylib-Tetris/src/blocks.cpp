#include "block.h"
#include "pos.h"

class LBlock : public Block{        //inherited public functions from Block
    public:
    LBlock(){
        id = 1;
        cells[0] = {Position(0,2),Position(1,0),Position(1,1),Position(1,2)};   //At rotation 0, these are the cell positions of the L block
        cells[1] = {Position(0,1),Position(1,1),Position(2,1),Position(2,2)};   //Think of rotations not on a lar scale, but on a grid just small enough to contain all rotations of this block!
        cells[2] = {Position(2,0),Position(1,0),Position(1,1),Position(1,2)}; 
        cells[3] = {Position(0,0),Position(0,1),Position(1,1),Position(2,1)}; 
        Move(0,3);  //Initializes the block in the center, tetris-fashion.
    }
};

class JBlock : public Block{       
    public:
    JBlock(){
        id = 2;
        cells[0] = {Position(0,0),Position(1,0),Position(1,1),Position(1,2)};   //At rotation 0, these are the cell positions of the L block
        cells[1] = {Position(0,1),Position(0,2),Position(1,1),Position(2,1)};   
        cells[2] = {Position(1,0),Position(1,1),Position(1,2),Position(2,2)}; 
        cells[3] = {Position(0,1),Position(1,1),Position(2,0),Position(2,1)}; 
        Move(0,3);
    }
};

class IBlock : public Block{       
    public:
    IBlock(){
        id = 3;
        cells[0] = {Position(1,0),Position(1,1),Position(1,2),Position(1,3)};   //At rotation 0, these are the cell positions of the L block
        cells[1] = {Position(0,2),Position(1,2),Position(2,2),Position(3,2)};  
        cells[2] = {Position(2,0),Position(2,1),Position(2,2),Position(2,3)}; 
        cells[3] = {Position(0,1),Position(1,1),Position(2,1),Position(3,1)}; 
        Move(-1,3);
    }
};
 
class OBlock : public Block{        
    public:
    OBlock(){
        id = 4;
        cells[0] = {Position(0,0),Position(0,1),Position(1,0),Position(1,1)};
        Move(0,4);   //At rotation 0, these are the cell positions of the L block 
    }
};

class SBlock : public Block{       
    public:
    SBlock(){
        id = 5;
        cells[0] = {Position(0,1),Position(0,2),Position(1,0),Position(1,1)};   //At rotation 0, these are the cell positions of the L block
        cells[1] = {Position(0,1),Position(1,1),Position(1,2),Position(2,2)};   
        cells[2] = {Position(1,1),Position(1,2),Position(2,0),Position(2,1)}; 
        cells[3] = {Position(0,0),Position(1,0),Position(1,1),Position(2,1)}; 
        Move(0,3);
    }
};

class TBlock : public Block{        
    public:
    TBlock(){
        id = 6;
        cells[0] = {Position(0,1),Position(1,0),Position(1,1),Position(1,2)};   //At rotation 0, these are the cell positions of the L block
        cells[1] = {Position(0,1),Position(1,1),Position(1,2),Position(2,1)};   
        cells[2] = {Position(1,0),Position(1,1),Position(1,2),Position(2,1)}; 
        cells[3] = {Position(0,1),Position(1,0),Position(1,1),Position(2,1)}; 
        Move(0,3);
    }
};

class ZBlock : public Block{       
    public:
    ZBlock(){
        id = 7;
        cells[0] = {Position(0,0),Position(0,1),Position(1,1),Position(1,2)};   //At rotation 0, these are the cell positions of the L block
        cells[1] = {Position(0,2),Position(1,1),Position(1,2),Position(2,1)};   
        cells[2] = {Position(1,0),Position(1,1),Position(2,1),Position(2,2)}; 
        cells[3] = {Position(0,1),Position(1,0),Position(1,1),Position(2,0)}; 
        Move(0,3);
    }
};

//51:45