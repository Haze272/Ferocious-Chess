//
//  Chessboard.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef Chessboard_hpp
#define Chessboard_hpp

#include <stdio.h>
#include <cstring>
#include "Piece.hpp"
#include "GameInfo.h"



class Chessboard {

public:
    Chessboard();

    Piece getBoard(int i, int j){return m_board[i][j];}

    void            LoadBoardFromFile(const string& path);
    VecOfPositions  GetValidMoves (const ChessPosition& pos) const;
    bool            MovePiece (const ChessPosition& posFrom, const  ChessPosition& posTo);
    string          ToString () const;
    ChessPieceColor GetPieceColorAtPos(const ChessPosition& pos) const;
    ChessPieceType GetPieceTypeAtPos(const ChessPosition& pos) const;
    
    
private:
    Piece m_board[NUM_COLS][NUM_ROWS];
    
};


#endif /* Chessboard_hpp */
