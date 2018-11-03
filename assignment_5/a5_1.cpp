/* 
Oscar Diec
Professor Harden
CS2A
a5_1.cpp

This program prompts the user to enter a certain number of numbers into the 
command line and the program will terminate once the user inputs the numbers.
The command will print out where the first and last target number (in this
case 7) were in the order of entering numbers. For example, if the user entered
5 numbers: 1 5 6 7 4. The program will say the first and last 7 occured at the
fourth entry. Similarly, if there were two more "7", then it'll return the first
and last indices of 7. If there are no "7" then the program will say no "7"s were
entered. 

*/
#include <iostream>
#include <string>

const int targetNumber = 7;

using namespace std;

int main(){
	int nums, count = 1;
	cout << "How many numbers will be entered? ";
	cin >> nums;
	int inputNum;
	int firstSeven = 0;
	int lastSeven = -1; // sentinal value
	
	while (count <= nums){
		cout << "Enter num: ";
		cin >> inputNum;

		if (inputNum == targetNumber && firstSeven == 0){
			firstSeven = count;
			lastSeven = count;
		}
		
		else if (inputNum == targetNumber && count > lastSeven)
			lastSeven = count;

		count++;
	}
	
	if (firstSeven == 0 && lastSeven == -1)
		cout << "Sorry, no 7's were entered." << endl;

	else{
		cout << "The first 7 was in position " << firstSeven << endl;
		cout << "The last 7 was in position " << lastSeven << endl;
	}

}

// Output

// How many numbers will be entered? 8
// Enter num: 5
// Enter num: 7
// Enter num: 6
// Enter num: 7
// Enter num: 7
// Enter num: 3
// Enter num: 8
// Enter num: 6
// The first 7 was in position 2
// The last 7 was in position 5

// How many numbers will be entered? 8
// Enter num: 5
// Enter num: 2
// Enter num: 6
// Enter num: 7
// Enter num: 1
// Enter num: 3
// Enter num: 8
// Enter num: 6
// The first 7 was in position 4
// The last 7 was in position 4

// How many numbers will be entered? 8
// Enter num: 5
// Enter num: 1
// Enter num: 6
// Enter num: 5
// Enter num: 9
// Enter num: 3
// Enter num: 8
// Enter num: 6
// Sorry, no 7's were entered.
