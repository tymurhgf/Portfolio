#pragma once

void dotToExclam(char* str);

void questToDol(char* str);

int kstSymb(char* str, char symb);

int kstRate(char* str);

int countOfDigit(char* str);
int countOfAlpha(char* str);
int countOfSymbla(char* str);

int countWord(char* str, char* word);

void toUpCase(char* str);

void toLowCase(char* str);

int getWords(char* s, char words[20][40]);
void printLengths(char words[20][40], int count);
int findMinIndex(char words[20][40], int count);
int findMaxIndex(char words[20][40], int count);
void changeWords(char words[20][40], int min, int max);
void printRes(char words[20][40], int count);

bool isPalindrome(char* s);
void printPRes(int res);