/*
Напишите программу находящую обратный по модулю элемент. Иначе говоря по числам  X и N нужно найти такое 
число Y, что остаток от деления X*Y на N равняется единице. В программе гарантируется, что все числа - натуральные
*/

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned int x, n, y, m, i;
	cin >> x >> n;
	m = 0;
	for (i = 1; i < n; i++) {
	    if (((x * i) % n) == 1) {
		y = i;
		m++;
		cout << y;
		break;
	    }
	    else
	    { 
				continue;
		}
	    }
	if (m == 0)
	{
		cout << "None";
	}
	return 0;
}
