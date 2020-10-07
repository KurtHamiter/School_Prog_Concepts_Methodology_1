#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

// Kurt Hamiter

// Instructions: Write a program to calculate the sales tax (7.5%). 
//The program should read up to 5 items with their prices and quantities (quantity per item).  
//The program should stop reading data when Item name entered is NONE. Then print the items, their cost, the total cost and the tax. In other words, a complete receipt

// For colors
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Function used to grab the details and put them in both arrays
int addToArray(string name[], float quantPrice[][2]) {

	// For loop, 5 times at max
	for (int i = 0; i < 5; i++) {

		// Ask for name of item, put into array
		cout << "Enter name of item" << endl;
		cin >> name[i];

		// If item is named "NONE", then break the for loop by ending the function
		if (name[i] == "NONE") {

			// Return the amount of items that were actually inserted
			return i;

		}

		// Ask for quantity of item, insert into second array
		cout << "Enter quantity of item" << endl;
		cin >> quantPrice[i][0];

		// Ask for price of item, insert into second array
		cout << "Enter price of item" << endl;
		cin >> quantPrice[i][1];

	}

	// If user doesn't specify a "NONE" value, then we will return 5, because that's the maximum amount of indexes in both arrays
	return 5;

}

// Procedure used to calculate stuff and print the values
void printInfo(string name[], float quantPrice[][2], int numberOfItems) {

	// Linebreak, tell the user that this is their receipt
	cout << "-------------------------" << endl;
	cout << "Your receipt is: " << endl;

	// Header 
	cout << "ITEM          QUANTITY          PRICE          TOTAL" << endl;

	// Initialize variables used for calculations
	float total = 0;
	float tax = 0;
	float finalTotal = 0;

	// For loop, so we can print only the exact number of items inside the array
	for (int i = 0; i < numberOfItems; i++) {

		// Set text color (based on loop value)
		SetConsoleTextAttribute(hConsole, i + 10);

		// Output values inside array
		cout << name[i] << "          " << quantPrice[i][0] << "                  " << quantPrice[i][1] << "               " << quantPrice[i][0] * quantPrice[i][1] << endl;

		// Calculate total amount to print after this for loop
		total = total + quantPrice[i][0] * quantPrice[i][1];
	}

	// Revert text color to normal
	SetConsoleTextAttribute(hConsole, 15);

	cout << "-------------------------------" << endl;

	// Set text color to yellow
	SetConsoleTextAttribute(hConsole, 14);

	// Print total amount that was calculated earlier
	cout << "TOTAL: " << total << endl;

	// Calculate tax value and print
	tax = total * 0.075;
	cout << "TAX: " << tax << endl;

	// Calculate final total and print
	finalTotal = total + tax;
	cout << "Final Total: " << finalTotal << endl;
}


int main() {
	
	// Initialize array 1 
	string name[5];
	
	// Initialize 2d array
	float quantPrice[5][2];
	
	// Call function and get number back (the number of items entered)
	int numberOfItems = addToArray(name, quantPrice);

	// Call procedure to print all of the information (this is a procedure, because nothing is being sent back)
	printInfo(name, quantPrice, numberOfItems);

}
