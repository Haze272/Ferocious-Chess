//
//  Chessboard.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include "Chessboard.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

ChessPieceColor Chessboard::GetPieceColorAtPos(const ChessPosition& pos) const
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

ChessPieceType Chessboard::GetPieceTypeAtPos(const ChessPosition& pos) const
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






//VecOfPositions Chessboard::GetValidMoves(const ChessPosition& pos) const
//{
    
    
            // Cavall/Knight
    //DESC: se suma/resta 1 en una direccio i se suma/resta 2 en una altra. Despres es canvies direccions i es repeteix el proces,  doncs tenim una forma de "L", com a maxim hi haura 8 quadrats.
    
    //Torre/Rook
    //DESC: búsqueda per columna i fila, des de origen (posició de la figura), sumant/restant 1 en un en totes direccions verticals i horizontals. Es fan quatre bucles, vertical positiu i negatiu, horitzontal positiu i negatiu. Com a resultat es dona seguit de vectors cap a posicions disponibles
    
    //Rei/King
    //DESC: búsqueda dels 8 quadrats al voltant del rei.
    
    //Alfil/Bishop
    //DESC: se suma/resta 1 a totes dues direccions i despres se suma/resta 1 a totes dues altres direccions. Busquem les diagonals.
    
    //Peon/Pawn
    //DESC: Si es el primer moviment d'aquest concret peo, hi ha oportunitat d'anar 2 quadrats endavant, despres un. Per matar una altra peca (d'un altre color) ha d'estar a una quadrat en diagonal endavant. Al final de taulell pot convertirse en una altra peca.
    
    //Dama/Queen
    //DESC: Combinacio de torre i alfil.
    
    // Per a totes les peces, el moviment acaba davant de la peca del mateix color o fi del taulell, o be es pot matar la figura d'un altre color.
    
    //Parameters: columna i fila d'origen, bool per dir si esta ocupat el quadrat i int per dir el color de la peca en quadrat ocupat.
    //Subfunctions: busquedavertical (positiva, negativa), busquedadiagonal(en un sentido y otro, (positiva, negativa)), busqueda horitzontal((positiva, negativa)), jaque (si el rei pot moure's o nee)
    
    // Per a fer l'enroc, el primer moviment dels peons i en peassant necessitem movecounter. Perque aquests moviments es poden fer com a primer moviment de la peca.
  
    // Per a la transformacio del peo, es forcara la transformacio de peo a la reina, ja que es practica habitual. Tot i que en alguns casos particulars es necessari la conversio al cavall (underpromoting).
    
    // Si un costat unicament te el rei al taulell, es el seu torn, no esta en jaque i no pot moure's; doncs aixo es un empat. Un costat guany nomes si rei esta en jaque i no pot moures's, ni parar el jaque amb una altra figura.
    
    // Si hi ha una figura que protegeix el rei del jaque, doncs aquesta no pot moure's.
    
//}

