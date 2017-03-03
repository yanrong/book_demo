#include "window.h"

Window::Window(QWidget * parent):QMainWindow(parent)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    setWindowTitle(tr("YiQiu"));
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

    procClient=new QProcess(this);
    procServer=new QProcess(this);
    isConnServer=false;
}

Window::~Window()
{
}

void Window::paintEvent(QPaintEvent * event)
{
	//画背景
	QPainter painter(this);
    painter.setBrush(Qt::lightGray);
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

    //将最后一步画的白棋子变绿，这样人能看清
	if (lastPs.x >=0 && lastPs.y >= 0)
    {
        painterChess.setBrush(Qt::green);
        painterChess.drawEllipse((lastPs.x+1)*20-10+MenuBarSize,(lastPs.y+1)*20-10+MenuBarSize, 20, 20);
    }
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
    QAction * ConnServer= new QAction(tr("Connect Server"),GameMenu);


	GameMenu->addAction(StartGame);
	GameMenu->addAction(StopGame);
	GameMenu->addAction(QuitGame);
    GameMenu->addSeparator();
    GameMenu->addAction(RestartGame);
    GameMenu->addSeparator();
    GameMenu->addAction(ConnServer);

	MenuBar->addMenu(GameMenu);

	connect(StartGame, SIGNAL(triggered()), this, SLOT(startGame()));
	connect(StopGame, SIGNAL(triggered()), this, SLOT(stopGame()));
	connect(QuitGame, SIGNAL(triggered()), this, SLOT(close()));
    connect(RestartGame,SIGNAL(triggered()),this,SLOT(restartGame()));

    connect(ConnServer,SIGNAL(triggered()),this,SLOT(connectServer()));

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
    QMessageBox::about(this, tr("About Game"),
                       tr("<h2>YiQiu</h2>"
                          "<p>Copyright &copy; Software Inc.</p>"
                          "<p>YiQiu is a small chess application.This program is free software."
                          " it published under the GNU General Public License"));
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

void Window::connectServer()
{
    QStringList ser(QString("server")),cli(QString("client"));
    QString prog("../shell/run_server");
    if(!isConnServer){
        int ret=QMessageBox::warning(this,tr("connect server"),
                                     tr("<p>server is not run,"
                                        "do you mean to start it?"),
                                     QMessageBox::Yes|QMessageBox::Cancel);
        if(ret==QMessageBox::Yes){
            procServer->startDetached(prog,ser);
            isConnServer=true;
        }else return;
    }else{
        int ret=QMessageBox::warning(this,tr("connect server"),
                                     tr("<p>server is running,"
                                        "this action will start client!"),
                                     QMessageBox::Yes);
        if(ret==QMessageBox::Yes){
            procClient->startDetached(prog,cli);
            this->close();
        }else return;
    }
}
