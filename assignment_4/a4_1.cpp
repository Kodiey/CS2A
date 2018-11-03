/*
Oscar Diec
CS2A
Professor Harden
a4_1.cpp

This program prompts the user to convert number of pounds (lb) to ounces (oz).
Unlike the program from assignment 1, this program prompts the user by
asking a question: whether the user would like to convert more pounds to
ounces. It will continue as long as the user keeps typing the letter 'Y'. Else,
the program will end.
*/



#include <iostream>
using namespace std;


const double poundToOunces = 16;

int main(){
	double pounds, ounces;
	char response;
	cout << "Do you want to convert pounds to ounces (Y/N)? ";
	cin >> response;

	while (response == 'Y'){
		cout << "enter pounds: ";
		cin >> pounds;

		ounces = pounds * poundToOunces;

		cout << pounds << " pounds is " << ounces << " ounces.\n";
		
		cout << "Do you need to convert pounds to ounces again (Y/N)? ";
		cin >> response;
	} // Infinite loop
	
	return 0;

}

/*
enter pounds (enter a negative number to exit): 100
100 pounds is 1600 ounces.
enter pounds (enter a negative number to exit): 50.1
50.1 pounds is 801.6 ounces.
enter pounds (enter a negative number to exit): 4
4 pounds is 64 ounces.
*/