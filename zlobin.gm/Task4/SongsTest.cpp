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

	Songs c(is);

	is.close();

	c.Menu();

	ofstream os;
	os.open("Songs.txt");
	os << c << endl;
	os.close();
	
	return 0;
}