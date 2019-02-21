#include <clocale>
#include <iostream>
#include <string>
#include "TpeyroJIHuk.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Russian");

	// Конструкторы
	TpeyroJIHuk c0;
	TpeyroJIHuk c1(1.1, 2.2, 3.3);
	TpeyroJIHuk c2(3.3, 4.4, 3.3);
	TpeyroJIHuk c3(c1);
	TpeyroJIHuk c4(3.3);

	TpeyroJIHuk *pc0 = new TpeyroJIHuk();
	TpeyroJIHuk *pc1 = new TpeyroJIHuk(1.1, 2.2, 3.3);
	TpeyroJIHuk *pc3 = new TpeyroJIHuk(c1);
	TpeyroJIHuk *pc4 = new TpeyroJIHuk(3.3);

	c0.outPut("c0");
	c1.outPut("c1");
	c2.outPut("c2");
	c3.outPut("c3");
	c4.outPut("c4");

	pc0->A() = 1.5;
	pc3->B() = pc4->A();
	pc0->outPut("pc0");
	pc3->outPut("pc3");

	TpeyroJIHuk c7(c1), c8(c2);
	c7.outPut("c7");
	cout << "Существует ли? " << c7.Exists() << endl;
	cout << "Тип треугольник " << c7.Type() << endl;
	c8.outPut("c8");
	cout << "Существует ли? " << c8.Exists() << endl;
	cout << "Тип треугольник " << c8.Type() << endl;

	TpeyroJIHuk c5, c6;
	c5.inPut();
	c5.outPut("c5");
	cout << "Площадь = " << c5.S() << ": Периметр = " << c5.P() << endl;
	c6.inPut();
	cout << "Площадь = " << c6.S() << ": Периметр = " << c6.P() << endl;
	c6.outPut("c6");

	delete pc0;
	delete pc1;
	delete pc3;
	delete pc4;

	system("pause");

	return 0;
}