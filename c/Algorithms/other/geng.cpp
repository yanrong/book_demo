#include <iostream>
using namespace std;
int com_div (int x, int y)
{
  int temp;
  if (x < y)
    	com_div (y, x);
  else
  {
      do
		{
			temp = x - y;
			if (y > temp)
			{
				  x = y;
				  y = temp;
			}
			else x = temp;
			
		}while (temp != 0);
      return x;
  }
}

int com_mul (int x, int y)
{				
  return x * y/com_div(x,y);
}

int main (void)
{
  int m, n;
  cout << "Enter two numbers:";
  cin >> m >> n;
  cout<< m <<" and "<< n <<" com-div is:"<<com_div(m,n)<<endl;
  cout<< m <<" and "<< n <<" com-mul is:"<<com_mul(m,n)<<endl;
}

