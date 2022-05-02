//
// Created by studi on 01.05.2022.
//

#include "Piece.h"

using namespace std;

Piece::Piece() {
    m_type = CPT_EMPTY;
    m_color = CPC_NONE;
}

string Piece::ConvertToString()
{
    string pieza;
    string str1, str2;

    switch (getType())
    {
        case CPT_King: str1 = 'R'; break;
        case CPT_Queen: str1 = 'D'; break;
        case CPT_Rook: str1 = 'T'; break;
        case CPT_Bishop: str1 = 'A'; break;
        case CPT_Knight: str1 = 'C'; break;
        case CPT_Pawn: str1 = 'P'; break;
        case CPT_EMPTY: str1= '_'; break;

    }
    switch (getColor())
    {
        case CPC_Black: str2 = 'N'; break;
        case CPC_White: str2 = 'B'; break;
        case CPC_NONE: str2 = '_'; break;
    }

    pieza = str1 + str2;

    return pieza;
}

// сделать reset функцию