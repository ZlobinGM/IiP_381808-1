#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
using namespace std;
// @ZlobinGM Task1
class Vector3D
{
private:
	double X, Y, Z;			// Kordinats vectora
public:
	Vector3D();								// Konstructor po umolchaniu
	Vector3D(const Vector3D &);		// Konstructor clone
	Vector3D(double, double, double);		// Konstructor initialisation
	Vector3D(double, double);				// Konstructor initialisation
	Vector3D(double);						// Konstructor preobrazovanie tupa
	~Vector3D();							// Deconstructor

	double& Ox() { return X; }
	double& Oy() { return Y; }
	double& Oz() { return Z; }
	double vectorLength() const { return sqrt(X * X + Y * Y + Z * Z); }

	void inPut();
	void outPut(const char*);

	// Peregryzka operaci
	// =, +, -
	Vector3D& operator=(const Vector3D &);
	Vector3D& operator+=(const Vector3D &);
	Vector3D operator+(const Vector3D &);
	Vector3D& operator-=(const Vector3D &);
	Vector3D operator-(const Vector3D &);
	// Skalyarnoe *, * on Skalyar
	double operator*(const Vector3D &);
	Vector3D operator*(double);
	Vector3D& operator*=(double);
	friend Vector3D operator*(double , const Vector3D &);
	// Sravnenie
	bool operator==(const Vector3D &);
	bool operator!=(const Vector3D &);
	bool operator>=(const Vector3D &);
	bool operator<=(const Vector3D &);
	bool operator>(const Vector3D &);
	bool operator<(const Vector3D &);
	// in and out stream
	friend ostream& operator<<(ostream&,  const Vector3D &);
	friend istream& operator>>(istream&, Vector3D &);
};
// * when number befor object
Vector3D operator*(double d, const Vector3D &vector);
// Prototips for functions
ostream& operator<<(ostream& stream, const Vector3D &vector);
istream& operator>>(istream& stream, Vector3D &vector);
// @ZlobinGM Task1