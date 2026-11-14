#pragma once
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
	Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    inline void setDay(int d) { day = d; }
    inline void setMonth(int m) { month = m; }
    inline void setYear(int y) { year = y; }

    inline int getDay() const { return day; }
    inline int getMonth() const { return month; }
    inline int getYear() const { return year; }

    void print() const {
        cout << day << "." << month << "." << year;
    }

};

class Persona {
private:
    string prisv;
    string name;
    string pobatk;
public:
	Persona() : prisv(""), name(""), pobatk("") {}
    Persona(string s, string n, string p): prisv(s), name(n), pobatk(p) {}

    inline void setSurname(const string& s) { prisv = s; }
    inline void setName(const string& n) { name = n; }
    inline void setPatronymic(const string& p) { pobatk = p; }

    inline string getSurname() const { return prisv; }
    inline string getName() const { return name; }
    inline string getPatronymic() const { return pobatk; }

    void print() const {
        cout << prisv << " " << name << " " << pobatk;
    }
};

class Mark {
private:
    int size;
    string* disciplines;
    int* grades;
public:
    Mark() : size(5) {
        disciplines = new string[size]{ "Math", "Physics", "Programming", "History", "English" };
        grades = new int[size];
        for (int i = 0; i < size; ++i) {
            grades[i] = 0;
		}
    }

    Mark(const string* disc, const int* gr, int s = 5) : size(s) {
        disciplines = new string[size];
        grades = new int[size];
        for (int i = 0; i < size; ++i) {
            disciplines[i] = disc[i];
            grades[i] = gr[i];
        }
    }

    ~Mark() {
        delete[] disciplines;
        delete[] grades;
    }

    Mark(const Mark& other) : size(other.size) {
        disciplines = new string[size];
        grades = new int[size];
        for (int i = 0; i < size; ++i) {
            disciplines[i] = other.disciplines[i];
            grades[i] = other.grades[i];
        }
    }

    Mark& operator=(const Mark& other) {
        if (this == &other) return *this;
        delete[] disciplines;
        delete[] grades;
        size = other.size;
        disciplines = new string[size];
        grades = new int[size];
        for (int i = 0; i < size; ++i) {
            disciplines[i] = other.disciplines[i];
            grades[i] = other.grades[i];
        }
        return *this;
    }

    Mark(Mark&& other) : size(other.size), disciplines(other.disciplines), grades(other.grades) {
        other.size = 0;
        other.disciplines = nullptr;
        other.grades = nullptr;
    }

    Mark& operator=(Mark&& other) {
        if (this == &other) return *this;
        delete[] disciplines;
        delete[] grades;
        size = other.size;
        disciplines = other.disciplines;
        grades = other.grades;
        other.size = 0;
        other.disciplines = nullptr;
        other.grades = nullptr;
        return *this;
    }

    inline int getSize() const { return size; }

    inline string getDiscipline(int index) const {
        if (index >= 0 && index < size) return disciplines[index];
        return "";
    }

    inline int getGrade(int index) const {
        if (index >= 0 && index < size) return grades[index];
        return -1;
    }

    inline void setDisciplineAndGrade(int index, const string& disc, int grade) {
        if (index >= 0 && index < size) {
            disciplines[index] = disc;
            grades[index] = grade;
        }
    }

    inline void print() const {
        for (int i = 0; i < size; ++i) {
            cout << "  - " << disciplines[i] << ": " << grades[i] << endl;
        }
    }
};

class Student {
private:
	Persona persona; // Композиція. При відрахуванні студента, його ПІП також має бути видалено і ПІП не може існувати без студента
	Date birthDate; // Композиція. Дата народження не існує без студента
	Mark marks; // Композиція. Оцінки теж не існують без студента
    double avScore;
public:
    void calcAvScore() {
        int count = marks.getSize();
        if (count == 0) {
            avScore = 0.;
            return;
        }
        double sum = 0;
        for (int i = 0; i < count; ++i) {
            sum += marks.getGrade(i);
        }
        avScore = sum/count;
    }
    Student() : avScore(0.) {}
    Student(const Persona& p, const Date& d, const Mark& m): persona(p), birthDate(d), marks(m) {
        calcAvScore();
    }

    inline void setPersona(const Persona& p) { persona = p; }
    inline void setBirthDate(const Date& d) { birthDate = d; }
    inline void setMarks(const Mark& m) {
        marks = m;
        calcAvScore();
    }

    inline Persona getPersona() const { return persona; }
    inline Date getBirthDate() const { return birthDate; }
    inline Mark getMarks() const { return marks; }
    inline double getAvScore() const { return avScore; }

    void print10_12Disciplines() const {
        cout << "Subjects with a grade of 10 and 12: " << endl;
        bool found = false;
        int grade;
        for (int i = 0; i < marks.getSize(); ++i) {
            grade = marks.getGrade(i);
            if (grade >= 10 && grade <= 12) {
                cout << "  - " << marks.getDiscipline(i) << " (" << grade << ")" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "There are no such disciplines" << endl;
        }
    }

    void printGradeByDisc(const string& discName) const {
        bool found = false;
        for (int i = 0; i < marks.getSize(); ++i) {
            if (marks.getDiscipline(i) == discName) {
                cout << "Grade for the course: " << discName << " - " << marks.getGrade(i) << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Discipline: " << discName << " - not found." << endl;
        }
    }

    void printPersonAndBirth() const {
        cout << "Student: ";
        persona.print();
        cout << "\nBirth date: ";
        birthDate.print();
        cout << endl;
    }

    void printAllMarks() const {
        cout << "List of disciplines and grades:" << endl;
        marks.print();
        cout << "Average score: " << avScore << endl;
    }
};
