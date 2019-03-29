#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include "windows.h"

using namespace std;

class Song
{
private:
	string name;
	string author;
	string composer;
	string executor;
	string album;
	string date;
public:
	Song();									// Konstructor
	Song(const Song &);						// Konstructor copy
	~Song();								// Deconstructor

	Song& SetFromConsole();					// Enter value from console
	bool SameAsMask(const Song &obj);		// Check same as mask or not

	// operator
	Song& operator=(const Song &);			
	bool operator<(const Song &);			// Used in SortSongs and SearchSongs in Songs
	bool operator>(const Song &);			// Used in SortSongs and SearchSongs in Songs
	// in and out stream
	friend ostream& operator<<(ostream&, const Song &);
	friend istream& operator>>(istream&, Song &);
};

