#include "typename.hpp"
#include<vector>
int main()
{
    std::vector<float> f_vec;
    for(int i=0;i!=10;++i){
        f_vec.push_back(static_cast<float>(1.1*i));
    }
    printcoll(f_vec);
    return 0;
}
