// CSCI 202 Mod 4 Assignement
// Summer Daily
// Convert Binary Numbers to Decimals Using a Stack

#include "pch.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

struct Stack {
	int *data;
	int stacktop;
	int numElements;
	int binary;
};

void initializeStack(Stack &theStack) {
	std::cout << "Enter a binary number you want to convert to decimal: ";
	std::cin >> theStack.binary;

	// while loop counts the number of digits in the binary number
	int checkDigits = theStack.binary;
	int n = 0;
	while (checkDigits > 0) {
		checkDigits = checkDigits/10;
		n++;
	}

	theStack.numElements = n;
	theStack.data = new int[theStack.numElements]; // allocated memory
	theStack.stacktop = 0; // set it to empty
}

bool isEmpty(Stack theStack) {
	return (theStack.stacktop == 0);
}

int peek(Stack theStack) {
	if (isEmpty(theStack)) {
		throw std::invalid_argument("Underflow Error");
	}
	return theStack.data[--theStack.stacktop];
}

bool isFull(Stack theStack) {
	return (theStack.stacktop == theStack.numElements);
}

void push(Stack &theStack, int newValue) {
	if (isFull(theStack)) {
		throw std::invalid_argument("Overflow Error");
	}
	theStack.data[theStack.stacktop++] = newValue;
}

int pop(Stack &theStack) {
	if (isEmpty(theStack)) {
		throw std::invalid_argument("Underflow Error");
	}
	return theStack.data[--theStack.stacktop];
}

int main()
{
	Stack myStack;

	initializeStack(myStack);

	int temp = myStack.binary;
	int newNum;
	while (!isFull(myStack)) {
		newNum = temp % 10;
		push(myStack, newNum);
		temp = temp / 10;
	}

	int weight = myStack.numElements-1;
	int decimal = 0;
	while (!isEmpty(myStack)) {
		decimal = decimal + (peek(myStack) * pow(2,weight));
		pop(myStack);
		weight--;
	}

	std::cout << "The binary number you entered: " << myStack.binary << std::endl;
	std::cout << "Converted to decimal = " << decimal << std::endl;

}