//yang1.c
///递归实现杨辉三角
#include <stdio.h>
#include <stdlib.h>
int pos (int x, int y);
int main (void)
{
  int i, j, n;
  printf ("line=");
  scanf ("%d", &n);
  if (n > 12)
  {
      fprintf (stderr, "line nunber above 12\n");
      exit (1);
  }
  //create yang hui number
  for (i = 1; i <= n; i++)
  {
      for (j = 0; j < 24 - 2 * i; j++)
		printf (" ");
      for (j = 1; j <= i; j++)
		printf ("%4d", pos (i, j));
      printf ("\n");
  }
  printf ("\n");
  return 0;
}

int pos (int x, int y)		//x表示行，y表示列
{
	//int z=0;
  	if ((y == 1) || (y == x))	//设置每一行的首尾都为1
    	return 1;
 	//z=pos (x - 1, y) + pos (x - 1, y - 1);
  	return pos (x - 1, y) + pos (x - 1, y - 1);
}
