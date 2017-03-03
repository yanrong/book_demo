#include<iostream>
using namespace std;
int mul(int x,int y)
{
    int rest;
    if(x<y)
        mul(y,x);
    while(rest!=0)
    {
        rest=x%y;
        x=y;
        y=rest;
    }
    return x;
}
int main(int argc, char* argv[])
{
    int m,n,r,b;
    cout<<"Enter two numbers：";
    cin>>m>>n;
    r=mul(m,n);
    b=(m*n)/r;
    cout<<"max_common_divisor："<<r<<endl;
    cout<<"minest_common_mutiply："<<b<<endl;
    return 0;
}

