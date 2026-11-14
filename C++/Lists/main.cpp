#include <iostream>
#include "header.h"
using namespace std;

void main()
{
	List lst;
	lst.Add(4.5);
	lst.Add(12.1);
	lst.Add(8.3);
	lst.Add(2.0);
	lst.Add(15.7);
	lst.Show();

	cout << "Number of elements: " << lst.GetCount() << "\n\n";

	cout << "Before 8.3" << endl;
	lst.AddBefore(9.9, 8.3);
	lst.Show();

	cout << "\nAfter 4.5" << endl;
	lst.AddAfter(5.5, 4.5);
	lst.Show();

	cout << "\nCopy" << endl;
	List lst2 = lst;
	lst2.Add(100.0);
	lst2.Show();
	cout << "lst1: "; lst.Show();

	cout << "\nCopy operator" << endl;
	List lst3;
	lst3 = lst2;
	lst3.Add(200.0);
	lst3.Show();
	cout << "lst2: "; lst2.Show();

	cout << "\nMove" << endl;
	List lst4 = move(lst);
	lst4.Show();
	cout << "lst: "; lst.Show();

	cout << "\nMove operator" << endl;
	List lst5;
	lst5 = move(lst2);
	lst5.Show();
	cout << "lst2: "; lst2.Show();

	cout << "\nDelete 9.9" << endl;
	lst5.DeleteElem(9.9);
	lst5.Show();

	cout << "\nProduct 3.0 - 12.0" << endl;
	double prod = lst5.ProdInRange(3.0, 12.0);
	cout << "Product: " << prod << endl;

	cout << "\nElements greater than 6.0" << endl;
	List filtList = lst5.GetListGrThan(6.0);
	filtList.Show();


	cin.get();
	cin.get();
}