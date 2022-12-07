#pragma once
class Account
{
private:
	double balance,
		interest,
		intRate;
	int transactions;
public:
	//constructor
	Account(double rate = 0.045, double bal = 0.0) {
		balance = bal;
		intRate = rate;
		interest = 0.0;
		transactions = 0;
	}
	// Method For Deposit
	void makeDeposit(double amount) {
		balance += amount;
		transactions++;
	}
	// Method For Withdrawal
	bool withdraw(double amount); // DEfination in Account.cpp
	
	void calculateInterest() {
		interest = balance * intRate;
		balance += interest;
	}
	// Method For Get Balance
	double getBalance() {
		return balance;
	}
	// Method For Get Interest
	double getInterest() {
		return interest;
	}
	// Method For Get Transactions
	int getTransactions() {
		return transactions;
	}

};