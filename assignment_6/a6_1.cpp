/*
Oscar Diec
CS2A
Professor Harden
a6_1.cpp
7/19/2018
*/


#include <iostream>
using namespace std;

// Prototypes
void getDimensions(int &width, int &height, int &stages);
void drawOneRow(int numSpaces);
void drawSpaces(int numSpaces);
void drawOddConeTip(int width);
void drawOddConeBody(int width);
void drawOddCone(int width);
void drawEvenConeTip(int width);
void drawEvenConeBody(int width);
void drawEvenCone(int width);
void drawCone(int width);
void drawHorizontalLine(int numXs);
void draw2VerticalLines(int numSpaces, int numRows);
void drawBox(int width, int height);
void drawRocket(int width, int height, int stages);


/*
This program draws a rocketship that is blasting off. The program
prompts the user to input three specific dimensions: width, height,
and stages.
- Width is how wide the rocketship will be and the height of the cones.
- Height is how tall the stages/boxes will be.
- Stages is the number of boxes will be included in the rocket.

In the main function, we have to initiate the parameters (dimensions) and
two function calls to get dimensions from user and another to draw the rocket.
Based on the parity (even/odd) of the inputted parameters, drawRocket()
will delegate to the correct functions to will properly draw a rocket.
*/
int main(){
	int width;
	int height;
	int stages;

	getDimensions(width, height, stages);
	drawRocket(width, height, stages);
} //main()






// This function prompts users to input the width, height and stages
// of the rocket. We also have to pass the inputted parameters back into
// main. So, we passed them back by reference.
void getDimensions(int &width, int &height, int &stages){
	cout << "Enter width of the rocket: ";
	cin >> width;

	cout << "Enter height of the rocket: ";
	cin >> height;

	cout << "Enter number of stages: ";
	cin >> stages;
} // getDimensions()






// This function prints "X<number of whitespaces (numSpaces)>X"
void drawOneRow(int numSpaces){
	int spaceCount;

	cout << "X";

	for (spaceCount = 0; spaceCount < numSpaces; spaceCount++){
		cout << " ";
	}

	cout << "X" << endl;
} // drawOneRow() 





// This function prints number (numSpaces) of whitespace.
void drawSpaces(int numSpaces){
	int spaceCount;

	for (spaceCount = 0; spaceCount < numSpaces; spaceCount++){
		cout << " ";
	}
} // drawSpaces()





// This prints out the center "X" (or the tip) of an odd-width cone.
void drawOddConeTip(int width){
	int leftSpaces = (width - 1) / 2;
	
	drawSpaces(leftSpaces);
	cout << "X\n";
} // drawOneRow()






// This prints out the rest of the cone: from tip (not inclusive) down.
// (top, down]. The width parameter is passed in by value so that the 
// function
void drawOddConeBody(int width){
	int rows = (width - 1) / 2;
	int leftSpaces, innerSpaces = 1;

	for (int i = 0; i < rows; i++){
		leftSpaces = rows - i - 1;
		drawSpaces(leftSpaces);
		drawOneRow(innerSpaces);
		innerSpaces += 2;
	}
} // drawOddConeBody()






// This function prints out the odd-width cone. It calls two functions to 
// complete its task: drawOddConeTip() and drawOddConeBody().
void drawOddCone(int width){
	drawOddConeTip(width);
	drawOddConeBody(width);
} //drawOddCone()






// This function prints out the even-width cone. By design,
// we want to put two ** on top of the cone. So, the program needs
// to figure out the leftSpaces and rightSpaces it needs to print.
void drawEvenConeTip(int width){
	int leftSpaces;
	leftSpaces = (width - 2) / 2;

	// draw out the tip of even Cones with **
	drawSpaces(leftSpaces);
	cout << "XX\n";
} // drawEvenConeTip()






// This function prints out the body of the even-width cone. Since the
// tip of the cone of even width are with **, then the X's are directly under
// the stars (just at the top of the body.) and works its way down to match
// the rocket's width.
void drawEvenConeBody(int width){
	int leftSpaces, innerSpaces = 2;
	int rows = (width - 2)  / 2;

	for (int rowCount = 0; rowCount < rows; rowCount++){		
		leftSpaces  = rows - rowCount - 1;		
		drawSpaces(leftSpaces);
		drawOneRow(innerSpaces);
		innerSpaces += 2;
	}
} //drawEvenConeBody()






// This function draws an even-width cone. It calls two functions:
// drawEvenConeTip() and drawEvenConeBody().
void drawEvenCone(int width){
	drawEvenConeTip(width);
	drawEvenConeBody(width);
} //drawEvenCone()






// This is the general function that draws a cone. Since drawing
// a rocketship's box depends on the parity of the width, then
// it will direct to the correct cone.
void drawCone(int width){
	
	if (width % 2 == 1) 
		drawOddCone(width);
	
	else
		drawEvenCone(width);
} // drawCone()






// This function draws a horizontal line of X's based on width.
void drawHorizontalLine(int numXs){
	int count;
	for (count = 0; count < numXs; count++){
		cout << "X";
	}
	cout << endl;
} //drawHorizontaLine()






// This function draws two vertical lines with X's at both ends.
// The gap between the two X's is width - 2 and the height of the vertical
// lines are the inputted height.
void draw2VerticalLines(int numSpaces, int numRows){
	int rowCount;

	for (rowCount = 0; rowCount < numRows; rowCount++){
		drawOneRow(numSpaces);
	}	
} //draw2VerticalLines()






// This function is the general function to draw a box. It calls two unique 
// functions: drawHorizontalLine() and draw2VerticalLines().
void drawBox(int width, int height){
	drawHorizontalLine(width);
	draw2VerticalLines(width - 2, height - 2);
	drawHorizontalLine(width);
} //drawBox()






// This is the master function (aside from the main). This function takes on
// the width, height, and stages from getDimensions() and passes the parameters
// (by value) to the two main drawing functions: drawCone() and drawBox().
void drawRocket(int width, int height, int stages){
	drawCone(width);
	
	for (int stageCount = 0; stageCount < stages; stageCount++){
		drawBox(width, height);
	}

	drawCone(width);
} //drawRocket()







// Output:

// Base Case
// Enter width of the rocket: 5
// Enter height of the rocket: 6
// Enter number of stages: 2
//   X
//  X X
// X   X
// XXXXX
// X   X
// X   X
// X   X
// X   X
// XXXXX
// XXXXX
// X   X
// X   X
// X   X
// X   X
// XXXXX
//   X
//  X X
// X   X

// Extra Credit


// Case(Even Width):
//Enter width of the rocket: 10
// Enter height of the rocket: 6
// Enter number of stages: 3
//     XX
//    X  X
//   X    X
//  X      X
// X        X
// XXXXXXXXXX
// X        X
// X        X
// X        X
// X        X
// XXXXXXXXXX
// XXXXXXXXXX
// X        X
// X        X
// X        X
// X        X
// XXXXXXXXXX
// XXXXXXXXXX
// X        X
// X        X
// X        X
// X        X
// XXXXXXXXXX
//     XX
//    X  X
//   X    X
//  X      X
// X        X 


// Case (Odd Width):
// Enter width of the rocket: 7
// Enter height of the rocket: 5
// Enter number of stages: 3
//    X
//   X X
//  X   X
// X     X
// XXXXXXX
// X     X
// X     X
// X     X
// XXXXXXX
// XXXXXXX
// X     X
// X     X
// X     X
// XXXXXXX
// XXXXXXX
// X     X
// X     X
// X     X
// XXXXXXX
//    X
//   X X
//  X   X
// X     X
