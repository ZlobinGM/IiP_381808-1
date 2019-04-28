#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include "windows.h"

using namespace std;

class Hall
{
	int rowLength;
	int rowCount, rowCountVIP;
	int **place, **placeVIP;
public:
	Hall();
	Hall(int _rowLength, int _rowCount, int _rowCountVIP);
	Hall(const Hall&);
	~Hall();

	bool TryPlaceThem(int _zone, int _places);
	void PlaceThem(int _zone, int _places, int** arrayOfPlaces);


	Hall& operator=(const Hall &);
	friend ostream& operator<<(ostream&, const Hall &);
	friend istream& operator>>(istream&, Hall &);
};

