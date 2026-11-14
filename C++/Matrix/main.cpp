#include "iostream"
#include "ctime"
using namespace std;

void main() {
	// Завдання 1
	cout << "Task 1\n";
	int matrx1[5][5];
	srand(time(0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrx1[i][j] = rand() % 10;
			cout << matrx1[i][j] << " ";
		}
		cout << "\n";
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i+j > 4) {
				sum += matrx1[i][j];
				cout << matrx1[i][j] << " ";
			}
			else {
				cout << "  ";
			}
		}
		cout << "\n";
	}
	cout << "The sum of the elements below the side diagonal: " << sum << "\n\n";

	// Завдання 2
	cout << "Task 2\n";
	double matrx2[5][5], max = -10.;
	int a, y = -10, x = 10;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrx2[i][j] = rand() % (y - x) + y;
			a = rand() % 10;
			matrx2[i][j] = matrx2[i][j] + (a * 0.1);
			cout << matrx2[i][j] << "\t";
			if (matrx2[i][j] > max) {
				max = matrx2[i][j];
			}
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (matrx2[i][j] < 0) {
				matrx2[i][j] = max;
			}
			cout << matrx2[i][j] << "\t";
		}
		cout << "\n";
	}

	cout << "\n";

	// Завдання 3
	cout << "Task 3\n";
	double matrx3[5][5], min = 10.;
	int min_p_row=0, min_p_col=0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrx3[i][j] = rand() % (y - x) + y;
			a = rand() % 10;
			matrx3[i][j] = matrx3[i][j] + (a * 0.1);
			cout << matrx3[i][j] << "\t";
			if (matrx3[i][j] < min) {
				min = matrx3[i][j];
				min_p_row = i;
				min_p_col = j;
			}
		}
		cout << "\n";
	}
	cout << "\nThe minimum element: " << min << "\n";
	cout << "The position of the minimum element: [" << min_p_row << "][" << min_p_col << "]\n\n";

	// Завдання 4
	cout << "Task 4\n\n";
	int matrx4[5][5], parn = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrx4[i][j] = rand() % 10;
			cout << matrx4[i][j] << " ";
			if (i > j && matrx4[i][j] % 2 == 0) {
				parn++;
			}
		}
		cout << "\n";
	}
	cout << "\nNumber of even elements below the main diagonal: " << parn << "\n";

	// Завдання 5
	cout << "\nTask 5\n\n";
	int matrx5[5][6], y_2 = 10, x_2 = 99, mas[30], k = 0, temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			matrx5[i][j] = rand() % (y_2 - x_2) + y_2;
			cout << matrx5[i][j] << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			mas[k] = matrx5[i][j];
			++k;
		}
	}

	for(int i = 0; i < 29; ++i) {
		int min = i;
		for (int j = i + 1; j < 30; ++j) {
			if (mas[j] < mas[min]) {
				min = j;
			}
		}
		temp = mas[i];
		mas[i] = mas[min];
		mas[min] = temp;
	}

	k = 0;
	cout << "\nSorted matrix:\n\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			matrx5[i][j] = mas[k];
			cout << matrx5[i][j] << " ";
			++k;
		}
		cout << "\n";
	}
	cout << "\n";

	// Завдання 6
	cout << "Task 6\n\n";
	int matrx6[5][5], sum_row[5] = {0}, sum_col[5] = {0}, sum_diag_gol = 0, sum_diag_pob = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrx6[i][j] = rand() % 10;
			cout << matrx6[i][j] << " ";
			sum_row[i] += matrx6[i][j];
			sum_col[j] += matrx6[i][j];
			if (i == j) {
				sum_diag_gol += matrx6[i][j];
			}
			if (i + j == 4) {
				sum_diag_pob += matrx6[i][j];
			}
		}
		cout << "\n";
	}
	cout << "\nSum of rows:\n";
	for (int i = 0; i < 5; i++) {
		cout << "Row " << i + 1 << ": " << sum_row[i] << "\n";
	}
	cout << "\nSum of columns:\n";
	for (int j = 0; j < 5; j++) {
		cout << "Column " << j + 1 << ": " << sum_col[j] << "\n";
	}
	cout << "\nSum of the main diagonal: " << sum_diag_gol << "\n";
	cout << "Sum of the side diagonal: " << sum_diag_pob << "\n";

	cin.get();
	cin.get();
}