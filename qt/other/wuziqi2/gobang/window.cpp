#include "window.h"

Window::Window(QWidget * parent):QMainWindow(parent)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    setWindowTitle(tr("网络五子棋"));
    N = 15;  //棋盘规模 NXN
    MenuBarSize = 10;
    setFixedSize(320+MenuBarSize, 320+MenuBarSize);
	bRun = true;
    Level = 1;
	vector<int> temp(N, 0);
	for (int i = 0; i < N; i++){
		gamedata.push_back(temp);
	}
    createMenu();
}

Window::~Window()
{
}

void Window::paintEvent(QPaintEvent * event)
{
	//画背景
	QPainter painter(this);
    painter.drawRect(0, 0, size().width(), size().height());
    //获取棋盘信息
	game.GetData(gamedata);
	//画棋盘
    for (int x = 20+MenuBarSize; x <= N*20+MenuBarSize; x += 20)
	{
        painter.drawLine(x, 20+MenuBarSize, x, N*20+MenuBarSize);
	}
    for (int y = 20+MenuBarSize; y <= N*20+MenuBarSize; y += 20)
	{
        painter.drawLine(20+MenuBarSize, y, N*20+MenuBarSize, y);
	}

    QPainter painterChess(this);
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			if (gamedata[x][y] == 1) //黑棋子
            {
                painterChess.setBrush(Qt::black);
                painterChess.drawEllipse((x+1)*20-10+MenuBarSize, (y+1)*20-10+MenuBarSize, 20, 20);
			}
            else if (gamedata[x][y] == 2) //白棋子
          	{
                painterChess.setBrush(Qt::white);
                painterChess.drawEllipse((x+1)*20-10+MenuBarSize, (y+1)*20-10+MenuBarSize, 20, 20);
			}
		}
	}

//    //将最后一步画的白棋子变绿，这样人能看清
//	if (lastPs.x >=0 && lastPs.y >= 0)
//    {
//        painterChess.setBrush(Qt::green);
//        painterChess.drawEllipse((lastPs.x+1)*20-10+MenuBarSize,(lastPs.y+1)*20-10+MenuBarSize, 20, 20);
//    }
	QMainWindow::paintEvent(event);
}

void Window::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton && bRun == true)
	{
		int x = event->x();
		int y = event->y();
        Point ps;
		ps.x = x;
		ps.y = y;
        if (ps.x<10+MenuBarSize||ps.y<10+MenuBarSize||ps.x>300+20+MenuBarSize||ps.y>300+20+MenuBarSize)
		{
			return;
		}
		if (!game.Fall(ps, 1, 20+MenuBarSize, 300+20+MenuBarSize))
		{
			return;
		}
        game.Run(ps, Level, 2);
		lastPs = ps;
		ps.x = 20 + MenuBarSize + ps.x*20;
		ps.y = 20 + MenuBarSize + ps.y*20;
		game.Fall(ps, 2, 20+MenuBarSize, 300+20+MenuBarSize);
		game.GetData(gamedata);
		update();
		int who = 0; //看谁赢了
		game.Judge(who);
		if (who == 1) //人赢了
		{
            QMessageBox::information(this, tr("Game Over"),tr("Congratulation. you are Winner!"));
			bRun = false;
		}
		else if (who == 2) //计算机赢了
		{
            QMessageBox::information(this, tr("Game Over"),tr("Bad luck. you are Loser!"));
			bRun = false;
		}
	}
}

void Window::createMenu(void)
{
	QMenuBar * MenuBar = new QMenuBar(this);
    QMenu * GameMenu = new QMenu(tr("Game"), MenuBar);
    QMenu * LevelMenu = new QMenu(tr("Level"), MenuBar);
    QMenu * HelpMenu = new QMenu(tr("Help"), MenuBar);

    QAction * StartGame = new QAction(tr("Start"), GameMenu);
    QAction * StopGame = new QAction(tr("Stop"), GameMenu);
    QAction * QuitGame = new QAction(tr("Quit"), GameMenu);
    QAction * RestartGame= new QAction(tr("Restart"),GameMenu);
    QAction * StartServer= new QAction(tr("Start Server"),GameMenu);
    QAction * StartClient= new QAction(tr("Connect Server"),GameMenu);


	GameMenu->addAction(StartGame);
	GameMenu->addAction(StopGame);
	GameMenu->addAction(QuitGame);
    GameMenu->addSeparator();
    GameMenu->addAction(RestartGame);
    GameMenu->addSeparator();
    GameMenu->addAction(StartServer);
    GameMenu->addAction(StartClient);

	MenuBar->addMenu(GameMenu);

	connect(StartGame, SIGNAL(triggered()), this, SLOT(startGame()));
	connect(StopGame, SIGNAL(triggered()), this, SLOT(stopGame()));
	connect(QuitGame, SIGNAL(triggered()), this, SLOT(close()));
    connect(RestartGame,SIGNAL(triggered()),this,SLOT(restartGame()));

    connect(StartServer,SIGNAL(triggered()),this,SLOT(startServer()));
    connect(StartClient,SIGNAL(triggered()),this,SLOT(startClient()));

    QAction * levelNormal = new QAction(tr("Normal"), LevelMenu);
    QAction * levelDifficult = new QAction(tr("Difficult"), LevelMenu);

    LevelMenu->addAction(levelNormal);
    LevelMenu->addAction(levelDifficult);

    MenuBar->addMenu(LevelMenu);
    connect(levelNormal, SIGNAL(triggered()), this, SLOT(setLevelNormal()));
    connect(levelDifficult, SIGNAL(triggered()), this, SLOT(setLevelDifficult()));

    QAction * About = new QAction(tr("About"), HelpMenu);
	HelpMenu->addAction(About);
	MenuBar->addMenu(HelpMenu);
	connect(About, SIGNAL(triggered()), this, SLOT(showAbout()));

	setMenuBar(MenuBar);
    connect(this,SIGNAL(doQuitSingle()),this,SLOT(quitSingle()));
}

void Window::startGame(void)
{
	if (bRun == false)
	{
		bRun = true;
		game.Clear();
		game.Init();
		lastPs.x = -1; lastPs.y = -1;
		update();
	}
}

void Window::stopGame(void)
{
	if (bRun == true)
	{
		bRun = false;
		game.Clear();
		lastPs.x = -1; lastPs.y = -1;
		update();
	}
}

void Window::restartGame()
{
        stopGame();
        startGame();
        return ;
}

void Window::showAbout(void)
{
    QMessageBox::about(this, tr("关于该游戏程序"),
                       tr("<h2>基于QT的网络游戏软件的设计与研发－五子棋</h2>"
                          "<p>Copyright &copy; 杜彦荣(CSUFT).</p>"
                          "<p>该游戏程序是个小型的五子棋游戏程序，是自由免费软件，"
                          " 它是在GNU通用公共许可证发行的，有些内容参考自网络空间．"
                          "作为本人毕业设计的课题设计,侵权必究！"));
}

void Window::setLevelDifficult(void)
{
    if (Level == 2){
		return;
	}
	stopGame();
    Level = 2;
	startGame();
}

void Window::setLevelNormal(void)
{
    if (Level == 1){
		return;
	}
	stopGame();
    Level = 1;
	startGame();
}

void Window::startServer()
{
    QProcess *procServer;

    procServer=new QProcess(this);
    QStringList ser(QString("server"));
    QString prog("../shell/run_server");

    int ret=QMessageBox::warning(this,tr("connect server"),
                                 tr("<p>This action will <font color=red size=5>quit</font>"
                                    " running game,and start <font color=green size=4>server</font>."
                                    "<p>are you sure?"),
                                 QMessageBox::Yes|QMessageBox::Cancel);
    if(ret==QMessageBox::Yes){

        procServer->startDetached(prog,ser);
//        this->close();
        emit doQuitSingle();
    }else return;

}

void Window::startClient()
{
    QProcess * procClient=new QProcess(this);

    QStringList cli(QString("client"));
    QString prog("../shell/run_server");

    int ret=QMessageBox::warning(this,tr("connect server"),
                                 tr("<p>This action will <font color=red size=4>quit</font>"
                                    " running game,and start <font color=green size=4>client</font>."
                                    "<p>are you sure?"),
                                 QMessageBox::Yes|QMessageBox::Cancel);
    if(ret==QMessageBox::Yes){

        procClient->startDetached(prog,cli);
        emit doQuitSingle();
    }else return;

}

void Window::quitSingle()
{
    this->close();
}
