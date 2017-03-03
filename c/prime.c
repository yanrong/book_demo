#include <stdio.h>

int visit[100];
int graphics[100][100];
int dist[100];
int prime_graphics(int pos)
{
	int index;
	int sum = 0;
	//set all nodes
	memset(visit,0,sizeof(visit));
	int i,j;
	//add all nodes that adjacent pos node
	for(i = 0;i < m; i++)
	{
		dist[i] = graphics[cur][i];
	}

	for(i = 0;i < m; i++)
	{
		int min = 9999;
		for(j = 0;j < m, j++)
		{
			if(!visit[j] && dist[j] < min) // get distance minimal,recode index
			{
				min = dist[j];
				index = j;
			}
		}
	

		visit[index] = 1;
		sum += min;

		for(j = 0;j < m; j++)
		{
			if(!visit[j] && dist[j] > graphics[index][j])
			{
				dist[j] = graphics[index][j];
			}
		}
	}

	return sum;
}
