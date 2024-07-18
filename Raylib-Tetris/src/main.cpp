#include <iostream>
#include <raylib.h>
#include "game.h" 
#include "colors.h"             

double LastUpdateTime = 0;

bool eventTriggered(double interval)
{
     double currentTime = GetTime();
     if(currentTime - LastUpdateTime >= interval)//Checks if the difference is >= interval in seconds, the interval has passed since last update
     {
          LastUpdateTime = currentTime;
          return true;
     }
     return false;
}

int main()
{
     InitWindow(500,600,"Tetris"); //width,height,title

     SetTargetFPS(60);

     Font font = LoadFontEx("Font/heboris-nullpomino.ttf", 64, 0, 0);           //Declaring a font:Font (name) = LoadFontEx(file path to .ttf, size, x, x)

      
     Game game = Game();

     //TBlock block = TBlock();                      //Initializes T-Block
     //block.Move(4,3);                              //Moves the block 4 units down, and 3 units right.

     while(WindowShouldClose() == false)//GAME LOOP
     {
          UpdateMusicStream(game.Music);
          game.handleInput();
          if(eventTriggered(0.5))//Every eventTriggered(x) seconds the block moves down automatically
          {
               game.moveDown();
          }
          

          BeginDrawing();
          ClearBackground(bgdarkBlue);

          //DRAWING BASIC TEXT/SHAPES
          DrawTextEx(font, "SCORE ",{325, 15}, 21, 2, WHITE);  //For implimenting font/text: DrawTextEx(font, text, vector pos(X,Y), spacing, color)
          DrawTextEx(font, "NEXT ",{325, 175}, 21, 2, WHITE);  
          
          DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);//Rectangle: ({rectangle = x,y, width, height}, roundness, segments, color)
          DrawTextEx(font, "SCORE ",{325, 15}, 21, 2, WHITE);


          //DRAWING SCORE
          char scoreText[10]; // score to char array
          sprintf(scoreText, "%d", game.score);
          Vector2 textSize = MeasureTextEx(font, scoreText, 21, 2); //creates a vector2 which returns the width and height
          
          DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 21, 2, WHITE); // We use 320 + 170 - textSize width to accuratley place the changing width of the score text
          DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

          
          game.draw();

          if(game.gameOver)
          {
               DrawTextEx(font, "GAME OVER ",{30, 100}, 21, 2, WHITE);
          }
          

          EndDrawing();
     }

     CloseWindow();
     return 0;
}