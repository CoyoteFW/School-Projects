//////////////////////////////////////////////////////////////////////
// Filename: AccountMain.cpp
// Date: November 26, 2016
// Programmer: Casey Cox
//
// Description: Part of a program to create and manage bank accounts.
// This part of the program is the Account class main function.
//

#include <iostream>
#include <cstdlib>
#include "Account.h"
#include "stdafx.h"

using namespace std;

double fRand(double fMin, double fMax) // Creation of Random Numbers for Account Balance Creation
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

int menu(int inputAccNum, int choice, Account list[10]) // Menu system functions
{
	// Variable Declarations
	int depositInput;
	int withdrawInput;

	if (choice == 1) // Deposit System
	{
		cout << fixed << setprecision(2) << "Your curent balance is: $" << list[inputAccNum].getBalance() << endl;
		cout << "Enter the amount you would like to deposit: $";
		cin >> depositInput;
		list[inputAccNum].deposit(depositInput);
		cout << endl;
	}
	else if (choice == 2) // Withdraw System
	{
		cout << fixed << setprecision(2) << "Your current balance is: $" << list[inputAccNum].getBalance() << endl;
		cout << "Enter the amount you would like to withdraw: $";
		cin >> withdrawInput;
		list[inputAccNum].withdraw(withdrawInput);
		cout << endl;

	}
	else if (choice == 3) // Show Balance
	{
		cout << "Current Balance: $" << list[inputAccNum].getBalance() << endl;
	}
	else if (choice == 4) // Show interest rates
	{
		cout << "Monthly Interest Rate: " << setprecision(1) << list[inputAccNum].getMonthlyInterestRate() << "%" << endl;
		cout << "Yearly Interest Rate: " << setprecision(1) << list[inputAccNum].getInterest() << "%" << endl;
	}
	else if (choice == 5) // Acoount overview
	{
		cout << "Account ID: " << list[inputAccNum].getAccountId() << endl;
		cout << "Current Balance: $" << fixed << setprecision(2) << list[inputAccNum].getBalance() << endl;
		cout << "Monthly Interest Rate: " << setprecision(1) << list[inputAccNum].getMonthlyInterestRate() << "%" << endl;
		cout << "Monthly Interest Rate Amount: $" << fixed << setprecision(2) << list[inputAccNum].getMonthlyInterest() << endl;
	}
	return 0;
}

int main()
{
	// Placeholders for account information
	Account acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9;
	Account list[10] = { acc0, acc1, acc2, acc3, acc4, acc5, acc6, acc7, acc8, acc9 };

	acc0.setAccountId(0), acc1.setAccountId(1), acc2.setAccountId(2), acc3.setAccountId(3),
	acc4.setAccountId(4), acc5.setAccountId(5), acc6.setAccountId(6), acc7.setAccountId(7),
	acc8.setAccountId(8), acc9.setAccountId(9);

	int inputAccNum;
	cout << "Please Enter An Account Number from 0-9: " << endl;
	cin >> inputAccNum; // Take Input from user for account Id and chooses array element
	list[inputAccNum].setAccountId(inputAccNum);
	if (inputAccNum != -1)
	{
		//This is how I learned how to create random numbers. Also, creation of values for Balance and Interest, based on account selection
		srand(unsigned(time(NULL)));
		list[inputAccNum].setBalance(fRand(10000.00, 20000.00));
		srand(unsigned(time(NULL)));
		list[inputAccNum].setInterest(1.5 + ((double)rand() / RAND_MAX) * (5.0 - 1.5));

		// Front-facing menu
		int choice;
		cout << endl << "Enter 1 to make a deposit" << endl;
		cout << "Enter 2 to make a withdraw" << endl;
		cout << "Enter 3 to check balance" << endl;
		cout << "Enter 4 to check interest rate" << endl;
		cout << "Enter 5 to display account summary" << endl;
		cout << "Enter -1 to return to the main menu" << endl;
		cin >> choice;

		int count = -1;
		for (int g = 0; g > count; g++) // loop to actually run program
		{
			if (choice != -1)
			{
				menu(inputAccNum, choice, list);
				cout << endl << "Enter 1 to make a deposit" << endl;
				cout << "Enter 2 to make a withdraw" << endl;
				cout << "Enter 3 to check balance" << endl;
				cout << "Enter 4 to check interest rate" << endl;
				cout << "Enter 5 to display account summary" << endl;
				cout << "Enter -1 to return to the main menu" << endl;
				cin >> choice;
			}
			else
			{
				cout << "Please Enter An Account Number from 0-9: " << endl;
				cin >> inputAccNum;
				list[inputAccNum].setAccountId(inputAccNum);
				if (inputAccNum != -1)
				{
					srand(unsigned(time(NULL)));
					list[inputAccNum].setBalance((rand()) / (RAND_MAX / (20000.00 - 10000.00)));
					list[inputAccNum].setInterest(1.5 + ((double)rand() / RAND_MAX) * (5.0 - 1.5));

					cout << endl << "Enter 1 to make a deposit" << endl;
					cout << "Enter 2 to make a withdraw" << endl;
					cout << "Enter 3 to check balance" << endl;
					cout << "Enter 4 to check interest rate" << endl;
					cout << "Enter 5 to display account summary" << endl;
					cout << "Enter -1 to return to the main menu" << endl;
					cin >> choice;
				}
				else
				{
					exit(0);
				}				
			}
		}
	}
	else
	{
		exit(0);
	}
}