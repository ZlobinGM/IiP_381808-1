#include "Cinema.h"



Cinema::Cinema()
{
	numberOfSessions = 0;
	numberOfHalls = 0;
}

Cinema::Cinema(istream &stream)
{
	stream >> numberOfHalls;
	halls = new Hall[numberOfHalls];
	for (int i = 0; i < numberOfHalls; i++)
		stream >> halls[i];
	stream >> numberOfSessions;
	thisMonth = new Session[numberOfSessions];
	int whichHall;
	for (int i = 0; i < numberOfSessions; i++) {
		stream >> whichHall;
		thisMonth[i].Write(stream, whichHall, halls[whichHall - 1]);
	}
}

Cinema::~Cinema()
{
	delete[] halls;
	numberOfHalls = 0;
	delete[] thisMonth;
	numberOfSessions = 0;
}

bool Cinema::TryFindPlace(int _date, double _currentDate, double _time, 
	double _currentTime, string _name, int _hall, int _zone, int _places, 
	string &_ans, int &_cost)
{
	if (_date > _currentDate + 3 || _date < _currentDate ||
		(_date == _currentDate && _time < _currentTime + 0.1)) 
	{
		_ans = "You can't go on sessions, which are after 3 days or was before";
		return false;
	}

	_ans = "There is no sessions with such parameters";

	for (int i = 0; i < numberOfSessions; i++)
	{
		if (thisMonth[i].CanGoOnThis(_date, _time,
			_name, _hall, _zone, _places, _ans, _cost))
			return true;
	}
	return false;
}

order Cinema::AddOrder(int _date, double _time, string _name, int _hall, 
	int _zone, int _places)
{
	string _ans;
	int _cost;
	for (int i = 0; i < numberOfSessions; i++)
	{
		if (thisMonth[i].CanGoOnThis(_date, _time,
			_name, _hall, _zone, _places, _ans, _cost))
			return thisMonth[i].AddOrder(_zone, _places);
	}
}

bool Cinema::TryFindCode(int _date, double _currentDate, double _time, 
	double _currentTime, string _name, int _hall, int _code, string &_ans)
{
	if (_date > _currentDate + 3 || _date < _currentDate ||
		(_date == _currentDate && _time > _currentTime + 0.1))
	{
		_ans = "You can't get money from sessions, which are not avaliable for sale";
		return false;
	}

	_ans = "There is no such code";

	for (int i = 0; i < numberOfSessions; i++)
	{
		if (thisMonth[i].CanFindCode(_date, _time,
			_name, _hall, _code))
			return true;
	}
	return false;
}

void Cinema::RemoveOrder(int _date, double _time, string _name, 
	int _hall, int _code)
{
	for (int i = 0; i < numberOfSessions; i++)
	{
		if (thisMonth[i].CanFindCode(_date, _time,
			_name, _hall, _code))
		{
			thisMonth[i].RemoveOrder(_code);
			return;
		}
	}
}

void Cinema::ShowOnConsole()
{
	for (int i = 0; i < numberOfSessions; i++)
	{
		cout << i + 1 << ". ";
		thisMonth[i].ShowOnConsole();
		cout << endl;
	}
}

ostream & operator<<(ostream &stream, const Cinema &obj)
{
	stream << obj.numberOfHalls << endl;
	for (int i = 0; i < obj.numberOfHalls; i++)
		stream << obj.halls[i] << endl;
	stream << obj.numberOfSessions << endl;
	for (int i = 0; i < obj.numberOfSessions; i++)
		stream << obj.thisMonth[i] << endl;
	return stream;
}

istream & operator>>(istream &stream, Cinema &obj)
{
	stream >> obj.numberOfHalls;
	obj.halls = new Hall[obj.numberOfHalls];
	for (int i = 0; i < obj.numberOfHalls; i++)
		stream >> obj.halls[i];
	stream >> obj.numberOfSessions;
	obj.thisMonth = new Session[obj.numberOfSessions];
	int whichHall;
	for (int i = 0; i < obj.numberOfSessions; i++) {
		stream >> whichHall;
		obj.thisMonth[i].Write(stream, whichHall, obj.halls[whichHall - 1]);
	}
	return stream;
}
