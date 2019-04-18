#include <clocale>
#include <iostream>
#include <fstream> 
#include "Songs.h"

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");

	ifstream is;
	is.open("Songs.txt");

	Songs c1(is);				// From konstructor

	is.close();

	c1.Menu();

	ofstream os;
	os.open("Songs.txt");
	os << c1 << endl;
	os.close();


	is.open("Songs.txt");

	Songs c2;
	is >> c2;					// From operator>>
	is.close();

	c2.Menu();

	os.open("Songs.txt");
	os << c2 << endl;
	os.close();
	
	return 0;
}