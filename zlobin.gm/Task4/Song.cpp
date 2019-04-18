#include "Song.h"

Song::Song()
{
	info = new string[6];
	for (int i = 0; i < 6; i++)
		info[i] = "";
}

Song::Song(const Song &obj)
{
	info = new string[6];
	for (int i = 0; i < 6; i++)
		info[i]=obj.info[i];
}

Song::~Song()
{
	for (int i = 0; i < 6; i++)
		info[i] = "";
	delete[] info;
}

Song & Song::SetFromConsole()
{
	cout << "Name: ";
	getline(cin, info[0]);
	cout << "Author: ";
	getline(cin, info[1]);
	cout << "Composer: ";
	getline(cin, info[2]);
	cout << "Executor: ";
	getline(cin, info[3]);
	cout << "Album: ";
	getline(cin, info[4]);
	cout << "Date(YYYY.MM.DD): ";
	getline(cin, info[5]);
	for (int i = 0; i < 6; i++)
		if (info[i] == "") info[i] = "Unknown";
	return *this;
}

bool Song::SameAsMask(const Song & obj)
{
	int same = 0;
	for (int i = 0; i < 6; i++)
		if (obj.info[i] == "Unknown" ||
			(info[i] == obj.info[i] && obj.info[i] != "Unknown")) same++;
	if (same == 6)
		return true;
	return false;
}

Song & Song::operator=(const Song &obj)
{
	for (int i = 0; i < 6; i++)
		if (obj.info[i] != "skip") info[i] = obj.info[i];
	return *this;
}

bool Song::operator<(const Song &obj)
{
	for (int i = 0; i < 6; i++)
		if (info[i] != obj.info[i])
			return info[i] < obj.info[i];
	return false;
}

bool Song::operator>(const Song &obj)
{
	for (int i = 0; i < 6; i++)
		if (info[i] != obj.info[i])
			return info[i] > obj.info[i];
	return false;
}

ostream & operator<<(ostream &stream, const Song & obj)
{
	for (int i = 0; i < 6; i++)
		stream << obj.info[i] << " ";
	return stream;
}

istream & operator>>(istream &stream, Song &obj)
{
	for (int i = 0; i < 6; i++)
		stream >> obj.info[i];
	return stream;
}
