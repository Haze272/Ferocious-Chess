//
// Created by studi on 01.05.2022.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "Chessboard.h"

using namespace std;

ChessPieceColor Chessboard::GetPieceColorAtPos(ChessPosition& pos)
{
    int i,j;

    i= pos.getPosX();
    j= pos.getPosY();

    switch(m_board[i][j].getColor())
    {
        case 0: return CPC_White;
            break;
        case 1: return CPC_Black;
            break;
        default: return CPC_NONE;
            break;
    }


}

ChessPieceType Chessboard::GetPieceTypeAtPos(ChessPosition& pos)
{
    int i,j;

    i= pos.getPosX();
    j= pos.getPosY();

    switch(getBoard(i,j).getType())
    {
        case 0: return CPT_King;
            break;
        case 1: return CPT_Queen;
            break;
        case 2: return CPT_Rook;
            break;
        case 3: return CPT_Bishop;
            break;
        case 4: return CPT_Knight;
            break;
        case 5: return CPT_Pawn;
            break;
        default: return CPT_EMPTY;
            break;
    }
}

void Chessboard::LoadBoardFromFile(string& path)
{
    ifstream fitxer;
    string linia;
    fitxer.open(path);


    if(fitxer.is_open())
    {

        while(!fitxer.eof())
        {
            getline(cin,linia);

            int n = linia.length();
            char coordenades[n];
            int fila, columna;


            strcpy(coordenades, linia.c_str());


            switch(coordenades[n-1])
            {
                case '1': fila = 7;
                    break;
                case '2': fila = 6;
                    break;
                case '3': fila = 5;
                    break;
                case '4': fila = 4;
                    break;
                case '5': fila = 3;
                    break;
                case '6': fila = 2;
                    break;
                case '7': fila = 1;
                    break;
                case '8': fila = 0;
                    break;
            }


            switch(coordenades[n-2])
            {
                case 'a': columna = 0;
                    break;
                case 'b': columna = 1;
                    break;
                case 'c': columna = 2;
                    break;
                case 'd': columna = 3;
                    break;
                case 'e': columna = 4;
                    break;
                case 'f': columna = 5;
                    break;
                case 'g': columna = 6;
                    break;
                case 'h': columna = 7;
                    break;
            }

            switch (coordenades[0])
            {
                case 0: m_board[columna][fila].setColor(CPC_White);
                    break;
                case 1: m_board[columna][fila].setColor(CPC_Black);
                    break;

            }

            switch(coordenades[n-3])
            {
                case 'R': m_board[columna][fila].setType(CPT_King);
                    break;
                case 'D': m_board[columna][fila].setType(CPT_Queen);
                    break;
                case 'T': m_board[columna][fila].setType(CPT_Rook);
                    break;
                case 'A': m_board[columna][fila].setType(CPT_Bishop);
                    break;
                case 'C': m_board[columna][fila].setType(CPT_Knight);
                    break;
                case 'P': m_board[columna][fila].setType(CPT_Pawn);
                    break;

            }
        }
        fitxer.close();

    }
}