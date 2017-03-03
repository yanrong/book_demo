#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;
const string ToothbrushCode ("0003");
class IsAToothbrush
{
public:
  bool operator () (string & SalesRecord)
  {
    return SalesRecord.substr (0, 4) == ToothbrushCode;
  }
};
int
main (void)
{
  list < string > SalesRecords;
  SalesRecords.push_back ("0001 Soap");
  SalesRecords.push_back ("0002 Shampoo");
  SalesRecords.push_back ("0003 Toothbrush");
  SalesRecords.push_back ("0004 Toothpaste");
  SalesRecords.push_back ("0003 Toothbrush");
  int Num (0);
  //count_if compare to count has one more function ,as count is a value
  Num =
    count_if (SalesRecords.begin (), SalesRecords.end (), IsAToothbrush ());
  cout << "There were " << Num << " toothbrushes sold" << endl;
  return 0;
}
