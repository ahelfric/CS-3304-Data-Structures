#include <iostream>
using namespace std;

int factorial(int fact) {
	if (fact == 0) return 1;
	else return(fact * factorial(fact-1));
}

int sum(int n) {
	return n + sum(n-1);
}

int fibonacci(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return(fibonacci(n - 1) + fibonacci(n - 2));
}

void nPrintln(string message, int times) {
	if (times >= 1) {
		cout << message << endl;
		nPrintln(message, times - 1);
	}
}

bool isPalindrome(const string& s) {
	if (s.size() <= 1) return true;
	else if (s[0] != s[s.size() -1]) return false;
	else return isPalindrome(s.substr(1, s.size() - 2));
}

int main() {
	int n, fact;
	string message; 
	
	cout << "Enter an integer n: ";
	cin >> n;
	fact = factorial(n);
	cout << "n! = " << fact << endl;
	
	int fib = fibonacci(n);
	cout << "The nth indice of the fibonacci series is: " << fib << endl;
	
	cout << "Enter a message: ";
	cin >> message;
	cout << "Print message how many times?: ";
	cin >> n;
	nPrintln(message, n);
	
	if(isPalindrome(message)) cout << message << " is a palindrome" << endl;
	else cout << message << " is not a palindrome" << endl;
	
	return 0;
}