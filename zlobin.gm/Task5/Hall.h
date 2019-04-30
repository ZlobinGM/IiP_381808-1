#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include "windows.h"

using namespace std;

class Hall
{
	int rowLength;					// Row length
	int rowCount, rowCountVIP;		// Count of rows in each zone
	int **place, **placeVIP;		// Matrix of places
public:
	Hall();							// Constructor
	Hall(int _rowLength, int _rowCount, int _rowCountVIP); // Constructor by parameters
	Hall(const Hall&);				// Constructor copy
	~Hall();						// Destructor

	bool TryPlaceThem(int _zone, int _places);						// If enough places empty in this hall
	void PlaceThem(int _zone, int _places, int** arrayOfPlaces);	// Reserve places

	// operator
	Hall& operator=(const Hall &);
	friend ostream& operator<<(ostream&, const Hall &);
	friend istream& operator>>(istream&, Hall &);
};

