#include "ProgramFunctions.h"

#include <iostream>
#include <fstream>

using namespace std;

char displayMenu() {
	char choice;

	// Display menu
	cout << "Program Menu Options:" << endl;
	cout << "   1 - Find a number in the array" << endl;
	cout << "   2 - Modify a value in the array" << endl;
	cout << "   3 - Add a new integer to the back of the array" << endl;
	cout << "   4 - Remove an integer from the array" << endl;
	cout << "   Q - Quit program" << endl << endl;

	cout << "Select an Option: ";

	// Get choice
	cin >> choice;
	choice = toupper(choice);

	// Check validity of input and re-prompt user until valid
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 'Q') {
		cout << endl;
		cout << "Invalid Choice. Please enter another option: ";
		cin.ignore(100, '\n');
		cin >> choice;
	}

	cout << endl;

	return choice;
	
}

void runFindFunction(int* arr, int size) {
	int key, index;

	// Get target number
	cout << "Enter a number to find in the array: ";

	key = getIntegerInput();

	// Run find function
	index = findNumber(arr, size, key);

	// If index == -1, then number is not in array
	if (index == -1)
		cout << key << " is not in the array." << endl << endl;

	else
		cout << key << " is located at index " << index << "." << endl << endl;

}

void runModifyFunction(int* arr, int size) {
	int index, newValue;
	bool valid = false;

	// Loop until valid (inbound) input is given, then run the modifyValue function
	while (!valid) {
		try {
			cout << "Enter the index of the value you would like to modify: ";
			index = getIntegerInput();

			if (index < 0 || index >= size)
				throw out_of_range("Index out of Bounds");

			cout << "Enter the new value to replace it: ";
			newValue = getIntegerInput();

			modifyValue(arr, index, newValue);
			valid = true;
		}
		
		// If user enters invalid index, then proceed to next iteration of the loop
		catch (out_of_range& e) {
			cout << e.what() << endl << endl;
			cout << "Please input a different index:\n\n";
			continue;
		}

		// If any unknown errors occur, terminate the program
		catch (...) {
			cout << "Undefined error caught";
			abort();
		}
	}
	
}

// **NOTE** A try catch block for input is located in the getIntegerInput() function
void runPushBackFunction(int* &arr, int &size) {
	int newNum;

	// Get new value
	cout << "Enter a number to add to the end of the array: ";

	newNum = getIntegerInput();

	// Push it to back of array
	pushBackNumber(arr, size, newNum);
}

void runRemoveFunction(int* arr, int size) {
	int index;
	bool valid = false;

	// Loop until valid (inbound) input is given, then remove the value at the given index
	while (!valid) {
		try {
			cout << "Enter the index of the integer you would like to remove: ";
			index = getIntegerInput();

			if (index < 0 || index >= size)
				throw out_of_range("Index out of Bounds");

			removeNumber(arr, index);
			valid = true;
		}

		// If user enters invalid index, then proceed to next iteration of the loop
		catch (out_of_range& e) {
			cout << e.what() << endl << endl;
			cout << "Please input a different index:\n\n";
			continue;
		}

		// If any unknown errors occur, terminate the program
		catch (...) {
			cout << "Undefined error caught";
			abort();
		}
	}
}

int getIntegerInput() {
	int num;
	bool valid = false;

	// Keep asking user for input until valid input is received
	while (!valid) {
		try {
			cin >> num;
			cout << endl;

			// Logic from CS201L
			if (cin.fail()) {
				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				throw runtime_error("Invalid Input Received");
			}

			valid = true;
		}

		// If user enters non-integer value, then proceed to next iteration of the loop
		catch (runtime_error& e) {
			cout << e.what() << endl;
			cout << "Enter another number: ";
			continue;
		}

		// If any unknown errors occur, terminate the program
		catch (...) {
			cout << "Undefined error caught";
			abort();
		}
	}

	return num;
}

void runProgram() {
	// Initialize Array
	int* arr;
	int size = 100;
	arr = new int[size];

	// Create input stream an open input file
	ifstream inFile;
	inFile.open("Input.txt");

	if (!inFile.is_open()) {
		cout << "Input file not opened properly" << endl;
		return;
	}

	// Load Array
	loadArray(inFile, arr, size);

	// Close File
	inFile.close();

	// ================================================= //

	// Run the Program

	bool keepRunning = true;
	char choice;

	cout << "Welcome to the Array Program!\n\n\n";

	while (keepRunning) {

		// Display the array to the user
		displayArray(arr, size);

		// Display menu and get choice
		choice = displayMenu();
		cin.ignore(100, '\n');

		// Run functions based on user choice
		switch (choice) {
		case '1':
			runFindFunction(arr, size);
			break;
		case '2':
			runModifyFunction(arr, size);
			break;
		case '3':
			runPushBackFunction(arr, size);
			break;
		case '4':
			runRemoveFunction(arr, size);
			break;
		case 'Q':
			keepRunning = false;
			break;
		default:
			break;
		}
	}
}