#include <iostream> 
#include <stdlib.h>
#include <ctime>
using namespace std;

int i = 0;
int x;

int main() {
	srand(time(NULL));
	int start = time(0);
	for (i; i < 1000000000; i++) {
		x += rand();
	}
	int end = time(0);
	cout << end - start << endl;
	return 0;
}