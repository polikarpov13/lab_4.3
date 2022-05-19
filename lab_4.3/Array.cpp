#include "Array.h" 

using namespace std;

unsigned char& IArray::operator[] (int i) {

	if (i < 0) {

		cout << "Index < 0 " << endl;

		exit(1);

	}

	if (i >= MAXSIZE) {

		cout << "Index: " << i << " >=  MAXSIZE: " << MAXSIZE << endl;

		exit(1);

	}

	return a[i];

}



Array::Array() {

	size = 0;

	for (int i = 0; i < MAXSIZE; i++) {

		a[i] = 0;

	}

};

Array::Array(int _size) {

	if (_size > MAXSIZE) {

		cout << " Size: " << _size << " >  MAXSIZE: " << MAXSIZE << endl;

		exit(1);

	}

	size = _size;

	for (int i = 0; i < MAXSIZE; i++) {
		a[i] = 0;
	}
};

void Array::Add(IArray& array) {

	this->size = max(this->size, array.getSize());

	for (int i = 0; i < array.getSize(); i++) {

		this->a[i] += array[i];

	}

};

ostream& operator<< (ostream& out, const Array& array) {
	out << "Array: [ ";
	for (int i = 0; i < array.size; i++) {

		out << array.a[i] << " ";

	}
	out << "]";
	return out;
}