#include <iostream>
#include "Piece.h"
#include "Chessboard.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Piece black_king;
    black_king.setColor(CPC_Black);
    black_king.setType(CPT_King);

    Chessboard juega1;
    juega1.addFigure(black_king, 4, 0);

    ChessPosition cp("e8");
    juega1.GetValidMoves(cp);

    return 0;
}
