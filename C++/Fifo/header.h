#pragma once
#include <iostream>
using namespace std;

template <class T>
class PriorityQueue {
private:
    int size;
    T* data;
    int* priorities;
    int Head, Tail;

public:
    PriorityQueue() {
        size = 10;
        Head = Tail = -1;
        data = new T[size];
        priorities = new int[size];
    }

    PriorityQueue(int s) {
        size = s;
        Head = Tail = -1;
        data = new T[size];
        priorities = new int[size];
    }

    ~PriorityQueue() {
        delete[] data;
        delete[] priorities;
    }

    PriorityQueue(const PriorityQueue& other) {
        size = other.size;
        Head = other.Head;
        Tail = other.Tail;

        data = new T[size];
        priorities = new int[size];

        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
            priorities[i] = other.priorities[i];
        }
    }

    PriorityQueue& operator=(const PriorityQueue& other) {
        if (this == &other) return *this;

        T* ndata = new T[other.size];
        int* nprop = new int[other.size];

        for (int i = 0; i < other.size; ++i) {
            ndata[i] = other.data[i];
            nprop[i] = other.priorities[i];
        }

        delete[] data;
        delete[] priorities;

        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = ndata;
        priorities = nprop;

        return *this;
    }

    PriorityQueue(PriorityQueue&& other) {
        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = other.data;
        priorities = other.priorities;

        other.data = nullptr;
        other.priorities = nullptr;
        other.size = 0;
        other.Head = -1;
        other.Tail = -1;
    }

    PriorityQueue& operator=(PriorityQueue&& other) {
        if (this == &other) return *this;

        delete[] data;
        delete[] priorities;

        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = other.data;
        priorities = other.priorities;

        other.data = nullptr;
        other.priorities = nullptr;
        other.size = 0;
        other.Head = -1;
        other.Tail = -1;

        return *this;
    }

    void EnQueue(T value, int priority)
    {
        if (Tail == size - 1)
        {
            cout << "Queue is FULL\n";
            return;
        }
        if (Head == -1 && Tail == -1)
        {
            ++Head;
            ++Tail;
            data[Tail] = value;
            priorities[Tail] = priority;
        }
        else
        {
            int i;
            for (i = Tail; (i >= Head && priorities[i] > priority); i--)
            {
                data[i + 1] = data[i];
                priorities[i + 1] = priorities[i];
            }

            data[i + 1] = value;
            priorities[i + 1] = priority;

            ++Tail;
        }
    }

    T DeQueue()
    {
        T x;
        if (Tail == -1) {
            cout << "Queue is empty\n";
            return T();
        }
        else if (Head == Tail) {
            x = data[Head];
            Head = -1;
            Tail = -1;
            return x;
        }
        else
        {
            x = data[Head];
            for (int i = 1; i <= Tail; ++i) {
                data[i - 1] = data[i];
                priorities[i - 1] = priorities[i];
            }
            Tail--;
            return x;
        }
    }

    void Show()
    {
        if (Tail == -1) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = Head; i <= Tail; ++i) {
			cout << data[i] << "\t";
        }
        cout << "\n";
        for (int i = Head; i <= Tail; ++i) {
            cout << priorities[i] << "\t";
        }
        cout << "\n\n";
    }
};

template <class T>
class DeckQueue {
private:
    int size;
    T* data;
    int Head, Tail;

public:
    DeckQueue() {
        size = 10;
        Head = Tail = -1;
        data = new T[size];
    }

    DeckQueue(int s) {
        size = s;
        Head = Tail = -1;
        data = new T[size];
    }

    ~DeckQueue() {
        delete[] data;
    }

    DeckQueue(const DeckQueue& other) {
        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = new T[size];

        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DeckQueue& operator=(const DeckQueue& other) {
        if (this == &other) return *this;

        T* ndata = new T[other.size];
        for (int i = 0; i < other.size; ++i) {
            ndata[i] = other.data[i];
        }

        delete[] data;

        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = ndata;

        return *this;
    }

    DeckQueue(DeckQueue&& other) {
        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
        other.Head = other.Tail = -1;
    }

    DeckQueue& operator=(DeckQueue&& other) {
        if (this == &other) return *this;

        delete[] data; 

        size = other.size;
        Head = other.Head;
        Tail = other.Tail;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
        other.Head = other.Tail = -1;

        return *this;
    }

    void pushBack(T value) {
        if ((Tail == size - 1 && Head == 0) || (Head - Tail == 1)) {
            cout << "Queue is FULL\n";
            return;
        }

        if (Head == -1) {
            Head = Tail = 0;
        }
        else if (Tail == size - 1) {
            Tail = 0;
        }
        else {
            ++Tail;
        }
        data[Tail] = value;
    }

    void pushFront(T value) {
        if ((Tail == size - 1 && Head == 0) || (Head - Tail == 1)) {
            cout << "Queue is FULL\n";
            return;
        }

        if (Head == -1) {
            Head = Tail = 0;
        }
        else if (Head == 0) {
            Head = size - 1;
        }
        else {
            --Head;
        }
        data[Head] = value;
    }

    T popFront() {
        if (Head == -1) {
            cout << "Queue is empty\n";
            return T();
        }

        T x = data[Head];

        if (Head == Tail) {
            Head = Tail = -1;
        }
        else if (Head == size - 1) {
            Head = 0;
        }
        else {
            ++Head;
        }
        return x;
    }

    T popBack() {
        if (Head == -1) {
            cout << "Queue is empty\n";
            return T();
        }

        T x = data[Tail];

        if (Head == Tail) {
            Head = Tail = -1;
        }
        else if (Tail == 0) {
            Tail = size - 1;
        }
        else {
            --Tail;
        }
        return x;
    }

    void Show(){
        if (Head == -1) {
            cout << "Queue is empty\n";
            return;
        }

        int i = Head;
        while (true) {
            cout << data[i] << " ";
            if (i == Tail) break;
            ++i;
            if (i == size) {
                i = 0;
            }
        }
        cout << "\n\n";
    }

};
