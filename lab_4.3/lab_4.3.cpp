#include "Array.h" 

#include "Hex.h" 



using namespace std;



int main() {

	Array A(3);

	A[0] = 'B';

	A[1] = 'y';

	A[2] = 'e';

	cout << "A: " << A << endl;



	Hex H1(5);

	H1[0] = 'H';

	H1[1] = 'e';

	H1[2] = 'l';

	H1[3] = 'l';

	H1[4] = 'o';

	cout << "H1: " << H1 << endl;



	Hex H2(3);

	H2[0] = '1';

	H2[1] = '2';

	H2[2] = '3';

	cout << "H2: " << H2 << endl;



	H1.Add(H2);

	cout << "H1.Add(H2) " << endl;

	cout << "H1: " << H1 << endl;



	Hex H3;

	H3 = H1 + H2;

	cout << "H3 = H1 + H2" << endl;

	cout << "H3: " << H3 << endl;



	Hex H4;

	H4 = H1 - H2;

	cout << "H4 = H1 - H2" << endl;

	cout << "H4: " << H4 << endl;



	cout << "H4 == H1: " << (H4 == H1) << endl;

	cout << "H4 == (H1-H2): " << (H4 == (H1 - H2)) << endl;



	return 0;

}