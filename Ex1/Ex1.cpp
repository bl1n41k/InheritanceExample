﻿#include <iostream>
using namespace std;

class B {
	int a;
public:
	B() { cout << "object of" << typeid(*this).name() << " was created\n"; }
	B(int x) :B() { a = x; }
	~B() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D1 : public B {
	int d1;
public:
	D1(int x, int y) : B(y)
	{
		d1 = x;
		cout << "object of" << typeid(*this).name() << " was created\n";
	}
	~D1() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D2 : private B {
	int d2;
public:
	D2(int x, int y) : B(y)
	{
		d2 = x;
		cout << "object of" << typeid(*this).name() << " was created\n";
	};
	~D2() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D3 : private D1, public D2 {
	int d3;
public:

	D3(int x, int y, int z, int i, int j) : D1(y, z), D2(i, j)
	{
		d3 = x;
		cout << "object of" << typeid(*this).name() << " was created\n";
	}
	~D3() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

class D4 : public D2, private D1 {
	int e;
public:
	D4(int x, int y, int z, int i, int j) : D1(y, z), D2(i, j)
	{
		e = x;
		cout << "object of" << typeid(*this).name() << " was created\n";
	}
	~D4() { cout << "object of" << typeid(*this).name() << " was destroyed\n"; }
};

int main()
{
	//	D3 temp(100, 200, 300, 400, 500);
	//  D4 temp1(1, 2, 3, 4, 5);
}