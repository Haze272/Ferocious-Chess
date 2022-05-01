#include <iostream>
#include "Piece.h"
#include "Chessboard.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Chessboard juega1;

    cout << "-------------King-------------" << endl;

    Piece black_king;
    black_king.setColor(CPC_Black);
    black_king.setType(CPT_King);
    juega1.addFigure(black_king, 4, 2);

    ChessPosition cp("e6");

    VecOfPositions mn = *(juega1.GetValidMoves(cp));
    for (auto& v : mn){
        cout << v.getPosX() << " " << v.getPosY() << endl;
    }

    cout << "-------------Rook-------------" << endl;

    Piece black_rook;
    black_rook.setColor(CPC_Black);
    black_rook.setType(CPT_Rook);
    juega1.addFigure(black_rook, 4, 2);

    ChessPosition cp1("e6");

    VecOfPositions mn1 = *(juega1.GetValidMoves(cp1));
    for (auto& v : mn1){
        cout << v.getPosX() << " " << v.getPosY() << endl;
    }

    return 0;
}
