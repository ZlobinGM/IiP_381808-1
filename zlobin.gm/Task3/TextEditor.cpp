#include "TextEditor.h"

bool TextEditor::outOfWindow(int x)
{
	HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hWnd, &consoleInfo);
	int weight = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	return x > weight;
}

void TextEditor::gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

TextEditor::TextEditor()
{
	system("cls");
	left = top = 2;
	size = 76;
	gotoxy(left, top);
	str = "";
}

TextEditor::TextEditor(string s)
{
	TextEditor::TextEditor();
	str = s;
	cout << str << endl;
}

TextEditor::TextEditor(int l, int t, int s)
{
	if (outOfWindow(l + s)) throw TTextEditorException(textedOUTOGRANGE);

	system("cls");
	left = l; top = t;
	size = s;
	gotoxy(left, top);
	str = "";
}

TextEditor::TextEditor(int l, int t, int s, string st)
{
	TextEditor::TextEditor(l, t, s);
	str = st;
	cout << str << endl;
}

TextEditor::~TextEditor()
{
	left = top = size = 0;
	str = "";
}

void TextEditor::setSize(int x)
{
	if (outOfWindow(left + x)) throw TTextEditorException(textedOUTOGRANGE);

	system("cls");
	size = x;
	gotoxy(left, top);
	setStr(str);
	cout << str << endl;
}

void TextEditor::setLocation(int x, int y)
{
	if (outOfWindow(size + x)) throw TTextEditorException(textedOUTOGRANGE);

	system("cls");
	left = x;
	top = y;
	gotoxy(left, top);
	cout << str << endl;
}

void TextEditor::setStr(string s)
{
	str = s;
	if (str.length() > size)
		str.resize(size);
}

string TextEditor::EnterText()
{
	system("cls");
	gotoxy(left, top);

	int x = str.length();
	char c;

	do
	{
		c = _getch();
		if (c == 8)	{			// Backspace
			if (x > 0 && str.length() > 1) { 
				str.erase(str.begin() + x - 1); x--;
			}
		}
		else if (c == 'à')		// Functional buttons
		{
			c = _getch();
			switch (c)
			{
			case 83:			// Delete
				if (x < str.length())
					str.erase(str.begin() + x);
				break;
			case 75:			// <-
				if (x > 0 && str.length() > 1) 
					x--;
				break;
			case 77:			// ->
				if (x < str.length()) 
					x++;
				break;
			}
		}
		else
		{
			if (str.length() < size)
			{
				str.insert(x, 1, c);
				x++;
			}
			else printf("\b");
		}
		system("cls");
		gotoxy(left, top);
		cout << str;
		gotoxy(x + left, top);
	} while (c != 13);		// Enter
	gotoxy(left, top + 2);
	cout << "Final text:";
	gotoxy(left, top + 3);
	cout << str << endl;
	return str;
}

void TextEditor::Menu()
{
	while (1)
	{
		system("cls");
		gotoxy(1, 1);
		cout << endl << "Current location X = " << left << ", Y = " << top << endl;
		cout << "Current size = " << size << endl;
		cout << "Menu:" << endl;
		cout << "1. Enter location and size" << endl;
		cout << "2. Start work with editor" << endl;
		cout << "3. Exit" << endl;
		int choose;

		do {
			cin >> choose;
		} while (choose < 1 || choose>3);

		switch (choose)
		{
		case 1:
			do
			{
				system("cls");
				gotoxy(1, 1);
				cout << endl << "Current location X = " << left << ", Y = " << top << endl;
				cout << "Current size = " << size << endl;
				cout << "Menu:" << endl;
				cout << "1. Change size" << endl;
				cout << "2. Change location" << endl;
				cout << "3. Return" << endl;

				do {
					cin >> choose;
				} while (choose < 1 || choose>3);

				switch (choose)
				{
				case 1:
					cout << "New size = ";
					cin >> size;
					break;
				case 2:
					cout << "New X = ";
					cin >> left;
					cout << "New Y = ";
					cin >> top;
					break;
				case 3:
					break;
				}
			} while (choose != 3);
			break;
		case 2:
			str = ""; 
			if (outOfWindow(size + left)) 
				throw TTextEditorException(textedOUTOGRANGE);
			EnterText();
			break;
		case 3:
			throw TTextEditorException(textedEND);
			break;
		}
	}
}

ostream & operator<<(ostream & stream, const TextEditor & texted)
{
	stream << texted.str << endl;
	return stream;
}

istream & operator>>(istream & stream, TextEditor & texted)
{
	getline(stream, texted.str);
	if (texted.str.length() > texted.size)
		texted.str.resize(texted.size);
	return stream;
}
