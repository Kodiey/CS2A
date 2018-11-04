/*
a7_1.cpp
Professor Harden
CS 2A
*/


#include <iostream>
#include <iomanip>

using namespace std;

void getProbsPerSet(int &probsPerSet);
void doOneSet(char operand, int probsPerSet, int &result);
void doOneProblem(char operand, int &score, int maxNum);
void generateOperands(char optr, int &firstNum, int &secondNum, int &usrAns, \
					int maxNum);
void calculateCorrectAnswer(char optr, int firstNum, int secondNum, \
							int &correctAns);
void checkAnswer(int userAnswer, int correctAnswer, int &score);
void printHeader(char optr);
void getMaxNum(int &maxNum);
void printReport(int numCorrect1, int numCorrect2, int numCorrect3, \
				 int probsPerSet);

const int numProblemSets = 3;
const int toPercentage = 100;

/*
The purpose of this program is to evaluate a person's ability to do simple
mathematical operations: addition (+), subtraction (-), and multiply (*).
When all the questions are answered, the program will print out a summary of
how the individual did on the math problems.
*/



// This is the main function that calls all the necessary functions to execute
// the purpose of this program. To walk through the function calls, we start
// by calling srand() to create a seed (pseudorandomly generate numbers).
// getProbsPerSet() will ask for user to give number of problems s/he wants per
// problem set. Finally, the program will generate a number of problems 
// specified from (getProbsPerSet) and printReport() displays the performance
// of the individual.
int main(){
	int probsPerSet;
	int numCorrect1 = 0;
	int numCorrect2 = 0;
	int numCorrect3 = 0; 

	srand(static_cast<unsigned>(time(0)));
	getProbsPerSet(probsPerSet);
	doOneSet('+', probsPerSet, numCorrect1);
	doOneSet('-', probsPerSet, numCorrect2);
	doOneSet('*', probsPerSet, numCorrect3);
	printReport(numCorrect1, numCorrect2, numCorrect3, probsPerSet);
} // main






// In this function, the number of correct of each set of problems, is passed 
// in by value and the number of problems per each set. Since all these values are
// integers and needed to be changed to double due to percentages. 
// Finally it prints out the statistics of how the individual performed.
void printReport(int numCorrect1, int numCorrect2, \
				int numCorrect3, int probsPerSet){
	
	double grade1, grade2, grade3;
	grade1 = (double) numCorrect1 / probsPerSet * toPercentage;
	grade2 = (double) numCorrect2 / probsPerSet * toPercentage;
	grade3 = (double) numCorrect3 / probsPerSet * toPercentage;
	int totalProblems = probsPerSet * numProblemSets;
	int totalCorrect = numCorrect1 + numCorrect2 + numCorrect3;
	double overallGrade = (double) totalCorrect / totalProblems * toPercentage;



	cout << setprecision(1) << fixed;
	cout << "Set#1:  You got " << numCorrect1 << " correct out of " 
		 << probsPerSet << " for " << grade1 << "%" << endl;
	
	cout << setprecision(1) << fixed;
	cout << "Set#2:  You got " << numCorrect2 << " correct out of " 
		 << probsPerSet << " for " << grade2 << "%" <<  endl;
	
	cout << setprecision(1) << fixed;
	cout << "Set#3:  You got " << numCorrect3 << " correct out of " 
			 << probsPerSet << " for " << grade3 << "%" << endl;
	
	cout << setprecision(1) << fixed;			
	cout << "Overall you got " << totalCorrect << " correct out of "
		 << totalProblems << " for " << overallGrade << "%" << endl;
} //printReport









// Prompts user to get the maximum value for a given problem set
void getMaxNum(int &maxNum){
	cout << "What is the maximum number for this set? ";
	cin >> maxNum;
	cout << endl;
} // getMaxNum







// Prompts user to input the number problems in problem set
void getProbsPerSet(int &probsPerSet){
	cout << "Enter number problems per set: ";
	cin >> probsPerSet;
	cout << endl; 
}








// Prints the Set number statement based on the operator
void printHeader(char optr){
	switch (optr){
		case '+':
			cout << "Set #1" << endl;
			break;
		case '-':
			cout << "Set #2" << endl;
			break;
		case '*':
			cout << "Set #3" << endl;
			break;												
	}
	cout << "----------" << endl;
}







// This prints out the questions that asks the user input the answer.
// Similarly, result is passed by reference so that later on printReport()
// can access this variable's value. 
void doOneSet(char operand, int probsPerSet, int &result){
	int score;
	int maxNum;

	printHeader(operand);
	getMaxNum(maxNum);

	for (int i = 0; i < probsPerSet; i++){
		doOneProblem(operand, score, maxNum);
		result += score;
	}
	cout << endl;
} // doOneSet







// doOneSet call this function to print out one statement and evaluate the
// user's performance. Since score is passed by reference, it's sent back to
// doOneSet to aggregate the number of times it did something correctly.
void doOneProblem(char operand, int &score, int maxNum){
	int firstNum;
	int secondNum;
	int userAnswer;
	int correctAnswer;
	generateOperands(operand, firstNum, secondNum, userAnswer, maxNum);
	calculateCorrectAnswer(operand, firstNum, secondNum, correctAnswer);
	checkAnswer(userAnswer, correctAnswer, score);
} //doOneProblem








// This generates the random number for first and second number for the problem.
// It asks the user for their answer. Since the first and second number and 
// user answer are passed by reference, so that calculateCorrectAnswer() can 
// access those variables!
void generateOperands(char optr, int &firstNum, int &secondNum, int &usrAns, \
					 int maxNum){
	firstNum = rand() % (maxNum + 1) ;
	secondNum = rand() % (maxNum + 1);
	cout << firstNum << " " << optr << " ";
	cout << secondNum << " = ";
	cin >> usrAns;
} // generateOperands





// This calculates the correct answer for the two randomly generated numbers:
// firstNum and secondNum. Once the correct answer is evaluated it will be 
// passed back to doOneProblem().
void calculateCorrectAnswer(char optr, int firstNum, int secondNum, \
							int &correctAns){
	switch (optr){
		case '+':
			correctAns = firstNum + secondNum;
			break;
		case '-':
			correctAns = firstNum - secondNum;
			break;
		case '*':
			correctAns = firstNum * secondNum;
			break;						
	} // cases for operand
} // calculateCorrectAnswer







// This checks if the userAnswer and correctAnswer are the same. Since
// score is passed by reference, we can pass it back to save results.
void checkAnswer(int userAnswer, int correctAnswer, int &score){
	if (userAnswer == correctAnswer){
		score = 1;
		cout << "correct" << endl;
	}
	else {
		score = 0;		
		cout << "incorrect" << endl;	
	}		
} // checkAnswer


// Output:
// ---------------------------------------------
// Enter number problems per set: 3

// Set #1
// ----------
// What is the maximum number for this set? 100

// 65 + 27 = 79
// incorrect
// 29 + 64 = 93
// correct
// 22 + 50 = 72
// correct

// Set #2
// ----------
// What is the maximum number for this set? 90

// 88 - 10 = 78
// correct
// 39 - 69 = -30
// correct
// 31 - 74 = -43
// correct

// Set #3
// ----------
// What is the maximum number for this set? 20

// 6 * 14 = 84
// correct
// 9 * 12 = 0
// incorrect
// 1 * 6 = 0
// incorrect

// Set#1:  You got 2 correct out of 3 for 66.7%
// Set#2:  You got 3 correct out of 3 for 100.0%
// Set#3:  You got 1 correct out of 3 for 33.3%
// Overall you got 6 correct out of 9 for 66.7%
