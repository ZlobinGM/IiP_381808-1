#include <clocale>
#include <iostream>
#include <fstream> 
#include "Vector3D.h"
using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");

	Vector3D c1;          
	Vector3D c2(1.1, 2.2); 
	Vector3D c3(3.3, 4.4, -10.0); 
	Vector3D c4(c2);       
	c1.outPut("c1");
	c2.outPut("c2");
	c3.outPut("c3");
	c4.outPut("c4");

	Vector3D *c5 = new Vector3D();
	c5->operator=(c2);
	c5->outPut("c5");

	Vector3D *c6 = new Vector3D();
	c6->operator=(c5->operator*(1.1));
	c6->outPut("c6");

	Vector3D c7;
	c7 += c2 + c3;
	c7.outPut("c7");

	Vector3D c8;
	c8 -= c3;
	cout << "Skalayrnoe proisvedenie c8 * c7 = " << c8 * c7 << endl;

	if (c1 == c2) cout << "c1 = c2 " << endl;
	else if (c1 > c2) cout << "c1 > c2 " << endl;
	else cout << "c1 > c2 " << endl;

	ofstream os;           
	os.open("TrexmernuyVector.txt"); 
	os << c2 << c3 << endl;
	os.close();

	ifstream is;           
	is.open("TrexmernuyVector.txt"); 
	is >> c1 >> c4;
	cout << "c1: " << c1;
	cout << "c4: " << c4;
	is.close();

	system ("pause");
	return 0;
}
