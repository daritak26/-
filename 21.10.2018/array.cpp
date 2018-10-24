#include "pch.h"
#include <iostream> 
using namespace std;

struct Array
{
	int array_size;
	int* data;
	Array(int n)
	{
		array_size = n;
		data = new int[n];
	};
	Array(const Array & a) 
	{
		array_size = a.array_size;
		data = a.data;
	};
	~Array()  
	{
		delete[] data;
	};
	void input()
	{
		for (int i = 0; i < array_size; i++)
			cin >> *(data + i);
	};
	void output()
	{
		for (int i = 0; i < array_size; i++)
			cout << *(data + i) << " ";
		cout << "\n";
	};
	int &operator[](int i)
	{
		return data[i];
	};
	int max()
	{
		int s = *data;
		for (int i = 0; i < array_size; i++)
			if (*(data + i) > s)
				s = *(data + i);
		return s;
	};
	int min()
	{
		int s = *data;
		for (int i = 0; i < array_size; i++)
			if (*(data + i) < s)
				s = *(data + i);
		return s;
	};
	int avg()
	{
		int sum = 0;
		for (int i = 0; i < array_size; i++)
			sum += *(data + i);
		return (sum / array_size);
	};
};
void mar(Array a)
{
	cout << "Copying constructor is working" << "\n";
}
int main()
{
	int N; 
	cin >> N;
	Array a(N);
	a.input();
	a.output();
	cout << a.max() << "\n";
	cout << a.min() << "\n";
	cout << a.avg() << "\n";
	cout << a[0] << " " << a[1] << " " << a[2] << "\n";
	mar(a);
	return 0;
}
