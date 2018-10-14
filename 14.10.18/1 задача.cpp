/*
Напишите программу проверяющую является ли число составным. В программе гарантируется, что число - натуральное.
*/

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned int n, b, a, i;
	cin >> n;
	a = n - 1;
	if (n == 1)
		cout << "Unit";
	if (n == 2)
		cout << "Prime";
	for (i = 2; i <= a; i++) {
		b = n % i;
		if (b == 0) {
			cout << "Composite";
			break;
		}
		else if (i == a)
			cout << "Prime";

	}
	return 0;

}
