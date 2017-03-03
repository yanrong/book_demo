#include <iostream>
#include <cstring>
#include <cstdio>
#define INF 1000000;
using namespace std;
int arr[1010][1010];
int dis[1010],vis[1010]; //dis[]记录的是起点经过中间点后到达 i点的最短距离 
int main()
{
	int n,p;
	int u,v,w,rec;
	int sum,min;
	while (1)
	{
		sum=0;
		cout<<"请输入点、边的数量："<<endl;
		scanf("%d%d",&n,&p);
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)   
			arr[i][j]=INF; 
		
		for (int i=0;i<p;i++)    //用矩阵建图 
		{
			scanf("%d%d%d",&u,&v,&w);
			arr[u-1][v-1]=arr[v-1][u-1]=w;
		}

		for(int i=0;i<n;i++)
		   dis[i]=arr[0][i];
		memset(vis,0,sizeof(vis));
		
		vis[0]=1;
		dis[0]=0;
		
		for(int i=1;i<n;i++)         //这里 循环 n-1次，确定 n-1条边，否则若为n，则出错 
		{
			 min=INF;              //dis[i]为INF时代表不能与根节点相连
			 
			 for(int j=0;j<n;j++)   //若该点未连到树中，找到此时最小的权值点 
			    if( !vis[j]&&dis[j]<min )
			    {
					min=dis[j];
					rec=j;
				}
			
			sum+=min;	
			cout<<"sum=  "<<sum<<endl;//计算sum的值，代表连到当前点的总权值 
			vis[rec]=1;

			for(int j=0;j<n;j++)   //更新dis[],使通过rec点可以与根节点相连的 dis[]更新 
			{
				if(!vis[j]&&dis[j]>arr[rec][j])
				dis[j]=arr[rec][j];
			}
		}

		for(int i=0;i<n;i++) 
			cout<<dis[i]<<"  ";cout<<endl;
		
		printf("sum=  %d\n",sum);
	}
	return 0;
} 

