//
// Created by studi on 01.05.2022.
//

#ifndef IGOR_SHIT_PIECE_H
#define IGOR_SHIT_PIECE_H

#include <string>

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
private:
    ChessPieceType m_type;
    ChessPieceColor m_color;
public:
    Piece();
    void setType(ChessPieceType type) { this->m_type = type; }
    void setColor(ChessPieceColor color) { this->m_color = color; }
    int getType() { return m_type; }
    int getColor() { return m_color; }
    string ToString();
    string igorToString();
};


#endif //IGOR_SHIT_PIECE_H
