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
	double currentTime;
	int currentDate;
	double money;
	Cinema* base;
public:
	TicketOffice();
	TicketOffice(Cinema *);
	~TicketOffice();

	void NewOrder();
	void DeleteOrder();
	void Menu();									// Menu
};

