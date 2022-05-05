#ifndef Chessboard_hpp
#define Chessboard_hpp

#include <stdio.h>
#include <cstring>
#include "Piece.h"
#include "GameInfo.h"



class Chessboard {

public:
    Chessboard();

    Piece getBoard(int, int);

    void            LoadBoardFromFile(const string& path);
    VecOfPositions  GetValidMoves (const ChessPosition& pos);
    bool            MovePiece (const ChessPosition& posFrom, const  ChessPosition& posTo);
    string          ToString ();
    ChessPieceColor GetPieceColorAtPos(const ChessPosition& pos) const;
    ChessPieceType GetPieceTypeAtPos(const ChessPosition& pos) const;
    char numToLetter(int num);
    
private:
    Piece m_board[NUM_COLS][NUM_ROWS];
    
};


#endif /* Chessboard_hpp */

