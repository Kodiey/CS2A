/*
CS2A
7/4/18
Professor David Harden
a2_1.cpp
*/

/*
The purpose of this program is to return the number of quarters (25), 
dimes (10), nickels (5), and pennies (1). When the program is compiled,
it will ask for the number of cents (int) to convert into the specific coins. 

Program Specific:

The program prompts the user to input the number of cents (integer) that needs 
to be allocated into coins. The program does some number crunching: computing 
floor integer division (get number of specific coins needed) and uses the modulo
operand to acquire the remaining cents that needs to be sorted. Notice that
we started with largest value coins (quarter) to least value coins (penny). 
Once the computation is finished, the program will print the number of each
specific coin in ascending value order.
*/


#include <iostream>
using namespace std;

const int QUARTER = 25;
const int DIME = 10;
const int NICKEL = 5;


int main(){
	int balance;
	cout << "enter number of cents: ";
	cin >> balance;
	
	int quarters = balance / QUARTER;
	balance %= QUARTER;

	int dimes = balance / DIME;
	balance %= DIME;

	int nickels = balance / NICKEL;
	balance %= NICKEL;

	
	cout << "pennies: " << balance << endl;
	cout << "nickels: " << nickels << endl;
	cout << "dimes: " << dimes << endl;
	cout << "quarters: " << quarters << endl;

	return 0;
}


/*
enter number of cents: 119
pennies: 4
nickels: 1
dimes: 1
quarters: 4
*/



