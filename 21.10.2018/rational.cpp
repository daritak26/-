#include "pch.h"
#include <iostream>
using namespace std;

int GCD(int a, int b)
{

	if (b == 0) return a;
	else return GCD(b, a % b);
}

struct rational
{
	int m;
	int n;


	rational (int a, int b)
	{
		m = a / GCD(a, b);
		n = b / GCD(a, b);
	}

	rational(int a) 
	{
		m = a;
		n = 1;
	}
	rational() 
	{ 
		m = 0;
		n = 1;
	}

	rational (const rational & a) { //copy
		m = a.m;
		n = a.n;
	}

	~ rational () {}

	rational & operator = (rational & a) //=
	{
		m = a.m;
		n = a.n;
		return *this;
	};

	rational & operator *= (const rational & a) { //operator *=
		m *= a.m;
		n *= a.n;
		m /= GCD(m, n);
		n /= GCD(m, n);
		return *this;
	}
	rational & operator /= (const rational & a) { // /=
		m *= a.n;
		n *= a.m;
		m /= GCD(m, n);
		n /= GCD(m, n);
		return *this;
	}

	rational & operator += (const rational & a) { // +=
		m = ((m * a.n) + (n * a.m));
		n *= a.n;
		m /= GCD(m, n);
		n /= GCD(m, n);
		return *this;
	}

	rational & operator -= (const rational & a) { // -=
		m = ((m * a.n) - (n * a.m));
		n *= a.n;
		m /= GCD(m, n);
		n /= GCD(m, n);
		return *this;
	}
};

rational & operator + (rational a, const rational & b) 
{
	return a += b;
}
rational & operator * (rational a, const rational & b) 
{ 
	return a *= b;
}
rational & operator / (rational a, const rational & b) 
{ 
	return a /= b;
}
rational & operator - (rational a, const rational & b) 
{ 
	return a -= b;
}
bool operator == (const rational &a, const rational & b) 
{ 
	return ((a.m == b.m) && (a.n == b.n));
}
bool operator != (const rational &a, const rational & b) 
{ 
	return !(a == b);
}

bool operator > (const rational & a, const rational & b) 
{ 
	return (((a.m * b.n) - (b.m * a.n) > 0) && (a.n * b.n > 0)) || (((a.m * b.n) - (b.m * a.n) < 0) && (a.n * b.n < 0));
}
bool operator<(const rational & a, const rational & b) 
{ 
	return (((a.m * b.n) - (b.m * a.n) < 0) && (a.n * b.n > 0)) || (((a.m * b.n) - (b.m * a.n) > 0) && (a.n * b.n < 0));
}

bool operator >= (const rational & a, const rational & b)
{ 
	return !(a < b);
}
bool operator <= (const rational & a, const rational & b) 
{ 
	return !(a > b);
}

istream & operator >> (istream & in, rational & a)
{
	in >> a.m >> a.n;
	int f = GCD(a.m, a.n);
	a.m /= f;
	a.n /= f;
	return in;
}
ostream & operator << (ostream & out, const rational & a) 
{
	out << a.m << "/" << a.n;
	return out;
}

using namespace std;

int main() {
	rational a(1, 5), b(2, 5); 
	cout << "a = " << a << " b = " << b << endl;
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a * b << endl;

	if (a == b)
	{
		cout << a << " == " << b << endl;
	};

	if (a != b)
	{
		cout << a << " != " << b << endl;
	};

	if (a > b)
	{
		cout << a << " > " << b << endl;
	};

	if (a >= b)
	{
		cout << a << " >= " << b << endl;
	};

	if (a < b)
	{
		cout << a << " < " << b << endl;
	};

	if (a <= b)
	{
		cout << a << " <= " << b << endl;
	};

	return 0;
}
