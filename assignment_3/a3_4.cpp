/*
Professor Harden
CS2A
7/11/18
a3_4.cpp
*/


#include <iostream>
#include <iomanip>

using namespace std;

/*
In this program, we want the net cost of a phone call. At certain hours of the
day and call lengths (duration), the phone service provider gives discounted rates.
The program starts by asking for two user inputs: start time (24-hour clock format
without the colon) and the duration of the call. Assuming both values are correctly
built, the computer computes the gross cost, applies all possible discounts and 
taxes. At the end, the computer prints out the net cost of the phone call.
*/




const int oneHour = 60;
const double callRate = 0.4;
const double federalTax = 1.04;
const double nightDiscount = 1800;
const double morningDiscount = 800; 
const double durationDiscount = 0.15;
const double offHourDicount = 0.5;


int main(){

	int startTime, duration;

	// Get User Input
	cout << "Enter start time: ";
	cin >> startTime;
	cout << "Enter length of call in minutes: ";
	cin >> duration;

	double grossCost = callRate * duration;

	cout << fixed;
	cout << setprecision(2);
	cout << "gross cost: $" << grossCost << endl;

	if (startTime >= nightDiscount || startTime <= morningDiscount)
		grossCost *= offHourDicount;

	if (duration >= oneHour)
		grossCost -= grossCost * durationDiscount;
	
	double netCost = grossCost * federalTax;
	cout << "net cost: $" << netCost << endl;

	return 0;
}

/*
Enter start time: 2322
Enter length of call in minutes: 67
gross cost: $26.80
net cost: $11.85
*/

/*
Enter start time: 759
Enter length of call in minutes: 10
gross cost: $4.00
net cost: $2.08
*/

/*
Enter start time: 1300
Enter length of call in minutes: 100
gross cost: $40.00
net cost: $35.36
*/

/*
Enter start time: 1300
Enter length of call in minutes: 10
gross cost: $4.00
net cost: $4.16
*/
