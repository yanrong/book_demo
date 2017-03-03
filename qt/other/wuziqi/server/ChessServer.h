//ChessServer.h
#ifndef CHESSSERVER_HH
#define CHESSSERVER_HH

#include <QtGui>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <stdlib.h>
#include "chesspiece.h"
#include "ChessServerWindow.h"

#define SERVER_PORT         65530

class ChessServerWindow;

class ChessServer:public QObject
{
    Q_OBJECT

public:
    ChessServer(ChessServerWindow*);

signals:
    void peerCoordinateAvailable(int x, int y);

public slots:
    void sendToClient(int x, int y);
    void readFromClient();
    void doNewConnection();
    void restart();

private:
    ChessServerWindow* chessServerWindow;
    QTcpServer *tcpChessServer;
    QTcpSocket* clientConnection;
    int XCoordiante, YCoordiante;
};

#endif
