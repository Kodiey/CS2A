/*
Oscar Diec
Professor Harden
7/15/2018
CS2A
a4_2.cpp

*/

/*
This program prompts user to input number of pounds and converts it into ounces.
Like a4_1.cpp, this program is an infinite while loop. Instead of asking when to 
terminate, the user inputs a negative number, the program will terminate.

*/


#include <iostream>

using namespace std;

const double poundToOunces = 16;

int main(){
	double pounds = 0, ounces;
	
	while (true){

		cout << "enter pounds (negative number to exit):\t";
		cin >> pounds;

		if (pounds < 0)
			break;

		ounces = pounds * poundToOunces;

		cout << pounds << " pounds is " << ounces << " ounces.\n";
	} // Infinite loop


	return 0;

}

// enter pounds (negative number to exit):	15
// 15 pounds is 240 ounces.
// enter pounds (negative number to exit):	4
// 4 pounds is 64 ounces.
// enter pounds (negative number to exit):	16.1
// 16.1 pounds is 257.6 ounces.
// enter pounds (negative number to exit):	1 
// 1 pounds is 16 ounces.
// enter pounds (negative number to exit):	-1