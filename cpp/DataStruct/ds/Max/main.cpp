#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int CompareToMax(int arr[],int n)
{
     int curMax ,i;
    /* make sure there is at least onw element in the array*/
     if(n <= 0)
        return -1;
    /* Set the largest number so far to the first array value*/
    curMax = arr[0];
    for(i = 1;i < n;i++)
    {
        if(arr[i] > curMax)
            curMax = arr[i];
    }
    return curMax;

}

int CompareToAll(int arr[], int n)
{
    int i,j;
    bool isMax;

    /* make sure there is at least onw element in the array*/
     if(n <= 0)
        return -1;
    for(i=n-1;i > 0;i--)
    {
        isMax=true;

        for(j=0;j<n;j++)
        {
            //see if any value is greate
            if(arr[j]>arr[i])
                isMax=false;/* arr[i] is not the largest value*/
        }
        if(isMax) break;
    }
    return arr[i];
}

int main()
{
    const int N=200;
    int A[N];
    srand(time(NULL));

    for(int i=0;i!=N;++i)
    {
        int temp=rand()/1000;
        A[i]=temp;
    }
    cout<<"CompareToMax get max is:"<<CompareToMax(A,N)<<endl;
    cout<<"CompareToAll get max is:"<<CompareToAll(A,N)<<endl;
    return 0;
}
