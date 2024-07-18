#pragma once
#include "grid.h"
#include "blocks.cpp"
class Game
{
private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    bool isBlockOutside();
    void LockBlock();
    bool blockFits();
    void Reset();
    void updateScore(int LinesCleared, int moveDownPoints);

    void moveLeft();
    void moveRight();
    
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();

public:
    Game();
    void draw();
    void handleInput();
    void hardDrop();
    void moveDown();
    void rotateBlock();
    Grid grid;
    bool gameOver;
    int score;
    ~Game();
    //Music Music;
    //Sound rotateSound;
    //Sound clearSound;
};