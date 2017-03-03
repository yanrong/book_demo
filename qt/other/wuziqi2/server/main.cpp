#include <iostream>
#include "ChessServerWindow.h"
#include "ChessServer.h"

using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    ChessBoard board;
    class Piece whitechess(white, &board);
    class Piece blackchess(black, &board);

    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    ChessServerWindow chessServerWindow(&board, &whitechess, &blackchess);
    chessServerWindow.show();

    return app.exec();
}
