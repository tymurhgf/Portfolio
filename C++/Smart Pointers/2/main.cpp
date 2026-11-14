#include <iostream>
#include "header.h"
using namespace std;

void main() {
	String s1;
	cout << "Size s1: " << s1.getSize() << endl;
	cout << "S1: "; s1.Show();
	cout << "\n";

	int size2;
	cout << "Enter size for s2: "; cin >> size2;
	String s2(size2);
	cout << "Size s2: " << s2.getSize() << endl;
	cout << "S2: "; s2.Show();
	cout << "\n";

	char str3[100];
	cout << "Enter string for s3: "; cin >> str3;
	String s3(str3);
	cout << "Size s3: " << s3.getSize() << endl;
	cout << "S3: "; s3.Show();
	cout << "\n";

	String s4(s3);
	cout << "Size s4(copy s3): " << s4.getSize() << endl;
	cout << "S4: "; s4.Show();
	cout << "\n";

	String s5 = move(s4);
	cout << "Size s5(move s4): " << s5.getSize() << endl;
	cout << "S5: "; s5.Show();
	cout << "Size s4 after move: " << s4.getSize() << endl;
	cout << "\n";

	cout << "getSize(): " << s3.getSize() << endl;
	cout << "getData(0): " << s3.getData(0) << endl;
	cout << "getStr(): " << s3.getStr() << endl;
	cout << "\n";

	s3.setCh(0, 'A');
	cout << "S3 after setCh: "; s3.Show();
	s3.setStr("Mama mula ramu");
	cout << "S3 after setStr: "; s3.Show();
	cout << "Size s3 after setStr: " << s3.getSize() << endl;
	cout << "Full size s3 after setStr: " << s3.getFSize() << endl;
}