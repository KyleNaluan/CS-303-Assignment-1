// These functions work with program functionality 

#pragma once

#include "ArrayFunctions.h"

using namespace std;

char displayMenu();
// post: displays a menu with the options with 4 options, corresponding to the array functions findNumber, modifyValue, pushBackNumber, and removeNumber
//       then returns the option that the user chose

void runFindFunction(int *arr, int size);
// post: Asks user for input and handles it, then uses it to run the findNumber array function

void runModifyFunction(int* arr, int size);
// post: Asks user for input and handles it, then uses it to run the modifyValue array function

void runPushBackFunction(int* &arr, int &size);
// post: Asks user for input and handles it, then uses it to run the pushBackNumber array function

void runRemoveFunction(int* arr, int size);
// post: Asks user for input and handles it, then uses it to run the removeNumber array function

int getIntegerInput();
// post: gets user input for an integer, checks to see if a number was entered, then returns the int value

void runProgram();
// post: sets up the input file and array and runs the functionalities of the program until user decides to exit
