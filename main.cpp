#include <iostream>
#include "Piece.h"
#include "Chessboard.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Chessboard juega1;

    cout << "-------------King1-------------" << endl;

    Piece black_king;
    black_king.setColor(CPC_Black);
    black_king.setType(CPT_King);
    juega1.addFigure(black_king, 0, 0);

    ChessPosition cp("a8");

    VecOfPositions mn = *(juega1.GetValidMoves(cp));
    for (auto& v : mn){
        cout << v.getPosX() << " " << v.getPosY() << endl;
    }

    return 0;
}
