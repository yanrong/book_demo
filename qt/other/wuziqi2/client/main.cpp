//main.cpp

#include <iostream>
#include "ChessClientWindow.h"
#include "ChessClient.h"

using namespace std;

int main(int argc, char** argv)
{
    ChessBoard board;
    class Piece whitechess(white, &board);
    class Piece blackChess(black, &board);

    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    ChessClientWindow chessWindow(&board, &whitechess, &blackChess);
    chessWindow.show();
    return app.exec();
}
