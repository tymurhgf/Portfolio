#pragma once

struct DATA {
    int day;
    int month;
    int year;
};

struct address {
    char countr[60];
    char obl[60];
    char city[60];
    char strt[60];
    char house[60];
    char pidy[60];
    char kvart[60];
};

struct PI {
    char prisv[60];
    char name[60];
};

struct STUDENT {
    PI pi;
    address adr;
    DATA birthD;
    DATA joinD;
    char phoneN[30];
};

STUDENT* LoadFromFile(STUDENT*, int&, const char*);
void showStudent(STUDENT* st, int size);
STUDENT inputStudent();
STUDENT* addStudent(STUDENT*, int&, STUDENT);
STUDENT* removeStudent(STUDENT*, int&, int);
STUDENT* bOnAutmn(STUDENT*, int, STUDENT*, int&);
STUDENT* JoinAfter25(STUDENT*, int, STUDENT*, int&);
void saveToFile(const char*, STUDENT*, int);