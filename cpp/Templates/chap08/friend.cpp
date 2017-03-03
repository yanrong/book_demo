#include <iostream>
using namespace std;

//prototype the class and the functions
template<class T> class strange;
template<class T> ostream& operator<< (ostream& osObject, const strange<T>& sObject);

//begin class
template <class T>
class strange
{
    public:
        // .... function prototypes go here.
            strange(T x,T y);
            friend ostream& operator<< <> (ostream& osObject, const strange<T>& sObject);
    private:
    T a;
    T b;
};
// .... your function definitions go here
template <class T>
strange<T>::strange(T first, T second)
{
        a = first;
        b = second;
}

template <class T>
ostream& operator<< (ostream& osObject, const strange<T>& sObject){
        osObject << sObject.a << ", " << sObject.b;
        return osObject;
}

int main()
{
    strange<int> x1(4,6) , x2(12,2) ;
    //strange<char> y1('m','n') , y2('m','n') ;
    cout << "x1 = " << x1 << endl;
    cout<<x2;
    return 0;
}
