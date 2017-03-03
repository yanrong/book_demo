#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long sum = 0, upperlim = 1;
void test(long row, long ld, long rd)
{
   if (row != upperlim)
   {
  long pos = upperlim & ~(row | ld | rd);
  while (pos)
  {
 long p = pos & -pos;
 pos -= p;
 test(row + p, (ld + p) << 1, (rd + p) >> 1);
  }
   } else sum++;
}
int main(int argc, char *argv[])
{
   time_t tm;
   int n = 16;
   if (argc != 1)
  n = atoi(argv[1]);
   tm = time(0);
   if ((n < 1) || (n > 32))
   {
  printf(" ֻ�ܼ���1-32֮��\n");
  exit(-1);
   }
   printf("%d �ʺ�\n", n);
   upperlim = (upperlim << n) - 1;
   test(0, 0, 0);
   printf("����%ld������, ����ʱ��%d�� \n", sum, (int) (time(0) - tm));
}