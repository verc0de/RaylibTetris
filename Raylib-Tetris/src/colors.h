#pragma once
#include <raylib.h>
#include <vector>

//'extern' keyword allows us to identify this here and use it across other files

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color bgdarkBlue;

std::vector<Color> getCellColors();





