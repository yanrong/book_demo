#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void Print(string& pString)
{
    cout<<pString<<endl;
}

void GetInfo(list<string>& l)
{
    list<string>::const_iterator iter=l.begin();
    for(;iter!=l.end();iter++)
        cout<<*iter<<" ";
    cout<<endl;
}
int main()
{
    list<string> MilkShakes;
   // MilkShakes.reverse(10);
    if(MilkShakes.empty())
        cout<<"first MileShakes is empty!"<<endl;

    MilkShakes.push_back("Chocolate");
    MilkShakes.push_back("Strawberry");
    MilkShakes.push_front("Lima");
    MilkShakes.push_front("Vanilla");

    if(!MilkShakes.empty())
    {
        cout<<"\nInformation message!\n"<<endl;
        GetInfo(MilkShakes);
    }
    for_each(MilkShakes.begin(),MilkShakes.end(),Print);

    return 0;
}
