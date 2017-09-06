//////////////////////////////////////////////////////////////////////
// Filename: Account.h
// Date: November 26, 2016
// Programmer: Casey Cox
//
// Description: Part of a program to create and manage bank accounts.
// This part of the program is the interface of the Account.
//

#ifndef Account_h
#define Account_h

#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>
#pragma once

class Account
{
private:
	// Private Data Members
	int accountId; // Account ID
	double balance; // Current Balance of the account
	double annualInterestRate; // Current Annual Interest Rate of the Account (ex. 4.5)

public:
	// Public Member Functions (Constructors)
	Account(); // Default Constructor (no params) 
	Account(int id, double bal, double interest); //Three-Param struct

	// Public Member Functions (Setters)
	void setAccountId(int x); // Function sets id to x 
	void setBalance(double x); // Function sets balance to x 
	void setInterest(double x); // Function sets annualInterestRate to x 

	// Public Member Functions (Getters)
	int getAccountId(); //Function returns accountId
	double getBalance(); //Function returns balance
	double getInterest(); //Function returns annualInterestRate

	// Public Member Functions
	double getMonthlyInterestRate(); // Function calculates the monthly interest rate and returns the value 
	double getMonthlyInterest(); // Function calculates the amount earned per month from interest and returns
								 // the value rounded to 2 decimal places. (Assume interest is not compounding).
	bool withdraw(double amount); // Function only allows withdraw if the current balance is greater than or equal to the withdraw amount.
								  // Return true if withdrawal is successful, else return false.
	void deposit(double amount); // Function adds the amount passed as a parameter to the current balance.

};

#endif