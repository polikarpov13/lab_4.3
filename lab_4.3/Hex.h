#pragma once
#include "Array.h"
#include <iostream>
#include <string>

using namespace std;

class Hex : public Array {
public:
	Hex() : Array() {};
	Hex(int _size) : Array(_size) {};

	friend ostream& operator<< (ostream& out, const Hex& hex);
	virtual void Add(const Hex& hex);
	friend bool operator == (Hex&, Hex&);
	Hex& operator = (Hex&);
	friend Hex& operator - (Hex&, Hex&);
	friend Hex& operator + (Hex&, Hex&);

	~Hex() {};
};