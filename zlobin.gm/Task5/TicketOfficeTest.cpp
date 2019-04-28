#include <clocale>
#include <iostream>
#include <fstream> 
#include <ctime> 
#include "TicketOffice.h"
#include "Cinema.h"

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_CTYPE, "Russian");
	srand(static_cast<unsigned int>(time(0)));
	ifstream is;
	is.open("TicketOffice.txt");

	Cinema c(is);				// From konstructor

	is.close();

	TicketOffice t(&c);
	t.Menu();

	ofstream os;
	os.open("TicketOffice.txt");
	os << c << endl;
	os.close();

	return 0;
}