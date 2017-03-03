//chessboard.cpp
#include "chessboard.h"
#include <iostream>
using namespace std;

ChessBoard::ChessBoard() {
    initBoard();
}

void ChessBoard::initBoard(){
    for(int i=0; i<19; i++)
        for(int j=0; j<19; j++)
            board[i][j] = null;
}

//棋手走一步棋
bool ChessBoard::SetChess(int x, int y, enum Chess c) {
    if(board[x][y] != null) {
        return false;
    }
    else {
        board[x][y] = c;
        return true;
    }
}

//获取坐标为(x,y)的状态(是否已经有棋子)
enum Chess ChessBoard::GetStatus(int x, int y) {
    return board[x][y];
}

//判断坐标为(x,y)处的棋子是否获胜
//需要判断四个方向：横向、纵向和两个对角方向
bool ChessBoard::Judge(int x, int y, enum Chess currentchess) {
    int count;
    int row, col;

    //----------横向----------
    count = 1, row = x, col = y;
    //判断（x,y）左边
    while((--row) >= 0 && board[row][y] == currentchess) {
        count++;
        if(count >= 5) { return true; }
    }

    row = x;
    //判断（x,y）右边
    while((++row) < 19 && board[row][y] == currentchess) {
        count++;
        if(count >= 5) { return true; }
    }


    //--------纵向----------
    count = 1, row = x, col = y;
    //判断（x,y）上面
    while((--col) >= 0 && board[x][col] == currentchess) {
        count++;
        if(count >= 5)  { return true; }
    }

    col = y;
    //判断（x,y）下面
    while((++col) < 19 && board[x][col] == currentchess) {
        count++;
        if(count >= 5) { return true; }
    }


    //-------判断西北到东南方-------
    count = 1, row = x, col = y;
    //判断（x,y）的左上
    while((--row) >= 0 && (--col) >= 0 && board[row][col] == currentchess)
    {
        count++;
        if(count >= 5)  { return true; }
    }

    row = x, col = y;
    //判断（x,y）的右下
    while((++row) < 19 && (++col) < 19 && board[row][col] == currentchess)
    {
        count++;
        if(count >= 5)  { return true; }
    }

    //-------判断东北到西南方-------
    count = 1, row = x, col = y;
    //判断（x,y）右上方
    while((++row) < 19 && (--col) >= 0 && board[row][col] == currentchess)
    {
        count++;
        if(count >= 5)  { return true; }
    }

    row = x, col = y;
    //判断（x,y）的左下方
    while((--row) >= 0 && (++col) < 19 && board[row][col] == currentchess)
    {
        count++;
        if(count >= 5) {  return true; }
    }

    return false;
}
