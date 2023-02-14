#include "ArrayFunctions.h"

#include <iostream>
#include <iomanip>

void loadArray(ifstream& inFile, int* arr, int size) {
	// Get integers from input file and put them into array
	for (int i = 0; i < size; i++) {
		inFile >> arr[i];
	}
}

int findNumber(int *arr, int size, int key) {
	// Linear Search through array
	for (int i = 0; i < size; i++) {
		if (arr[i] == key)
			return i;
	}

	// Return -1 if key isn't found, indicating it is not in array
	return -1;
}

void modifyValue(int *arr, int index, int newValue) {
	
	int oldValue = arr[index];

	arr[index] = newValue;

	cout << "Old Value: " << oldValue << endl;
	cout << "New Value: " << newValue << endl << endl;
	
	
}

void pushBackNumber(int *&arr, int &size, int num) {
	// Create a new array of 1 larger size to accommodate for the new number
	int* newArr = new int[size + 1];

	// Copy contents of old array onto new one, then set the last value to the new number
	for (size_t i = 0; i < size; i++)
		newArr[i] = (arr)[i];

	newArr[size] = num;

	// Delete the old array data, then point arr to the new data

	arr = newArr;

	size++;
}

void removeNumber(int *arr, int index) {
	arr[index] = 0;
}

void displayArray(int* arr, int size) {
	
	// Output the array
	cout << "Array: [ ";

	for (int i = 0; i < size; i++) {
		cout << left << setw(3) << arr[i] << " ";
	}

	cout << "]" << endl;

	// Output index legend
	cout << "Index:   ";

	for (int i = 0; i < size; i++) {
		cout << left << setw(3) << i << " ";
	}

	cout << endl << endl;
}