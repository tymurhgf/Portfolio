#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include "cstring"
#include "func.h"
using namespace std;

void dotToExclam(char* str) {
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == '.') str[i] = '!';
}

void questToDol(char* str) {
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == '?') str[i] = '$';
}

int kstSymb(char* str, char symb) {
	int k = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == symb) ++k;
	return k;
}

int kstRate(char* str) {
	int k = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (str[i] == '%') ++k;
	return k;
}

int countOfDigit(char* str) {
	int k = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (isdigit(str[i])) ++k;
	return k;
}
int countOfAlpha(char* str) {
	int k = 0;
	for (int i = 0; i < strlen(str); ++i)
		if (isalpha(str[i])) ++k;
	return k;
}
int countOfSymbla(char* str) {
	return strlen(str) - countOfAlpha(str) - countOfDigit(str);
}

int countWord(char* str, char* word) {
	int count = 0;

	if (strlen(word) == 0) return 0;
	char* pos = strstr(str, word);

	while (pos != NULL) {
		count++;
		pos = strstr(pos + strlen(word), word);
	}

	return count;
}

void toUpCase(char* str) {
	for (int i = 0; i < strlen(str); ++i) {
		str[i] = toupper(str[i]);
	}
}

void toLowCase(char* str) {
	for (int i = 0; i < strlen(str); ++i) {
		str[i] = tolower(str[i]);
	}
}

int getWords(char* s, char words[20][40]) {
	int count = 0;
	char* p = strtok(s, " ");

	while (p != NULL && count < 20) {
		strcpy(words[count], p);
		count++;
		p = strtok(NULL, " ");
	}
	return count;
}
void printLengths(char words[20][40], int count) {
	printf("\n\n");
	for (int i = 0; i < count; i++) {
		printf("Word: %s \t Length: %d\n", words[i], int(strlen(words[i])));
	}
}
int findMinIndex(char words[20][40], int count) {
	int minIdx = 0;
	for (int i = 1; i < count; i++) {
		if (strlen(words[i]) < strlen(words[minIdx])) {
			minIdx = i;
		}
	}
	return minIdx;
}
int findMaxIndex(char words[20][40], int count) {
	int maxIdx = 0;
	for (int i = 1; i < count; i++) {
		if (strlen(words[i]) > strlen(words[maxIdx])) {
			maxIdx = i;
		}
	}
	return maxIdx;
}
void changeWords(char words[20][40], int min, int max) {
	char temp[40];
	strcpy(temp, words[min]);
	strcpy(words[min], words[max]);
	strcpy(words[max], temp);
}
void printRes(char words[20][40], int count) {
	printf("Final string: ");
	for (int i = 0; i < count; i++) {
		printf("%s ", words[i]);
	}
}

bool isPalindrome(char* s) {
	for (int i = 0; i < strlen(s) / 2; i++) {
		if (s[i] != s[strlen(s) - 1 - i]) {
			return false; 
		}
	}
	return true;
}
void printPRes(int res) {
	printf("\n");
	if (res == true) {
		printf("\nIs palindrom.\n");
	}
	else {
		printf("\nIs not palindrom.\n");
	}
}



