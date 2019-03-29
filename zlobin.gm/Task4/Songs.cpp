#include "Songs.h"

int Songs::SearchSong(Song key)						// Binary search
{
	int mid, left = 0, right = current;
	while (left <= right) {
		mid = (left + right) / 2;
		if (key < songs[mid])
			right = mid - 1;
		else if (key > songs[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;										
}

void Songs::SortSongs(Song *list, int last)			// Hoara sort
{
	int i = 0, j = last - 1;
	Song by = list[(i + j) / 2];
	Song tmp;

	do {
		while (list[i] < by) i++;
		while (list[j] > by) j--;

		if (i <= j) {
			if (list[i] > list[j])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		SortSongs((list + i), last - i);
	if (0 < j)
		SortSongs(list, j + 1);
}													

void Songs::getMoreLength(int len, int buf)
{
	length = len + buf;
	Song* tmp = new Song[length];
	for (int i = 0; i < current; i++)
		tmp[i] = songs[i];
	songs = new Song[length];
	for (int i = 0; i < current; i++)
		songs[i] = tmp[i];
	delete[] tmp;
}

void Songs::gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

void Songs::Menu()
{
	int choose = -1;
	while (choose != 0)
	{
		system("cls");
		gotoxy(1, 1);
		cout << "Menu:" << endl;
		cout << "1. Show" << endl;
		cout << "2. Find" << endl;
		cout << "3. Add/Remove/Change" << endl;
		cout << "4. Current length" << endl;
		cout << "0. Exit" << endl;

		do {
			choose = _getch() - '0';
		} while (choose < 0 || choose>4);

		switch (choose)
		{
		case 1:
			system("cls");
			SortSongs(songs, current);
			ShowOnConsole(*this);
			system("pause");
			break;
		case 2:
		{
			system("cls");
			gotoxy(1, 1);
			cout << "Enter characteristics of song" << endl;
			Song anysong;
			anysong.SetFromConsole();
			FindByParameters(anysong).ShowOnConsole(*this);
			system("pause");
		}
			break;
		case 3:
			do
			{
				system("cls");
				gotoxy(1, 1);
				cout << "Menu:" << endl;
				cout << "1. Add" << endl;
				cout << "2. Remove" << endl;
				cout << "3. Change" << endl;
				cout << "4. Return" << endl;

				do {
					choose = _getch() - '0';
				} while (choose < 1 || choose > 4);

				system("cls");
				gotoxy(1, 1);

				switch (choose)
				{
				case 1:
				{
					cout << "Enter characteristics of song" << endl;
					Song anysong;
					anysong.SetFromConsole();
					AddSong(anysong);
				}
					break;
				case 2:
				case 3:
				{
					cout << "Enter index: ";
					int ans;
					do {
						string some;
						getline(cin, some);
						ans = stoi(some);
					} while (ans < 1 || ans > current);
					ans--;
					if (choose == 2) {
						DelSong(ans); break;
					}
					cout << "Current characteristics: " << songs[ans] << endl;
					cout << endl << "Enter characteristics of song (Enter <skip> to skip)" << endl;
					Song anysong;
					anysong.SetFromConsole();
					songs[ans] = anysong;
				}
					break;
				default:
					break;
				}
			} while (choose != 4);
			break;
		case 4:
			system("cls");
			gotoxy(1, 1);
			cout << "Current length: " << this->getCount;
			system("pause");
			break;
		default:
			break;
		}
	}
}

ostream & operator<<(ostream & stream, const Songs & object)
{
	stream << object.current << endl;
	for (int i = 0; i < object.current; i++)
		stream << object.songs[i] << " " << endl;
	return stream;
}

istream & operator>>(istream & stream, Songs & object)
{
	stream >> object.current;
	if (object.current >= object.length)
		object.getMoreLength(object.current, object.buffer);
	for (int i = 0; i < object.current; i++)
		stream >> object.songs[i];
	return stream;
}

Songs::Songs()
{
	buffer = 10;
	current = 0;
	length = buffer + current;
	songs = new Song[length];
}

Songs::Songs(int len, int buf)
{
	buffer = buf;
	current = 0;
	length = len + buf;
	songs = new Song[length];
}

Songs::Songs(const Songs & object)
{
	buffer = object.buffer;
	current = object.current;
	length = object.length;
	songs = new Song[length];
	for (int i = 0; i < current; i++)
		songs[i] = object.songs[i];
}

Songs::Songs(istream &stream)
{
	stream >> current;
	buffer = 10;
	length = current + buffer;
	songs = new Song[length];
	for (int i = 0; i < current; i++)
		stream >> songs[i];
}

Songs::~Songs()
{
	buffer = length = current = 0;
	delete[] songs;
}

bool Songs::AddSong(const Song &pesnya)
{
	if (SearchSong(pesnya) >= 0)
		return false;
	if (current + 1 > length)
		getMoreLength(current, buffer);
	songs[current] = pesnya;
	current++;
	this->SortSongs(songs, current);
	return true;
}

void Songs::DelSong(int index)
{
	Song* tmp = new Song[length];
	for (int i = 0; i < current - 1; i++)
	{
		if (i == index) {
			tmp[i] = songs[current - 1]; continue;
		}
		tmp[i] = songs[i];
	}
	delete[] songs;
	current--;
	songs = new Song[length];
	for (int i = 0; i < current; i++)
		songs[i] = tmp[i];
	delete[] tmp;
	this->SortSongs(songs, current);
}

Songs Songs::FindByParameters(const Song &mask)
{
	Songs whatYouGet;
	for (int i = 0; i < current; i++)
		if (songs[i].SameAsMask(mask))
			whatYouGet.AddSong(songs[i]);
	return whatYouGet;
}

void Songs::ShowOnConsole(Songs& main)
{
	for (int i = 0; i < current; i++)
	{
		int position = i;
		if (&main != this)
			position = main.SearchSong(songs[i]);
		cout << position + 1 << ". " << songs[i] << endl;
	}
}
