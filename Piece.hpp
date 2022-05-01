//
//  Piece.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include "GameInfo.h"

using namespace std;

typedef enum {
    CPT_King,
    CPT_Queen,
    CPT_Rook,
    CPT_Bishop,
    CPT_Knight,
    CPT_Pawn,
    CPT_EMPTY
} ChessPieceType;

typedef enum {
    CPC_Black,
    CPC_White,
    CPC_NONE
} ChessPieceColor;



class Piece {

public:
    Piece();
    void setType(ChessPieceType type){ m_type = type;}
    void setColor(ChessPieceColor color){ m_color = color;}
    int getType(){ return m_type;} const
    int getColor(){ return m_color;} const    
    
   const string ConvertToString();

private:
    ChessPieceType  m_type;
    ChessPieceColor m_color;
};


#endif /* Piece_hpp */
