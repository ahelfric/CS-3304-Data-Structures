// File: bank_account.h
// CLASS PROVIDED: bank_account
//
// CONSTRUCTOR
//	bank_account( )
//		Postcondition: Creates a bank_account object with balance and
//					   annual interest rate set to zero. 
//
// MODIFICATION MEMEBER FUNCTIONS for the bank_account class:
//	void setInterestRate(const double interest_in)
//		Postcondition: Annual interest rate is set to the input variable.
//
// 	void setBalance(conts double balance_in) 
//		Postcondition: Balance is set to the input variable.
//
//	void deposit(double amount)
//		Precondition: Entry has a value greater than zero.
//		Postcondition: Value of balance is increased the input amount.
//
//	void withdraw(double amount)
//		Precondition: Amount >= zero; amount <= balance.
//		Postcondition: Balance has been reduced by the input amount. 
//
//	void updateInterest(double years)
//		Precondition: Years has a non-negative value; Interest > 0;
//		Postcondition: Caculates accumulated interest based on the current
//					   balance and the input number of years, and adds to 
//					   the current balance.
//
// CONSTANT MEMBER FUNTIONS for the bank_account class:
//	double getBalance() const
//		Postcondition: The return value is the current balance
//
//	double getInterestRate() const
//		Postcondition: The return value is the interest rate

#include <cstdlib> // Provides size_t

class bank_account
{
	public:
		// CONSTRUCTOR
		bank_account( );
		// MODIFICATON MEMBER FUNCTIONS
		void setInterestRate(const double& interest_in);
		void setBalance(const double& balance_in);
		void deposit(double amount);
		void withdraw(double amount);
		void updateInterest(double years);
		// CONSTANT MEMBER FUNCTIONS
		double getBalance() const;
		double getInterestRate() const;
	private:
		double balance; //Balance of the bank_account object
		double interest; //Annual Interest Rate
};