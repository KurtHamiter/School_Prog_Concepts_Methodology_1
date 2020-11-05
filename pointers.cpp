#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

// Kurt Hamiter
// Instructions: Write a program to manage student names and grades in a class. The program must read the following data from a file located in c:\temp and should be called data.txt

int main() {
    
    // For colors
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Initialize variables
    string size;
    string one, two;
    float classAvg = 0;

    // Get file location to open text file containing data
    ifstream MyReadFile("C:\\temp\\data.txt");

    // Create structure
    struct grade {
        string name;
        string gpa;  
    };

    // Get first line of text file (so you know how many people there are)
    MyReadFile >> one;
    size = one;

    // Create dynamic structure array using pointers
    grade* grades = new grade[stoi(size)];

    // Loop through text file, store data in structured array
    for (int i = 0; i < stoi(size); i++) {

        MyReadFile >> one >> two;
        grades[i].name = one;
        grades[i].gpa = two;

    }
   
    SetConsoleTextAttribute(hConsole, 10);

    // Close text file
    MyReadFile.close();

    // Format name and GPA
    cout << "NAME";

    for (int i = 0; i < 10; i++) {

        cout << " ";

    }

    cout << "GPA" << endl << endl;

    SetConsoleTextAttribute(hConsole, 11);

    // Print name and GPA which was stored from the array
    for (int i = 0; i < stoi(size); i++) {

        cout << grades[i].name << " ";

        for (int j = 0; j < 10; j++) {

            cout << " ";

        }

        cout << grades[i].gpa << endl;

        for (int i = 0; i < 20; i++) {

            cout << char(196);

        }

        cout << endl;

    }

    // Add all GPA's together (to find the average)
    for (int i = 0; i < stoi(size); i++) {

        classAvg += stof(grades[i].gpa);

    }

    // Divide added up numbers by students in the class (to find the average)
    classAvg /= stoi(size);

    SetConsoleTextAttribute(hConsole, 14);

    // Print class average
    cout << "Class average is: " << classAvg;

    SetConsoleTextAttribute(hConsole, 15);

    
}
