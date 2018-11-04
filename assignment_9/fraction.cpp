/*
CS 2A
Professor Harden
7/30/2018
fraction.cpp

This is an implementation file of the Fraction class. All the methods and
members of this class are in fraction.h. The purpose of this program is to
compute fractions (+, -, *, /). 


*/

#include <iostream>
#include "fraction.h"
using namespace std;


// This is the Fraction class. This class takes in 0 or 2 parameters. Namely,
// numerator and denominator. 
class Fraction;





// This is the default constructor.
Fraction::Fraction(){
	numerator = 0;
	denominator = 1;
} // Fraction






// This is the constructor (and overloading function) when given two inputs:
// numerator and denominator. I wrote this->simplify() (simplify()) would have
// sufficed but I just wanted
Fraction::Fraction(int inNum, int inDenom) {
	numerator = inNum;
	denominator = inDenom;
	this->simplify();
} // Fraction Constructor







// This function prints out the Fraction object (numerator/denominator).
void Fraction::print() const {
	cout << numerator << "/" << denominator;
} // Fraction::print()






// This function takes in a Fraction object and multiplies the two Fractions.
// It returns the resulting (product) of two Fractions.
Fraction Fraction::multipliedBy(const Fraction &inFrac) const {
	int newNum, newDenom;

	newNum = numerator * inFrac.numerator;
	newDenom = denominator * inFrac.denominator;

	Fraction newFrac(newNum, newDenom);
	newFrac.simplify();
	return newFrac;
} // Fraction::multipledBy







// This function takes in a Fraction object and divides the two Fractions.
// It returns the quotient of two fractions.
Fraction Fraction::dividedBy(const Fraction &inFrac) const {
	int newNum, newDenom;

	newNum = numerator * inFrac.denominator;
	newDenom = denominator * inFrac.numerator;

	Fraction newFrac(newNum, newDenom);
	newFrac.simplify();
	return newFrac;
} // dividedBy()








// This function takes in a Fraction object and divides the two Fractions.
// It returns the sum of two fractions.
Fraction Fraction::addedTo(const Fraction &inFrac) const {
	int leftNum, rightNum;
	int newNum, newDenom;

	leftNum = numerator * inFrac.denominator;
	rightNum = inFrac.numerator * denominator;

	newNum = leftNum + rightNum;
	newDenom = denominator * inFrac.denominator;

	Fraction newFrac(newNum, newDenom);
	newFrac.simplify();
	return newFrac;
} // Fraction::addedTo










// This function takes in a fraction object and subtracts the two Fractions.
// It returns the difference of two fractions.
Fraction Fraction::subtract(const Fraction &inFrac) const {
	int leftNum, rightNum;
	int newNum, newDenom;

	leftNum = numerator * inFrac.denominator;
	rightNum = denominator * inFrac.numerator;

	newNum = leftNum - rightNum;
	newDenom = denominator * inFrac.denominator;

	Fraction newFrac(newNum, newDenom);
	newFrac.simplify();
	return newFrac;
} // Fraction::subtract








// This function accesses the data members and changes (or simplify) the 
// fraction. The two base cases is when the numerator/denomintor is a divisor
// of one another. (E.g. 9/3 --> 3/1, and 3/9 --> 1/3) The last condition (else)
// naively looks for the greatest common factor between numerator and
// denominator.
void Fraction::simplify(){
	if (numerator % denominator == 0){
		numerator = (numerator / denominator);
		denominator = 1;

	}
	else if (denominator % numerator == 0){
		numerator = 1;
		denominator = (denominator / numerator);
	}

	else
		this->reduce();
	
} // Fraction::simplify










// This function uses a crude method O(n) to find the greatest common factor
// of the numerator and denomoinator. If the numerator and denominator are both
// prime numbers -- this program will not do anything (gcf = 1).
void Fraction::reduce(){
        int numIterations;
        if (numerator > denominator)
            numIterations = denominator;
        else
            numIterations = numerator;
        
        // Find Greatest Commmon Factor (Naive Approach)
		int gcf = 1;
		for (int i = 2; i < numIterations; i++){
			if (numerator % i == 0 && denominator % i == 0)
				gcf = i;
		}
		numerator /= gcf;
		denominator /= gcf;
} // Fraction::reduce











// Checks if the two Fractions are equivalent.
bool Fraction::isEqualTo(const Fraction &inFrac) const {
	return numerator * inFrac.denominator == denominator * inFrac.numerator;
	// return (numerator == inFrac.numerator) && (denomintor == inFrac.denomintor); 
} // Fraction::isEqualTo


// Output:
// The result starts off at 0/1
// The product of 9/8 and 2/3 is 3/4
// The quotient of 9/8 and 2/3 is 27/16
// The sum of 9/8 and 2/3 is 43/24
// The difference of 9/8 and 2/3 is 11/24
// The two Fractions are not equal.
// The product of 3/2 and 2/3 is 1/1
