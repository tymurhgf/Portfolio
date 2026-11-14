#pragma once
#include "header.h"
using namespace std;

bool checkDuzk(const char str[])
{
    stack<char> duzk;
    char open;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            duzk.push(str[i]);
        }
        else
        {
            if (duzk.isEmpty())
                return false;

            open = duzk.popA();

            if (str[i] == ')' && open != '(')
                return false;

            if (str[i] == ']' && open != '[')
                return false;

            if (str[i] == '}' && open != '{')
                return false;
        }
    }

    return duzk.isEmpty();
}

void printRes(bool res)
{
    if (res)
        cout << "true";
    else
        cout << "false";
}