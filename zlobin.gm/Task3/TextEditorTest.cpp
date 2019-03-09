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
	TextEditor* c3 = new TextEditor(60, 60, 15, "Ultra string");
	TextEditor* c4 = new TextEditor(6, 6, 6);
	TextEditor c5;
	c5.setStr("Some very very long line, which we will move around consol and change size.");
	cout << c5;
	c5.setSize(40);
	cout << "Current size = " << c5.getSize() << endl;
	c5.setLocation(30, 50);
	cout << "Current location X = " << c5.X()
		<< ", Y = " << c5.Y() << endl;
	c5.setSize(20);
	cout << "Current size = " << c5.getSize() << endl;
	c5.setLocation(10, 10);
	cout << "Current location X = " << c5.X()
		<< ", Y = " << c5.Y() << endl;

met:
	try
	{
		c4->Menu();
	}
	catch (TTextEditorException &exept)
	{
		if (exept.extype == textedEND)
			return 1;
		else
		{
			cout << endl << "Out of window" << endl;
			goto met;
		}
	}

	system("pause");
	return 0;
}
