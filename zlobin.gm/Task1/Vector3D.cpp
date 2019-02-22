#include "Vector3D.h"
#include <clocale>
#include <iostream>
#include <fstream> 
using namespace std;

Vector3D operator*(double d, const Vector3D & vector) {
	Vector3D res;
	res.X = vector.X * d;
	res.Y = vector.Y * d;
	return res;
}

// Instream and Outream
ostream & operator<<(ostream & stream, const Vector3D &vector) {
	stream << vector.X << " " << vector.Y << " " << vector.Z << endl; return stream;
}

istream & operator>>(istream & stream, Vector3D & vector) {
	stream >> vector.X >> vector.Y >> vector.Z; return stream;
}

// Konstructor po umolchaniu
Vector3D::Vector3D() { X = Y = Z = 0; }

// Konstructor clone
Vector3D::Vector3D(const Vector3D &vector) { X = vector.X; Y = vector.Y; Z = vector.Z; }

// Konstructor initialisation
Vector3D::Vector3D(double x, double y, double z) { X = x; Y = y; Z = z; }

// Konstructor initialisation
Vector3D::Vector3D(double x, double y) { X = x; Y = y; Z = 0; }

// Konstructor preobrazovanie tupa
Vector3D::Vector3D(double x) { X = x; Y = Z = 0; }

// Deconstructor
Vector3D::~Vector3D() { X = Y = Z = 0; }

void Vector3D::inPut() {
	cout << "X = "; cin >> X;
	cout << "Y = "; cin >> Y;
	cout << "Z = "; cin >> Z;
}

void Vector3D::outPut(const char *name) {
	cout << name << ": X = " << X << ": Y = " << Y << ": Z = " << Z << endl;
}

// Peregryzka prostux operaci
Vector3D & Vector3D::operator=(const Vector3D & vector){
	X = vector.X; Y = vector.Y; Z = vector.Z; return *this;
}

Vector3D & Vector3D::operator+=(const Vector3D & vector) {
	X += vector.X; Y += vector.Y; Z += vector.Z; return *this;
}

Vector3D Vector3D::operator+(const Vector3D & vector) {
	Vector3D res;
	res.X = X + vector.X;
	res.Y = Y + vector.Y;
	res.Z = Z + vector.Z;
	return res;
}

Vector3D & Vector3D::operator-=(const Vector3D & vector) {
	X -= vector.X; Y -= vector.Y; Z -= vector.Z; return *this;
}

Vector3D Vector3D::operator-(const Vector3D &vector) {
	Vector3D res;
	res.X = X - vector.X;
	res.Y = Y - vector.Y;
	res.Z = Z - vector.Z;
	return res;
}

// Skalyarnue operations
double Vector3D::operator*(const Vector3D & vector) {
	return X * vector.X + Y * vector.Y + Z * vector.Z;
}

Vector3D Vector3D::operator*(double d) {
	Vector3D res;
	res.X = X * d;
	res.Y = Y * d;
	return res;
}

Vector3D & Vector3D::operator*=(double d) {
	X *= d; Y *= d; return *this;
}

// Sravnenia
bool Vector3D::operator==(const Vector3D &vector) {
	double esp = 1e-10;
	if (abs(vectorLength() - vector.vectorLength()) < esp) return true;
	return false;
}

bool Vector3D::operator!=(const Vector3D &vector) {
	if (*this == vector) return false;
	return true;
}

bool Vector3D::operator>=(const Vector3D &vector) {
	if (*this == vector || vectorLength() > vector.vectorLength()) return true;
	return false;
}

bool Vector3D::operator<=(const Vector3D &vector) {
	if (*this == vector || vectorLength() < vector.vectorLength()) return true;
	return false;
}

bool Vector3D::operator>(const Vector3D &vector) {
	if (*this == vector || vectorLength() < vector.vectorLength()) return false;
	return true;
}

bool Vector3D::operator<(const Vector3D &vector) {
	if (*this == vector || vectorLength() > vector.vectorLength()) return false;
	return true;
}

