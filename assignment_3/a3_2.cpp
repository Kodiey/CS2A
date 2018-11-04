/*
CS2A
7/11/2018
a3_2.cpp
*/


#include <iostream>

using namespace std;

/*
The purpose of this program, is to determine the education level based on the
number of years the student spent in school. The program starts by prompting 
the user to input the number of years spent in school. From there, the program
goes through a series of conditional statements to determine what's the level
of education a student has. Once the program goes through the condtional 
statements, it will return the education level of the student, ranging from
no schooling to college.
*/



const int endElementary = 6;
const int beginMiddle = 7;
const int endMiddle = 8;
const int beginHigh = 9;
const int endHigh = 12;

int main(){

	int years;
	cout << "Enter years of school: ";
	cin >> years;

	// Be sure to use named constants rather than any numbers other than 0 
	// in this program.

	if (years < 0)
		cout << "years of school must be a non-negative integer\n";

	else if (years == 0)
		cout << "no school\n";

	else if (years > 0 && years <= endElementary)
		cout << "elementary school\n";

	else if (years >= beginMiddle && years <= endMiddle)
		cout << "middle school\n";

	else if (years >= beginHigh && years <= endHigh)
		cout << "high school\n";

	else
		cout << "college\n";

	return 0;
}



/*
Enter years of school: 7
middle school
*/

/*
Enter years of school: -4
years of school must be a non-negative integer
*/
