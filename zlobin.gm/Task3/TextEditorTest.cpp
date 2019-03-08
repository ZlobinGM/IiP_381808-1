#include <iostream>
#include <clocale>
#include <fstream> 
#include "TextEditor.h"

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");
	/*
	int n = _getch();					// How you can find code
	int keycode = _getch();				// for functional buttons 
	cout << n << " " << keycode;
	*/
	TextEditor c1;
	TextEditor c2("Some string");
	TextEditor* c3 = new TextEditor(60, 60, 75, "Ultra string");
	TextEditor* c4 = new TextEditor(6, 6, 12);
	c4->EnterText();

	TextEditor c5;
	c5.setStr("Some very very long line, which we will move around consol and change size.");
	cout << c5;
	c5.setSize(40);
	cout << c5.getSize();
	c5.setLocation(30, 50);
	cout << c5.X() << " " << c5.Y();
	c5.setSize(20);
	cout << c5.getSize();
	c5.setLocation(10, 10);
	cout << c5.X() << " " << c5.Y();

	system("pause");
	return 0;
}
