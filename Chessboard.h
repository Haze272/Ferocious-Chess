//
// Created by studi on 01.05.2022.
//

#ifndef IGOR_SHIT_CHESSBOARD_H
#define IGOR_SHIT_CHESSBOARD_H


#include "Piece.h"
#include "ChessPosition.h"
#include "GameInfo.h"

#include <stdio.h>
#include <cstring>
#include "Piece.h"
#include "GameInfo.h"



class Chessboard {

public:
    Chessboard();

    Piece getBoard(int i, int j){return m_board[i][j];}

    void            LoadBoardFromFile(string& path);
    VecOfPositions  GetValidMoves (ChessPosition& pos);
    bool            MovePiece (ChessPosition& posFrom, ChessPosition& posTo);
    string          ToString ();
    ChessPieceColor GetPieceColorAtPos(ChessPosition& pos);
    ChessPieceType  GetPieceTypeAtPos(ChessPosition& pos);

    // ESTEBAN
    void addFigure(Piece piece, int x, int y);
    char numToLetter(int govno);

private:
    Piece m_board[NUM_COLS][NUM_ROWS];

};

#endif //IGOR_SHIT_CHESSBOARD_H
