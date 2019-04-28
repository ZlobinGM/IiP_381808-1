#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include "windows.h"
#include "Session.h"
#include "Hall.h"

using namespace std;

class Cinema
{
	Session* thisMonth;
	int numberOfSessions;
	Hall* halls;
	int numberOfHalls;
public:
	Cinema();
	Cinema(istream&);
	~Cinema();

	bool TryFindPlace(int _date, double _currentDate, double _time, 
		double _currentTime, string _name, int _hall,
		int _zone, int _places, string &_ans, int &_cost);
	order AddOrder(int _date, double _time, string _name, int _hall,
		int _zone, int _places);

	bool TryFindCode(int _date, double _currentDate, double _time, 
		double _currentTime, string _name, int _hall, int _code, string &_ans);
	void RemoveOrder(int _date, double _time, string _name, int _hall,
		int _code);

	void ShowOnConsole();

	friend ostream& operator<<(ostream&, const Cinema &);
	friend istream& operator>>(istream&, Cinema &);
};

