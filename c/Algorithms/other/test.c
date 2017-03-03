#include<stdio.h>
main ()
{
  int l, i, j;
  int num = 1, lc = 0, rc = 0, rpn = 0;	//定义行增加度lc，列增加度rc，rpn用来存放每行开始的数字值
  int elc = 0;			//定义每行初始增加度
  printf ("please input line numbers: ");
  scanf ("%d", &l);
  for (i = 1; i <= l; i++)
   {
      elc = lc + i + 1;		//每行初始增加度
      rc = i;			//计算下一列增加度
      rpn = num + rc;		//下一列的初始值
      for (j = l; j >= i; j--)
		{
		  printf (" %-4d", num);
		  num = num + elc;	//下一个数字等于初始值加行增加度
		  elc++;		//每行增加度自加
		}
      num = rpn;		//用上一行的首个数值用来计算下一行初始数字值
      printf ("\n");
    }
}
