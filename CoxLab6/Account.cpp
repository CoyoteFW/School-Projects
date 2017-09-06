//////////////////////////////////////////////////////////////////////
// Filename: Account.cpp
// Date: November 26, 2016
// Programmer: Casey Cox
//
// Description: Part of a program to create and manage bank accounts.
// This part of the program is the class implementation.
//

#include <iostream>
#include "Account.h"
#include "stdafx.h"
 
using namespace std;

	Account::Account() // Default
	{
	int accountId;
	double balance;
	double annualInterestRate;
	}

	Account::Account(int id, double bal, double interest) // Three Parameter
	{
		accountId = id;
		balance = bal;
		annualInterestRate = interest;
	}

	void Account::setAccountId(int x) // set Id to x
	{
		accountId = x;
	}

	void Account::setBalance(double x)
	{
		balance = x;
		x = (rand() % 20000 + 10000);
	}

	void Account::setInterest(double x) // set annualInterestRate to x
	{
		annualInterestRate = x;
		srand(unsigned(time(NULL)));
		x = (1.5 + ((double)rand() / RAND_MAX) * (5.0 - 1.5));
	}

	int Account::getAccountId() // Returns accountId
	{
		return accountId;
	}

	double Account::getBalance() // returns Balance
	{
		return balance;
	}

	double Account::getInterest() // returns annualInterestRate
	{
		return annualInterestRate;
	}

	double Account::getMonthlyInterestRate() // calculates monthly interest and returns value
	{
		double monthlyInterest = (annualInterestRate / 12);
		return monthlyInterest;
	}

	double Account::getMonthlyInterest() // calculates amount earned per month from interest and returns. Does not compound
	{
		return (getMonthlyInterestRate() * getBalance());
	}

	bool Account::withdraw(double amount) // allows for withdraw if current balance is greater than or equal to withdraw amount.
	{
		if (getBalance() >= amount)
		{
			balance = (balance - amount);
			return true;
		}
		else
		{
			cout << "You don't have enough money." << endl;
			return false;
		}
	}

	void Account::deposit(double amount) // adds amount passed as parameter to current balance
	{
		balance = (balance + amount);
	}