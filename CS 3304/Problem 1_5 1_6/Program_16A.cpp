//Problem 1.6A) Replace the words in quotes with your description of each 
//              value that is displayed.

#include <iostream>
using namespace std;

int main()
{
  int count = 5;
  int* pCount = &count;

  cout << "This is the value of the int count: " << count << endl;
  cout << "This is the address of the int count: " << &count << endl;
  cout << "This is the value of the int* pCount, \nwhich was set as the address of the int count:";
  cout << pCount << endl;
  cout << "This is the value of the object located at the address that pCount refers to: ";
  cout << *pCount << endl;

  return 0;
}
