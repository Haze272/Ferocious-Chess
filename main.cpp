#include <iostream>
#include "Piece.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Piece black_queen;
    black_queen.setColor(CPC_Black);
    black_queen.setType(CPT_Queen);

    cout << black_queen.ToString() << endl;


    return 0;
}
