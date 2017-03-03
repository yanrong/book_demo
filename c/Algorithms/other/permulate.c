#include <stdio.h>
#include <stdlib.h>

int n = 0;
void
swap (int *a, int *b)
{
  int m = *a;
  *a = *b;
  *b = m;
}

void
perm (int list[], int k, int m)
{

  int i;
  if (k == m)
    {
      for (i = 0; i <= m; i++)
	    printf ("%c ", list[i]);
      printf ("\n");
      n++;
    }
  else
    {
      for (i = k; i <= m; i++)
	    {
	      swap (&list[k], &list[i]);
	      perm (list, k + 1, m);
	      swap (&list[k], &list[i]);
	    }
    }
}

int
main ()
{
  int k, i;
  printf ("请输入连续自然数的个数：");
  scanf ("%d", &k);
  int *list = (int *) malloc (k);
  for (i = 0; i < k; i++)
    {
      list[i] = 97 + i;
    }
  perm (list, 0, k - 1);
  printf ("total:%d\n", n);
  return 0;
}
