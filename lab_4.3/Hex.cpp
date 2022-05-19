#include "Hex.h" 

using namespace std;

void Hex::Add(const Hex& hex) {
	this->size = max(this->size, hex.size);

	for (int i = 0; i < hex.size; i++) {
		this->a[i] += hex.a[i];
	}
};



ostream& operator<< (ostream& out, const Hex& hex) {

	out << "Hex: [ ";

	for (int i = 0; i < hex.size; i++) {

		out << hex.a[i] << " ";

	}

	out << "]";

	return out;

}



bool operator == (Hex& A, Hex& B) {

	if (A.size != B.size) return false;

	for (int i = 0; i < A.size; i++) {

		if (A[i] != B[i]) return false;

	}

	return true;

}



Hex& Hex::operator = (Hex& A) {

	this->size = A.size;

	for (int i = 0; i < MAXSIZE; i++) {

		(*this)[i] = A[i];

	}

	return *this;

}



Hex& operator - (Hex& A, Hex& B) {

	Hex* result = new Hex(max(A.size, B.size));

	for (int i = 0; i < MAXSIZE; i++)

		(*result)[i] = A[i] - B[i];

	return *result;

}



Hex& operator + (Hex& A, Hex& B) {
	Hex* result = new Hex(max(A.size, B.size));

	for (int i = 0; i < MAXSIZE; i++)
		(*result)[i] = A[i] + B[i];

	return *result;
}