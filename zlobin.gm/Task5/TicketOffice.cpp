#include "TicketOffice.h"



TicketOffice::TicketOffice()
{
}

TicketOffice::TicketOffice(Cinema *_cinema)
{
	currentTime = 0.01;
	currentDate = 1;
	money = 0;
	base = _cinema;
}


TicketOffice::~TicketOffice()
{
	currentTime = 0;
	currentDate = 0;
	money = 0;
}

void TicketOffice::NewOrder()
{
	int date, hall, zone, places;
	double time;
	string name;
	cout << "Date: "; cin >> date;
	cout << "Time: "; cin >> time;
	cout << "Name: "; cin >> name;
	cout << "Hall: "; cin >> hall;
	cout << "Zone (0 - simple / 1 - VIP): "; cin >> zone;
	cout << "Count of places: "; cin >> places;

	int cost;
	string ans;
	if (!base->TryFindPlace(date, currentDate, time, currentTime, name, hall,
		zone, places, ans, cost)) {
		cout << ans; return;
	}

	system("cls");
	cout << "Cost: " << cost << endl;
	cout << "Menu:" << endl;
	cout << "1. Agree" << endl;
	cout << "2. Refuse" << endl;

	int choose;
	do {
		choose = _getch() - '0';
	} while (choose < 1 || choose > 2);

	if (choose == 2) return;
	money += cost;

	order place = base->AddOrder(date, time,
		name, hall, zone, places);
	for (int i = 0; i < places; i++)
	{
		cout << endl << "Ticket ¹ " << i + 1 << endl;
		cout << "Date: " << date << endl;
		cout << "Time: " << time << endl;
		cout << "Name: " << name << endl;
		cout << "Hall: " << hall << endl;
		cout << "Row: " << place.places[i][0] << endl;
		cout << "Number: " << place.places[i][1] << endl;
		cout << "Code: " << place.code << endl;
	}
}

void TicketOffice::DeleteOrder()
{
	int date, hall, code;
	double time;
	string name;
	cout << "Date: "; cin >> date;
	cout << "Time: "; cin >> time;
	cout << "Name: "; cin >> name;
	cout << "Hall: "; cin >> hall;
	cout << "Code: "; cin >> code;

	string ans;
	if (!base->TryFindCode(date, currentDate, time,
		currentTime, name, hall, code, ans)) {
		cout << ans; return;
	}

	system("cls");
	cout << "Are you sure?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;

	int choose;
	do {
		choose = _getch() - '0';
	} while (choose < 1 || choose > 2);

	if (choose == 2) return;

	base->RemoveOrder(date, time, name, hall, code);
	cout << "Order was removed: " << endl;
}

void TicketOffice::Menu()
{
	int choose = -1;
	while (choose != 0)
	{
		system("cls");
		cout << "Day:" << currentDate << " Time: " << currentTime << endl;
		cout << "Menu:" << endl;
		cout << "1. Go to ticket office" << endl;
		cout << "2. Wait" << endl;
		cout << "0. Exit" << endl;

		do {
			choose = _getch() - '0';
		} while (choose < 0 || choose > 2);
		
		switch (choose)
		{
		case 1:					// Contact with ticket office
			do
			{
				system("cls");
				cout << "Menu:" << endl;
				cout << "1. Show all sessions" << endl;
				cout << "2. Add order" << endl;
				cout << "3. Remove order" << endl;
				cout << "4. Return" << endl;

				do {
					choose = _getch() - '0';
				} while (choose < 1 || choose > 4);

				system("cls");

				switch (choose)
				{
				case 1:
				{
					system("cls");
					base->ShowOnConsole();
					system("pause");
				}
				break;
				case 2:
				{
					system("cls");
					NewOrder();
					system("pause");
				}
				break;
				case 3:
				{
					system("cls");
					DeleteOrder();
					system("pause");
				}
				break;
				default:
					break;
				}
			} while (choose != 4);
			break;
		case 2:					// Wait menu
		{
			do
			{
				system("cls");
				cout << "Day:" << currentDate << " Time: " << currentTime << endl;
				cout << "Menu:" << endl;
				cout << "1. Wait 6 days" << endl;
				cout << "2. Wait 1 days" << endl;
				cout << "3. Wait 6 hours" << endl;
				cout << "4. Wait 1 hours" << endl;
				cout << "5. Wait 10 minutes" << endl;
				cout << "6. Wait 1 minute" << endl;
				cout << "7. Return" << endl;

				do {
					choose = _getch() - '0';
				} while (choose < 1 || choose > 7);
				
				switch (choose)
				{
				case 1: { 
					currentDate += 6; 
					if (currentDate >= 31)
						currentDate -= 30;
				} break;
				case 2: { 
					currentDate += 1;
					if (currentDate >= 31)
						currentDate -= 30;
				} break;
				case 3: { 
					currentTime += 6;
					if (currentTime >= 24)
						currentTime -= 24;
				} break;
				case 4: { 
					currentTime += 1;
					if (currentTime >= 24)
						currentTime -= 24;
				} break;
				case 5: { 
					currentTime += 0.1;
					if (currentTime - int(currentTime) >= 0.6)
						currentTime -= 0.6;
				} break;
				case 6: { 
					currentTime += 0.01;
					if (currentTime - int(currentTime) >= 0.6)
						currentTime -= 0.6;
				} break;
				default:
					break;
				}
			} while (choose != 7);
		}
		break;
		default:
			break;
		}
	}
}
