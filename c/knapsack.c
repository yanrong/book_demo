#include <stdio.h>
int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int dp[n+1][W+1];
    for (i = 0; i <= n; i++)
    {
       for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                dp[i][w] = 0;
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][W];
}

int main()
{
  int wt[] = {10,40,20,80,50};
  int val[] = {30,70,40,0,80};
  int  W = 80;

  int n = sizeof(val)/sizeof(val[0]);
  printf("%d", knapSack(W, wt, val, n));
  return 0;

}
