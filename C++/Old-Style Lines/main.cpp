#pragma once
#include "iostream"
#include "cstring"
#include "func.h"
using namespace std;

void main() {

	char inputs[40], inputs_t1[40], inputs_t2[40];
	printf("Input something: "); gets_s(inputs, 40);

	//Завдання 1

	strcpy_s(inputs_t1, 40, inputs);

	dotToExclam(inputs_t1);
	printf("\nChanged: %s\n\n", inputs_t1);

	//Завдання 2

	strcpy_s(inputs_t2, 40, inputs);

	questToDol(inputs_t2);
	printf("Changed: %s", inputs_t2);

	//Завдання 3

	char symb_str[40], symb;
	printf("\n\nInput a character: "); gets_s(symb_str, 40);
	symb = symb_str[0];

	printf("Number of characters: %d", kstSymb(inputs, symb));

	//Завдання 4

	printf("\n\nNumber of characters %%: %d", kstRate(inputs));

	//Завдання 5

	printf("\n\nNumber of letters: %d", countOfAlpha(inputs));
	printf("\nNumber of numbers: %d", countOfDigit(inputs));
	printf("\nNumber of characters: %d", countOfSymbla(inputs));

	//Завдання 6

	char slovo_vv[30];
	printf("\n\nInput a word: "); gets_s(slovo_vv, 30);

	printf("The word occurs %d times.", countWord(inputs, slovo_vv));

	//Завдання 7

	toUpCase(inputs);
	printf("\n\nString in uppercase: %s", inputs);

	//Завдання 8

	toLowCase(inputs);
	printf("\n\nString in lowercase: %s", inputs);

	//Завдання 9

	char words[20][40];
	char copy[40];
	strcpy_s(copy, 40, inputs);

	int n = getWords(copy, words);
	printLengths(words, n);
	int min = findMinIndex(words, n);
	int max = findMaxIndex(words, n);
	changeWords(words, min, max);
	printRes(words, n);

	//Завдання 10

	bool res = isPalindrome(inputs);
	printPRes(res);

	cin.get();
	cin.get();
}