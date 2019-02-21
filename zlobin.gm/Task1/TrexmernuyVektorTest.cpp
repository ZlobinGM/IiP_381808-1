#include <clocale>
#include <iostream>
#include <fstream> 
#include "TrexmernuyVector.h"
using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");

	TrexmernuyVector c1;           // конструктор по умолчанию
	TrexmernuyVector c2(1.1, 2.2); // конструктор инициализатор
	TrexmernuyVector c3(3.3, 4.4, -10.0); // конструктор инициализатор
	TrexmernuyVector c4(c2);       // конструктор копирования
	c1.outPut("c1");
	c2.outPut("c2");
	c3.outPut("c3");
	c4.outPut("c4");

	TrexmernuyVector *c5 = new TrexmernuyVector();
	c5->operator=(c2);
	c5->outPut("c5");

	TrexmernuyVector *c6 = new TrexmernuyVector();
	c6->operator=(c5->operator*(1.1));
	c6->outPut("c6");

	TrexmernuyVector c7;
	c7 += c2 + c3;
	c7.outPut("c7");

	TrexmernuyVector c8;
	c8 -= c3;
	cout << "Skalayrnoe proisvedenie c8 * c7 = " << c8 * c7 << endl;

	if (c1 == c2) cout << "c1 = c2 " << endl;
	else if (c1 > c2) cout << "c1 > c2 " << endl;
	else cout << "c1 > c2 " << endl;

	// Запись в поток
	ofstream os;            // поток для записи
	os.open("TrexmernuyVector.txt"); // файл для записи
	os << c2 << c3 << endl;
	os.close();

	// Чтение из потока
	ifstream is;            // поток для чтения
	is.open("TrexmernuyVector.txt"); // файл для чтения
	is >> c1 >> c4;
	cout << "c1: " << c1;
	cout << "c4: " << c4;
	is.close();

	system ("pause");
	return 0;
}
