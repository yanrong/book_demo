//ChessClientWindow.cpp

#include <QtGui/QtGui>
#include "ChessClientWindow.h"

//棋盘的宽度(即棋盘是CHESS_WIDTH*CHESS_WIDTH)
#define CHESS_WIDTH        19    
//每个格子的宽度(棋盘有很多小方格组成)
#define GRID_WIDTH        20
//棋盘的宽度(长和宽相等)
#define CHESSBOARD_WIDTH        GRID_WIDTH*(CHESS_WIDTH+1)    
//最边上的那条线到棋盘边缘的距离
#define ORIGINAL_WIDTH    15
//当前的x坐标
#define CURRENTX_COORDINATE        ((ORIGINAL_WIDTH)+(GRID_WIDTH)*(currentX))
//当前的y坐标
#define CURRENTY_COORDINATE        ((ORIGINAL_WIDTH)+(GRID_WIDTH)*(currentY))

ChessClientWindow::ChessClientWindow(ChessBoard *b, Piece* whitec, Piece* blackc, QWidget* parent)
    :QWidget(parent), board(b), whiteChess(whitec), blackChess(blackc)
{
    previousClickedButton = whiteClicked;

    setWindowTitle("YiQiu--Client(White)");
    setGeometry(200, 200, CHESSBOARD_WIDTH, CHESSBOARD_WIDTH);
    update();

    startDialog = new StartDialog;
    connect(startDialog, SIGNAL(quitClient()), this, SLOT(close()));
    connect(startDialog, SIGNAL(start(const QString&, const QString&)),
            this, SLOT(doStart(const QString&, const QString&)));
    startDialog->exec();

    chessClient = new ChessClient(this, serverName, serverPort);

    connect(chessClient, SIGNAL(peerCoordinateAvailable(int, int)),
            this, SLOT(getPeerCoordinate(int ,int)));
    connect(this, SIGNAL(victorySignal(enum Chess)),
            this, SLOT(restart(enum Chess)));

    victory = new victoryDialog;
    connect(victory, SIGNAL(quitSignal()),this, SLOT(close()));
}

void ChessClientWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.setBrush(Qt::lightGray);
    //draw horizonal lines
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
    //draw vertical lines
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
            }else if(board->GetStatus(currentX, currentY) == white){

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

void ChessClientWindow::mousePressEvent(QMouseEvent * event)
{
    //get x coordinate
    if((event->x()-ORIGINAL_WIDTH)%GRID_WIDTH <= GRID_WIDTH/2){

        currentX = (event->x()-ORIGINAL_WIDTH)/GRID_WIDTH;
    }else{

        currentX = (event->x()-ORIGINAL_WIDTH)/GRID_WIDTH + 1;
    }
    //get y coordinate
    if((event->y()-ORIGINAL_WIDTH)%GRID_WIDTH <= GRID_WIDTH/2){

        currentY = (event->y()-ORIGINAL_WIDTH)/GRID_WIDTH;
    }else{

        currentY = (event->y()-ORIGINAL_WIDTH)/GRID_WIDTH + 1;
    }

    if((event->button() == Qt::LeftButton)
            || (event->button() == Qt::RightButton)){

        clickedButton = whiteClicked;
    }else {

        clickedButton = noClicked;
    }

    //get the coordinate
    if(!(board->GetStatus(currentX, currentY) == null))
    {
        next = false;
        return;
    }
    //set x,y coordinate
    if((previousClickedButton == blackClicked))
    {
        whiteChess->SetChess(currentX, currentY);

        if(whiteChess->getCurrentChessStatus()){
            next = true;
        }else{
            next = false;
        }
    }

    //update the chess board
    if(next == true)
    {
        update();
        previousClickedButton = clickedButton;
        emit myCoordinateAvailable(currentX, currentY);
    }
    //judge victory
    if(whiteChess->GetEndFlag()){
        emit victorySignal(white);
    }
}

void ChessClientWindow::restart(enum Chess c)
{
    QString printStr;
    if(c == black){
        printStr.append("Black victory, Congratulation!");
    }else if(c == white){
        printStr.append("White victory, Congratulation!");
    }

    victory->congratulationLabel->setText(printStr);
    victory->exec();
    board->initBoard();
    whiteChess->setEndFlag(false);
    previousClickedButton = whiteClicked;

    update();
    emit restart();
}

void ChessClientWindow::getPeerCoordinate(int x, int y)
{
    clickedButton = blackClicked;
    //set x,y coordinate
    if((previousClickedButton == whiteClicked))
    {
        blackChess->SetChess(x, y);
        if(blackChess->getCurrentChessStatus()){
            next = true;
        }else{
            next = false;
        }
    }

    //update the chess board
    if(next == true){
        update();
        previousClickedButton = clickedButton;
    }

    //judge victory
    if(blackChess->GetEndFlag()){
        emit victorySignal(black);
    }
}

void ChessClientWindow::doStart(const QString& name, const QString& port)
{
    serverName = name;
    serverPort = port;
}
