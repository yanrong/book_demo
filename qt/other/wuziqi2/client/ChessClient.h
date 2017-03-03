#ifndef CHESSCLIENT_HH
#define CHESSCLIENT_HH

#include <QtGui/QtGui>
#include <QtNetwork>
#include <QTcpSocket>
#include "chesspiece.h"
#include "ChessClientWindow.h"

class ChessClientWindow;

class ChessClient:public QObject
{
    Q_OBJECT

public:
    ChessClient(ChessClientWindow*, const QString&, const QString&);

signals:
    void peerCoordinateAvailable(int x, int y);
    ////////////////////////////////////////////
    void doQuitClient();

public slots:
    void displayError(QAbstractSocket::SocketError);
    void readChessServer();
    void writeChessServer(int, int);
    void restart();

private:
    QString serverName;
    QString serverPort;
    ChessClientWindow* chessClientWindow;
    QTcpSocket* tcpClientSockt;
    int XCoordiante;
    int YCoordiante;
    QString blackCoordinate;
};

#endif

