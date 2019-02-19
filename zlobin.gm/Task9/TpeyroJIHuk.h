#pragma once

#include <string>
using namespace std;

class TpeyroJIHuk
{
private:
	double a, b, c;
	bool exist;
	double Pifagor(double& first, double& second) { return sqrt(pow(first, 2) + pow(second, 2)); }
public:
	TpeyroJIHuk();
	TpeyroJIHuk(double);
	TpeyroJIHuk(double, double, double);
	TpeyroJIHuk(const TpeyroJIHuk &);
	~TpeyroJIHuk();

	string Type();
	string Exists();

	double& A() { return a; }
	double& B() { return b; }
	double& C() { return c; }

	double S();
	double P();

	void inPut();
	void outPut(const char* name);
};

