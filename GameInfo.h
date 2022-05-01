//
// Created by studi on 01.05.2022.
//

#ifndef IGOR_SHIT_GAMEINFO_H
#define IGOR_SHIT_GAMEINFO_H

#include <vector>
#include "ChessPosition.h"

struct Direction {
    int dirX;
    int dirY;
};

const int NUM_COLS = 8;
const int NUM_ROWS = 8;


typedef vector<ChessPosition> VecOfPositions;

#endif //IGOR_SHIT_GAMEINFO_H
