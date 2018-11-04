/*
Oscar Diec
Professor Harden
CS2A
7/11/2018
a3_1.cpp



The purpose of this program is to calculate the area of a two-dimensional
figure: a square or a triangle. The program will prompt the user to input
a letter: "t" (for triangle) or "s" (for square). If user correctly enters
either letter, it will prompt the user to input the dimensions. For squares,
the program will ask for the dimension of a side. Whereas for triangles, it will
ask for length of the base and height of the triangle. Assuming the inputs are 
correct, the program will print out the area of the specified shape.
*/

#include <iostream>
#include <iomanip>

using namespace std;



int main(){

	char shape;
	double area;
	cout << "Enter the type of figure (s or t): ";
	cin >> shape;
	
	if (shape  == 's') {
		double side;
		
		cout << "Enter the length of a side: ";
		cin >> side;
		
		area = side * side;
	} // Square Case

	if (shape == 't') {
		double base, height;

		cout << "Enter the base: ";
		cin >> base;

		cout << "Enter the height: ";
		cin >> height;
		
		// According to the assignment, it will best to NOT use any named 
		// constant.
		area  = base * height * 0.5;
	} // Triangle Case

	
	cout << fixed;
	cout << setprecision(1);
	cout << "The area is " <<  area << endl;

	return 0;
	
}


// Square
/*
Enter the type of figure (s or t): s
Enter the length of a side: 9
The area is 81.0
*/

// Triangle
/*
Enter the type of figure (s or t): t
Enter the base: 7
Enter the height: 3
The area is 10.5
*/
