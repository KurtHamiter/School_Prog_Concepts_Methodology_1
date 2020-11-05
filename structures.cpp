#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>
#include <string>
#include <Windows.h>

// Kurt Hamiter

// Directions: 
//Write a program that simulates inventory bins in a warehouse. Each bin holds a number of the same type of parts.
//Description of the part kept in the bin
//Number of parts in the bin
//The program should have an array of 10 bins
//Code MUST use struct, functions and loops.

using namespace std;

// Initialize structure so it can be rebuilt in every function
struct Parts {
	string name;
	int totalParts;
};

// For colors
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Called when the parts need to be displayed
void displayParts(Parts totalBin[]) {

	cout << "----------------------------" << endl;

	SetConsoleTextAttribute(hConsole, 14);

	// Loop through all 10 bins, print their names and the amount of parts in each bin
	for (int i = 0; i < 10; i++) {

		cout << i << " : " << totalBin[i].name << " : " << totalBin[i].totalParts << " parts" << endl;

	}

	SetConsoleTextAttribute(hConsole, 15);

	cout << "----------------------------" << endl;

}


// Called when a part is to be added to a specific bin
void addParts(Parts totalBin[]) {

	// Initialize variable for selecting menu option
	int chooseMenu;

	SetConsoleTextAttribute(hConsole, 13);

	cout << "Pick which bin you would like to add to: " << endl;

	SetConsoleTextAttribute(hConsole, 15);

	// Call display parts function, to display all bins and their contents
	displayParts(totalBin);

	// Lopo until user enters correct value
	while (1) {

		cin >> chooseMenu;

		// Check is value is correct. 
		if (chooseMenu >= 0 && chooseMenu < 10) {

			//Break infinite loop
			break;

		}
	}

	// Check if user has entered correct value
	if (chooseMenu >= 0 && chooseMenu < 10) {

		SetConsoleTextAttribute(hConsole, 13);

		cout << "Choose amount to add to " << totalBin[chooseMenu].name << endl;

		SetConsoleTextAttribute(hConsole, 15);

		// Infinite loop, should be broken if user entters a legit value
		while (1) {

			int chooseAmount;
			cin >> chooseAmount;
			// Check if user's input will make total over 30. If not, break the infinite loop
			if (totalBin[chooseMenu].totalParts + chooseAmount <= 30) {
				totalBin[chooseMenu].totalParts = totalBin[chooseMenu].totalParts + chooseAmount;
				SetConsoleTextAttribute(hConsole, 10);
				cout << "Successfully added " << chooseAmount << " Units to " << totalBin[chooseMenu].name << endl;
				SetConsoleTextAttribute(hConsole, 15);
				cout << "----------------------------" << endl;
				break;
			}
			else {
				// Tell the user they entered a wrong value. Loop is not broken so it will automatically reset
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Invalid amount. Total cannot be over 30 items per bin" << endl;
				SetConsoleTextAttribute(hConsole, 15);

			}
		}
	}

}

// Called when a part should be removed
void removeParts(Parts totalBin[]) {

	// Initailize variable to store selected menu option
	int chooseMenu;

	SetConsoleTextAttribute(hConsole, 13);

	cout << "Pick which bin you would like to remove from: " << endl;

	SetConsoleTextAttribute(hConsole, 15);

	// Call display parts function, to print all bins and their contents
	displayParts(totalBin);

	// Infinite loop
	while (1) {

		// Ask user for input
		cin >> chooseMenu;

		// If input is legit, break the infinite loop
		if (chooseMenu >= 0 && chooseMenu < 10) {

			break;

		}

	}

	SetConsoleTextAttribute(hConsole, 13);

	cout << "Choose amount to remove from " << totalBin[chooseMenu].name << endl;

	SetConsoleTextAttribute(hConsole, 15);

	int chooseAmount;

	// Infinite loop
	while (1) {
			
		// Ask for user input
		cin >> chooseAmount;

		// If user input is legit, subtract from bin and break the loop
		if (totalBin[chooseMenu].totalParts - chooseAmount >= 0) {


			totalBin[chooseMenu].totalParts = totalBin[chooseMenu].totalParts - chooseAmount;
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Successfully removed " << chooseAmount << " Units from " << totalBin[chooseMenu].name << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "----------------------------" << endl;
			break;


		}
		else {
			// Input wasn't legit, don't break loop so the user must enter the value again
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Invalid amount entered. Stock would become negative." << endl;
			SetConsoleTextAttribute(hConsole, 15);

		}

	}

	

}

int main()
{
	// Create structure object as an array to easily add bins and automate the rest
	Parts totalBin[10];
	totalBin[0].name = "Valve";
	totalBin[0].totalParts = 10;

	totalBin[1].name = "Bearing";
	totalBin[1].totalParts = 5;

	totalBin[2].name = "Bushing";
	totalBin[2].totalParts = 15;

	totalBin[3].name = "Coupling";
	totalBin[3].totalParts = 21;

	totalBin[4].name = "Flange";
	totalBin[4].totalParts = 7;

	totalBin[5].name = "Gear";
	totalBin[5].totalParts = 5;

	totalBin[6].name = "Gear Housing";
	totalBin[6].totalParts = 5;

	totalBin[7].name = "Vacuum Gripper";
	totalBin[7].totalParts = 25;

	totalBin[8].name = "Cable";
	totalBin[8].totalParts = 18;

	totalBin[9].name = "Rod";
	totalBin[9].totalParts = 12;

	// Infinite loop
	while (1) {

		// Initialize variable to store selected menu option
		int chooseMenu;
	
		// Display menu options
		cout << "Choose an option from the following menu:" << endl;
		cout << "1. Display Bins" << endl;
		cout << "2. Add to Bin" << endl;
		cout << "3. Remove from Bin" << endl;
		cout << "4. Quit" << endl;

		// Ask for user input for menu selection
		cin >> chooseMenu;

		// Switch case to take action based on menu selection
		switch (chooseMenu) {
		case 1:
			displayParts(totalBin);
			break;
		case 2:
			addParts(totalBin);
			break;
		case 3:
			removeParts(totalBin);
			break;
		case 4:
			goto exit_loop;
			break;
		default:
			break;
		}

	}

// Used for breaking out of the loop in the switch statement
exit_loop:;

}