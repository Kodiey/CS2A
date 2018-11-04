/*
Professor Dave Harden
CS2A
fraction.h
7/30/2018

*/


#ifndef FRACTION_H
#define FRACTION_H




/*
The Fraction class is called in client.cpp (implementation) and fraction.cpp.
As the name suggests, it takes two integer numbers: numerator and denomintor.
However, there isn't a self-regulating member that checks if the fraction is
invalid (e.g. denomintor = 0). 

There are a few differences comparing to the prior Fraction class. The setter()
member is replaced with a default and normal constructor Fraction() and 
Fraction (int inNum, int inDenom). I also put const on all operation related 
functions/methods (*, /, +, -, =) and print because I didn't want to possibly
unintendedly change an object's value. I did three things: made the parameters
const and passed by reference (can't change it) and return a new Fraction 
object.

Fraction(): Pre-Condition: None
	Post-Condition: Fraction object created and the numerator = 0 and 
	denominator = 1

Fraction(int, int): Precondition: two integer numbers: numerator, denominator.
	Post-Conditoin: it will construct a new Fraction object (simplified)

void print(): pre-conditoin: None
	post-condition: it will print out the fraction object that is human 
	readable.	

Fraction multipliedBy(const Fraction): 	
	Pre-Condition: Fraction object (passed by reference and is constant)
	Post-Condition: Returns a simplified Fraction

Fraction dividedBy(const Fraction):
	Pre-Condition: Fraction object (passed by reference and is constant).
	This doesn't check if any of the denominators are dividing by zero.
	Post-Condition: Returns a simplified Fraction

Fraction addedTo(const Fraction):
	Pre-condition: Fraction object (passed by reference and is constant)
	Post-Condition: returns a simplified Fraction

Fraction subtract(const fraction):
	Pre-Condition: Fraction object (passed by refernce and is constant)
	Post-Condition: returns a simplified Fraction

bool isEqualTo(const Fraction):
	Pre-Condition: Fraction object (passed by reference and is constant)
	post-condition: returns a boolean whether or not two fractions are
	equivalent.	

void simplify() and reduce() makes sure each Fraction object is as simple as
possible.

*/
class Fraction{
	public:
		Fraction();
		Fraction(int inNum, int inDenom);
		void print() const;	
		Fraction multipliedBy(const Fraction &inFrac) const;
		Fraction dividedBy(const Fraction &inFrac) const;
		Fraction addedTo(const Fraction &inFrac) const;
		Fraction subtract(const Fraction &inFrac) const;
		bool isEqualTo(const Fraction &inFrac) const;
	private:
		void simplify();
		void reduce();
		int numerator;
		int denominator;		
};

#endif
