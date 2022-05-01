//
// Created by studi on 01.05.2022.
//

#ifndef IGOR_SHIT_CHESSPOSITION_H
#define IGOR_SHIT_CHESSPOSITION_H

#include <string>

using namespace std;

class ChessPosition {

public:
    ChessPosition(){m_posX=0; m_posY=0;}
    ChessPosition(string posicio);

    void setPosX(int posxnew){m_posX = posxnew;}
    void setPosY(int posynew){m_posY = posynew;}

    int getPosX() {return m_posX;}
    int getPosY() {return m_posY;}

    bool operator == (ChessPosition& pos1);
    void operator << (ChessPosition& pos);

private:
    int m_posX; //Column
    int m_posY; //Row


};


#endif //IGOR_SHIT_CHESSPOSITION_H
