//this an error example program
#include <string>
/* while string as a reference in function template ,it will cause complie error
by different length of string, it means different length belong to different 
type */
template <typename T>
inline T const& max(T const& a,T const& b)
{
	return a < b?b:a;
}

int main()
{
	std::string s;
	::max("apple","peach");
	::max("apple","tomato");
	::max("apple",s);
}
