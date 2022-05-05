#ifndef ChessPosition_hpp
#define ChessPosition_hpp

#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

class ChessPosition {

public:
    ChessPosition(){m_posX=0; m_posY=0;}
    ChessPosition(const string posicio);
    void setPosX(const int posxnew){m_posX = posxnew;}
    void setPosY(const int posynew){m_posY = posynew;}
    int getPosX() const {return m_posX;}
    int getPosY() const {return m_posY;}
    bool operator== (const ChessPosition& pos1) const;
    void operator<< (ChessPosition& pos);
    
private:
    int m_posX; //Column
    int m_posY; //Row
    
    
};


#endif /* ChessPosition_hpp */
