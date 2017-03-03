#include<stdio.h>
void printStar (int lines);
int main (void)
{
  int i, j, k, lines;
  char sele;
  printf ("enter the line numbers :");
  scanf ("%d", &lines);
  printStar (lines);
}

void printStar (int lines)
{
  int i, j, k;
  if ((lines % 2) != 0)
  {
      	for (i = 0; i <= (lines / 2); i++)
		{
		  for (j = 0; j < (lines / 2) - i; j++)
			printf (" ");
		  for (k = 0; k <= 2 * i; k++)
			printf ("*");
		  printf ("\n");
		}
      	for (i = 1; i <= (lines / 2); i++)
		{
		  for (j = 0; j <= i - 1; j++)
			printf (" ");
		  for (k = lines - 2 * i; k > 0; k--)
			printf ("*");
		  printf ("\n");
		}
  }
  else
  {
      	for (i = 0; i < (lines / 2); i++)
		{
		  for (j = 0; j < (lines / 2) - i - 1; j++)
			printf (" ");
		  for (k = 0; k <= 2 * i; k++)
			printf ("*");
		  printf ("\n");
		}
     	for (i = 0; i < (lines / 2); i++)
		{
		  for (j = 0; j < i; j++)
			printf (" ");
		  for (k = lines - 2 * i - 1; k > 0; k--)
			printf ("*");
		  printf ("\n");
		}
  }
}
