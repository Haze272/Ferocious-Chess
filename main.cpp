#include <iostream>
#include "Piece.h"
#include "Chessboard.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Piece black_king;
    black_king.setColor(CPC_Black);
    black_king.setType(CPT_King);

    Chessboard juega1;
    juega1.addFigure(black_king, 4, 2);

    ChessPosition cp("e6");
    VecOfPositions mn = *(juega1.GetValidMoves(cp));
    for (auto& v : mn){
        cout << v.getPosX() << " " << v.getPosY() << endl;
    }

    return 0;
}
