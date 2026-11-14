#pragma once
#include <iostream>
using namespace std;

class List
{
private:
    struct Node
    {
        double x;
        Node* Next;
        Node* Prev;
    };

    Node* Head;
    Node* Tail;

public:
    List() : Head(nullptr), Tail(nullptr) {};
    ~List() {
        if (!Head) return;
        Tail->Next = nullptr;
        Node* curr = Head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->Next;
            delete curr;
            curr = next;
        }
        Head = Tail = nullptr;
    }
    List(const List& other) : Head(nullptr), Tail(nullptr)
    {
        if (!other.Head) return;
        Node* curr = other.Head;
        do {
            Add(curr->x);
            curr = curr->Next;
        } while (curr != other.Head);
    }

    List& operator=(const List& other)
    {
        if (this == &other) return *this;

        if (Head) {
            Node* curr = Head;
            Node* next = nullptr;
            while (curr->Next != Head) {
                next = curr->Next;
                delete curr;
                curr = next;
            }
            delete curr;
            Head = nullptr;
            Tail = nullptr;
        }

        if (other.Head) {
            Node* curr = other.Head;
            do {
                Add(curr->x);
                curr = curr->Next;
            } while (curr != other.Head);
        }

        return *this;
    }
    List(List&& other) : Head(other.Head), Tail(other.Tail)
    {
        other.Head = other.Tail = nullptr;
    }

    List& operator=(List&& other) 
    {
        if (this == &other) return *this;
        if (Head) {
            Node* curr = Head;
            Node* next = nullptr;
            while (curr->Next != Head) {
                next = curr->Next;
                delete curr;
                curr = next;
            }
            delete curr;
            Head = nullptr;
            Tail = nullptr;
        }

        Head = other.Head;
        Tail = other.Tail;
        other.Head = nullptr;
        other.Tail = nullptr;

        return *this;
    }

    void Show() const
    {
        if (!Head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = Head;
        do {
            cout << temp->x << " ";
            temp = temp->Next;
        } while (temp != Head);
        cout << "\n";
    }

    void Add(double x)
    {
        Node* temp = new Node;
        temp->x = x;
        temp->Next = nullptr;
        temp->Prev = nullptr;

        if (Head != nullptr)
        {
            Tail->Next = temp;
            temp->Prev = Tail;
            temp->Next = Head;
            Head->Prev = temp;
            Tail = temp;
        }
        else
        {
            Head = Tail = temp;
            Head->Next = Head;
            Head->Prev = Head;
        }
    }

    void AddBefore(double val, double tVAl)
    {
        if (!Head) return;
        Node* t1 = Head;
        Node* temp = nullptr;
		Node* p = nullptr;
        do {
            if (t1->x == tVAl)
            {
                temp = new Node;
                temp->x = val;
                temp->Next = nullptr;
                temp->Prev = nullptr;

                if (t1 == Head)
                {
                    temp->Next = Head;
                    temp->Prev = Tail;
                    Tail->Next = temp;
                    Head->Prev = temp;
                    Head = temp;
                }
                else
                {
                    p = t1->Prev;
                    p->Next = temp;
                    temp->Prev = p;
                    temp->Next = t1;
                    t1->Prev = temp;
                }
                return;
            }
            t1 = t1->Next;
        } while (t1 != Head);
    }

    void AddAfter(double val, double tVAL)
    {
        if (!Head) return;
        Node* t1 = Head;
		Node* temp = nullptr;
		Node* n = nullptr;
        do {
            if (t1->x == tVAL)
            {
                temp = new Node;
                temp->x = val;
                temp->Next = nullptr;
                temp->Prev = nullptr;

                n = t1->Next;
                t1->Next = temp;
                temp->Prev = t1;
                temp->Next = n;
                n->Prev = temp;

                if (t1 == Tail)
                {
                    Tail = temp;
                }
                return;
            }
            t1 = t1->Next;
        } while (t1 != Head);
    }

    void DeleteElem(double val) {
        if (!Head) return;
        Node* t1 = Head;
        Node* t2 = nullptr;
        Node* n = nullptr;
        do {
            if (t1->x == val) {
                if (Head == Tail) {
                    delete Head;
                    Head = Tail = nullptr;
                }
                else {
                    t2 = t1->Prev;
                    n = t1->Next;
                    t2->Next = n;
                    n->Prev = t2;
                    if (t1 == Head) Head = n;
                    if (t1 == Tail) Tail = t2;
                    delete t1;
                }
                return;
            }
            t1 = t1->Next;
        } while (t1 != Head);
    }

    int GetCount()
    {
        if (!Head) return 0;
        int count = 0;
        Node* temp = Head;
        do {
            count++;
            temp = temp->Next;
        } while (temp != Head);
        return count;
    }

    double ProdInRange(double minVal, double maxVal)
    {
        if (!Head) return 0.0;
        double product = 1.0;
        bool found = false;
        Node* temp = Head;
        do {
            if (temp->x >= minVal && temp->x <= maxVal)
            {
                product *= temp->x;
                found = true;
            }
            temp = temp->Next;
        } while (temp != Head);

        if (found)
        {
            return product;
        }
        else
        {
            return 0.0;
        }
    }

    List GetListGrThan(double val)
    {
        List newList;

        if (!Head)
        {
            return newList;
        }

        Node* temp = Head;
        do {
            if (temp->x > val)
            {
                newList.Add(temp->x);
            }
            temp = temp->Next;
        } while (temp != Head);

        return newList;
    }

};
