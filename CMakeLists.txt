cmake_minimum_required(VERSION 3.22)
project(igor_shit)

set(CMAKE_CXX_STANDARD 14)

add_executable(igor_shit main.cpp Piece.h Piece.cpp Chessboard.cpp Chessboard.h ChessPosition.cpp ChessPosition.h)

# ChessPosition.cpp ChessPosition.h Chessboard.cpp Chessboard.h GameInfo.h
