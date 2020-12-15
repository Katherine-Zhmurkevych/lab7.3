//ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int elementsSumInPositiveRows(int** a, int k, int n) {
	int sum = 0;
	bool rowPositive;
	for (int i = 0; i < k; i++) {
		rowPositive = true;
		for (int j = 0; j < n; j++) {
			if (a[i][j] < 0) {
				rowPositive = false;
				break;
			}
		}
		if (rowPositive) {
			for (int z = 0; z < n; z++) {
				sum += a[i][z];
			}
		}
	}
	return sum;
}

int main()
{
	srand((unsigned)time(NULL));
	int low = -1;
	int high=10;
	int k;
	int n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	create(a, n, low, high);
	print(a, n);
	cout << "Sum " << elementsSumInPositiveRows(a,k,n);
	return 0;
}