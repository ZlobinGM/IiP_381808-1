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
	right = 78;
	gotoxy(left, top);
	str = "";
}

TextEditor::TextEditor(string s)
{
	TextEditor::TextEditor();
	str = s;
	cout << str;
}

TextEditor::TextEditor(int l, int t, int r)
{
	if (outOfWindow(r)) throw TTextEditorException(textedOUTOGRANGE);

	system("cls");
	left = l; top = t;
	right = r;
	gotoxy(left, top);
	str = "";
}

TextEditor::TextEditor(int l, int t, int r, string s)
{
	TextEditor::TextEditor(l, t, r);
	str = s;
	cout << str;
}

TextEditor::~TextEditor()
{
	left = top = right = 0;
	str = "";
}

void TextEditor::setSize(int x)
{
	if (outOfWindow(left + x)) throw TTextEditorException(textedOUTOGRANGE);

	system("cls");
	right = left + x;
	gotoxy(left, top);
	setStr(str);
	cout << str;
}

void TextEditor::setLocation(int x, int y)
{
	if (outOfWindow(right - left + x)) throw TTextEditorException(textedOUTOGRANGE);

	system("cls");
	right = right - left + x;
	left = x;
	top = y;
	gotoxy(left, top);
	cout << str;
}

void TextEditor::setStr(string s)
{
	str = s;
	if (str.length() > right - left)
		str.resize(right - left);
}

string TextEditor::EnterText()
{
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
			if (str.length() < right - left)
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
	cout << str;
	return str;
}

ostream & operator<<(ostream & stream, const TextEditor & texted)
{
	stream << texted.str << endl;
	return stream;
}

istream & operator>>(istream & stream, TextEditor & texted)
{
	getline(stream, texted.str);
	if (texted.str.length() > texted.right - texted.left)
		texted.str.resize(texted.right - texted.left);
	return stream;
}
