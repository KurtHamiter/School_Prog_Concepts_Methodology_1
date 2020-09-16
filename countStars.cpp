#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

// Kurt Hamiter - 9-16-2020

int main()
{
	// Used for colors
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Make sure each random value is truly random each time. If you don't do this, you'll get the same "random" values every time the program runs.
	srand(time(NULL));

	// Initialize array. First value is maximum value and second value records the number of hits per number range.
	int countRand[10][2] = { {10,0}, {20,0}, {30,0}, {40,0}, {50,0}, {60,0}, {70,0}, {80,0}, {90,0},{100,0} };

	// Initialize first for loop, loop 500 times
	for (int i = 0; i < 500; i++) {

		// Initialize variable, assign random value to it
		int randNum = (rand() % 100);

		// Initialize for loop to determine where in the array the number should land
		for (int j = 0; j < 10; j++) {

			// Initialize variable and grab left value of each array insertion (so we know if we should insert the value or not)
			int upperValue = countRand[j][0];
			// Initialize variable and subtract from previous variable, to create proper range data (for the next step)
			int lowerValue = upperValue - 10;

			// if statement, used to check if number is in range a certain set of values (the left array column)
			if (randNum >= lowerValue && randNum <= upperValue) {

				// Grab current value of right array column (whatever the if statement hit on)
				int currentValue = countRand[j][1];

				// Add one to previous variable and insert back into array
				countRand[j][1] = currentValue + 1;

				// Break current for loop, so we don't have to use any excess computing power or memory looping through useless values that we don't need
				break;
			}

		}
	}

	// For loop for building the output
	for (int i = 0; i < 10; i++) {

		// Set color to white
		SetConsoleTextAttribute(hConsole, 15);

		// Print left column of each array insertion
		cout << (countRand[i][0] - 10) << " - " << countRand[i][0] << ": ";

		// Loop used to create the stars which dictate the value of the right column in each array insertion. Loop amount depends on value of right column.
		for (int j = 0; j < countRand[i][1]; j++) {

			// Set color to red
			SetConsoleTextAttribute(hConsole, 12);
			// Print one star (for each value)
			cout << "*";

		}

		// Set color to white
		SetConsoleTextAttribute(hConsole, 15);

		// Print line break
		cout << endl << "-------------------------------------------------------------------------" << endl;

	}

}