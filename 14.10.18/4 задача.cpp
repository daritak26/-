/*
 Напишите программу находящую в массиве сумму элементов делящихся либо на 72 либо на 27(не вместе).
*/

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 27 == 0 || a[i] % 72 == 0)
		{
			sum = sum + a[i];
		}
		if (a[i] % 27 == 0 && a[i] % 72 == 0)
		{
			sum = sum - a[i];
		}
	}
	cout << sum;
	return 0;
}

