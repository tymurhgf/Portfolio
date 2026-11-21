#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
    TolkoviySlovnyk sl;
    FileManager fm(sl, "dictionary.txt");
    fm.lFromFile();

    int choice = -1;
    string word, def, oldW, newW, newD;

    while (choice != 0) {
        cout << "1. Search\n2. Add\n3. Remove\n4. Edit\n5. Show All\n6. Save\n0. Exit\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            continue;
        }
        cin.ignore();

        if (choice == 1) {
            cout << "Word: "; getline(cin, word);
            cout << (sl.findSlov(word, def) ? "Definition: " + def : "Not found") << '\n';
        }
        else if (choice == 2) {
            cout << "Word: "; getline(cin, word);
            cout << "Definition: "; getline(cin, def);
            cout << (sl.dodSlov(word, def) ? "Added" : "Error") << '\n';
        }
        else if (choice == 3) {
            cout << "Word: "; getline(cin, word);
            cout << (sl.vydSlov(word) ? "Removed" : "Not found") << '\n';
        }
        else if (choice == 4) {
            cout << "Old word: "; getline(cin, oldW);
            cout << "New word: "; getline(cin, newW);
            cout << "New definition: "; getline(cin, newD);
            cout << (sl.editZap(oldW, newW, newD) ? "Updated" : "Error") << '\n';
        }
        else if (choice == 5) {
            sl.showAll();
        }
        else if (choice == 6) {
            cout << (fm.saveToFile() ? "Saved" : "Error") << '\n';
        }
		cout << "\n";
    }
	cin.get();
	cin.get();
}
