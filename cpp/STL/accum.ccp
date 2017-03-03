#include <numeric>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vec(10);
	fill(vec.begin(),vec.end(),1);
	int sum=accumulate(vec.begin(),vec.end(),0);
	cout<<sum<<endl;

	fill(vec.begin(),vec.begin()+vec.size()/2,10);
	cout<<accumulate(vec.begin(),vec.end(),0)<<endl;

	fill_n(vec.begin(),vec.size()/2,0);
	cout<<accumulate(vec.begin(),vec.end(),0)<<endl;

	fill_n(back_inserter(vec),10,42);
	cout<<accumulate(vec.begin(),vec.end(),0)<<endl;
		
	vector<string> v;
	string s;
	while(cin>>s)
		v.push_back(s);
	string concat=accumulate(v.begin(),v.end(),string(""));
	cout<<concat<<endl;
	return 0;
}
