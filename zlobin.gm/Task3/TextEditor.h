#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include "windows.h"
#include <conio.h>

using namespace std;

enum TTextEditorEXType { textedOUTOGRANGE };
struct TTextEditorException
{
	TTextEditorEXType extype;	// Typo of exception
	TTextEditorException(TTextEditorEXType _extype) :
		extype(_extype) {}
};

class TextEditor
{
private:
	int left, top, right;
	string str;
	bool outOfWindow(int);							// Out of consol window?
	void gotoxy(int, int);							// Function from conio
	// gotoxy doesn't exist in "conio.h" now
public:
	TextEditor();									// Konstructor po umolchaniu
	TextEditor(string);								// Konstructor chage type
	TextEditor(int, int, int);						// Konstructor
	TextEditor(int, int, int, string);				// Konstructor
	~TextEditor();									// Deconstruct

	int getSize() { return right - left; }			// Get size
	void setSize(int);								// Set size

	int& X() { return left; }						// Get location X
	int& Y() { return top; }						// Get location Y
	void setLocation(int, int);						// Set location

	void setStr(string);							// Set string with length conrol
	string EnterText();								// Editor

	// in and out stream
	friend ostream& operator<<(ostream&, const TextEditor &);
	friend istream& operator>>(istream&, TextEditor &);
};
// Prototips for functions
ostream& operator<<(ostream& stream, const TextEditor &texted);
istream& operator>>(istream& stream, TextEditor &texted);



