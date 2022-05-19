#include "Fraction.h" 

#include "Array.h" 

#include "Hex.h" 



using namespace std;



void Fraction::Add(const Fraction& fraction) {

	this->size = max(this->size, fraction.size);

	for (int i = 0; i < fraction.size; i++) {

		this->a[i] += fraction.a[i];

	}

};



ostream& operator<< (ostream& out, const Fraction& fraction) {

	out << "Fraction: [ ";

	for (int i = 0; i < fraction.size; i++) {

		out << fraction.a[i] << " ";

	}

	out << "]";

	return out;

}



bool operator== (Fraction& A, Fraction& B) {

	if (A.size != B.size) return false;

	if (A.sign != B.sign) return false;

	if (A.decimals != B.decimals) return false;

	for (int i = 0; i < A.size; i++) {

		if (A[i] != B[i]) return false;

	}

	return true;

}



Fraction& Fraction::operator= (Fraction& A) {

	this->size = A.size;

	this->sign = A.sign;

	this->decimals = A.decimals;

	for (int i = 0; i < MAXSIZE; i++) {

		(*this)[i] = A[i];

	}

	return *this;

}



bool operator> (Fraction& A, Fraction& B) {

	if (A.sign == 1 && B.sign == 0) return true;

	if (A.sign == 1 && B.sign == -1) return true;

	if (A.sign == 0 && B.sign == -1) return true;

	if (B.sign == 1 && A.sign == 0) return false;

	if (B.sign == 1 && A.sign == -1) return false;

	if (B.sign == 0 && A.sign == -1) return false;

	if (A.sign == 0 && B.sign == 0) return false;

	if (A.sign == 1 && B.sign == 1) {

		if (A.getIntSize() > B.getIntSize()) return true;

		if (B.getIntSize() > A.getIntSize()) return false;

		for (int posA = (A.size - 1), posB = (B.size - 1), i = 0; i < A.getIntSize(); posA--, posB--, i++) {

			if (A[posA] > B[posB]) return true;

			if (B[posB] > A[posA]) return false;

		};

		for (int posA = A.decimals - 1, posB = B.decimals - 1, i = 0; i < min(A.decimals, B.decimals); posA--, posB--, i++) {

			if (A[posA] > B[posB]) return true;

			if (B[posB] > A[posA]) return false;

		}

		if (A.decimals > B.decimals) return true;

		if (B.decimals > A.decimals) return false;

		return false;

	}

	if (A.sign == -1 && B.sign == -1) {

		if (A.getIntSize() > B.getIntSize()) return false;

		if (B.getIntSize() > A.getIntSize()) return true;

		for (int posA = A.size - 1, posB = B.size - 1, i = 0; i < A.getIntSize(); posA--, posB--, i++) {

			if (A[posA] > B[posB]) return false;

			if (B[posB] > A[posA]) return true;

		};

		for (int posA = A.decimals - 1, posB = B.decimals - 1, i = 0; i < min(A.decimals, B.decimals); posA--, posB--, i++) {

			if (A[posA] > B[posB]) return false;

			if (B[posB] > A[posA]) return true;

		}

		if (A.decimals > B.decimals) return false;

		if (B.decimals > A.decimals) return true;

		return false;

	}

}



Fraction& operator+ (Fraction& A, Fraction& B) {

	int _decimals = max(A.decimals, B.decimals);

	int int_size = max(A.size - A.decimals, B.size - B.decimals);

	int _size = _decimals + int_size;

	Fraction* result = new Fraction(_size, 1, _decimals);

	for (int i = 0; i < MAXSIZE; i++)

		(*result)[i] = A[i] + B[i];

	return *result;

}



Fraction& operator- (Fraction& A, Fraction& B) {
	Fraction* result = new Fraction(A.size, 1, B.size);
	for (int i = 0; i < MAXSIZE; i++)
		(*result)[i] = A[i] - B[i];
	return *result;
}