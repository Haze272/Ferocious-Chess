//
// Created by studi on 01.05.2022.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "Chessboard.h"

using namespace std;

// ------------------- ESTEBAN
void Chessboard::addFigure(Piece piece, int x, int y) {
    m_board[x][y] = piece;
}


// Метод для переработки цифер в буквы (блять ну лень писать ифы нахуй)
char Chessboard::numToLetter(int govno) {
    return 'A' + govno - 1;
}
Chessboard::Chessboard() {}
// ------------------- ESTEBAN END


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

VecOfPositions Chessboard::GetValidMoves(ChessPosition& pos)
{
    /*
    ChessPosition p1;
    p1->setPosX(letter);
    p1->setPosY(digit);
    validMoves->push_back(*p1);
    */
    VecOfPositions validMoves;

    int x = pos.getPosX();
    int y = pos.getPosY();
    int i=1, j=1;
    bool final = false;

    string tempResult;

    switch (GetPieceTypeAtPos(pos)) {
        case 0:

            if(getBoard(x+1, y).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x+1, y).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x+1);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x+1, y+1).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x+1, y+1).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x+1);
                    p1.setPosY(y+1);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x+1, y-1).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x+1, y-1).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x+1);
                    p1.setPosY(y-1);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x, y+1).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x, y+1).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y+1);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x, y-1).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x, y-1).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x);
                    p1.setPosY(y-1);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x-1, y).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x-1, y).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x-1);
                    p1.setPosY(y);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x-1, y+1).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x-1, y+1).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x-1);
                    p1.setPosY(y+1);
                    validMoves.push_back(p1);
                }
            }
            if(getBoard(x-1, y-1).getColor() != getBoard(x,y).getColor()) {
                if (getBoard(x-1, y-1).ConvertToString() == "__") {
                    ChessPosition p1;
                    p1.setPosX(x-1);
                    p1.setPosY(y-1);
                    validMoves.push_back(p1);
                }
            }



            break;

        case 1:

            while(getBoard(x+i, y).getColor() !=  getBoard(x,y).getColor() && !final)
            {
                if(getBoard(x+i, y).getType() != 0 && getBoard(x+i, y).getType() != 6 )
                {getBoard(x+i, y).ConvertToString();
                    final=true;}

                if(getBoard(x+i, y).getType() == 6)
                {getBoard(x+i, y).ConvertToString();}

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
                if(getBoard(x-i, y).getType() != 0 )
                {getBoard(x-i, y).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x-i, y).getType() == 6)
                {getBoard(x-i, y).ConvertToString();}

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
                if(getBoard(x, y+j).getType() != 0 )
                {getBoard(x, y+j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x, y+j).getType() == 6)
                {getBoard(x, y+j).ConvertToString();}

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
                if(getBoard(x, y-j).getType() != 0 )
                {getBoard(x, y-j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x, y-j).getType() == 6)
                {getBoard(x, y-j).ConvertToString();}

                if(getBoard(x, y-j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x+i, y+j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x+i, y+j).getType() != 0 )
                {getBoard(x+i, y+j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x+i, y+j).getType() == 6)
                {getBoard(x+i, y-j).ConvertToString();}

                if(getBoard(x+i, y+j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x-i, y+j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x-i, y+j).getType() != 0 )
                {getBoard(x-i, y+j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x-i, y+j).getType() == 6)
                {getBoard(x-i, y+j).ConvertToString();}

                if(getBoard(x-i, y+j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x+i, y-j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x+i, y-j).getType() != 0 )
                {getBoard(x+i, y-j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x+i, y-j).getType() == 6)
                {getBoard(x+i, y-j).ConvertToString();}

                if(getBoard(x+i, y-j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x-i, y-j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x-i, y-j).getType() != 0 )
                {getBoard(x-i, y-j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x-i, y-j).getType() == 6)
                {getBoard(x-i, y-j).ConvertToString();}

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
                {getBoard(x+i, y).ConvertToString();
                    final=true;}

                if(getBoard(x+i, y).getType() == 6)
                {getBoard(x+i, y).ConvertToString();}

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
                if(getBoard(x-i, y).getType() != 0 )
                {getBoard(x-i, y).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x-i, y).getType() == 6)
                {getBoard(x-i, y).ConvertToString();}

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
                if(getBoard(x, y+j).getType() != 0 )
                {getBoard(x, y+j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x, y+j).getType() == 6)
                {getBoard(x, y+j).ConvertToString();}

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
                if(getBoard(x, y-j).getType() != 0 )
                {getBoard(x, y-j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x, y-j).getType() == 6)
                {getBoard(x, y-j).ConvertToString();}

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
            while(getBoard(x+i, y+j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x+i, y+j).getType() != 0 )
                {getBoard(x+i, y+j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x+i, y+j).getType() == 6)
                {getBoard(x+i, y-j).ConvertToString();}

                if(getBoard(x+i, y+j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x-i, y+j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x-i, y+j).getType() != 0 )
                {getBoard(x-i, y+j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x-i, y+j).getType() == 6)
                {getBoard(x-i, y+j).ConvertToString();}

                if(getBoard(x-i, y+j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x+i, y-j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x+i, y-j).getType() != 0 )
                {getBoard(x+i, y-j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x+i, y-j).getType() == 6)
                {getBoard(x+i, y-j).ConvertToString();}

                if(getBoard(x+i, y-j).getType() == 0 )
                {final = true;}

                if(x+i >8 && x-i <0 && y+j>8 && y-j<0)
                {final = true;}

                j++;
            }
            i=1;
            j=1;
            final = false;

            while(getBoard(x-i, y-j).getColor() !=  getBoard(x+i,y+j).getColor() && !final)
            {
                if(getBoard(x-i, y-j).getType() != 0 )
                {getBoard(x-i, y-j).ConvertToString();}
                else
                {final=true;}

                if(getBoard(x-i, y-j).getType() == 6)
                {getBoard(x-i, y-j).ConvertToString();}

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
            if(getBoard(x+1, y+2).getColor() != getBoard(x,y).getColor()) {getBoard(x+1, y).ConvertToString();}
            if(getBoard(x+1, y-2).getColor() != getBoard(x,y).getColor()) {getBoard(x+1, y+1).ConvertToString();}
            if(getBoard(x+2, y-1).getColor() != getBoard(x,y).getColor()) {getBoard(x+1, y-1).ConvertToString();}
            if(getBoard(x+2, y+1).getColor() != getBoard(x,y).getColor()) {getBoard(x, y+1).ConvertToString();}
            if(getBoard(x-1, y-2).getColor() != getBoard(x,y).getColor()) {getBoard(x, y-1).ConvertToString();}
            if(getBoard(x-1, y+2).getColor() != getBoard(x,y).getColor()) {getBoard(x-1, y).ConvertToString();}
            if(getBoard(x-2, y+1).getColor() != getBoard(x,y).getColor()) {getBoard(x-1, y+1).ConvertToString();}
            if(getBoard(x-2, y-1).getColor() != getBoard(x,y).getColor()) {getBoard(x-1, y-1).ConvertToString();}

            break;

        case 5:
            if (getBoard(x, 1).getColor()==0)
            {
                getBoard(x, 3).ConvertToString();

            }
            if(getBoard(x, y).getColor()==0)
            {
                if (getBoard(x+1, y+1).getColor()==1){getBoard(x+1, y+1).ConvertToString();}
                if (getBoard(x+1, y-1).getColor()==1){getBoard(x+1, y-1).ConvertToString();}
                if (getBoard(x, y-1).getColor() ==3){getBoard(x, y+1).ConvertToString();}
            }

            if (getBoard(x, 6).getColor()==1)
            {
                getBoard(x, 4).ConvertToString();

            }

            if(getBoard(x, y).getColor()==1)
            {

                if (getBoard(x+1, y-1).getColor()==0){getBoard(x+1, y-1).ConvertToString();}
                if (getBoard(x-1, y+1).getColor()==0){getBoard(x-1, y+1).ConvertToString();}
                if (getBoard(x, y-1).getColor()==3){getBoard(x, y-1).ConvertToString();}
            }


        default:
            cout << "Error" << endl;
            break;
    }




    return validMoves;
}

string Chessboard::ToString() {
    string res;
    for(int i = 0; i < 8; i++) {
        res.append(to_string(8 - i) + " "); // cout << 8 - i << " ";
        for(int j = 0; j < 8; j++) {
            res.append(m_board[i][j].ConvertToString() + " "); // cout << m_board[i][j].ConvertToString() << " ";
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

bool Chessboard::MovePiece(ChessPosition& posFrom, ChessPosition& posTo) {
<<<<<<< Updated upstream
    VecOfPositions *validPosisitions = GetValidMoves(posFrom);
=======
    bool isMoved = false;
    VecOfPositions available = GetValidMoves(posFrom);
>>>>>>> Stashed changes

    int x1 = posFrom.getPosY();
    int y1 = posFrom.getPosX();

    int x2 = posTo.getPosY();
    int y2 = posTo.getPosX();

    Piece buffer = m_board[x1][y1];
    m_board[x1][y1] = Piece();
    m_board[x2][y2] = buffer;

<<<<<<< Updated upstream
    VecOfPositions *validPosisitions1 = GetValidMoves(posTo);

    for (auto pos: *validPosisitions) {
        cout << pos.getPosX() << " " << pos.getPosY() << endl;
    }

    for (auto pos1: *validPosisitions1) {
        cout << pos1.getPosX() << " " << pos1.getPosY() << endl;
    }

    return 1;
=======
    for (ChessPosition p : available) {
        if (p.getPosX() == posTo.getPosX() && p.getPosY() == posTo.getPosY()) {
            cout << "ХУЙ" << endl;
            isMoved = true;
            break;
        }
    }

    return isMoved;
>>>>>>> Stashed changes
}


// Per a fer l'enroc, el primer moviment dels peons i en peassant necessitem movecounter. Perque aquests moviments es poden fer com a primer moviment de la peca.

// Per a la transformacio del peo, es forcara la transformacio de peo a la reina, ja que es practica habitual. Tot i que en alguns casos particulars es necessari la conversio al cavall (underpromoting).

// Si un costat unicament te el rei al taulell, es el seu torn, no esta en jaque i no pot moure's; doncs aixo es un empat. Un costat guany nomes si rei esta en jaque i no pot moures's, ni parar el jaque amb una altra figura.

// Si hi ha una figura que protegeix el rei del jaque, doncs aquesta no pot moure's.

//}