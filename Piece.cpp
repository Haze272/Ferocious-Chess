//
// Created by studi on 01.05.2022.
//

#include "Piece.h"

using namespace std;

Piece::Piece() {
    m_type = CPT_EMPTY;
    m_color = CPC_NONE;
}

string Piece::ToString() {
    string pieza = "";

    switch (this->getType()) {
        case 0:
            pieza.append(1, 'R');
            break;
        case 1:
            pieza.append(1, 'D');
            break;
        case 2:
            pieza.append(1, 'T');
            break;
        case 3:
            pieza.append(1, 'A');
            break;
        case 4:
            pieza.append(1, 'C');
            break;
        case 5:
            pieza.append(1, 'P');
            break;
        default:
            pieza.append(1, '*');
            break;
    }

    switch (this->getColor()) {
        case 0:
            pieza.append(1, 'N');
            break;
        case 1:
            pieza.append(1, 'B');
            break;
        default:
            pieza.append(1, '*');
            break;

    }

    return pieza;
}

string Piece::igorToString() {
    string pieza;
    string str1, str2;

    switch (this->getType()) {
        case 0: str1 = 'R'; break;
        case 1: str1 = 'D'; break;
        case 2: str1 = 'T'; break;
        case 3: str1 = 'A'; break;
        case 4: str1 = 'C'; break;
        case 5: str1 = 'P'; break;
        default: str1 = '*'; break;
    }

    switch (this->getColor()) {
        case 0: str2 = 'N'; break;
        case 1: str2 = 'B'; break;
        default: str2 = '*'; break;
    }

    pieza = str1 + str2;
    return pieza;
}