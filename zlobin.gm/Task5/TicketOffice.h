#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include "windows.h"
#include "Cinema.h"

using namespace std;

class TicketOffice
{
private:
	double currentTime;				// Time at ticket office
	int currentDate;				// Date at ticket office
	double money;					// How much this ticket office earn
	Cinema* base;					// Reference on base
public:
	TicketOffice();					// Constructor
	TicketOffice(Cinema *);			// Constructor with reference
	~TicketOffice();				// Destructor

	void NewOrder();				// If user want to form order
	void DeleteOrder();				// If user want to close order
	void Menu();					// Menu
};

