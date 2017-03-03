//ChessClientWindow.h

#ifndef CHESSCLIENTWINDOW_HH
#define CHESSCLIENTWINDOW_HH

#include <QtGui/QtGui>
#include "chessboard.h"
#include "ChessClient.h"
#include "victoryDialog.h"
#include "startDialog.h"

//下面的枚举类型分别表示，黑棋，白棋和无效
enum button{blackClicked, whiteClicked, noClicked};

class ChessClient;

class ChessClientWindow:public QWidget
{
    Q_OBJECT
public:
    ChessClientWindow(ChessBoard*, Piece*, Piece*, QWidget* parent = 0);

protected:
    void paintEvent(QPaintEvent * event );
    void mousePressEvent(QMouseEvent * event);
    void judgeLocation(int x,int y);

public slots:
    void restart(enum Chess);
    void getPeerCoordinate(int x, int y);
    void doStart(const QString&, const QString&);
    /*this is for quit chess client while connect error*/
    void quitClient();

signals:
    void victorySignal(enum Chess);
    void myCoordinateAvailable(int x, int y);
    void restart();

private:
    StartDialog* startDialog;
    QPixmap chessPixmap;
    ChessBoard* board;
    Piece* whiteChess;
    Piece* blackChess;
    Piece* currentChess;
    enum button previousClickedButton;
    enum button clickedButton;
    bool next;                    //如果走的一步棋正确，则为true
    int currentX,currentY;        //当前的坐标
    victoryDialog* victory;
    ChessClient* chessClient;
    QString serverName;
    QString serverPort;
};

#endif
