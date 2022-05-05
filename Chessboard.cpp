#include "Chessboard.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;

Chessboard::Chessboard(){}

char Chessboard::numToLetter(int num) {
    return 'A' + num - 1;
}

Piece Chessboard::getBoard(int i, int j)
{
    return m_board[i][j];
    
}

ChessPieceColor Chessboard::GetPieceColorAtPos(const ChessPosition& pos) const
{
    return m_board[pos.getPosX()][pos.getPosY()].getColor();
    
}

ChessPieceType Chessboard::GetPieceTypeAtPos(const ChessPosition& pos) const
{
     return m_board[pos.getPosX()][pos.getPosY()].getType();
}

void Chessboard::LoadBoardFromFile(const string& path)
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

VecOfPositions Chessboard::GetValidMoves(const ChessPosition& pos)
{
    VecOfPositions validMoves;
        
       int x = pos.getPosX();
       int y = pos.getPosY();
        int i=1, j=1;
        bool final = false;
        
    
    switch (GetPieceTypeAtPos(pos)) {
        case 0:
            
           
            if(getBoard(x+1, y).getColor() != getBoard(x,y).getColor() && getBoard(x+1, y).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x+1);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
            }
            if(getBoard(x+1, y+1).getColor() != getBoard(x,y).getColor() && getBoard(x+1, y+1).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x+1);
                    p1.setPosY(y+1);
                    validMoves.push_back(p1);
            }
            if(getBoard(x+1, y-1).getColor() != getBoard(x,y).getColor() && getBoard(x+1, y-1).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x+1);
                    p1.setPosY(y-1);
                    validMoves.push_back(p1);
            }
            if(getBoard(x, y+1).getColor() != getBoard(x,y).getColor() && getBoard(x, y+1).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y+1);
                    validMoves.push_back(p1);
            }
            if(getBoard(x, y-1).getColor() != getBoard(x,y).getColor() && getBoard(x, y-1).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y-1);
                    validMoves.push_back(p1);
            }
            if(getBoard(x-1, y).getColor() != getBoard(x,y).getColor() && getBoard(x-1, y).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x-1);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
            }
            if(getBoard(x-1, y+1).getColor() != getBoard(x,y).getColor() && getBoard(x-1, y+1).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x-1);
                    p1.setPosY(y+1);
                    validMoves.push_back(p1);
            }
            if(getBoard(x-1, y-1).getColor() != getBoard(x,y).getColor() && getBoard(x-1, y-1).getType() != 0) {
                    ChessPosition p1;
                    p1.setPosX(x-1);
                    p1.setPosY(y-1);
                    validMoves.push_back(p1);
            }
            
            break;
            
        case 1:
            
            while(getBoard(x+i, y).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y).getType() != 0 && getBoard(x+i, y).getType() != 6 )
                { ChessPosition p1;
                    p1.setPosX(x+i);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
                    
                    final=true;}
                
                if(getBoard(x+i, y).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y);
                        validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x+i, y).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                i++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x-i, y).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x-i, y).getType() != 0 && getBoard(x-i, y).getType() != 6 )
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y);
                        validMoves.push_back(p1);
                    final=true;}
                
                if(getBoard(x-i, y).getType() == 6)
                {
                    ChessPosition p1;
                    p1.setPosX(x-i);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x-i, y).getType() == 0 )
                { final = true; }
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                i++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x, y+j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x, y+j).getType() != 0 && getBoard(x, y+j).getType() != 6 )
                {ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y+j);
                    validMoves.push_back(p1);
                
                    final=true;
                    
                }
                
                if(getBoard(x, y+j).getType() == 6)
                {
                    ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y+j);
                    validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x, y+j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x, y-j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x, y-j).getType() != 0 && getBoard(x, y).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x, y-j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);

                }
                
                if(getBoard(x, y-j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x+i, y+j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y+j).getType() != 0 && getBoard(x+i, y+j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y+j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x+i, y+j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y+j);
                        validMoves.push_back(p1);
                }
                
                if(getBoard(x+i, y+j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x-i, y+j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x-i, y+j).getType() != 0 && getBoard(x-i, y+j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y+j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x-i, y+j).getType() == 6)
                {
                    ChessPosition p1;
                    p1.setPosX(x-i);
                    p1.setPosY(y+j);
                    validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x-i, y+j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x+i, y-j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y-j).getType() != 0 && getBoard(x+i, y-j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x+i, y-j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                }
                
                if(getBoard(x+i, y-j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x-i, y-j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x-i, y-j).getType() != 0 && getBoard(x-i, y-j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x-i, y-j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                }
                
                if(getBoard(x-i, y-j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
                
            break;
        
        case 2:
            while(getBoard(x+i, y).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y).getType() != 0 && getBoard(x+i, y).getType() != 6 )
                { ChessPosition p1;
                    p1.setPosX(x+i);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
                    
                    final=true;}
                
                if(getBoard(x+i, y).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y);
                        validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x+i, y).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                i++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x-i, y).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x-i, y).getType() != 0 && getBoard(x-i, y).getType() != 6 )
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y);
                        validMoves.push_back(p1);
                    final=true;}
                
                if(getBoard(x-i, y).getType() == 6)
                {
                    ChessPosition p1;
                    p1.setPosX(x-i);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x-i, y).getType() == 0 )
                { final = true; }
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                i++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x, y+j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x, y+j).getType() != 0 && getBoard(x, y+j).getType() != 6 )
                {ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y+j);
                    validMoves.push_back(p1);
                
                    final=true;
                    
                }
                
                if(getBoard(x, y+j).getType() == 6)
                {
                    ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y+j);
                    validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x, y+j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x, y-j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x, y-j).getType() != 0 && getBoard(x, y).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x, y-j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);

                }
                
                if(getBoard(x, y-j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
        case 3:
            while(getBoard(x+i, y+j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y+j).getType() != 0 && getBoard(x+i, y+j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y+j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x+i, y+j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y+j);
                        validMoves.push_back(p1);
                }
                
                if(getBoard(x+i, y+j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x-i, y+j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x-i, y+j).getType() != 0 && getBoard(x-i, y+j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y+j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x-i, y+j).getType() == 6)
                {
                    ChessPosition p1;
                    p1.setPosX(x-i);
                    p1.setPosY(y+j);
                    validMoves.push_back(p1);
                    
                }
                
                if(getBoard(x-i, y+j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x+i, y-j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y-j).getType() != 0 && getBoard(x+i, y-j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x+i, y-j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x+i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                }
                
                if(getBoard(x+i, y-j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
            
            while(getBoard(x-i, y-j).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x-i, y-j).getType() != 0 && getBoard(x-i, y-j).getType() != 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                    
                        final=true;
                    
                }
                
                if(getBoard(x-i, y-j).getType() == 6)
                {
                    ChessPosition p1;
                        p1.setPosX(x-i);
                        p1.setPosY(y-j);
                        validMoves.push_back(p1);
                }
                
                if(getBoard(x-i, y-j).getType() == 0 )
                {final = true;}
                
                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}
                
                j++;
            }
            i=1;
            j=1;
            final = false;
                
            break;
            
        case 4:
            if(getBoard(x+1, y+2).getColor() != getBoard(x,y).getColor() && getBoard(x+1, y+2).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x+1);
                p1.setPosY(y+2);
                validMoves.push_back(p1);
                
            }
            if(getBoard(x+1, y-2).getColor() != getBoard(x,y).getColor() && getBoard(x+1, y-2).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x+1);
                p1.setPosY(y-2);
                validMoves.push_back(p1);
            }
            if(getBoard(x+2, y-1).getColor() != getBoard(x,y).getColor() && getBoard(x+2, y-1).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x+2);
                p1.setPosY(y-1);
                validMoves.push_back(p1);
                
            }
            if(getBoard(x+2, y+1).getColor() != getBoard(x,y).getColor() && getBoard(x+2, y+1).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x+2);
                p1.setPosY(y+1);
                validMoves.push_back(p1);
            }
            if(getBoard(x-1, y-2).getColor() != getBoard(x,y).getColor() && getBoard(x-1, y-2).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x-1);
                p1.setPosY(y-2);
                validMoves.push_back(p1);
            }
            if(getBoard(x-1, y+2).getColor() != getBoard(x,y).getColor() && getBoard(x-1, y+2).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x-1);
                p1.setPosY(y+2);
                validMoves.push_back(p1);
            }
            if(getBoard(x-2, y+1).getColor() != getBoard(x,y).getColor() && getBoard(x-2, y+1).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x-2);
                p1.setPosY(y+1);
                validMoves.push_back(p1);
            }
            if(getBoard(x-2, y-1).getColor() != getBoard(x,y).getColor() && getBoard(x-2, y-1).getType() != 0)
            {
                ChessPosition p1;
                p1.setPosX(x-2);
                p1.setPosY(y-1);
                validMoves.push_back(p1);
            }
            
            break;
            
        case 5:
            if (getBoard(x, 1).getColor()==0)
            {
                ChessPosition p1;
                p1.setPosX(x);
                p1.setPosY(3);
                validMoves.push_back(p1);
                
            }
                if(getBoard(x, y).getColor()==0)
                {
                    if (getBoard(x+1, y+1).getColor()==1)
                    {
                        ChessPosition p1;
                        p1.setPosX(x+1);
                        p1.setPosY(y+1);
                        validMoves.push_back(p1);
                    }
                    if (getBoard(x+1, y-1).getColor()==1)
                    {
                        ChessPosition p1;
                        p1.setPosX(x+1);
                        p1.setPosY(y-1);
                        validMoves.push_back(p1);
                        
                    }
                    if (getBoard(x, y-1).getColor() ==3)
                    {
                        ChessPosition p1;
                        p1.setPosX(x);
                        p1.setPosY(y-1);
                        validMoves.push_back(p1);
                    }
                }
            
            if (getBoard(x, 6).getColor()==1)
            {
                ChessPosition p1;
                p1.setPosX(x);
                p1.setPosY(4);
                validMoves.push_back(p1);
                
            }
            
                if(getBoard(x, y).getColor()==1)
                {
            
                    if (getBoard(x+1, y-1).getColor()==0)
                    {
                        ChessPosition p1;
                        p1.setPosX(x+1);
                        p1.setPosY(y-1);
                        validMoves.push_back(p1);
                    }
                    if (getBoard(x-1, y+1).getColor()==0)
                    {
                        ChessPosition p1;
                        p1.setPosX(x-1);
                        p1.setPosY(y+1);
                        validMoves.push_back(p1);
                    }
                    if (getBoard(x, y-1).getColor()==3)
                    {
                        ChessPosition p1;
                        p1.setPosX(x);
                        p1.setPosY(y-1);
                        validMoves.push_back(p1);
                    }
                }
        
    }
    
    
    
    
    return validMoves;
}

string Chessboard::ToString() {
    string res;
    for(int i = 0; i < 8; i++) {
        res.append(to_string(8 - i) + " "); // cout << 8 - i << " ";
        for(int j = 0; j < 8; j++) {
            res.append(getBoard(i, j).ConvertToString() + " "); // cout << m_board[i][j].ConvertToString() << " ";
        }
        if (i == 7) {
            res.append("\n  "); // cout << endl << "  ";
            for(int m = 1; m <= 8; m++) {
                string letter = "";
                letter += numToLetter(m);
                res.append(letter + "  "); // cout << numToLetter(m) << "  ";
            }
        }
        res.append("\n"); // cout << endl;
    }
    return res;
}


bool Chessboard::MovePiece(const ChessPosition& posFrom, const ChessPosition& posTo) {
    bool isMoved = false;
    VecOfPositions available = GetValidMoves(posFrom);

    int x1 = posFrom.getPosY();
    int y1 = posFrom.getPosX();

    int x2 = posTo.getPosY();
    int y2 = posTo.getPosX();

    Piece buffer = m_board[x1][y1];

    for (ChessPosition p : available) {
        if (p.getPosX() == posTo.getPosX() && p.getPosY() == posTo.getPosY()) {
            isMoved = true;
            m_board[x1][y1] = Piece();
            m_board[x2][y2] = buffer;
            break;
        }
    }

    return isMoved;
}




