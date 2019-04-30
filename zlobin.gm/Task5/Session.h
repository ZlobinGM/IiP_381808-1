#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <string>
#include "Hall.h"
#include "windows.h"

using namespace std;

struct order {						// Sub class 
	int code;					// Every order goes with unique code
	int count;					// Count of places in order
	int** places;				// Array of places's cordinates (row and column)

	void GetRandomCode(int min, int max);		// Random code

	order();					// Constructor
	order(const order &);		// Constructor copy
	order(int _count);			// Constructor
	~order();					// Destructor

	// Overload operations
	order& operator=(const order &);
	friend ostream& operator<<(ostream&, const order &);
	friend istream& operator>>(istream&, order &);
};

class Session					// Seace in Cinema
{
private:
	int date;				// Session date
	double time;			// Session time
	string name;			// Film name
	int cost, costVIP;		// Cost of ticket

	int hallNumber;			// Hall number
	Hall hall;				// Hall (matrix of empty and not places)

	int orders;				// Count of orders
	int buffer;				// buffer
	int length;				// real length 
	order *ordersInfo;

	void GetMoreOrders(int len, int buf);		// more place for orders
	bool HaveSameCode(int _code);				// Check in random code already exist

public:
	Session();						// Constructor
	Session(const Session &);		// Constructor copy
	~Session();						// Constructor

	// Find session by parameters (ans - answer to user What's wrog, cost - cost of tickets)
	bool CanGoOnThis(int _date, double  _time, string _name, int  _hall, 
		int  _zone, int  _places, string &_ans, int &_cost);
	// Add order
	order AddOrder(int _zone, int  _places);
	// Find session with such code
	bool CanFindCode(int _date, double _time, string _name, int  _hall, 
		int  _code);
	// Remove order by code
	void RemoveOrder(int _code);

	void ShowOnConsole();
	// Constructor for elements of (array of sessions)
	void Write(istream &stream, int _hallNumber, Hall _hall);
	// operator
	friend ostream& operator<<(ostream&, const Session &);
};

