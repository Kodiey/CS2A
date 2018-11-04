/*
Professor Harden
7/11/2018
CS2A
a3_3.cpp

*/

#include <iostream>
#include <iomanip>
using namespace std;

/*
The purpose of this program is to take in three inputs and return the value of
the mathematical expression. The program starts by prompting the user three times.
First, it asks the user to input a number. Second, it asks for an artimetic 
operator (+, - , /, x). Lastly, it asks for another number. At the end, it will 
print out the value of the mathemathical statement. (E.g. 4.00 + 2.00 = 6.00) 
with 3 significant figures.
*/



int main(){
	double first, second, total;
	char operand; 

	cout << "Enter a number: ";
	cin  >> first;
	cout << "Enter an operator (+, -, x, or /): ";
	cin >> operand;
	cout << "Enter a number: ";
	cin >> second;

	
	switch (operand) {
		case '+':
			total = first + second;
			break;

		case '-':
			total = first - second;
			break;

		case 'x':
			total = first * second;
			break;

		case '/':
			total = first / second;

			break;				

		default: 
			cout << "Invalid Operator";
	}
	cout << fixed;
	cout << setprecision(2);
	cout << first << " " << operand << " " <<  second 
		 << " = " <<  total << endl;

	return 0;
}

/*
Enter a number: 5
Enter an operator (+, -, x, or /): x
Enter a number: 6
5.00 x 6.00 = 30.00
*/




