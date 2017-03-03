#include <stdio.h>
#include <stdlib.h>
void shellSort (int *pa);
int N;
int
main (void)
{
  int i;
  FILE *fp;
  printf ("Enter a number(0-30):");
  scanf ("%d", &N);
  int arr[N];
  while (N < 0 || N >= 30)
    {
      printf ("Enter a number(0-30):");
      scanf ("%d", &N);
    }
  if (!(fp = fopen ("arr.dat", "r")))
    {
      printf ("falied open file!\n");
      exit (1);
    }
  for (i = 0; i < N; i++)
    fscanf (fp, "%d", arr + i);
  fclose (fp);
  shellSort (arr);
  printf ("after sort:\n");
  for (i = 0; i < N; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
  return 0;
}

void
shellSort (int *pa)
{
  int i, j, increment, tmp;
  for (increment = N / 2; increment > 0; increment /= 2)
    for (i = increment; i < N; i++)
      {
	tmp = pa[i];
	for (j = i; j >= increment; j -= increment)
	  if (tmp < pa[j - increment])
	    pa[j] = pa[j - increment];
	  else
	    break;
	pa[j] = tmp;
      }
}
