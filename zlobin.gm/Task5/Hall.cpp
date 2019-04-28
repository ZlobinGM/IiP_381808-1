#include "Hall.h"



Hall::Hall() :
	rowLength(1), rowCount(1), rowCountVIP(1)
{
	place = new int*[1];
	place[0] = new int[1];
	place[0][0] = 0;
	placeVIP = new int*[1];
	placeVIP[0] = new int[1];
	placeVIP[0][0] = 0;
}

Hall::Hall(int _rowLength, int _rowCount, int _rowCountVIP):
	rowLength(_rowLength), rowCount(_rowCount), rowCountVIP(_rowCountVIP)
{
	place = new int*[rowCount];
	for (int i = 0; i < rowCount; i++)
		place[i] = new int[rowLength];
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < rowLength; j++)
			place[i][j] = 0;
	placeVIP = new int*[rowCountVIP];
	for (int i = 0; i < rowCountVIP; i++)
		placeVIP[i] = new int[rowLength];
	for (int i = 0; i < rowCountVIP; i++)
		for (int j = 0; j < rowLength; j++)
			placeVIP[i][j] = 0;
}

Hall::Hall(const Hall &obj):
	rowLength(obj.rowLength), rowCount(obj.rowCount), rowCountVIP(obj.rowCountVIP)
{
	place = new int*[rowCount];
	for (int i = 0; i < rowCount; i++)
		place[i] = new int[rowLength];
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < rowLength; j++)
			place[i][j] = obj.place[i][j];
	placeVIP = new int*[rowCountVIP];
	for (int i = 0; i < rowCountVIP; i++)
		placeVIP[i] = new int[rowLength];
	for (int i = 0; i < rowCountVIP; i++)
		for (int j = 0; j < rowLength; j++)
			placeVIP[i][j] = obj.placeVIP[i][j];
}

Hall::~Hall()
{
	for (int i = 0; i < rowCount; i++)
		delete[] place[i];
	delete[] place;
	for (int i = 0; i < rowCountVIP; i++)
		delete[] placeVIP[i];
	delete[] placeVIP;
	rowLength = rowCount = rowCountVIP = 0;
}

bool Hall::TryPlaceThem(int _zone, int _places)
{
	int emptyPlaces = 0;
	if (_zone) {
		for (int i = 0; i < rowCountVIP; i++)
			for (int j = 0; j < rowLength; j++)
				if (placeVIP[i][j] == 0) emptyPlaces++;
	}
	else {
		for (int i = 0; i < rowCount; i++)
			for (int j = 0; j < rowLength; j++)
				if (place[i][j] == 0) emptyPlaces++;
	}
	return (emptyPlaces >= _places) ? true : false;
}

void Hall::PlaceThem(int _zone, int _places, int ** arrayOfPlaces)
{
	int emptyPlaces = 0;
	if (_zone) {
		for (int i = 0; i < rowCountVIP; i++)
			for (int j = 0; j < rowLength; j++)
				if (placeVIP[i][j] == 0 && emptyPlaces < _places) {
					arrayOfPlaces[emptyPlaces][0] = i + 1;
					arrayOfPlaces[emptyPlaces][1] = j + 1;
					place[i][j] = 1;
					emptyPlaces++;
					if (emptyPlaces == _places) return;
				}
	}
	else {
		for (int i = 0; i < rowCount; i++)
			for (int j = 0; j < rowLength; j++)
				if (place[i][j] == 0 && emptyPlaces < _places) {
					arrayOfPlaces[emptyPlaces][0] = i + 1;
					arrayOfPlaces[emptyPlaces][1] = j + 1;
					place[i][j] = 1;
					emptyPlaces++;
					if (emptyPlaces == _places) return;
				}
	}
}

Hall & Hall::operator=(const Hall &obj)
{
	rowLength = obj.rowLength;
	rowCount = obj.rowCount;
	rowCountVIP = obj.rowCountVIP;
	place = new int*[rowCount];
	for (int i = 0; i < rowCount; i++)
		place[i] = new int[rowLength];
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < rowLength; j++)
			place[i][j] = obj.place[i][j];
	placeVIP = new int*[rowCountVIP];
	for (int i = 0; i < rowCountVIP; i++)
		placeVIP[i] = new int[rowLength];
	for (int i = 0; i < rowCountVIP; i++)
		for (int j = 0; j < rowLength; j++)
			placeVIP[i][j] = obj.placeVIP[i][j];
	return *this;
}

ostream & operator<<(ostream &stream, const Hall &obj)
{
	stream << obj.rowLength << " ";
	stream << obj.rowCount << " ";
	stream << obj.rowCountVIP;
	return stream;
}

istream & operator>>(istream &stream, Hall &obj)
{
	stream >> obj.rowLength;
	stream >> obj.rowCount;
	stream >> obj.rowCountVIP;
	obj.place = new int*[obj.rowCount];
	for (int i = 0; i < obj.rowCount; i++)
		obj.place[i] = new int[obj.rowLength];
	for (int i = 0; i < obj.rowCount; i++)
		for (int j = 0; j < obj.rowLength; j++)
			obj.place[i][j] = 0;
	obj.placeVIP = new int*[obj.rowCountVIP];
	for (int i = 0; i < obj.rowCountVIP; i++)
		obj.placeVIP[i] = new int[obj.rowLength];
	for (int i = 0; i < obj.rowCountVIP; i++)
		for (int j = 0; j < obj.rowLength; j++)
			obj.placeVIP[i][j] = 0;
	return stream;
}
