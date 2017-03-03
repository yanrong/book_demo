#include <iostream>
#include <QtGui/QtGui>
#include "ChessClient.h"

#define SERVER_PORT             65530

ChessClient::ChessClient(ChessClientWindow* window, const QString& name, const QString& port)
    :chessClientWindow(window), serverName(name), serverPort(port)
{
    tcpClientSockt = new QTcpSocket(this);
    connect(tcpClientSockt, SIGNAL(readyRead()),
            this, SLOT(readChessServer()));
    connect(tcpClientSockt, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(chessClientWindow, SIGNAL(myCoordinateAvailable(int, int)),
            this, SLOT(writeChessServer(int, int)));
    connect(chessClientWindow, SIGNAL(restart()),
            this, SLOT(restart()));

    XCoordiante = 0;
    YCoordiante = 0;
    tcpClientSockt->abort();
    tcpClientSockt->connectToHost(serverName, serverPort.toInt());
}

void ChessClient::readChessServer()
{
    QDataStream in(tcpClientSockt);
    in.setVersion(QDataStream::Qt_4_0);
    if(tcpClientSockt->bytesAvailable() < 2*(int)sizeof(quint16)){
        return;
    }
    in>>XCoordiante>>YCoordiante;

    emit peerCoordinateAvailable(XCoordiante, YCoordiante);
}

void ChessClient::displayError(QAbstractSocket::SocketError socketError)
{
    switch(socketError){
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(0, tr("Chess Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(0, tr("Chess Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(0, tr("Chess Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpClientSockt->errorString()));
    }
}

void ChessClient::writeChessServer(int x, int y){
    QByteArray block;

    XCoordiante = x;
    YCoordiante = y;

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out<<(qint32)XCoordiante<<(qint32)YCoordiante;
    tcpClientSockt->write(block);
}

void ChessClient::restart(){
    tcpClientSockt->abort();
    tcpClientSockt->connectToHost(QHostAddress("127.0.0.1"), quint16(SERVER_PORT));
}
