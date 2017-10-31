// FILE: shell.cpp
// An interactive test program for the shellsort method

#include <iostream>		//Provides cout, cin
#include <cstdlib> 		//Provides size_t

//Prototype
void shellsort(int data[], size_t count);

using namespace std;

int main() {
    const size_t ARRAY_SIZE = 10;  // Number of elements in the array to be sorted
    int data[ARRAY_SIZE];          // Array of integers to be sorted
    int user_input;                // Number typed by the user
    size_t count;   		       // How much of the array is used
    size_t i;                      // Array index

    cout << "Please type up to " << ARRAY_SIZE << " positive integers. ";
    cout << "Indicate the list's end with a zero." << endl;

    count = 0;
    cin >> user_input;
    while ((user_input != 0) && (count < ARRAY_SIZE))
    {
        data[count] = user_input;
        count++;
        cin >> user_input;
    }

    shellsort(data, count);
    cout << "In sorted order, your numbers are: "<< endl;
    for (i = 0; i < count; i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}

void shellsort(int data[], size_t count) {
	int temp;
	size_t ss, i, j;
	
	//Start at count/2
	for (ss = count/2; ss > 0; ss = ss/2)
	{
		//Insertion sort for everything of this gap size ss
		for (i = ss; i < count; ++i)
		{
			for (size_t j = i - ss; j >= 0; j = j - ss)
			{
				if (data[j + ss] >= data[j])
				break;
				else
				{
					temp = data[j];
					data[j] = data[j + ss];
					data[j + ss] = temp;
				}
			}
		}
	}
}