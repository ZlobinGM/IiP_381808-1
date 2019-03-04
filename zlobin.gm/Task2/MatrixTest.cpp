#include <clocale>
#include <iostream>
#include <fstream> 
#include "Matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");

	Matrix c1;
	Matrix c2(2, 1);
	Matrix c3(3, -10);
	Matrix c4(c2);
	c1.outPut("c1");
	c2.outPut("c2");
	c3.outPut("c3");
	c4.outPut("c4");
	Matrix *c5 = new Matrix();
	c5->operator=(c3);
	c5->outPut("c5");

	Matrix *c6 = new Matrix();
	c6->operator=(c5->operator+(c3));
	c6->outPut("c6");
met:
	try
	{
	Matrix c7;
	c7.inPut("c7");
	c7.outPut("c7");
	}
	catch (TMatrixException &exept)
	{
		cout << "Out of range" << endl;
		goto met;
	}

	Matrix c8(2);
	c8.inPut("c8");
	if(c8.IsDiagonalMain())
		cout << "c8 have diagonal predominance" << endl;
	else
		cout << "c8 dont have diagonal predominance" << endl;

	if (c1 == c2) cout << "c1 = c2 " << endl;
	else cout << "c1 != c2 " << endl;

	ofstream os;
	os.open("Matrix.txt");
	os << c2 << c3 << endl;
	os.close();

	ifstream is;
	is.open("Matrix.txt");
	is >> c1 >> c4;
	cout << "c1: " << c1;
	cout << "c4: " << c4;
	is.close();

	system("pause");
	return 0;
}