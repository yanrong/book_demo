//this an error example program
#include <string>
/* while string as a non-reference in function template , char * and string as 
two different type ,you must decay them is a specified type
*/
template <typename T>
inline T const& max(T const a,T const b)
{
	return a < b?b:a;
}

int main()
{
	std::string s;
	::max("apple","peach");
	::max("apple","tomato");
	::max("apple",s);//s.c_str()) OK
}
