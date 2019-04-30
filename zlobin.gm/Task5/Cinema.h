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
	Session* thisMonth;				// Sessions in this month
	int numberOfSessions;			// Count of sessions
	Hall* halls;					// Halls in this Cinema
	int numberOfHalls;				// Count of halls
public:
	Cinema();						// Constructor
	Cinema(istream&);				// Constructor stream
	~Cinema();						// Destructor

	/* 
	_date, _time - user enter
	_currentDate, _currentTime - from ticket office
	_ans - answer to user if not found
	_cost - how much cost if found
	_hall - in which hall will be sessi0n
	_zone - VIP or simple
	*/
	bool TryFindPlace(int _date, double _currentDate, double _time, 
		double _currentTime, string _name, int _hall,
		int _zone, int _places, string &_ans, int &_cost);
	// Add order by parameters
	order AddOrder(int _date, double _time, string _name, int _hall,
		int _zone, int _places);
	// Find session by parameters and code inside
	bool TryFindCode(int _date, double _currentDate, double _time, 
		double _currentTime, string _name, int _hall, int _code, string &_ans);
	// Remove order with such code in session with such parameters
	void RemoveOrder(int _date, double _time, string _name, int _hall,
		int _code);

	void ShowOnConsole();
	// operator
	friend ostream& operator<<(ostream&, const Cinema &);
	friend istream& operator>>(istream&, Cinema &);
};

