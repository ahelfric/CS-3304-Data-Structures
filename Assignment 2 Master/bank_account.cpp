// File: bank_account.cpp
// CLASS IMPLEMENTED: bank_account
// INVARIANT for the bag class:
//		1. The dollar amount in the account is the member variable balance
//		2. The annual interest rate is the member variable interest

#include <cassert> 	//Provides assert function
#include "bank_account.h"
using namespace std;

bank_account::bank_account() {
	balance = 0.0;
	interest = 0.0;
}

void bank_account::setInterestRate(const double& interest_in) {
	// Library facilities used: cassert
	assert(interest_in >= 0 && interest_in <= 100);
	interest = interest_in;
}

void bank_account::setBalance(const double& balance_in) {
	// Library facilities used: cassert
	assert(balance_in >= 0);
	balance = balance_in;
}

void bank_account::deposit(double amount) {
	// Library facilities used: cassert
	assert(amount > 0.0);
	balance += amount;
}

void bank_account::withdraw(double amount) {
	// Library facilities used: cassert
	assert(amount >= 0.0);
	assert(amount <= balance);
	balance -= amount;
}

void bank_account::updateInterest(double years) {
	assert(years >= 0);
	assert(interest > 0);
	balance += (balance * (interest / 100) * years);
}

double bank_account::getBalance() const {
	return balance;
}

double bank_account::getInterestRate() const {
	return interest;
}

