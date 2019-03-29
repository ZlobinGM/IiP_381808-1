#include "Song.h"

Song::Song()
{
	name = "";
	author = "";
	composer = "";
	executor = "";
	album = "";
	date = "";
}

Song::Song(const Song &obj)
{
	name = obj.name;
	author = obj.author;
	composer = obj.composer;
	executor = obj.executor;
	album = obj.album;
	date = obj.date;
}

Song::~Song()
{
	name = "";
	author = "";
	composer = "";
	executor = "";
	album = "";
	date = "";
}

Song & Song::SetFromConsole()
{
	cout << "Name: ";
	getline(cin, name);
	if (name == "")name = "Unknown";
	cout << "Author: ";
	getline(cin, author);
	if (author == "")author = "Unknown";
	cout << "Composer: ";
	getline(cin, composer);
	if (composer == "")composer = "Unknown";
	cout << "Executor: ";
	getline(cin, executor);
	if (executor == "")executor = "Unknown";
	cout << "Album: ";
	getline(cin, album);
	if (album == "")album = "Unknown";
	cout << "Date(YYYY.MM.DD): ";
	getline(cin, date);
	if (date == "")date = "Unknown";
	return *this;
}

bool Song::SameAsMask(const Song & obj)
{
	string infoThis[6] = { name, author, composer, executor, album, date };
	string infoObj[6] = { obj.name, obj.author, obj.composer, obj.executor, obj.album, obj.date };
	int total = 6;
	for (int i = 0; i < 6; i++)
		if (infoObj[i] == "Unknown") total--;
	int same = 0;
	for (int i = 0; i < 6; i++)
		if (infoObj[i] == infoThis[i] && infoObj[i] != "Unknown") same++;
	if (same == total)
		return true;
	return false;
}

Song & Song::operator=(const Song &obj)
{
	if (obj.name != "skip") name = obj.name;
	if (obj.author != "skip") author = obj.author;
	if (obj.composer != "skip") composer = obj.composer;
	if (obj.executor != "skip") executor = obj.executor;
	if (obj.album != "skip") album = obj.album;
	if (obj.date != "skip") date = obj.date;
	return *this;
}

bool Song::operator<(const Song &obj)
{
	string infoThis[6] = { name, author, composer, executor, album, date };
	string infoObj[6] = { obj.name, obj.author, obj.composer, obj.executor, obj.album, obj.date };
	for (int i = 0; i < 6; i++)
		if (infoObj[i] != infoThis[i]) 
			return infoThis[i] < infoObj[i];
	return false;
}

bool Song::operator>(const Song &obj)
{
	string infoThis[6] = { name, author, composer, executor, album, date };
	string infoObj[6] = { obj.name, obj.author, obj.composer, obj.executor, obj.album, obj.date };
	for (int i = 0; i < 6; i++)
		if (infoObj[i] != infoThis[i])
			return infoThis[i] > infoObj[i];
	return false;
}

ostream & operator<<(ostream &stream, const Song & obj)
{
	stream << obj.name << " ";
	stream << obj.author << " ";
	stream << obj.composer << " ";
	stream << obj.executor << " ";
	stream << obj.album << " ";
	stream << obj.date;
	return stream;
}

istream & operator>>(istream &stream, Song &obj)
{
	stream >> obj.name;
	stream >> obj.author;
	stream >> obj.composer;
	stream >> obj.executor;
	stream >> obj.album;
	stream >> obj.date;
	return stream;
}
