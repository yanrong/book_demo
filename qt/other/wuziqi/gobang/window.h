#ifndef WINDOW_H
#define WINDOW_H

#include <QtGui>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QMessageBox>

#include <iostream>
#include <vector>
#include "gobang.h"

using namespace std;

class Window : public QMainWindow
{
	Q_OBJECT
public:
	Window(QWidget * parent = 0);
	~Window();

protected:
	void paintEvent(QPaintEvent * event); //处理重绘消息
	void mousePressEvent(QMouseEvent * event); //鼠标事件消息处理

protected slots:
    void startGame(void);
    void stopGame(void);
    void restartGame();
    void connectServer();
    void showAbout(void);
    void setLevelDifficult(void);
    void setLevelNormal(void);

private:
    void createMenu(void);

private:
	int MenuBarSize; //菜单栏所占的位置
    Gobang game;
	vector<vector<int> > gamedata; //游戏数据
	int N;  //棋盘边长
    Point lastPs;  //记录计算机最后落子的座标
	bool bRun; //标志游戏是否开始
    int Level; //选择计算机下棋使用的算法
    bool isConnServer;
    QProcess * procClient,*procServer;
};

#endif
