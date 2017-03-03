//chesspiece.cpp
#include "chesspiece.h"

Piece::Piece(enum Chess c, ChessBoard *b) {
    chess = c;
    board = b;
    endflag = false;
    currentChessOk = false;
}

void Piece::SetChess(int x, int y)
{
/* if current coordination (x,y) is invalid for set chess,
    set flag and using function get it.
  */
    if(!board->SetChess(x, y, chess)){
        currentChessOk = false;
    }
    // judget whether a side win game,and set endflag
    if( board->Judge( x, y, chess) ){
        endflag = true;
    }
    else {
        endflag = false;
    }
    currentChessOk = true;
}

bool Piece::getCurrentChessStatus(){
    return currentChessOk;
}

bool Piece::GetEndFlag() {
    return endflag;
}

bool Piece::setEndFlag(bool f){
    endflag = f;
    return true;
}
