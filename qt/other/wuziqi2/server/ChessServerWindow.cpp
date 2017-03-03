//ChessServerWindow.cpp

#include <QtGui/QtGui>
#include "ChessServerWindow.h"

#define CHESS_WIDTH        19    
#define GRID_WIDTH        20
#define CHESSBOARD_WIDTH        GRID_WIDTH*(CHESS_WIDTH+1)    
#define ORIGINAL_WIDTH    15
#define CURRENTX_COORDINATE        ((ORIGINAL_WIDTH)+(GRID_WIDTH)*(currentX))
#define CURRENTY_COORDINATE        ((ORIGINAL_WIDTH)+(GRID_WIDTH)*(currentY))

ChessServerWindow::ChessServerWindow(ChessBoard *b, Piece* whitec, Piece* blackc, QWidget* parent)
    :QWidget(parent), board(b), whiteChess(whitec), blackChess(blackc)
{
    victory = new victoryDialog;
    chessServer = new ChessServer(this);

    clientConnecting = false;
    previousClickedButton = blackClicked;

    setWindowTitle(tr("网络五子棋(服务器端)-黑棋"));
    setGeometry(0, 0, CHESSBOARD_WIDTH, CHESSBOARD_WIDTH);
    update();

    connect(this, SIGNAL(victorySignal(enum Chess)),
            this, SLOT(restart(enum Chess)));
    connect(victory, SIGNAL(quitSignal()), this, SLOT(close()));
    connect(chessServer, SIGNAL(peerCoordinateAvailable(int, int)),
            this, SLOT(getPeerCoordinate(int ,int)));
/////////////////////////////////////////////////
    connect(chessServer,SIGNAL(doQuitServer()),this,SLOT(quitServer()));

}

void ChessServerWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setPen(Qt::gray);
    painter.setBrush(Qt::gray);

    //draw horizon
    currentX = 0;
    currentY = 0;
    for(int i=0; i<CHESS_WIDTH; i++)
    {
        painter.drawLine(ORIGINAL_WIDTH,
                         CURRENTY_COORDINATE,
                         CHESSBOARD_WIDTH-GRID_WIDTH,
                         CURRENTY_COORDINATE);
        currentY++;
    }
    //draw vertical
    currentX = 0;
    currentY = 0;
    for(int i=0; i<CHESS_WIDTH; i++)
    {
        painter.drawLine(CURRENTX_COORDINATE,
                         ORIGINAL_WIDTH,
                         CURRENTX_COORDINATE,
                         CHESSBOARD_WIDTH-GRID_WIDTH);
        currentX++;
    }

    //draw chess
    for(int currentX = 0; currentX < CHESS_WIDTH; ++currentX)
    {
        for(int currentY = 0; currentY< CHESS_WIDTH; ++currentY)
        {
            if(board->GetStatus(currentX, currentY) == black)
            {
                painter.setPen(Qt::black);
                painter.setBrush(QBrush(Qt::black));
                painter.drawEllipse(QPoint(CURRENTX_COORDINATE,
                                           CURRENTY_COORDINATE),
                                    GRID_WIDTH/2,
                                    GRID_WIDTH/2);
            }
            else if(board->GetStatus(currentX, currentY) == white)
            {
                painter.setPen(Qt::blue);
                painter.setBrush(QBrush(Qt::white));
                painter.drawEllipse(QPoint(CURRENTX_COORDINATE,
                                           CURRENTY_COORDINATE),
                                    GRID_WIDTH/2,
                                    GRID_WIDTH/2);
            }
        }
    }
}

void ChessServerWindow::mousePressEvent(QMouseEvent * event)
{
    //get x coordinate
    if((event->x()-ORIGINAL_WIDTH)%GRID_WIDTH <= GRID_WIDTH/2){
        currentX = (event->x()-ORIGINAL_WIDTH)/GRID_WIDTH;
    }
    else{
        currentX = (event->x()-ORIGINAL_WIDTH)/GRID_WIDTH + 1;
    }

    //get y coordinate
    if((event->y()-ORIGINAL_WIDTH)%GRID_WIDTH <= GRID_WIDTH/2){
        currentY = (event->y()-ORIGINAL_WIDTH)/GRID_WIDTH;
    }
    else{
        currentY = (event->y()-ORIGINAL_WIDTH)/GRID_WIDTH + 1;
    }

    //get the information of mouse
    if((event->button() == Qt::LeftButton) || (event->button() == Qt::RightButton)){
        clickedButton = blackClicked;
    }
    else {
        clickedButton = noClicked;
    }

    if( !(board->GetStatus(currentX, currentY) == null) ){
        next = false;
        return;
    }

    //set x,y coordinate
    if((previousClickedButton == whiteClicked))
    {
        blackChess->SetChess(currentX, currentY);
        if(blackChess->getCurrentChessStatus()){
            next = true;
        }
        else{
            next = false;
        }
    }
    //update the chess board
    if((next == true) && clientConnecting)
    {
        update();
        previousClickedButton = clickedButton;
        emit myCoordinateAvailable(currentX, currentY);
    }

    if(blackChess->GetEndFlag()){
        emit restartSignal();
        emit victorySignal(black);
    }
}

void ChessServerWindow::restart(enum Chess c)
{
    QString printStr;
    if(c == black){
        printStr.append("You are Winner, Congratulation!");
    }
    else if(c == white){
        printStr.append("You are Loser, Bad Luck!");
    }

    victory->setWindowTitle(tr("服务器端－黑棋"));
    victory->congratulationLabel->setText(printStr);
    victory->exec();

    board->initBoard();
    blackChess->setEndFlag(false);
    previousClickedButton = whiteClicked;

    update();
}

void ChessServerWindow::setClientConnecting(bool b)
{
    if(b){
        clientConnecting = true;
        previousClickedButton = whiteClicked;
    }
    else {
        clientConnecting = false;
        previousClickedButton = blackClicked;
    }
}

void ChessServerWindow::getPeerCoordinate(int x, int y)
{
    //set x,y coordinate
    clickedButton = whiteClicked;
    if((previousClickedButton == blackClicked))
    {
        whiteChess->SetChess(x, y);
        if(whiteChess->getCurrentChessStatus()){
            next = true;
        }
        else{
            next = false;
        }
    }

    //update the chess board
    if(next == true){
        update();
        previousClickedButton = clickedButton;
    }

    //judge victory
    if(whiteChess->GetEndFlag()){
        emit victorySignal(white);
    }
}

///////////////////////////////////
void ChessServerWindow::quitServer()
{
    this->close();
}
