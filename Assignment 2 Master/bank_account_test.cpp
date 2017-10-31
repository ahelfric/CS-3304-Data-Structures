// FILE: bank_account_test.cpp
// Non-intereactive test program for bank_account class.
//
// Tests all non-constant member functions for accuracy. 

#include <iostream>			//Provides cout.
#include <cstdlib> 			//Provides size_type.
#include "bank_account.h" 	//Provides bank_account class.
using namespace std;

int main() {
	bank_account test;
	bool answer;
	
	//Testing deposit() method
	cout << "Testing that deposit() is correctly implemented:" << endl;
	cout << "Adding $100.00 to empty bank account: ";
	test.deposit(100.0);
	if (test.getBalance() == 100.0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Adding $500.00 to partially filled account: ";
	test.deposit(500.0);
	if (test.getBalance() == 600.0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	//Testing withdraw() method
	cout << "Testing that withdraw() is correctly implemented." << endl;
	cout << "Withdrawing $200.00 from account with $600: ";
	test.withdraw(200.0);
	if (test.getBalance() == 400.0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Emptying account: ";
	test.withdraw(400.0);
	if (test.getBalance() == 0.0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	//Testing updateInterest() method
	test.setInterestRate(15);
	cout << "Testing that updateInterest() is correctly implemented:" << endl;;
	cout << "Updating interest on an empty account: ";
	test.updateInterest(1.0);
	if (test.getBalance() == 0.0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	test.setBalance(500.0);
	cout << "Testing 15% interest rate on $500.00 over 1 year: ";
	test.updateInterest(1.0);
	if (test.getBalance() == 575.0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	test.setBalance(1000.0);
	cout << "Testing 15% interest rate on $1000.00 over half a year: ";
	test.updateInterest(0.5);
	if (test.getBalance() == 1075) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	return 0;
}