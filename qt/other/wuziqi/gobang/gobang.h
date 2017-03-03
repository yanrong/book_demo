#ifndef GOBANG_H
#define GOBANG_H

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

class Point
{
public:
	int x;
	int y;
    Point(const int X=-1, const int Y=-1){x = X; y = Y;}
};

class Gobang
{
private:
    int N; //棋盘大小
    vector<vector<int> > Data; //棋盘上每个格子的状态,0为啥也没有，1为黑棋，2为白棋
    Point ps_Now; //记录白棋最后一步的位置,用于特别标示
    int Total; //落子总数，用于判断是否已经下满，下满则为和棋

public:
    Gobang(const int n = 15);
    ~Gobang(void);
    void Init(void); //数据初始化
    void GetData(vector<vector<int> > & data); //获取游戏数据，用于画图
    void Judge(int & Who); //判断当前局面是否出现输赢，Who = 1黑方(人)胜，Who = 2白方胜，Who = 0则没有结束
    //人落子,若鼠标点击区域无效返回false;
    bool Fall(const Point & ps, const int & who,const int & beginPos, const int & endPos);
    void Clear(void);
    void Run(Point & ps, const int & Which, const int & Who); //计算机走棋
		 
private:
    bool ChangePos(const Point & srcPos, Point & desPos,const int & beginPos, const int & endPos);

private:
    void LevelDifficult(Point & ps);
    void LevelNormal(Point & ps);
    void SetScore(const int i, const int j, const int Who,vector<vector<int> > & State); //评分函数
    int p_Score(int num, int bp[]); //实际的评分函数
    bool first; //是否是第一步

};
#endif
