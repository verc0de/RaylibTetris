#include "game.h"
#include <random>



Game::Game()
{
    grid = Grid();
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
    score = 0;
    InitAudioDevice();  //Sets up audio device
    Music = LoadMusicStream("Sounds/Connected (Yours Forever).mp3");
    PlayMusicStream(Music);
    rotateSound = LoadSound("Sounds/Vine Boom Sound Effect.mp3");
    clearSound = LoadSound("Sounds/tetris_game_boy_line_clear_sound_effects.mp3");

}

Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(Music);
    CloseAudioDevice();
}
Block Game::getRandomBlock()
{
    if(blocks.empty())
    {
        blocks = getAllBlocks();   
    }
    int randomIndex = rand() % blocks.size(); //returns a value from 0-6, whihc is used as the random block id in the blocks vector
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin()+randomIndex);//deletes the  chosen block from the vector so that it cannot be chosen again
    return block;
}

std::vector<Block> Game::getAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(),TBlock(), ZBlock()}; //refills blocks vector 
}

void Game::draw()
{
    grid.draw();
    currentBlock.draw(10, 10);

    switch(nextBlock.id)//Displayes  next blokc in "next"
    {
        case 3:// I Block
        nextBlock.draw(265, 280);
        break;

        case 4: //O Block
        nextBlock.draw(255, 270);
        break;

        default:
        nextBlock.draw(270,270);    
        break;
    }
    
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();//raylib command 
    if(gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    
    switch(keyPressed)
    {
        case KEY_LEFT:
        case KEY_A:
            moveLeft();
            break;
        case KEY_RIGHT:   
        case KEY_D:
            moveRight();
            break;
        case KEY_DOWN:
        case KEY_S:
            moveDown();
            updateScore(0,1);
            break;
        case KEY_UP:
        case KEY_W:
            hardDrop();
            break;
        case KEY_LEFT_SHIFT:
        case KEY_E:
            rotateBlock();
            break;
    }
}

void Game::moveLeft()
{
    if(!gameOver)
    {
        currentBlock.Move(0,-1);
        if(isBlockOutside() || blockFits() == false)
        {
            currentBlock.Move(0,1); //Boundary check that moves block back to original pos
        }
    }
    
}

void Game::moveRight()
{
    if(!gameOver)
    {
        currentBlock.Move(0,1);
        if(isBlockOutside() || blockFits() == false)
        {
            currentBlock.Move(0,-1);
        }
    }
}

void Game::hardDrop() //CODED W/O TUTORIAL
{   
    if(!gameOver)
    {
        while(blockFits() == true && isBlockOutside() == false)
        {
            currentBlock.Move(1,0);
            updateScore(0,1);
        }
        if(isBlockOutside() || blockFits() == false)
        {
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}

void Game::moveDown()
{
    if(!gameOver)
    {
        currentBlock.Move(1,0);
        if(isBlockOutside() || blockFits() == false)
        {
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
}

//BOUNDARY CHECKS
void Game::rotateBlock()
{
    if(!gameOver)
    {
        currentBlock.rotate();
        if(isBlockOutside() || blockFits() == false)
        {
            currentBlock.undoRotate();
        }
        else{
            PlaySound(rotateSound);
        }
        
    }
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item : tiles)    //this loops through each tiles in a block
    {
        if(grid.isCellOutside(item.row, item.col))
        {
            return true;
        }
    }
    return false;
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles)           //Loops through position of every tile in this block
    {
        grid.grid[item.row][item.col]=currentBlock.id;  //Changes grid values at (x,y) from 0 to id to "place" the blocks
    }
    currentBlock = nextBlock;           //sets new current block to null

    if(!blockFits())
    {
        gameOver = true;
    }
    nextBlock =  getRandomBlock();      //sets next block to one of the random blocks in queue
    int rowsCleared = grid.ClearFullRows();
    if (rowsCleared>0)
    {
        PlaySound(clearSound);
        updateScore(rowsCleared, 0);
    }
    
  
}

bool Game::blockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for(Position item: tiles)
    {
        if(grid.IsCellEmpty(item.row, item.col)==false)  //checks is pos of NEW block's tiles are alr occupied (if they are, returns false, undoes changes) 
        {
            return false;
        }
    }
    return true;
}


void Game::Reset()
{

    grid.Initialize();          //Resets grid for next play
    blocks = getAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    score = 0;


    /* Instead of doing all this, just reset the entire grid to 0 forehead
    //1:37:50, but try the game over yourself
    std::vector<Position> tiles = currentBlock.getCellPositions();
     for(Position item: tiles)
    {
        if(grid.IsCellEmpty(item.row, item.col)==false)  //checks is pos of NEW block's tiles are alr occupied (if they are, returns false, undoes changes) 
        {
            return true;
        }
    }
    return false;
    */
}

void Game::updateScore(int LinesCleared, int moveDownPoints)
{
    switch(LinesCleared)
    {
        //One-Line Clears
        case 1:
        score += 100;
        break;

        //Two-Line Clears
        case 2:
        score +=  200;
        break;

        //Three-Line Clears
        case 3:
        score += 500;
        break;

        //Tetris
        case 4:
        score +=  1000;
        break;

        default:
        score += moveDownPoints;
        break;

        

    }
}
