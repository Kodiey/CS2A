/*
CS2A
Professor Harden
a4_3.cpp
7/15/2018

This program has multiple parts: it gathers information about the attendee, and
what kind of food preference that person likes. Then it returns descriptive
statistics of the attendees that has been process. For example, it tells you
the number of attendees are in a certain age group or food preferences, 
youngest, oldest and  average age in the inputted data.

*/


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	// Age Group variable initiation
	int minor = 0, youngAdult = 0, adult = 0 , oldAdult = 0, senior = 0;

	// Age number variable initiation
	int age, count = 0, totalAge = 0, youngestAge = INT_MAX, oldestAge = 0;

	// Food count variable initiation
	int popcorn = 0, soda = 0, both = 0;
	
	// inStream variable initiation
	char foodPreference;

	while (true){
		cout << "Enter age of attendee (negative number to quit): ";
		cin >> age;

		// Negative Ages serves as sentinal values
		if (age < 0)
			break;

		// Read in food preference
		cout << "Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): ";
		cin >> foodPreference;

		// Food Preference Decisions
		if (foodPreference == 'b')
			both++;

		else if (foodPreference == 's')
			soda++;

		else if (foodPreference == 'p')
			popcorn++;

		// Binning user input into Age Groups 	
		if (age <= 18)
			minor++;

		else if (age <= 30)
			youngAdult++;

		else if (age <= 40)
			adult++;

		else if (age <= 60)
			oldAdult++;

		else
			senior++;

		// Maintains the youngest and oldest age entered.
		if (youngestAge > age)
			youngestAge = age;
		
		else if (oldestAge < age)
			oldestAge = age;

		totalAge += age;
		count++;

	 } // while: get user input, sort and count data.


	 // Once all the data is completed, lets print it out!
	 
	 cout << "\nage 0  to 18: " << minor << endl;
	 cout << "age 19 to 18: " << youngAdult << endl;
	 cout << "age 31 to 40: " << adult << endl;
	 cout << "age 41 to 40: " << oldAdult << endl;
	 cout << "over 60: " << senior << endl;

	 // Need to typecast totalAge or count because both are ints and
	 // average is not necessarily an integer.
	 double averageAge = (double) totalAge / count;

	 cout << "\nfood preference popcorn: " << popcorn << endl;
	 cout << "food preference soda: " << soda << endl;
	 cout << "food preference both: " << both << endl;

	 // Need to set precision
	 cout << fixed << setprecision(1);
	 cout << "The average age was " << averageAge << endl;
	 cout << "The youngest person in attendance was " << youngestAge << endl;
	 cout << "The oldest person in attendance was " << oldestAge << endl;

} // main()


// Enter age of attendee (negative number to quit): 34
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
// Enter age of attendee (negative number to quit): 16
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
// Enter age of attendee (negative number to quit): 68
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
// Enter age of attendee (negative number to quit): 53
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
// Enter age of attendee (negative number to quit): 39
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): p
// Enter age of attendee (negative number to quit): 23
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
// Enter age of attendee (negative number to quit): 21
// Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
// Enter age of attendee (negative number to quit): -1

// age 0  to 18: 1
// age 19 to 18: 2
// age 31 to 40: 2
// age 41 to 40: 1
// over 60: 1

// food preference popcorn: 1
// food preference soda: 4
// food preference both: 2
// The average age was 36.3
// The youngest person in attendance was 16
// The oldest person in attendance was 68

