#include "ChessPosition.hpp"
#include "GameInfo.h"
#include <iostream>
#include <string>
#include <cstring>


ChessPosition::ChessPosition(string posicio)
{
    
    int n = posicio.length();
    char coordenades[n];
     
        strcpy(coordenades, posicio.c_str());
    
    
    switch(coordenades[n-1])
    {
        case '1': setPosY(7);
            break;
        case '2': setPosY(6);
            break;
        case '3': setPosY(5);
            break;
        case '4': setPosY(4);
            break;
        case '5': setPosY(3);
            break;
        case '6': setPosY(2);
            break;
        case '7': setPosY(1);
            break;
        case '8': setPosY(0);
            break;
    }
    
    switch(coordenades[n-2])
    {
        case 'a': setPosX(0);
            break;
        case 'b': setPosX(1);
            break;
        case 'c': setPosX(2);
            break;
        case 'd': setPosX(3);
            break;
        case 'e': setPosX(4);
            break;
        case 'f': setPosX(5);
            break;
        case 'g': setPosX(6);
            break;
        case 'h': setPosX(7);
            break;
    }
    
    
}

void ChessPosition::operator<<(ChessPosition& pos)
{
    string posicio;
    char columna;
    int fila;
    
    posicio= "";
    
    switch (getPosX())
    {
        case 0: columna = 'a';
        case 1: columna = 'b';
        case 2: columna = 'c';
        case 3: columna = 'd';
        case 4: columna = 'e';
        case 5: columna = 'f';
        case 6: columna = 'g';
        case 7: columna = 'h';
    }
    
    fila = getPosY() + 1;
    
    
    
    posicio += to_string(columna);
    posicio += to_string(fila);
    
    cout << posicio;
}


 bool ChessPosition::operator==(const ChessPosition& pos1) const
{
     return(getPosX() == pos1.getPosX() && getPosY() == pos1.getPosY());
}




/* Coordinate system:
    Y (rows)
  . ^
  . |  ***Black***
  4 |
  3 |
  2 |
  1 |  ***White***
 (0,0)----------> X (cols)
      a b c ...
*/

