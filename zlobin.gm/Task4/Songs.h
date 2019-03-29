#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include "windows.h"
#include "Song.h"

using namespace std;

class Songs
{
private:
	int length, current, buffer;

	Song *songs;

	int SearchSong(Song);							// Find index 
	void SortSongs(Song*, int);						// Sort all by Name > Author > ... > Date

	void getMoreLength(int, int);					// Add more length to (Song* songs)
	void gotoxy(int, int);							// Function from conio
public:
	Songs();										// Konstructor default
	Songs(int, int);								// Konstructor tmp
	Songs(const Songs&);							// Konstructor copy
	Songs(istream&);								// Konstructor from file
	~Songs();										// Deconstruct

	int getCount() { return current; }				// Current length
	
	bool AddSong(const Song &);						// Add song
	void DelSong(int);								// Remove song

	Songs FindByParameters(const Song&);			// Search 

	void ShowOnConsole(Songs&);						// Write on console

	void Menu();									// Menu

	// in and out stream
	friend ostream& operator<<(ostream&, const Songs &);
	friend istream& operator>>(istream&, Songs &);
};

