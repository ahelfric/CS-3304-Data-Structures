///////////////////   Problem 1.5B
#include <iostream>
using namespace std;

void m(int, int []);

int main()
{
  int x = 1; 
  int y[10]; 
  y[0] = 1;

  m(x, y); 

  cout << "x is " << x << endl;
  cout << "y[0] is " << y[0] << endl;

  return 0;
}

void m(int number, int numbers[])
{
  number = 1001; 
  numbers[0] = 5555; 
}
