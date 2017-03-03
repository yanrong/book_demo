
#include <stdio.h>
#include <stdlib.h>
//#define N 10
int N;
void insertSort (int *pa);
int
main (void)
{
  printf ("please input sort numbers count:(0-30)");
//warning in MS VC6.0, it do not support variable array,it also exitence the lower version GCC
  scanf ("%d", &N);
  for (; N < 0 || N >= 30;)
    {
      printf ("invalide input! try again!(0-30)");
      scanf ("%d", &N);
    }
  int arr[N];
  int i;
  FILE *fp = fopen ("arr.dat", "r");
  if (!fp)
    {
      printf ("falied to open arr.dat!\n");
      exit (0);
    }
  for (i = 0; i < N; i++)
    {
      fscanf (fp, "%d", arr + i);
    }
  fclose (fp);
  insertSort (arr);
  printf ("after sort :\n");
  for (i = 0; i < N; i++)
    printf ("%d ", *(arr + i));
  printf ("\n");
  return 0;
}

void
insertSort (int *pa)
{
  int i, j;
  int tmp;
/*
for(i=1;i<N;i++)
{
tmp=pa[i];
for(j=i;j>0&&pa[j-1]>tmp;j--)
pa[j]=pa[j-1];
pa[j]=tmp;
}*/
//here is anthoer coding method that using exchange two elements,rahtan overwrite the element like above comments codes 
  for (i = 1; i < N; i++)
    {
      for (j = i; j > 0 && pa[j - 1] > pa[i]; j--, i--)
	{
	  tmp = pa[i];
	  pa[i] = pa[j - 1];
	  pa[j - 1] = tmp;
	}
    }
}
