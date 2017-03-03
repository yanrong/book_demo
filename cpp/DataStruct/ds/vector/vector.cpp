#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> ivec;
    vector<int>::const_iterator iter_vec;//=ivec.begin();
    cout << "Hello world!" << endl;
    srand(time(NULL));
    for(int i=0;i!=10;++i)
    {
        int temp=rand()%100;
        ivec.push_back(temp);
    }

    for(iter_vec=ivec.begin();iter_vec!=ivec.end();++iter_vec)
    {
        cout<<*iter_vec<<" ";
    }

    cout<<endl;
    if(!ivec.empty())
        cout<<"ivec's size is:" << ivec.size();
    return 0;
}
