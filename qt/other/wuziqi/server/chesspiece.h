#ifndef CHESSPIECE_HH
#define CHESSPIECE_HH

#include "chessboard.h"

class Piece {
public:
    Piece(enum Chess, ChessBoard *board);
    void ReadInfo();
    enum Chess GetChess(int x, int y);
    void SetChess(int, int);
    bool getCurrentChessStatus();
    bool GetEndFlag();
    bool setEndFlag(bool);                //重置结束标志，开始下一轮

private:
    bool endflag;
    bool currentChessOk;        //当前的这步棋可以落下
    enum Chess chess;
    int currentx, currenty;
    ChessBoard *board;
};

#endif
