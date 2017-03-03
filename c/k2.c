/* 朴素的递归实现  0-1 背包 */
#include <stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

// 返回  前n个物品在容量为W时，能得到的最大价值
int knapSack(int W, int wt[], int val[], int n)
{
   // 没有物品了
   if (n == 0 || W == 0)
       return 0;

   // 如果当前第n个物品超重了，就排除在外
   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);

   //返回两种情况下最大的那个 (1) 包括第n个物品 (2) 不包括第n个物品
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}

// 测试
int main()
{
    int val[] = {60, 100, 120,300};
    int wt[] = {10, 40, 30,100};
    int  W = 170;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}