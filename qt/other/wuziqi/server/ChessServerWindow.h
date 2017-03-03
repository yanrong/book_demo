//ChessServerWindow.h

#ifndef CHESSSERVERWINDOW_HH
#define CHESSSERVERWINDOW_HH

#include <QtGui/QtGui>
#include "ChessServer.h"
#include "victoryDialog.h"

enum button{blackClicked, whiteClicked, noClicked};

class ChessServer;

class ChessServerWindow:public QWidget
{
    Q_OBJECT

public:
    ChessServerWindow(ChessBoard*, Piece*, Piece*, QWidget* parent = 0);
    void setClientConnecting(bool);

protected:
    void paintEvent(QPaintEvent * event );
    void mousePressEvent(QMouseEvent * event);
    void judgeLocation(int x,int y);

public slots:
    void restart(enum Chess);
    void getPeerCoordinate(int x, int y);

signals:
    void victorySignal(enum Chess);
    void myCoordinateAvailable(int, int);
    void restartSignal();

private:
    QPixmap chessPixmap;
    ChessBoard* board;
    Piece* whiteChess;
    Piece* blackChess;
    Piece* currentChess;
    enum button previousClickedButton;
    enum button clickedButton;
    bool next;
    int currentX,currentY;
    victoryDialog* victory;
    ChessServer* chessServer;
    bool clientConnecting;
};

#endif

