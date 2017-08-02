// Peregruzka_matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
int n;
class matrix {
	int **a;
public:
	matrix::matrix() {
		a = new int*[n];
		for (int i = 0; i<n; i++) {
			a[i] = new int[n];
		}
	}

	friend ostream & operator <<(ostream & is, matrix & r);
	friend istream & operator >> (istream & is, matrix& r);

	matrix operator +(matrix r) {
		matrix z;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				z.a[i][j] = a[i][j] + r.a[i][j];
			}
		}
		return z;
	}

	matrix operator /(matrix r){
		matrix z;
		for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				{
					if (i>j) { z.a[i][j] = a[i][j]; }
					else { z.a[i][j] = 0; }
				}
			}
		}
		return z;
	}
	
	matrix operator *(matrix r) {
		matrix z;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				z.a[i][j] = 0;
				for (int y = 0; y<n; y++) {
					z.a[i][j] += a[i][y] * r.a[y][j];
				}
			}
		}
		return z;
	}
	bool matrix::operator==(matrix r)
	{
		bool k = 1;
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++) {
				if (r.a[i][j] != a[i][j]) {
					k = 0;
				}
			}
		}
		return k;
	}
};

ostream & operator <<(ostream & is, matrix & r)
{
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {

			cout << r.a[i][j] << " ";
			if (j == n - 1) { cout << endl; }
		}
	}
	return is;
}

istream & operator >> (istream & is, matrix & r)
{
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			cin >> r.a[i][j];
		}
	}
	return is;
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "size massiv" << endl;
	cin >> n;
	system("cls");
	matrix l;
	cout << "1 matrix:" << endl;
	cin >> l;
	system("cls");
	cout << "ok! 2 matrix" << endl;
	matrix k;
	cin >> k;
	system("cls");
	cout << "*" << endl << l*k << endl;
	cout << "+" << endl << l + k << endl;
	cout << "/" << endl << l / k;
	if (l == k)
		cout << "Matrices are equal!" << endl;
	else
		cout << "Matrices are not equal!" << endl;
	system("pause");
	return 0;
}