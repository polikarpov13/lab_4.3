#pragma once 

#include "Array.h" 

#include <iostream> 

#include <string> 



using namespace std;



class Fraction : public Array {

protected:

	int sign;

	int decimals;

public:

	Fraction() : Array() {};

	Fraction(int _size, int _sign, int _decimals) : Array(_size) { sign = 0; decimals = 0; };



	friend ostream& operator<< (ostream& out, const Fraction& fraction);

	virtual void Add(const Fraction& fraction);

	friend bool operator== (Fraction&, Fraction&);

	Fraction& operator= (Fraction&);

	friend Fraction& operator- (Fraction&, Fraction&);

	friend Fraction& operator+ (Fraction&, Fraction&);

	friend bool operator> (Fraction&, Fraction&);



	int getIntSize() { return size - decimals; };



	~Fraction() {};

};