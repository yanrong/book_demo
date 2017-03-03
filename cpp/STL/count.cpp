#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
void info(int &i)
{
	cout<<i<<" ";
}
int main()
{
    srand(time(NULL));
    list<int> Score;
    for(int i=0; i!=100; i++)
    {
        int temp=10+rand()%10;
        Score.push_back(temp);
    }
    int num(0);
    num=count(Score.begin(),Score.end(),15);
    for_each(Score.begin(),Score.end(),info);
    
    cout<<"\nthere "<<num<<"numbers is equal to 15"<<endl;
    return 0;
}
