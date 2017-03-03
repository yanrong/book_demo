#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int > ivec;
	cout<<"ivec's size:"<<ivec.size()<<"\tivec's capacity:"<<ivec.capacity()<<endl;
	for(vector<int>::size_type ix=0;ix!=24;++ix)
		ivec.push_back(ix);
	cout<<"ivec's size:"<<ivec.size()<<"\tivec's capacity:"<<ivec.capacity()<<endl;
	ivec.reserve(50);
	cout<<"ivec's size:"<<ivec.size()<<"\tivec's capacity:"<<ivec.capacity()<<endl;
	while(ivec.size()!=ivec.capacity())
		ivec.push_back(0);
	cout<<"ivec's size:"<<ivec.size()<<"\tivec's capacity:"<<ivec.capacity()<<endl;
	ivec.push_back(42);
	
	cout<<"ivec's size:"<<ivec.size()<<"\tivec's capacity:"<<ivec.capacity()<<endl;
	return 0;
}
