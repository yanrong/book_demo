//yang2.c
/*
用数组来实现杨辉三角
*/
#include<stdio.h>
#include<stdlib.h>
#define M 12
int
main (void)
{
  int i, j, n;
  int a[M][M];
  printf ("Enter line number:");
  scanf ("%d", &n);
  if (n > M)
  {
      fprintf (stderr, "line is out of range of array size!\n");
      exit (1);
  }
  printf ("杨辉三角！\n");
  for (i = 0; i < n; i++)
  {
      a[i][0] = 1;
      a[i][i] = 1;
  }
  for (i = 2; i < n; i++)
  {
      for (j = 1; j < i; j++)
		{
		  a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
  }
  for (i = 0; i < n; i++)
  {
      printf ("%*d", 24 - i * 2, a[i][0]);//* standard a[i][0] needed width is equal to 24-i*2;
      for (j = 1; j <= i; j++)
		  printf ("%4d", a[i][j]);
      printf ("\n");
  }
  return 0;
}
