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

    VecOfPositions mn = juega1.GetValidMoves(cp);
    for (auto& v : mn) {
        cout << v.getPosX() << " " << v.getPosY() << endl;
    }

    cout << "-------------ToString-------------" << endl;

    cout << juega1.ToString();

    cout << "-------------Moving piece-------------" << endl;
    ChessPosition cp1("a3");
    cout << juega1.MovePiece(cp, cp1) << endl;
    cout << juega1.ToString();

    return 0;
}
