/*
Oscar Diec
Professor Dave Harden
CS 2A
a10_1.cpp
7/31/2018

This program asks the user to input a nonnegative integer (up to 1000 times) or
exits by inputting a negative number. The program processes each user input.
Once, the user input loop is finished, the program will print out all the 
distinct integers inputted. It will be in the order that the user inputted. 
*/



#include <iostream>
using namespace std;

const int ARRAY_SIZE = 1000;

void readNumbers(int list[], int &numDistinctItems);
bool isDistinctNum(int inputNumber, int count, int array[]);
void printNumbers(int list[], int numDistinct);





// Initializes the array (and its size) and number of distinct items. Then it 
// will read in user input (up to 1000 times) and returns distinct numbers 
// entered.
int main(){
	int numDistinctItems = 0;
	int array[ARRAY_SIZE];
	
	readNumbers(array, numDistinctItems);
	printNumbers(array, numDistinctItems);
} // main











// Reads in user input until the user either entered more than the array size
// or user inputted a negative number. I had to create an early break because 
// array size.
void readNumbers(int list[], int &numDistinctItems){
	int inputNum;
	int count = 0;
	
	while (count < ARRAY_SIZE){
		cout << "Enter a non-negative integer (negative to quit): ";
		cin >> inputNum;

		if (inputNum < 0)
			break;

		if (isDistinctNum(inputNum, count, list)){
			list[numDistinctItems] = inputNum;
			numDistinctItems++;
		}
		count++;
	}
} // readNumbers








// Prints all the distinct numbers in the array. The array and count of 
// distinct number. If user didn't enter any valid numbers in the beginning,
// it will print "You didn't enter any valid numbers!"
void printNumbers(int list[], int numDistinct){
	// O(N)
	if (numDistinct > 0){
		cout << "You entered:\n";
		for (int i = 0; i < numDistinct; i++){
			cout << list[i] << " ";
		}
		cout << endl;
	}
	else{
		cout << "You didn't enter any valid numbers!\n";
	}
} //printNumbers








// This function takes two integers and an array. It will go through the array
// and check if the user-input number is in the array or not.
bool isDistinctNum(int inputNumber,int count, int array[]){
	// O(N) look up 
	for (int i = 0; i <= count - 1; i++){
		if (array[i] == inputNumber)
			return false;
	}
	return true;
} // isDistinctNum







// Output
// Enter a non-negative integer (negative to quit): 1
// Enter a non-negative integer (negative to quit): 2
// Enter a non-negative integer (negative to quit): 3
// Enter a non-negative integer (negative to quit): 2
// Enter a non-negative integer (negative to quit): 1
// Enter a non-negative integer (negative to quit): 6
// Enter a non-negative integer (negative to quit): 3
// Enter a non-negative integer (negative to quit): 4
// Enter a non-negative integer (negative to quit): 5
// Enter a non-negative integer (negative to quit): 2
// Enter a non-negative integer (negative to quit): -4
// You entered:
// 1 2 3 6 4 5 
