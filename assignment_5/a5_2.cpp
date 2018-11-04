/*
CS2A
Professor Harden
a5_2.cpp


This program was interesting one. It sums up the squared value from 1 to
floor(number). For example the sum of squares of 5 is 1^2 + 2^2 + 3^2 + 4^2
+ 5^2 or 55. This can calculate with a mathematical equation is even cooler!
The program prompts the user to input an integer greater than 1. (If the user
inputs a non-integer like 1.5, it will do the floor operation and set it to 1.)
The program then walks through a loop that terminates after summing up every
integer between 1 to <inputted integer> (inclusively). Then prints out the
sum of squares.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	int sumOfSquares;
	string question = "Enter a number greater than 0 (less than 1 to quit) ";
	
	cout << question;
	cin >> sumOfSquares;
	
	while (sumOfSquares >= 1){
		int sum = 0;
		for (int i = 1; i <= sumOfSquares; i++){
			sum += i * i;
		}
		cout << "The sum of the squares from 1 to " << sumOfSquares << " is "
			 << sum << endl;
		cout << question;
		cin >> sumOfSquares;			 
	}		

}


// Output

// Enter a number greater than 0 (less than 1 to quit) 4
// The sum of the squares from 1 to 4 is 30
// Enter a number greater than 0 (less than 1 to quit) 1
// The sum of the squares from 1 to 1 is 1
// Enter a number greater than 0 (less than 1 to quit) 0

