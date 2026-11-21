#pragma once
#include <map>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
using namespace std;

class TolkoviySlovnyk {
private:
    map<string, string> zp;
public:
    TolkoviySlovnyk() = default;
    TolkoviySlovnyk(const map<string, string>& inZp): zp(inZp) {}
    const map<string, string>& getSlovn() const {
        return zp;
    }
    int getSize() const {
        return zp.size();
	}
    bool isEmpty() const {
        return zp.empty();
	}
    void clearSlov() {
        zp.clear();
	}
    void setSlov(const map<string, string>& inZp) {
        zp = inZp;
    }

    bool findSlov(const string& shukSl, string& znaydZnach) const {
        auto poz = zp.find(shukSl);
        if (poz != zp.end()) {
            znaydZnach = poz->second;
            return true;
        }
        return false;
    }
    bool dodSlov(const string& novSl, const string& novZnach) {
        if (novSl.empty() || novZnach.empty() || zp.count(novSl) > 0) {
            return false;
        }
        zp.insert(pair<string, string>(novSl, novZnach));
        return true;
    }
    bool vydSlov(const string& slov) {
        if (zp.erase(slov) > 0) {
            return true;
        }
        return false;
    }
    bool editZap(const string& oldSl, const string& novSl, const string& novZnach) {
        auto poz = zp.find(oldSl);
        if (poz == zp.end() || novSl.empty() || novZnach.empty()) {
            return false;
        }
        if (oldSl == novSl) {
            poz->second = novZnach;
            return true;
        }
        if (zp.count(novSl) > 0) {
            return false;
        }
        zp.erase(poz);
        zp.insert(pair<string, string>(novSl, novZnach));
        return true;
    }
    void showSlov() const {
        for (const auto& para : zp) {
            cout << para.first << " - " << para.second << '\n';
        }
    }
    void showAll() const {
        int n = 1;
        for (const auto& para : zp) {
            cout << n++ << ". " << para.first << " - " << para.second << '\n';
        }
    }
};

class FileManager {
private:
    TolkoviySlovnyk& slovnyk;
    string weg;
public:
	FileManager() = default;
	FileManager(TolkoviySlovnyk& sl) : slovnyk(sl), weg("") {}
    FileManager(TolkoviySlovnyk& sl, const string& name): slovnyk(sl), weg(name) {}

    const TolkoviySlovnyk& getDictionary() const {
        return slovnyk;
    }
    const string& getWeg() const {
        return weg;
	}
    void setWeg(const string& name) {
		weg = name;
	}

    bool lFromFile() {
        ifstream file(weg);
        if (!file.is_open()) {
            return false;
        }
        slovnyk.clearSlov();
        string word, def;
        while (getline(file, word) && getline(file, def)) {
            if (!word.empty() && !def.empty()) {
                slovnyk.dodSlov(word, def);
            }
        }
        return true;
    }

    bool saveToFile() const {
        ofstream file(weg);
        if (!file.is_open()) {
            return false;
        }

        for (const auto& entry : slovnyk.getSlovn()) {
            file << entry.first << '\n' << entry.second << '\n';
        }
        return true;
    }
};
