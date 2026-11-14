#pragma once
#include "iostream"
using namespace std;

template <class T>
class stack {
    T* data;
    int size;
    int top;
public:
    stack() :size{ 10 }, top{ -1 } {
        data = new T[size];
    }

    stack(int n) :size{ n }, top{ -1 } {
        data = new T[size];
    }

    ~stack() {
        delete[] data;
    }

    stack(const stack<T>& other)
    {
        this->size = other.size;
        this->top = other.top;
        data = new T[size];

        for (int i = 0; i <= top; ++i)
            data[i] = other.data[i];
    }

    stack(stack<T>&& other)
    {
        this->data = other.data;
        this->size = other.size;
        this->top = other.top;

        other.data = nullptr;
        other.size = 0;
        other.top = -1;
    }

    stack<T>& operator=(const stack<T>& other)
    {
        if (this != &other)
        {
            delete[] data;
            this->size = other.size;
            this->top = other.top;
            data = new T[size];

            for (int i = 0; i <= top; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    stack<T>& operator=(stack<T>&& other)
    {
        if (this != &other)
        {
            delete[] data;
            this->data = other.data;
            this->size = other.size;
            this->top = other.top;

            other.data = nullptr;
            other.size = 0;
            other.top = -1;
        }
        return *this;
    }

    void push(T val) {
        T* temp;
        if (top != size - 1) {
            ++top;
            data[top] = val;
        }
        else {
            temp = new T[size + 1];
            for (int i = 0; i <= top; ++i)
                temp[i] = data[i];

            ++top; 
            ++size;
            temp[top] = val;
            delete[] data;
            data = temp;
        }
    }

    T pop() {
        if (top == -1) {
            return 0;
        }
        else return data[top];
    }

    T popA() {
        if (top == -1) {
            return 0;
        }
        else {
            --top;
            return data[top + 1];
        }
    }

    void show() {
        for (int i = top; i >= 0; --i)
            cout << data[i] << "\n";
    }

    bool isFull() {
        if (top == size - 1)
            return true;
        return false;
    }

    bool isEmpty() {
        if (top == -1) return true;
        return false;
    }

    inline int getsize()const {
        return size;
    }

    inline int getTop()const {
        return top;
    }
};

bool checkDuzk(const char str[]);
void printRes(bool res);
