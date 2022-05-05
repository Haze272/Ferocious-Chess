#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>

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
    void setType(ChessPieceType);
    void setColor(ChessPieceColor);
    ChessPieceType getType() const;
    ChessPieceColor getColor() const;
    string ConvertToString();

private:
    ChessPieceType  m_type;
    ChessPieceColor m_color;
};


#endif /* Piece_hpp */
