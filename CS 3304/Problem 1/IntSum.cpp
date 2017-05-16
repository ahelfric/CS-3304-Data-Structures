#include <iostream>
using namespace std;
int integerN, output = 0;

int main() {
	cout << "Enter a positive integer: ";
	cin >> integerN;
	for(int i = integerN; i > 0; i--) {
		output = output + i;
	}
	cout << "For positive integer N = " << integerN << ",\nthe sum of the first ";
	cout << integerN << " integers is " << output << ".\n" << endl;
	
	return 0;
}