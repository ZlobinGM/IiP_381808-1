#include "Matrix.h"
#include "Exception.h"

void Matrix::NewCreate()
{
	matr = new int*[Size];
	for (int i = 0; i < Size; i++)
		matr[i] = new int[Size];
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			matr[i][j] = 0;
}

Matrix::Matrix(const Matrix &m)
{
	Size = m.Size;
	NewCreate();
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			matr[i][j] = m.matr[i][j];
}

Matrix::Matrix(int i)
{
	if (i < MinSize || i > MaxSize)
		throw TMatrixException(matrixOUTOGRANGE);
	Size = i;
	NewCreate();
}

Matrix::Matrix(int i, int num)
{
	if (i < MinSize || i > MaxSize)
		throw TMatrixException(matrixOUTOGRANGE);
	Size = i;
	NewCreate();
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			matr[i][j] = num;
}

Matrix::Matrix(int **m, int i)
{
	if (i < MinSize || i > MaxSize)
		throw TMatrixException(matrixOUTOGRANGE);
	Size = i;
	NewCreate();
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			matr[i][j] = m[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < Size; i++)
		delete[] matr[i];
	delete[] matr;
	Size = 0;
	*(const_cast<int*>(&MaxSize)) = 0;
	*(const_cast<int*>(&MinSize)) = 0;
}

void Matrix::setSize(int i)
{
	if (i < MinSize || i > MaxSize)
		throw TMatrixException(matrixOUTOGRANGE);
	Matrix clone(*this);
	for (int j = 0; j < Size; j++)
		delete[] matr[j];
	delete[] matr;
	Size = i;
	NewCreate();
	for (int i = 0; i < clone.Size && i < Size; i++)
		for (int j = 0; j < clone.Size && j < Size; j++)
			matr[i][j] = clone.matr[i][j];
}

void Matrix::inPut(const char* name)
{
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			cout << name << "[" << i << "][" << j << "] = ";
			cin >> matr[i][j];
		}
}

void Matrix::outPut(const char *name)
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			cout << name << "[" << i << "][" << j << "] = "
				<< matr[i][j] << " ";
		}
		cout << endl;
	}
}

bool Matrix::IsDiagonalMain()
{
	for (int i = 0; i < Size; i++)
	{
		int sum = 0;
		for (int j = 0; j < Size; j++)
		{
			if (j == i)continue;
			sum += matr[i][j];			
		}
		if (sum > matr[i][i]) return false;
	}
	return true;
}

int & Matrix::operator()(int i, int j)
{
	if (i < MinSize || j < MinSize || i > MaxSize || j > MaxSize)
		throw TMatrixException(matrixOUTOGRANGE);
	return matr[i][j];
}

Matrix & Matrix::operator=(const Matrix &m)
{
	if (Size != m.Size)
	{
		for (int j = 0; j < Size; j++)
			delete[] matr[j];
		delete[] matr;
		Size = m.Size;
		NewCreate();
	}
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			matr[i][j] = m.matr[i][j];
	return *this;
}

Matrix Matrix::operator+(const Matrix &m)
{
	if (Size != m.Size)
		throw TMatrixException(matrixOUTOGRANGE);
	Matrix res(Size);
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			res.matr[i][j] = m.matr[i][j] + matr[i][j];
	return res;
}

Matrix Matrix::operator-(const Matrix &m)
{
	if (Size != m.Size)
		throw TMatrixException(matrixOUTOGRANGE);
	Matrix res(Size);
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			res.matr[i][j] = matr[i][j] - m.matr[i][j];
	return res;
}

bool Matrix::operator==(const Matrix &m)
{
	if (Size != m.Size)
		return false;
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (matr[i][j] != m.matr[i][j])
				return false;
	return true;
}

ostream & operator<<(ostream & stream, const Matrix & matrix)
{
	for (int i = 0; i < matrix.Size; i++)
	{
		for (int j = 0; j < matrix.Size; j++)
		{
			stream << matrix.matr[i][j] << " ";
		}
		stream << endl;
	}
	return stream;
}

istream & operator>>(istream & stream, Matrix & matrix)
{
	for (int i = 0; i < matrix.Size; i++)
		for (int j = 0; j < matrix.Size; j++)
			stream >> matrix.matr[i][j];
	return stream;
}
