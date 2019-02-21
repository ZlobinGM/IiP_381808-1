#include "TrexmernuyVector.h"
#include <clocale>
#include <iostream>
#include <fstream> 
using namespace std;

TrexmernuyVector operator*(double d, const TrexmernuyVector & vector) {
	TrexmernuyVector res;
	res.X = vector.X * d;
	res.Y = vector.Y * d;
	return res;
}

// Instream and Outream
ostream & operator<<(ostream & stream, const TrexmernuyVector &vector) {
	stream << vector.X << " " << vector.Y << " " << vector.Z << endl; return stream;
}

istream & operator>>(istream & stream, TrexmernuyVector & vector) {
	stream >> vector.X >> vector.Y >> vector.Z; return stream;
}

// Konstructor po umolchaniu
TrexmernuyVector::TrexmernuyVector() { X = Y = Z = 0; }

// Konstructor clone
TrexmernuyVector::TrexmernuyVector(const TrexmernuyVector &vector) { X = vector.X; Y = vector.Y; Z = vector.Z; }

// Konstructor initialisation
TrexmernuyVector::TrexmernuyVector(double x, double y, double z) { X = x; Y = y; Z = z; }

// Konstructor initialisation
TrexmernuyVector::TrexmernuyVector(double x, double y) { X = x; Y = y; Z = 0; }

// Konstructor preobrazovanie tupa
TrexmernuyVector::TrexmernuyVector(double x) { X = x; Y = Z = 0; }

// Deconstructor
TrexmernuyVector::~TrexmernuyVector() { X = Y = Z = 0; }

void TrexmernuyVector::inPut() {
	cout << "X = "; cin >> X;
	cout << "Y = "; cin >> Y;
	cout << "Z = "; cin >> Z;
}

void TrexmernuyVector::outPut(const char *name) {
	cout << name << ": X = " << X << ": Y = " << Y << ": Z = " << Z << endl;
}

// Peregryzka prostux operaci
TrexmernuyVector & TrexmernuyVector::operator=(const TrexmernuyVector & vector){
	X = vector.X; Y = vector.Y; Z = vector.Z; return *this;
}

TrexmernuyVector & TrexmernuyVector::operator+=(const TrexmernuyVector & vector) {
	X += vector.X; Y += vector.Y; Z += vector.Z; return *this;
}

TrexmernuyVector TrexmernuyVector::operator+(const TrexmernuyVector & vector) {
	TrexmernuyVector res;
	res.X = X + vector.X;
	res.Y = Y + vector.Y;
	res.Z = Z + vector.Z;
	return res;
}

TrexmernuyVector & TrexmernuyVector::operator-=(const TrexmernuyVector & vector) {
	X -= vector.X; Y -= vector.Y; Z -= vector.Z; return *this;
}

TrexmernuyVector TrexmernuyVector::operator-(const TrexmernuyVector &vector) {
	TrexmernuyVector res;
	res.X = X - vector.X;
	res.Y = Y - vector.Y;
	res.Z = Z - vector.Z;
	return res;
}

// Skalyarnue operations
double TrexmernuyVector::operator*(const TrexmernuyVector & vector) {
	return X * vector.X + Y * vector.Y + Z * vector.Z;
}

TrexmernuyVector TrexmernuyVector::operator*(double d) {
	TrexmernuyVector res;
	res.X = X * d;
	res.Y = Y * d;
	return res;
}

TrexmernuyVector & TrexmernuyVector::operator*=(double d) {
	X *= d; Y *= d; return *this;
}

// Sravnenia
bool TrexmernuyVector::operator==(const TrexmernuyVector &vector) {
	double esp = 1e-10;
	if (abs(vectorLength() - vector.vectorLength()) < esp) return true;
	return false;
}

bool TrexmernuyVector::operator!=(const TrexmernuyVector &vector) {
	if (*this == vector) return false;
	return true;
}

bool TrexmernuyVector::operator>=(const TrexmernuyVector &vector) {
	if (*this == vector || vectorLength() > vector.vectorLength()) return true;
	return false;
}

bool TrexmernuyVector::operator<=(const TrexmernuyVector &vector) {
	if (*this == vector || vectorLength() < vector.vectorLength()) return true;
	return false;
}

bool TrexmernuyVector::operator>(const TrexmernuyVector &vector) {
	if (*this == vector || vectorLength() < vector.vectorLength()) return false;
	return true;
}

bool TrexmernuyVector::operator<(const TrexmernuyVector &vector) {
	if (*this == vector || vectorLength() > vector.vectorLength()) return false;
	return true;
}

