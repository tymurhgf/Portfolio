#pragma once
#include <iostream>
#include "header.h"
using namespace std;

void main() {
    //priority
	cout << "Priority Queue:\n\n";

	//Create priority
    PriorityQueue<string> pq1(5);
    pq1.EnQueue("Six", 6);
    pq1.EnQueue("Three", 3);
	pq1.EnQueue("Four", 4);
    pq1.EnQueue("One", 1);
	pq1.EnQueue("Five", 5);
    pq1.EnQueue("Two", 2);
    pq1.Show();

	//DeQueue priority
    cout << "DeQueue q1= -> " << pq1.DeQueue() << "\n";
    pq1.Show();

	//Copy priority
	PriorityQueue<string> pq2 = pq1;
    cout << "Copy q2=:\n";
    pq2.Show();
    cout << "DeQueue q2= -> " << pq2.DeQueue() << "\n";
	pq2.Show();

    PriorityQueue<string> pq3;
    pq3 = pq1;
    cout << "Copy q3=:\n";
    pq3.Show();

	//Move priority
    PriorityQueue<string> pq4 = move(pq3);
	cout << "Move q4=:\n";
    pq4.Show();
	cout << "pq3= after move:\n";
	pq3.Show();
	cout << "\n";

    PriorityQueue<string> pq5(5);
    pq5 = move(pq4);
	cout << "Move q5=:\n";
	pq5.Show();
	cout << "pq4= after move:\n";
	pq4.Show();

    //deck
	cout << "\nDeck Queue:\n\n";

	//Create deck
    DeckQueue<int> dck1(5);
    dck1.pushBack(200);
    dck1.pushFront(50);
    dck1.pushBack(100);
    dck1.pushFront(10);
	dck1.Show();

	//Pop deck
    cout << "PopFront dck1= -> " << dck1.popFront() << "\n";
    dck1.Show();
    cout << "PopBack dck1= -> " << dck1.popBack() << "\n";
	dck1.Show();

	//Copy deck
	DeckQueue<int> dck2 = dck1;
	cout << "Copy dck2=:\n";
	dck2.Show();
	cout << "PopFront dck2= -> " << dck2.popFront() <<"\n";
	dck2.Show();

	DeckQueue<int> dck3;
	dck3 = dck1;
	cout << "Copy dck3=:\n";
	dck3.Show();

	//Move deck
	DeckQueue<int> dck4 = move(dck3);
	cout << "Move dck4=:\n";
	dck4.Show();
	cout << "dck3= after move:\n";
	dck3.Show();
	cout << "\n";

	DeckQueue<int> dck5(5);
	dck5 = move(dck4);
	cout << "Move dck5=:\n";
	dck5.Show();
	cout << "dck4= after move:\n";
	dck4.Show();

	cin.get();
	cin.get();
}