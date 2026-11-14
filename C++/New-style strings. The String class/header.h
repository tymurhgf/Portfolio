#pragma once
#include "string"
#include "iostream"
using namespace std;

void replTabs(string&);

int getWords(string, string words[20]);
void printLengths(string words[20], int);

int findMinIndex(string words[20], int);
int findMaxIndex(string words[20], int);

void combine12Words(string words[12], string&);

int countMatchWords(string, string);
void printMatches(string, string);

void reverseStr(string, string&);

bool isPalindrome(string);