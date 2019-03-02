#pragma once

enum TMatrixEXType { matrixNOTNUMERIC, matrixOUTOGRANGE };
struct TMatrixException
{
	TMatrixEXType extype;	// Typo of exception
	TMatrixException(TMatrixEXType _extype) :
		extype(_extype) {}
};