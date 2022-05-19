#pragma once
#define MAXSIZE 100
#include <iostream>
#include <string>

using namespace std;

class IArray {
protected:
	int size;
	unsigned char a[MAXSIZE];
public:
	virtual void Add(IArray&) = 0;
	unsigned char& operator [] (int);

	void setSize(int _size) { size = _size; };

	int getSize() { return size; };
};

class Array : public IArray {
public:
	Array();
	Array(int _size);

	friend ostream& operator << (ostream& out, const Array& array);
	void Add(IArray& array);

	~Array() {};
};