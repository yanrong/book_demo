#include <iostream>
#include "ChessServerWindow.h"
#include "ChessServer.h"

using namespace std;

int main(int argc, char** argv)
{
    ChessBoard board;
    class Piece whitechess(white, &board);
    class Piece blackchess(black, &board);

    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    ChessServerWindow chessServerWindow(&board, &whitechess, &blackchess);
    chessServerWindow.show();

    return app.exec();
}
