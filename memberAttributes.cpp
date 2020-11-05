#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <cmath>
using namespace std;


// Kurt Hamiter

// Directions: Write a program that demonstrates the Dice class. 
// The program should create an instance of the class and display the side that is initially facing up. 
// Then, use a loop to throw the dice 100  times.

    class Dice {
    private:
        int sideUpValue;
    public:
        void RollDice() {
            sideUpValue = rand() % 6 + 1;;
        }

        int SideUp() {
            return sideUpValue;
        }
    };

    int main() {

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        int storeItemsFrequency[6] = { 0,0,0,0,0,0 };
        int returnValue;

        Dice diceObj;

        for (int i = 0; i < 100; i++) {

            diceObj.RollDice();

            returnValue = diceObj.SideUp();

            storeItemsFrequency[returnValue - 1] += 1;

        }

        for (int i = 0; i < 6; i++) {

            SetConsoleTextAttribute(hConsole, 15);

            cout << i + 1 << " : ";

            for (int j = 0; j < storeItemsFrequency[i]; j++) {

                SetConsoleTextAttribute(hConsole, i + 2);

                cout << char(219) << " ";

            }

            cout << endl << endl;

        }

    }
