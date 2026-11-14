#pragma once
#include <iostream>
#include <string>
#include "header.h"

using namespace std;

void main() {
    int choice = -1;
    int n, minIdx, maxIdx;
    string str, input, res, reversed;
    string words[20];
    string words12[12];
    bool resBool;

    while (choice != 0) {
        cout << "\n1. Replace spaces with tabs" << endl;
        cout << "2. Count words and lengths" << endl;
        cout << "3. Longest and shortest word" << endl;
        cout << "4. Combine 12 words" << endl;
        cout << "5. Print words matching first" << endl;
        cout << "6. Reverse string" << endl;
        cout << "7. Check palindrome" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Input string: ";
            cin.ignore();
            getline(cin, str);
            replTabs(str);
            cout << "Changed: " << str << endl;
        }
        else if (choice == 2) {
            cout << "Input string: ";
            cin.ignore();
            getline(cin, str);
            n = getWords(str, words);
            cout << "Words count: " << n << endl;
            printLengths(words, n);
        }
        else if (choice == 3) {
            cout << "Input string: ";
            cin.ignore();
            getline(cin, input);
            n = getWords(input, words);
            if (n > 0) {
                minIdx = findMinIndex(words, n);
                maxIdx = findMaxIndex(words, n);
                cout << "Shortest word: " << words[minIdx] << endl;
                cout << "Longest word: " << words[maxIdx] << endl;
            }
        }
        else if (choice == 4) {
            cout << "Input 12 words:" << endl;
            for (int i = 0; i < 12; i++) {
                cout << "Word " << i + 1 << ": ";
                cin >> words12[i];
            }
            combine12Words(words12, res);
            cout << "Result: " << res << endl;
        }
        else if (choice == 5) {
            cout << "Input string: ";
            cin.ignore();
            getline(cin, input);
            n = getWords(input, words);
            if (n > 0) {
                printMatches(input, words[0]);
            }
        }
        else if (choice == 6) {
            cout << "Input string: ";
            cin.ignore();
            getline(cin, input);
            reverseStr(input, reversed);
            cout << "Reversed string: " << reversed << endl;
        }
        else if (choice == 7) {
            cout << "Input string: ";
            cin.ignore();
            getline(cin, input);
            resBool = isPalindrome(input);
            if (resBool) {
                cout << "Is palindrome." << endl;
            }
            else {
                cout << "Is not palindrome." << endl;
            }
        }
    }

}
