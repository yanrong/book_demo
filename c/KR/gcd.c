#include <stdio.h>
unsigned gcd (unsigned, unsigned);
int main (void)
{
  unsigned m, n;
  printf ("请输入两个正整数：");
  scanf ("%u%u", &m, &n);
  printf ("%u与%u的最大公约数为：%u\n", m, n, gcd (m, n));
  return 0;
}
unsigned gcd (unsigned m, unsigned n)
{
  unsigned temp;
  if (m < n)
  {
      temp = m;
      m = n;
      n = temp;
  }
  
  if (m % n == 0)
      return n;
  else
      return gcd (n, m % n);
}
