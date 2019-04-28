#pragma once
#include <clocale>
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <string>
#include "Hall.h"
#include "windows.h"

using namespace std;

struct order {
	int code;
	int count;
	int** places;

	void GetRandomCode(int min, int max);

	order();
	order(const order &);
	order(int _count);
	~order();

	order& operator=(const order &);
	friend ostream& operator<<(ostream&, const order &);
	friend istream& operator>>(istream&, order &);
};

class Session
{
private:
	int date;
	double time;
	string name;
	int cost, costVIP;

	int hallNumber;
	Hall hall;

	int orders;
	int buffer;
	int length;
	order *ordersInfo;

	void GetMoreOrders(int len, int buf);
	bool HaveSameCode(int _code);

public:
	Session();
	Session(const Session &);
	~Session();

	bool CanGoOnThis(int _date, double  _time, string _name, int  _hall, 
		int  _zone, int  _places, string &_ans, int &_cost);
	order AddOrder(int _zone, int  _places);

	bool CanFindCode(int _date, double _time, string _name, int  _hall, 
		int  _code);
	void RemoveOrder(int _code);

	void ShowOnConsole();

	void Write(istream &stream, int _hallNumber, Hall _hall);

	friend ostream& operator<<(ostream&, const Session &);
};

