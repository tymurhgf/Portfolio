#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
	Persona persona("Yanovych", "Tymur", "Alimovych");
	Date birthDate(26, 1, 2011);
	string disciplines[5] = { "Math", "Physics", "Programming", "History", "English" };
	int grades[5] = { 12, 6, 11, 9, 12 };
	Mark marks(disciplines, grades, 5);
	Student student(persona, birthDate, marks);

	student.printPersonAndBirth();
	cout << endl;

	student.printAllMarks();
	cout << endl;

	student.print10_12Disciplines();
	cout << endl;

	student.printGradeByDisc("Programming");
	student.printGradeByDisc("Chemistry");
	cout << endl;

	Mark newMarks;
	newMarks.setDisciplineAndGrade(0, "Math", 9);
	newMarks.setDisciplineAndGrade(1, "Physics", 10);
	newMarks.setDisciplineAndGrade(2, "Programming", 12);
	newMarks.setDisciplineAndGrade(3, "History", 11);
	newMarks.setDisciplineAndGrade(4, "English", 10);
	student.setMarks(newMarks);
	student.printAllMarks();
	cout << endl;

	Student studentCpy = student;
	studentCpy.printPersonAndBirth();
	studentCpy.printAllMarks();

	cin.get();
	cin.get();
}