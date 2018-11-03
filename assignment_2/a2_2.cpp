/*
	Oscar Diec
	CS2A
	7/4/18
	Professor David Harden
	a2_2.cpp
*/


/*
The purpose of this program is to convert user-input (double) Celsius and
convert the value to (double) Fahrenheit. The program starts by prompting 
the user for Celsius value. It relies on the Celsius to Fahrenheit converting 
equation and then prints out "<User Input> degrees Celsius is <Converted Value>
degrees Fahrenheit."
*/

#include <iostream>
using namespace std;

int main(){

	double celsius, fahrenheit;

	cout << "enter degrees Celsius: ";
	cin >> celsius;

	fahrenheit = 9.0 / 5.0 * celsius + 32;

	cout << celsius << " degrees Celsius is " 
		 << fahrenheit << " degrees Fahrenheit." << endl;

	return 0;
}


/*
enter degrees Celsius: 30
30 degrees Celsius is 86 degrees Fahrenheit.
*/