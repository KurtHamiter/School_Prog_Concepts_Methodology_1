#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

// Kurt Hamiter - 9-24-2020

// Instructions: Write a program to read two sets of numbers in two arrays. 

//The maximum size of numbers each array can have is 10, after the user enters the values into the arrays, display the following menu:

//1-) Content of Array 1

//2-) Content of Array 2

//3-) Array 1 UNION Array 2

//4-) Array 1 INTERSECT Array 2

//5-) The values in Array 1 that are NOT in array 2

//6-) The values of Array 2 that are NOT in array 1

//then print the union of both arrays (numbers that exist in one AND the other).

//For example, if my array size was 5 and I entered the following data:

//1 4 5 8 9

//1 5 8 10  11

//Then from the menu I selected 1 (Intersect), I should get:

//The output is: 1 5 8

// Initialize both arrays
int array1[5];
int array2[5];

// First menu option; Content of array 1
void contentArrayOne() {

	cout << "All content from array 1: " << endl;

	// Grab all values from array 1
	for (int i = 0; i < 5; i++) {

		// Print all values from array 1
		cout << array1[i] << " ; ";

	}

	cout << "\n";

}

// Second menu option; Content of array 2
void contentArrayTwo() {

	cout << "All content from array 2: " << endl;

	// Grab all values from array 2
	for (int i = 0; i < 5; i++) {

		// Print all values from array 2
		cout << array2[i] << " ; ";

	}

	cout << "\n";

}

// Third menu option; Array 1 union 2
void unionArrayOne() {

	cout << "Array 1 union array 2: " << endl;

	// Combine 2 arrays
	int combinedArrays[10];

	// Load values from array 1 into indexes 0-4 from combined array
	for (int i = 0; i < 5; i++) {

		combinedArrays[i] = array1[i];

	}

	// Iteration variable for combining two arrays
	int iterateMe = 5;

	// Load values from array 2 into indexes 5-9 from combined array
	for (int i = 0; i < 5; i++) {

		combinedArrays[iterateMe] = array2[i];

		iterateMe++;

	}

	// New array to keep track of duplicate values
	int excludeDuplicates1[10];

	// Check for duplicate values
	for (int i = 0; i < 10; i++) {

		// Should insert into anti-dupe array?
		bool dontInsert = false;

		// Detect if value from large array matches any values already inside duplicate array
		for (int j = 0; j < 10; j++) {

			if (combinedArrays[i] == excludeDuplicates1[j]) {

				dontInsert = true;
				break;

			}

		}

		// Value doesn't exist? Put it into anti dupe array
		if (dontInsert == false) {

			excludeDuplicates1[i] = combinedArrays[i];

		}
		else {
			// Value already exists? Mark it as a zero 
			excludeDuplicates1[i] = 0;

		}
		// Print all values from anti dupe array that are not zeroes
		if (excludeDuplicates1[i] != 0) {

			cout << excludeDuplicates1[i] << endl;

		}

	}

	cout << "\n";

}

// Fourth menu option; Array 1 insersect array 2
void intersectArrayOne() {

	cout << "Array 1 intersect array 2: " << endl;

	// For loop to check all 5 values in array
	for (int i = 0; i < 5; i++) {

		// For loop to check if array 1 and 2 share the same values
		for (int j = 0; j < 5; j++) {

			// Check if value from array 1 matches ANY value from array 2
			if (array1[i] == array2[j]) {

				cout << array1[i] << endl;

			}

		}

	}

}

// Fifth menu option; values in array 1 not in array 2
void notArrayTwo() {

	cout << "Values in array 1 that are NOT in array 2: " << endl;

	// For loop to check all 5 values from array
	for (int i = 0; i < 5; i++) {

		// Does the value match any values in the opposite array?
		bool isInArray = false;

		// Check if array 1 has any matching values inside array 2
		for (int j = 0; j < 5; j++) {

			if (array1[i] == array2[j]) {

				isInArray = true;

			}

		}

		// Value does not exist, so print it
		if (isInArray == false) {

			cout << array1[i] << endl;

		}

	}

}

// Sixth menu option; values in array 2 not in array 1
void notArrayOne() {

	cout << "Values in array 2 that are NOT in array 1: " << endl;

	// For loop to check all 5 values from array
	for (int i = 0; i < 5; i++) {

		// Does the value match any values in the opposite array?
		bool isInArray = false;

		// Check if array 2 has any matching values inside array 1
		for (int j = 0; j < 5; j++) {

			if (array2[i] == array1[j]) {

				isInArray = true;

			}

		}

		// Value does not exist, so print it
		if (isInArray == false) {

			cout << array2[i] << endl;

		}

	}

}

int main()
{
	// Handle colors
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Initialize variable for choosing menu options
	int menuChoose;

	// Tell user to enter first data set
	cout << "Enter data set for first array" << endl;

	// For loop, tells user to enter values 1-5
	for (int i = 0; i < 5; i++) {

		cout << "Enter number " << i + 1 << endl;

		// Get user input
		cin >> array1[i];

	}

	// Tell user to enter data set for second array
	cout << "-------------------" << endl << "Enter data for second array" << endl;

	// For loop, get user input for second array
	for (int i = 0; i < 5; i++) {

		cout << "Enter number " << i + 1 << endl;

		// Get user input
		cin >> array2[i];

	}
	SetConsoleTextAttribute(hConsole, 10);
	// Create menu options
	cout << "-------------------" << endl << "Array construction complete. Choose an option from the following menu: " << endl;

	cout << "1-) Content of Array 1" << endl;

	cout << "2-) Content of Array 2" << endl;

	cout << "3-) Array 1 UNION Array 2" << endl;

	cout << "4-) Array 1 INTERSECT Array 2" << endl;

	cout << "5-) The values in Array 1 that are NOT in array 2" << endl;

	cout << "6-) The values of Array 2 that are NOT in array 1" << endl;

	SetConsoleTextAttribute(hConsole, 15);

	// Get user input for menu options
	cin >> menuChoose;

	// Switch case to decide which menu option to execute based on user input
	switch (menuChoose) {
	case 1:
		// Option 1 pressed
		contentArrayOne();
		break;
	case 2:
		// Option 2 pressed
		contentArrayTwo();
		break;
	case 3:
		// Option 3 pressed
		unionArrayOne();
		break;
	case 4:
		// Option 4 pressed
		intersectArrayOne();
		break;
	case 5:
		// Option 5 pressed
		notArrayTwo();
		break;
	case 6:
		// Option 5 pressed
		notArrayOne();
		break;

	default:
		break;
	}

}
