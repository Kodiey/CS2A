/*
CS2A
7/4/18
Professor David Harden
a2_3.cpp




The purpose of this program is to get User's input of first, middle, and last 
name. Then display the the name, initials, a range of letter(s) in the name, 
and how long the name is.

The program starts by prompting the user to enter a first, middle and last name.
There are two ways: the user can put one long string and each name is separated 
by a whitespace or the user can input the number of names separated by a new line.
The program manipulates the user input to printing the whole name in separated lines,
initials, substring of the middle name, the 8th letter in the full name, and the 
length of the full name.
*/



#include <iostream>
#include <string>
using namespace std;


int main(){
	
	string first, middle, last;
	

	// Get User Input
	cout << "Enter a name in the format First Middle Last: ";
	cin >> first >> middle >> last;

	// (1) Print out a whole name
	cout << first << endl
		<< middle << endl
		<< last << endl;
	
	// (2) Person's initials
	cout << first.substr(0, 1) + middle.substr(0, 1) + last.substr(0, 1) 
		 << endl;		

	// (3) First 3 letters of the middle name
	// I opted to use the literal 3 instead of a name constant because the 
	// assignment says not to.
	cout << middle.substr(0, 3) << endl;

	// (4) Print the eighth character in the person's full name
	// I used the literal 7 instead of a name constant because the assignment
	// says not to.
	string fullname = first + " " + middle + " " + last;
	cout << fullname.substr(7, 1)<< endl;

	// (5) Print total number of characters in the person's name
	cout << fullname.length() << endl;

	return 0;
}

/*
Enter a name in the format First Middle Last: James Tiberius Kirk
James
Tiberius
Kirk
JTK
Tib
i
19
*/
