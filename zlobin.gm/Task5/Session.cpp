#include "Session.h"



void Session::GetMoreOrders(int len, int buf)
{
	length = len + buf;
	order* tmp = new order[length];
	for (int i = 0; i < orders; i++)
		tmp[i] = ordersInfo[i];
	delete[] ordersInfo;
	ordersInfo = tmp;
}

bool Session::HaveSameCode(int _code)
{
	for (int i = 0; i < orders; i++)
		if (ordersInfo[i].code == _code) return true;
	return false;
}

Session::Session()
{
	date = time = cost = costVIP = hallNumber = 0;
	name = "";
	orders = 0;
	buffer = length = 10;
	ordersInfo = new order[length];
}

Session::Session(const Session &obj)
{
	date = obj.date;
	time = obj.time;
	name = obj.name;
	cost = obj.cost;
	costVIP = obj.costVIP;

	hallNumber = obj.hallNumber;
	hall = obj.hall;

	orders = obj.orders;
	buffer = obj.orders;
	length = obj.orders;
	ordersInfo = new order[length];
	for (int i = 0; i < orders; i++)
		ordersInfo[i] = obj.ordersInfo[i];
}

Session::~Session()
{
	date = time = cost = costVIP = hallNumber = 0;
	name = "";

	delete[] ordersInfo;
	orders = buffer = length = 0;
}

bool Session::CanGoOnThis(int _date, double _time, string _name, int _hall,
	int _zone, int _places, string & _ans, int & _cost)
{
	if (!(date == _date && time == _time && name == _name && hallNumber == _hall))
		return false;
	if (!hall.TryPlaceThem(_zone, _places)) {
		_ans = "There are not enough empty placces for you";
		return false;
	}

	double sale = (time < 12) ? 0.75 : ((time > 18) ? 1.5 : 1.0);
	int currentCost = (_zone) ? costVIP : cost;
	_cost = currentCost * sale * _places;
	return true;
}

order Session::AddOrder(int _zone, int _places)
{
	if (orders == length)
		GetMoreOrders(orders, buffer);
	order newOrder(_places);

	do {newOrder.GetRandomCode(10000, 99999);}
	while (HaveSameCode(newOrder.code));
	hall.PlaceThem(_zone, _places, newOrder.places);

	ordersInfo[orders] = newOrder;
	orders++;
	return newOrder;
}

bool Session::CanFindCode(int _date, double _time, string _name, int _hall, int _code)
{
	if (!(date == _date && time == _time && name == _name && hallNumber == _hall))
		return false;
	return HaveSameCode(_code);
}

void Session::RemoveOrder(int _code)
{
	order* tmp = new order[length];
	for (int i = 0; i < orders - 1; i++)
	{
		if (ordersInfo[i].code == _code) {
			tmp[i] = ordersInfo[orders - 1]; continue;
		}
		tmp[i] = ordersInfo[i];
	}
	delete[] ordersInfo;
	orders--;
	ordersInfo = new order[length];
	for (int i = 0; i < orders; i++)
		ordersInfo[i] = tmp[i];
}

void Session::ShowOnConsole()
{
	cout << "Date: " << date << " ";
	cout << "Time: " << time << " ";
	cout << "Name: " << name << " ";
	cout << "Simple: " << cost << " ";
	cout << "VIP: " << costVIP;
}

void Session::Write(istream & stream, int _hallNumber, Hall _hall)
{
	stream >> date;
	stream >> time;
	stream >> name;
	stream >> cost;
	stream >> costVIP;

	hallNumber = _hallNumber;
	hall = _hall;

	stream >> orders;
	buffer = 10;
	length = orders;
	ordersInfo = new order[length];
	for (int i = 0; i < orders; i++)
		stream >> ordersInfo[i];
}

// struct order

void order::GetRandomCode(int min, int max)
{
	double range = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	code = static_cast<int>(rand() * range *(max - min + 1) + min);
}

order::order() : count(0), code(0){}

order::order(const order &obj) : count(obj.count), code(obj.code)
{
	places = new int*[count];
	for (int i = 0; i < count; i++)
	{
		places[i] = new int[2];
		places[i][0] = obj.places[i][0];
		places[i][1] = obj.places[i][1];
	}
}

order::order(int _count): count(_count)
{
	places = new int*[count];
	for (int i = 0; i < count; i++)
	{
		places[i] = new int[2];
		places[i][0] = 0;
		places[i][1] = 0;
	}
}

order::~order()
{
	for (int i = 0; i < count; i++)
		delete[] places[i];
	if (count > 0)	delete[] places;
	code = count = 0;
}

order & order::operator=(const order &obj)
{
	count = obj.count;
	code = obj.code;
	places = new int*[count];
	for (int i = 0; i < count; i++)
	{
		places[i] = new int[2];
		places[i][0] = obj.places[i][0];
		places[i][1] = obj.places[i][1];
	}
	return *this;
}

ostream & operator<<(ostream &stream, const order & obj)
{
	stream << obj.code << " ";
	stream << obj.count << " ";
	for (int i = 0; i < obj.count; i++)
	{
		stream << obj.places[i][0] << " ";
		stream << obj.places[i][1] << " ";
	}
	return stream;
}

istream & operator>>(istream &stream, order & obj)
{
	stream >> obj.code;
	stream >> obj.count;
	obj.places = new int*[obj.count];
	for (int i = 0; i < obj.count; i++)
	{
		obj.places[i] = new int[2];
		stream >> obj.places[i][0];
		stream >> obj.places[i][1];
	}
	return stream;
}

ostream & operator<<(ostream &stream, const Session &obj)
{
	stream << obj.hallNumber << " ";
	stream << obj.date << " ";
	stream << obj.time << " ";
	stream << obj.name << " ";
	stream << obj.cost << " ";
	stream << obj.costVIP << " ";

	stream << obj.orders << " ";
	for (int i = 0; i < obj.orders; i++)
		stream << obj.ordersInfo[i] << " ";
	return stream;
}
