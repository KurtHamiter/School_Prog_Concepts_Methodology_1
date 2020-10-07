#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

// Kurt hamiter

// Directions: Analyze the constitution text at:
//https://www.usconstitution.net/const.txt (Links to an external site.)
//Display a histogram showing each symbol with its frequency.Because the frequency  might be large, you  might want to consider counting each* as 100 or so.For example :
//A: ***
//B : **
//The above means the letter A appeared 300 times while letter B 200. So you're counting by 100s. 
//Note : Remember, EACH Symbol means all symbols, including numbersand special symbols(like period).

int main() {

	// For colors
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Create array, insert standard alphabet
	char characters[26] = {'A', 'B', 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' , 'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z' };
	int characterCount[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// Create array, insert numbers 0-9
	char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int numberCount[10] = { 0,0,0,0,0,0,0,0,0,0 };

	// Create second array, insert special characters
	char specialCharacters[12] = { ' ', ',', '.', ';', '-', ':', '(', ')', '/', '"', '[', ']' };
	int specialCount[12] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// Initialize character variable to read the file one letter at a time
	char myText;
	
	// Open text file containing the text that this program needs to analyze
	fstream ReadFile("C:\\Users\\Kurt\\Desktop\\const.txt", fstream::in);

	// Read every character from the text file
	while (ReadFile.get(myText))
	{
		// Check if character matches any of the 26 letters in the standard english alphabet
		for (int i = 0; i < 26; i++) {
			if (tolower(characters[i]) == myText) {
				// If match, increment
				characterCount[i]++;
			} else 

			// Same as above, but checks lowercase
			if (toupper(characters[i]) == myText) {
				// If match, increment 
				characterCount[i]++;
			} 
		}

		// Check if any of the characters matches of the 12 special characters
		for (int i = 0; i < 12; i++) {

			if (specialCharacters[i] == myText) {
				// If match, increment
				specialCount[i]++;
			}

		}

		for (int i = 0; i < 10; i++) {

			if (numbers[i] == myText) {
				// If match, increment
				numberCount[i]++;
			}

		}
	}

	// Set color to green
	SetConsoleTextAttribute(hConsole, 10);
	// Each aterisk contains 50 hits. If table cell is less than 50, no aterisk will appear
	cout << "Histogram * = x50" << endl;

	// Display all hits on standard alphabet
	for (int i = 0; i < 26; i++) {

		// Set color to blue
		SetConsoleTextAttribute(hConsole, 11);
		cout << characters[i] << " : ";
		// Set color to red
		SetConsoleTextAttribute(hConsole, 12);
		// Display total divided by 50 (for the aterisks)
		for (int j = 0; j < characterCount[i] / 50; j++) {
			cout << "*";
		}
		// Display number value after the aterisks
		cout << " (" << characterCount[i] << ")" << endl;;
	}

	// Display all hits on numbers
	for (int i = 0; i < 10; i++) {

		// Set color to blue
		SetConsoleTextAttribute(hConsole, 11);
		cout << numbers[i] << " : ";
		// Set color to red
		SetConsoleTextAttribute(hConsole, 12);
		// Display total divided by 50 (for the aterisks)
		for (int j = 0; j < numberCount[i] / 50; j++) {
			cout << "*";
		}
		// Display number value after the aterisks
		cout << " (" << numberCount[i] << ")" << endl;;
	}

	// Display all hits on special characters
	for (int i = 0; i < 12; i++) {

		// Set color to blue
		SetConsoleTextAttribute(hConsole, 11);
		cout << specialCharacters[i] << " : ";
		// Set color to red
		SetConsoleTextAttribute(hConsole, 12);
		// Display total divided by 50 (for the aterisks)
		for (int j = 0; j < specialCount[i] / 50; j++) {
			cout << "*";
		}
		// Display number value after the aterisks
		cout << " (" << specialCount[i] << ")" << endl;;
	}


}