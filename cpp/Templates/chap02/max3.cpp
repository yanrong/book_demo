#include <iostream>
#include <string>
#include <cstring>

template <typename T>
inline T const& max(T const& a,T const& b)
{
	return a<b?b:a;
}

//return a pointer that point to bigger one
template <typename T>
inline T* const& max(T* const& a,T* const& b)
{
	return *a < *b ? b : a;
}

//get big one between two string
inline char const* const& max(char const* const& a,char const* const& b)
{
	return std::strcmp(a,b) <0 ? b : b;
}

int main()
{
	int a=7;
	int b=40;
	std::cout<<::max(a,b)<<std::endl;
	
	std::string s="hey";
	std::string t="you";
	std::cout<<::max(s,t)<<std::endl;
	
	int *p1=&a;
	int *p2=&b;
	std::cout<<::max(p1,p2)<<std::endl;
	
	char const* s1="David";
	char const* s2="Nico";
	std::cout<<::max(s1,s2)<<std::endl;
}
