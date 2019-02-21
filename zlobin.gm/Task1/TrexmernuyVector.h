#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
using namespace std;

class TrexmernuyVector
{
private:
	double X, Y, Z;			// Kordinats vectora
public:
	TrexmernuyVector();								// Konstructor po umolchaniu
	TrexmernuyVector(const TrexmernuyVector &);		// Konstructor clone
	TrexmernuyVector(double, double, double);		// Konstructor initialisation
	TrexmernuyVector(double, double);				// Konstructor initialisation
	TrexmernuyVector(double);						// Konstructor preobrazovanie tupa
	~TrexmernuyVector();							// Deconstructor

	double& Ox() { return X; }
	double& Oy() { return Y; }
	double& Oz() { return Z; }
	double vectorLength() const { return sqrt(X * X + Y * Y + Z * Z); }

	void inPut();
	void outPut(const char*);

	// Peregryzka operaci
	// =, +, -
	TrexmernuyVector& operator=(const TrexmernuyVector &);
	TrexmernuyVector& operator+=(const TrexmernuyVector &);
	TrexmernuyVector operator+(const TrexmernuyVector &);
	TrexmernuyVector& operator-=(const TrexmernuyVector &);
	TrexmernuyVector operator-(const TrexmernuyVector &);
	// Skalyarnoe *, * on Skalyar
	double operator*(const TrexmernuyVector &);
	TrexmernuyVector operator*(double);
	TrexmernuyVector& operator*=(double);
	friend TrexmernuyVector operator*(double , const TrexmernuyVector &);
	// Sravnenie
	bool operator==(const TrexmernuyVector &);
	bool operator!=(const TrexmernuyVector &);
	bool operator>=(const TrexmernuyVector &);
	bool operator<=(const TrexmernuyVector &);
	bool operator>(const TrexmernuyVector &);
	bool operator<(const TrexmernuyVector &);
	// in and out stream
	friend ostream& operator<<(ostream&,  const TrexmernuyVector &);
	friend istream& operator>>(istream&, TrexmernuyVector &);
};
// * when number befor object
TrexmernuyVector operator*(double d, const TrexmernuyVector &vector);
// Prototips for functions
ostream& operator<<(ostream& stream, const TrexmernuyVector &vector);
istream& operator>>(istream& stream, TrexmernuyVector &vector);