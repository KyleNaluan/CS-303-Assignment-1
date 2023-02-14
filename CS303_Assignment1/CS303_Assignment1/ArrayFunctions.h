// These functions strictly work on modifying/interacting with the array

#pragma once

#include <fstream>

using namespace std;

void loadArray(ifstream& inFile, int *arr, int size);
// pre : input stream opened file properly
// post: loads the array with integers from the input file

int findNumber(int *arr, int size, int key);
// post: returns the index of the target number, -1 if it is not found

void modifyValue(int *arr, int index, int newValue);
// post: changes the value at the given index to the new value, then outputs the old and new value to the user

void pushBackNumber(int *&arr, int &size, int num);
// post: adds the given number to the end of the array after resizing it

void removeNumber(int *arr, int index);
// post: replaces the value at the given index with a 0

void displayArray(int* arr, int size);
// post: displays array with positions labeled by index