//ChessServer.cpp
#include "ChessServer.h"

ChessServer::ChessServer(ChessServerWindow* window)
    :chessServerWindow(window)
{
    tcpChessServer = new QTcpServer;

    if(!tcpChessServer->listen(QHostAddress::Any, quint16(SERVER_PORT))){
        QMessageBox::critical(0,
                              QObject::tr("Chess Server"),
                              QObject::tr("unable to start the server: %1").
                              arg(tcpChessServer->errorString()));
    }

    QMessageBox::information(0, QObject::tr("Chess Server"),
                             QObject::tr("The server is running on port %1.\n"
                                         "Run the Chess Client now.").
                             arg(tcpChessServer->serverPort()));

    connect(tcpChessServer, SIGNAL(newConnection()),
            this, SLOT(doNewConnection()));
    connect(chessServerWindow, SIGNAL(myCoordinateAvailable(int, int)),
            this, SLOT(sendToClient(int, int)));
    connect(chessServerWindow, SIGNAL(restartSignal()), this, SLOT(restart()));
}

//send the coordinate to the white chess
//x coordinate,ycoordiante
void ChessServer::sendToClient(int x, int y)
{
    QByteArray block;

    XCoordiante = x;
    YCoordiante = y;

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out<<(qint32)XCoordiante<<(qint32)YCoordiante;
    clientConnection->write(block);
}

void ChessServer::doNewConnection()
{
    clientConnection = tcpChessServer->nextPendingConnection();
    connect(clientConnection, SIGNAL(readyRead()),
            this, SLOT(readFromClient()));
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    chessServerWindow->setClientConnecting(true);
}

void ChessServer::readFromClient()
{
    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_4_0);

    if(clientConnection->bytesAvailable() < 2*(int)sizeof(quint16)){
        return;
    }
    in>>XCoordiante>>YCoordiante;

    emit peerCoordinateAvailable(XCoordiante, YCoordiante);
}


void ChessServer::restart()
{
    clientConnection->disconnectFromHost();
    chessServerWindow->setClientConnecting(false);
}

