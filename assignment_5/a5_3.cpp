/*
Oscar Diec
CS2A
Professor Harden
a5_3.cpp

This program prompts the user to enter a filename and it will open up
a file stream and count the number of words are in the text file. This 
was tricky beacuse the files must be in the same working directory as
this program. So, basically, when the user enters a string (filename),
the program will invoke a library fstream opens the file and reads it 
and then closes the file. At the end of the program, it will display
the number of words (delimited by white space) are in the text file.


*/

#include <iostream>
#include <string>
#include <fstream>
/*
File Names:
file_1.txt
file_2.txt
file_3.txt
file_4.txt
file_5.txt
*/


using namespace std;

int main(){
	
	string fileName, text;
	int wordCount = 0;
	cout << "Enter the filename: ";
	cin >> fileName;		

	while (fileName != "quit"){
		wordCount = 0;
		fstream inputStream;
		inputStream.open(fileName);

		while (inputStream >> text){
			wordCount++;
		} // inner while: count number of words in the text

		cout << "The word count of this text file is " << wordCount << ".\n";
		inputStream.close();

		cout << "Enter another filename: ";
		cin >> fileName;

	} // outer while: repeat the process until the user inputs "quit"

} // main()

// Enter the filename: file_1.txt
// The word count of this text file is 7.
// Enter another filename: file_2.txt
// The word count of this text file is 10.
// Enter another filename: file_3.txt
// The word count of this text file is 21.
// Enter another filename: file_4.txt
// The word count of this text file is 19.
// Enter another filename: file_5.txt
// The word count of this text file is 22.
// Enter another filename: quit
