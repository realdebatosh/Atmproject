#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

void dispalyMenu()
{
	cout << "\n\n            MENU\n\n";
	cout << "1) DISPLAY THE ACCCOUNT BALANCE\n";
	cout << "2) DISPLAY THE NUMBER OF TRANSACTIONS\n";
	cout << "3) DISPLAY THE INTEREST EARNED DURING THIS PERIOD\n";
	cout << "4) MAKE A DEPOSIT\n";
	cout << "5) MAKE A WITHDRAWAL\n";
	cout << "6) ADD INTEREST FOR THIS PERIOD\n";
	cout << "7) EXIT\n\n";
	cout << " ENTER YOUR CHOICE: ";
}
// Method To Get Choice, Validate Choice and Return Choice to Main Method

char getChoice(char max)
{
	char choice = cin.get();
	cin.ignore(); // Bypass the \n in the input buffer

	while (choice < '1' || choice > max)
	{
		cout << " CHOICE MUST BE BETWEEN 1 AND " << max << ". "
			 << " PLEASE RE-ENTER CHOICE: ";
		choice = cin.get();
		cin.ignore();
	}
	return choice;
}
// Method For Deposit which has an object parameter
void makeDeposit(Account &account)
{
	double rupees;
	cout << "ENTER THE AMOUNT OF DEPOSIT: ";
	cin >> rupees;
	cin.ignore();
	account.makeDeposit(rupees);
}
// Method For Withdrawal
void withdraw(Account &account)
{
	double rupees;
	cout << " ENTER THE AMOUNT OF WITHDRAWAL: ";
	cin >> rupees;
	cin.ignore();
	if (!account.withdraw(rupees))
	{
		cout << "ERROR: Withdra Amount is too large.\n\n";
	}
}
// Main Method of Application
int main()
{
	const char MAX_CHOICE = '7';

	Account savings;

	char choice;
	cout << fixed << showpoint << setprecision(2);
	do
	{
		dispalyMenu();
		choice = getChoice(MAX_CHOICE);

		switch (choice)
		{
		case '1':
			cout << "THE CURRENT BALANCE IS RS.";
			cout << savings.getBalance() << endl;
			break;
		case '2':
			cout << "THERE HAVE BEEN ";
			;
			cout << savings.getTransactions() << " TRANSACTIONS.\n";
			break;
		case '3':
			cout << "INTEREST EARNED FOR THIS PERIOD: RS.";
			cout << savings.getInterest() << endl;
			break;
		case '4':
			makeDeposit(savings);
			break;
		case '5':
			withdraw(savings);
			break;
		case '6':
			savings.calculateInterest();
			cout << "INTEREST ADDED.\n";
		}
	} while (choice != '7');
	return 0;
};