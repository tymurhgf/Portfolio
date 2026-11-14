#pragma once
#include "header.h"
#include "iostream"
using namespace std;

void main()
{
    char test1[] = "((({[]})))";
    char test2[] = "{[()]}";
    char test3[] = "(([{]}))";
    char test4[] = ")([]{}";
    char test5[] = "()";
    char test6[] = "([]{})";
    char test7[] = "{[(())]}";
    char test8[] = "((())";
    char test9[] = "{[}]";
    char test10[] = "(([])){()}[]";

    cout << "1: " << test1 << "\t"; printRes(checkDuzk(test1)); cout << endl;
    cout << "2: " << test2 << "\t"; printRes(checkDuzk(test2)); cout << endl;
    cout << "3: " << test3 << "\t"; printRes(checkDuzk(test3)); cout << endl;
    cout << "4: " << test4 << "\t"; printRes(checkDuzk(test4)); cout << endl;
    cout << "5: " << test5 << "\t"; printRes(checkDuzk(test5)); cout << endl;
    cout << "6: " << test6 << "\t"; printRes(checkDuzk(test6)); cout << endl;
    cout << "7: " << test7 << "\t"; printRes(checkDuzk(test7)); cout << endl;
    cout << "8: " << test8 << "\t"; printRes(checkDuzk(test8)); cout << endl;
    cout << "9: " << test9 << "\t"; printRes(checkDuzk(test9)); cout << endl;
    cout << "10: " << test10 << "\t"; printRes(checkDuzk(test10)); cout << endl;
    
    cin.get();
	cin.get();
}