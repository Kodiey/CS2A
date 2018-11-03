/*
Oscar Diec
a8_1.cpp
Professor Harden
CS2A
*/

#include <iostream>
using namespace std;

// This program allows one to add, subtract, multiply, divide, create, print,
// and check the equality of fractions. In order to do this, we have to create
// a custom Fraction class with two data memebers: numerator and denominator.


// This class declaration, Fraction, allows user to contracturo a Fraction 
// object and all these Fraction objects can be printed, added, subtracted,
// multiplied, divded, setted and equalized.

/*
Functions
Public Member Methods:
void set(): Pre-condition: requires two input integers: numerator and denominator,
	   respectively. 
	   Post-Condition: It will create a new Fraction object/variable
void print(): Precondition: none.
	   Post-Condition: it only prints the Fraction object 
	   "[numerator] / [denominator]"
Fraction addedTo(): Pre-condition: requires another Fraction object
		Post-Condition: returns the sum of two fraction objects.
Fraction subtract(): Pre-condition: requires another Fraction object
		Post-Condition: returns the difference of two Fraction objects.
Fraction multipliedTo(): Pre-condition: requires another Fraction object
		Post-Condition: returns the product of two Fraction objects.
Fraction divdedBy(): Pre-condition: requires another Fraction object
		Post-Condition: returns the quotient of two Fractions objects 
Fraction isEqualTo(): Pre-condition: requires another Fraction object
		Post-Condition: returns a boolean to see if the two Fraction objects are
		equal.
*/


class Fraction{

	public:
		void set(int numerator, int denominator);
		void print();
		Fraction addedTo(Fraction frac);
		Fraction subtract(Fraction frac);
		Fraction multipliedBy(Fraction frac);
		Fraction dividedBy(Fraction frac);
		bool isEqualTo(Fraction frac);
	private:
		int numerator;
		int denominator;
}; // Fraction







// This is a setter function. When one wants to create a new Fraction object
// and set it to specific values, we would use this function. Simply pass the
// values by value in the following format: (numerator, denominator).
void Fraction::set(int inNum, int inDenom){
	numerator = inNum;
	denominator = inDenom;
} // Fraction::set 







// This is a printing function. It prints out the fraction form of the Fraction
// object. It takes no input arguments -- it simply uses the data member in the
// fraction object that is already declared.
void Fraction::print(){
	cout << numerator << "/" << denominator;
} // Fraction::print







// This is a adding function. It's not a operator overloading function. It takes
// in another Fraction object and adds the two fractions. It returns a new 
// Fraction object.
Fraction Fraction::addedTo(Fraction frac){
	int leftNum, rightNum;
	int newNum, newDenom;
	Fraction newFraction;

	leftNum = numerator * frac.denominator;
	rightNum = frac.numerator * denominator;
	newNum = leftNum + rightNum;

	newDenom = frac.denominator * denominator;
	
	newFraction.set(newNum, newDenom);
	return newFraction;
} //Fraction::addedTo





// This function multiples two Fraction objects. It requires one fraction input.
// It creats a third Fraction object and returns it.
Fraction Fraction::multipliedBy(Fraction frac){
	int newNum, newDenom;
	newNum = frac.numerator * numerator;
	newDenom = frac.denominator * denominator;
	Fraction new_fraction;
	new_fraction.set(newNum, newDenom);
	return new_fraction;
} // Fraction::multipliedBy()





// This function divides two Fraction objects. It requires one fraction input
// It creates a third Fraction object and returns it. 
Fraction Fraction::dividedBy(Fraction frac){
	int newNum, newDenom;
	Fraction newFraction;

	newNum = numerator * frac.denominator;
	newDenom = denominator * frac.numerator;
	
	newFraction.set(newNum, newDenom);
	return newFraction;
} // Fraction::dividedBy






// This function subtracts the two Fraction objects. It requires the second
// fraction to be inputted. A third Fraction object is created to be returned.
Fraction Fraction::subtract(Fraction frac){
	int newNum, newDenom;
	int leftNum, rightNum;
	Fraction newFraction;

	leftNum = numerator * frac.denominator;
	rightNum = frac.numerator * denominator;

	newNum = leftNum - rightNum;
	newDenom = denominator * frac.denominator;

	newFraction.set(newNum, newDenom);
	return newFraction;

} //Fraction::subtract







// This function belongs to the Fraction class. It also checks if two Fraction
// objects are equal. Unlike other operating functions, it returns a boolean.
bool Fraction::isEqualTo(Fraction inFrac){
	return numerator * inFrac.denominator == inFrac.numerator * denominator;
} // Fraction::isEqualTo








// This is the main function. It creates three Fraction objects and checks all
// the Fraction (class) methods.
int main(){
	Fraction f1;
	Fraction f2;
	Fraction result;

	f1.set(9, 8);
	f2.set(2, 3);

	cout << "The product of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.multipliedBy(f2);
	result.print();
	cout << endl;

	cout << "The quotient of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.dividedBy(f2);
	result.print();
	cout << endl;

	cout << "The sum of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.addedTo(f2);
	result.print();
	cout << endl;

	cout << "The difference of ";
	f1.print();
	cout << " and ";
	f2.print();
	cout << " is ";
	result = f1.subtract(f2);
	result.print();
	cout << endl;

	if (f1.isEqualTo(f2)){
		cout << "The two Fractions are equal." << endl;		
	} else{
		cout << "The two Fractions are not equal." << endl;
	}

}

// Output
// The product of 9/8 and 2/3 is 18/24
// The quotient of 9/8 and 2/3 is 27/16
// The sum of 9/8 and 2/3 is 43/24
// The difference of 9/8 and 2/3 is 11/24
// The two Fractions are not equal.
