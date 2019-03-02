#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
using namespace std;

class Matrix
{
private:
	int Size;
	const int MaxSize = 8, MinSize = 2;		// Ogranicheniya
	int** matr;
	void NewCreate();
public:
	Matrix(): Size(3) { NewCreate(); }		// Konstructor po umolchaniu
	Matrix(const Matrix &);					// Konstructor clone
	Matrix(int);							// Konstructor initialisation
	Matrix(int, int);						// Konstructor initialisation
	Matrix(int**, int);						// Konstructor preobrazovanie tupa
	~Matrix();								// Deconstructor
	
	int getSize() { return Size; }			// Get size
	void setSize(int);						// Set size

	void inPut(const char*);
	void outPut(const char*);

	bool IsDiagonalMain();					// Diagonal is Main

	// Peregryzka operaci
	// Obyavlenie function
	int& operator()(int, int);
	// =, +, -
	Matrix& operator=(const Matrix &);
	Matrix operator+(const Matrix &);
	Matrix operator-(const Matrix &);
	// Sravnenie
	bool operator==(const Matrix &);
	// in and out stream
	friend ostream& operator<<(ostream&, const Matrix &);
	friend istream& operator>>(istream&, Matrix &);
};
// Prototips for functions
ostream& operator<<(ostream& stream, const Matrix &matrix);
istream& operator>>(istream& stream, Matrix &matrix);
