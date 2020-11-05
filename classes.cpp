#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
#include <cmath>
using namespace std;

// Kurt Hamiter

// Directions: Write a program that calculates the area for the following shapes :

// Right Triangle, Circle, Rectangle.

// User must first select the shape he / she wants, then based on that, the proper data is created

int main() {

    HANDLE  hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Triangle class
    class Triangle {      
    private:
        // Variables for triangle class (can only be accessed by this class because they are private)
        float a, b;
    public:             
        void getData() {   

            for (int i = 0; i < 30; i++) {

                cout << char(220);

            }

            cout << endl;

            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 10);

            // Ask for parameters
            cout << "Enter value for a" << endl;
            cin >> a;
            cout << "Enter value for b" << endl;
            cin >> b;

            SetConsoleTextAttribute(hConsole, 11);

            // Calculate area and print
            cout << "Area of triangle: " << (a * b) / 2 << endl;

        }
    };

    // Circle class
    class Circle {
    private:
        // Variable for circle class (can only be accessed by this class because it is private)
        float r;
    public:
        void getData() {

            for (int i = 0; i < 30; i++) {

                cout << char(220);

            }

            cout << endl;

            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 10);

            // Ask for parameters
            cout << "Enter radius of circle" << endl;
            cin >> r;

            SetConsoleTextAttribute(hConsole, 11);

            // Calculate area and print
            cout << "Area of circle: " << pow(r, 2) * 3.14 << endl;
        }
    };
    
    // Rectangle class
    class Rectangle {
    private:
        // Variables for rectangle class (can only be accessed by this class because they are private)
        float l, w;
    public:
        void getData() {

            for (int i = 0; i < 30; i++) {

                cout << char(220);

            }

            cout << endl;

            HANDLE  hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, 10);
            
            // Ask for parameters
            cout << "Enter length of rectangle" << endl;
            cin >> l;
            cout << "Enter width of rectangle" << endl;
            cin >> w;

            SetConsoleTextAttribute(hConsole, 11);

            // Calculate area and print
            cout << "Area of rectangle: " << w * l << endl;
        }
    };

    // Creat class objects for all shapes
    Triangle Tri;
    Circle Cir;
    Rectangle Rec;
    int chooseMenu;

    while (1) {

        SetConsoleTextAttribute(hConsole, 15);

        // Create menu
        cout << "Choose a value from the menu:" << endl;

        SetConsoleTextAttribute(hConsole, 14);

        cout << "1: Triangle" << endl;
        cout << "2: Circle" << endl;
        cout << "3: Rectangle" << endl;
        cout << "4: Exit" << endl;

        // Get option for menu input
        cin >> chooseMenu;

        // Switch case for choosing menu items
        switch (chooseMenu) {
        case 1:
            Tri.getData();
            break;
        case 2:
            Cir.getData();
            break;
        case 3:
            Rec.getData();
            break;
        case 4:
            goto exit_loop;
            break;
        default:
            goto exit_loop;
            break;

        }

    }

    exit_loop: ;

    
}