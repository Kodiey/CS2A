#include <iostream>
#include <fstream>

using namespace std;


int main(){
	cout << "Enter a test score: ";
	cin >> test_score;

	 if(test_score < 60)
	 	cout << "You failed the test!" << endl;
	 if(test_score > 60)
	 	cout << "You passed the test!" << endl;
	 else
	 	cout << "You'll need to study for the next test!";
}