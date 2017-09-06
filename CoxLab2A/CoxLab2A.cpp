///////////////////////////////////////////////////////////////////////////////////////
// 
//	Filename: CoxLab2A.cpp
//	Date: January 21, 2017
//	Programmer: Casey Cox
//
//	Description: 
//			Program that reads students' names and test grades. The program outputs each name followed by the test
//			scores and the grade. It also finds and prints the highest test score. This program stores data in a struct
//			variable of the type studentType, which has four components: studentFName, and studentLName of string type,
//			testScore of type int, and grade of type string.
//			Does the following:
//			1. Function reads student data into the array.
//			2. Function to assignt he relevant grade to each student.
//			3. Function to find the highest test score.
//			4. Function to print the names of the students with the highest test score.
//			The function should output each students' name in this form: last name followed by a coma, followed by a space,
//			followed by the first name, and the name must be left justified. The main function should only be a collection
//			of function calls.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>

using namespace std;

// Define a struct "studentType"

struct studentType

{
	string studentFName;
	string studentMName;
	string studentLName;
	double testScore;
	char grade;

};

const int MAX_STUDENTS = 6;
// Function Prototypes

void getStudentData(ifstream& inFile, studentType students[], const int MAX_STUDENTS);
void calcGrade(studentType students[], const int MAX_STUDENTS);
int highestScore(const studentType students[], const int MAX_STUDENTS);
void printResult(const studentType students[], const int MAX_STUDENTS);

int main()
{
	ifstream in;
	in.open("student.dat");

	if (in.fail())

	{
		cout << "File could not be opened.\n";
		system("pause");
		system("exit");

	}

	//Define array

	studentType students[20];

	// Call functions

	getStudentData(in, students, MAX_STUDENTS);
	calcGrade(students, MAX_STUDENTS);
	printResult(students, MAX_STUDENTS);

	in.close();
	system("pause");
	return 0;

}

// Define getStudentData

void getStudentData(ifstream& inFile, studentType students[], const int MAX_STUDENTS)
{
	int n = 0;

	while (n < MAX_STUDENTS)
	{
		string lineOfFile = "";
		getline(inFile, lineOfFile);
		istringstream iss(lineOfFile);
		if (lineOfFile != "") {
			int numWord = 1;
			do
			{
				std::string sub;
				iss >> sub;
				if (numWord == 1)
					students[n].studentFName = sub;
				else if (numWord == 2)
					students[n].studentMName = sub;
				else if (numWord == 3)
					students[n].studentLName = sub;
				numWord++;
			} while (!iss.eof());

			if (numWord == 3) {
				students[n].studentLName = students[n].studentMName;
				students[n].studentMName = "";
			}

			inFile >> students[n].testScore;
			n++;
		}
	}
}

//Define calcGrade

void calcGrade(studentType students[], const int MAX_STUDENTS)
{
	int i;

	//Loop until length

	for (i = 0; i < MAX_STUDENTS; i++)
	{
		if (students[i].testScore < 60)
		{
			students[i].grade = 'F';
		}
		else if (students[i].testScore < 70)
		{
			students[i].grade = 'D';
		}
		else if (students[i].testScore < 80)
		{
			students[i].grade = 'C';
		}
		else if (students[i].testScore < 90)
		{
			students[i].grade = 'B';
		}
		else
		{
			students[i].grade = 'A';
		}
	}
}

// Define highestScore

int highestScore(const studentType students[], const int MAX_STUDENTS)
{
	int high = 0, i;

	//Loop until length

	for (i = 0; i < MAX_STUDENTS; i++)
	{
		if (high < students[i].testScore)

			high = students[i].testScore;
	}
	return high;
}

// Define printResult

void printResult(const studentType students[], const int MAX_STUDENTS)
{
	cout << left << setw(30) << "Student Name" << right << setw(10) << "TestScore" << right << setw(7) << "Grade" << endl;

	string name;
	int high, i;

	for (i = 0; i < MAX_STUDENTS; i++)

	{
		name = students[i].studentLName + " " + students[i].studentMName + " " + students[i].studentFName;
		cout << left << setw(30) << name << right << setw(10) << students[i].testScore << right << setw(7) << students[i].grade << endl;

	}

	cout << endl;
	high = highestScore(students, MAX_STUDENTS);
	cout << "Highest Test Score: " << high << endl;
	cout << "Students having the highest test score: " << endl;
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (students[i].testScore == high)
		{
			cout << students[i].studentLName << " " << students[i].studentMName << " " << students[i].studentFName << endl;
		}
	}
}
