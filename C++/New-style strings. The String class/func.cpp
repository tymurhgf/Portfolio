#pragma once
#include "header.h"
#include "string"
#include "iostream"
using namespace std;

void replTabs(string& str) { 
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			str[i] = '\t';
		}
	}
}

int getWords(string s, string words[20]) {
	int count = 0;
	string currWrd = "";

	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == ' ' || s[i] == '.' || s[i] == ',' || s[i] == '!' ||
			s[i] == '?' || s[i] == ';' || s[i] == ':') {

			if (!currWrd.empty()) {
				if (count < 20) {
					words[count] = currWrd;
					count++;
				}
				else {
					return count;
				}
				currWrd = "";
			}
		}
		else {
			currWrd += s[i];
		}
	}
	if (!currWrd.empty() && count < 20) {
		words[count] = currWrd;
		count++;
	}

	return count;
}

void printLengths(string words[20], int count) {
	for (int i = 0; i < count; i++) {
		cout << "Word: " << words[i] << "\t Length: " << words[i].length() << endl;
	}
}

int findMinIndex(string words[20], int count) {
	int minIdx = 0;
	for (int i = 1; i < count; i++) {
		if (words[i].length() < words[minIdx].length()) {
			minIdx = i;
		}
	}
	return minIdx;
}

int findMaxIndex(string words[20], int count) {
	int maxIdx = 0;
	for (int i = 1; i < count; i++) {
		if (words[i].length() > words[maxIdx].length()) {
			maxIdx = i;
		}
	}
	return maxIdx;
}

void combine12Words(string words[12], string& result) {
	result = "";
	for (int i = 0; i < 12; i++) {
		if (i > 0 && i % 3 == 0 && words[i].length() > 0) {
			words[i][0] = toupper(words[i][0]);
		}

		result += words[i];

		if ((i + 1) % 3 == 0) {
			result += ". ";
		}
		else if (i < 11) {
			result += " ";
		}
	}
}

int countMatchWords(string s, string word) {
	string words[20];
	int count, matches = 0;
	count = getWords(s, words);

	for (int i = 0; i < count; i++) {
		if (words[i] == word) {
			matches++;
		}
	}
	return matches;
}

void printMatches(string s, string word) {
	string words[20];
	int count;
	count = getWords(s, words);

	cout << "Matching words: " << endl;
	for (int i = 0; i < count; i++) {
		if (words[i] == word) {
			cout << words[i] << endl;
		}
	}
}

void reverseStr(string s, string& res) {
	res = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		res += s[i];
	}
}

bool isPalindrome(string s) {
	string cleaned = "";
	for (int i = 0; i < s.length(); ++i) {
		if (isalnum(s[i])) {
			cleaned += tolower(s[i]);
		}
	}

	if (cleaned.empty()) return false;

	for (int i = 0; i < cleaned.length() / 2; i++) {
		if (cleaned[i] != cleaned[cleaned.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}