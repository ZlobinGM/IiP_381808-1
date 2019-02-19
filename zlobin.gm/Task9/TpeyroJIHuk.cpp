#include "TpeyroJIHuk.h"
#include <iostream>
using namespace std;

TpeyroJIHuk::TpeyroJIHuk()
{
	a = b = c = 1;
}

TpeyroJIHuk::TpeyroJIHuk(double one)
{
	a = b = c = one;
}

TpeyroJIHuk::TpeyroJIHuk(double first, double second, double third)
{
	a = first; b = second; c = third;
}

TpeyroJIHuk::TpeyroJIHuk(const TpeyroJIHuk &some)
{
	a = some.a; b = some.b; c = some.c;
}

TpeyroJIHuk::~TpeyroJIHuk()
{
	a = b = c = 0;
}

string TpeyroJIHuk::Type()
{
	double esp = 1e-8;

	if (this->Exists() == "Не существует\0")
		return this->Exists();

	if (abs(a - Pifagor(b, c)) <= esp || abs(b - Pifagor(a, c)) <= esp || abs(c - Pifagor(b, a)) <= esp)
		return "Прямоугольный";
	else if (a > Pifagor(b, c) || b > Pifagor(a, c) || c > Pifagor(b, a))
		return "Тупоугольный";
	else
		return "Остроугольный";
}

string TpeyroJIHuk::Exists()
{
	double esp = 1e-8;

	if (a <= 0 || b <= 0 || c <= 0 || a - b - c >= -esp || b - a - c >= -esp || c - b - a >= -esp)
		return "Не существует\0";
	else
		return "Существует\0";
}

double TpeyroJIHuk::S()
{
	if (this->Exists() == "Не существует\0")
		return NAN;
	else
		return 0.25*sqrt((a + b + c)*(a + b - c)*(a + c - b)*(b + c - a));
}

double TpeyroJIHuk::P()
{
	if (this->Exists() == "Не существует\0")
		return NAN;
	else
		return a + b + c;
}

void TpeyroJIHuk::inPut() {
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
}
void TpeyroJIHuk::outPut(const char* name) {
	cout << name << ": a = " << a << ": b = " << b << ": c = " << c << endl;
}