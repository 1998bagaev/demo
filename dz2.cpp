#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <map>
#include "Header.h"

#define LOAD 0
#define AD 1
#define AA 2
#define AP 3
#define SEARCHD 4
#define SEARCHA 5
#define SEARCHP 6
#define SHOWD 7
#define SHOWA 8
#define SHOWP 9

using namespace std;

map<int, driver> drivers;
map<int, autom> automobiles;
map<int, passen> passengers;


void loadbase()
{
	int count;
	char temp[7];

	ifstream f("base.txt");

	f >> count;
	f.getline(temp, 7);
	for (int i = 0; i < count; ++i)
	{
		driver driver;
		driver.load(f);
		drivers[driver.IDD] = driver;
	}


	f >> count;
	f.getline(temp, 7);
	for (int i = 0; i < count; ++i)
	{
		autom autom;
		autom.load(f);
		automobiles[autom.IDA] = autom;
	}


	f >> count;
	f.getline(temp, 7);
	for (int i = 0; i < count; ++i)
	{
		passen passen;
		passen.load(f);
		passengers[passen.IDP] = passen;
	}

	f.close();

}


/*void savebase()
{
	ofstream f("db.txt");
	int count;
	char temp[7];
	f << count << endl;
		
	for (int i = 0; i < count; ++i)
	{
	    driver driver;
		driver.save(f);
		drivers[driver.IDD] = driver;
	}
	
	f << count << endl;
	
	for (int i = 0; i < count; ++i)
	{
		autom autom;
		autom.save(f);
		automobiles[autom.IDA] = autom;
	}


	f << count << endl;
	for (int i = 0; i < count; ++i)
	{
		passen passen;
		passen.save(f);
		passengers[passen.IDP] = passen;
	}

	f.close();


}
*/


void addDriver()
{
	driver driver;
	cin >> driver;
	drivers[driver.IDD] = driver;
}

void addAutom()
{
	autom autom;
	cin >> autom;
	automobiles[autom.IDA] = autom;
}

void addPassen()
{
	passen passen;
	cin >> passen;
	passengers[passen.IDP] = passen;
}



driver &searchDriver()
{
	int IDD;
	char temp[7];
	cout << "Input id: ";
	cin >> IDD;
	cin.getline(temp, 7);
	return drivers[IDD];
}



void ShowDriver()
{
	cout << searchDriver();
}



autom &searchAutom()
{
	int IDA;
	char temp[7];
	cout << "Input id: ";
	cin >> IDA;
	cin.getline(temp, 7);
	return automobiles[IDA];
}


void ShowAutom()
{
	cout << searchAutom();
}


passen &searchPassen()
{
	int IDP;
	char temp[7];
	cout << "Input id: ";
	cin >> IDP;
	cin.getline(temp, 7);
	return passengers[IDP];
}

void ShowPassen()
{
	cout << searchPassen();
}


int main()
{
	
	
		int choise;
		char temp[25];
		cout << LOAD << "  load file" << endl;
		cout << AD << "  add new driver" << endl;
		cout << AA << "  add new automobile" << endl;
		cout << AP << "  add new passenger" << endl;
		cout << SEARCHD << "search driver using id" << endl;
		cout << SEARCHA << "search automobile using id" << endl;
		cout << SEARCHP << "search passenger using id "  << endl;
		cout << SHOWD << " show driver " << endl;
		cout << SHOWA << " show automobile " << endl;
		cout << SHOWP << " show passenger " << endl;


		cin >> choise;
		
		switch (choise)
		{
		case LOAD:
			loadbase();
			cout << "Loaded" << endl;
			break;

		case AD:
			addDriver();
			cout << "object added" << endl;
			break;

		case AA:
			addAutom();
			cout << "object added" << endl;
			break;

		case AP:
			addPassen();
			cout << "object added" << endl;
			break;

		case SEARCHD:
			&searchDriver();
			cout << "object found" << endl;
			break;

		case SEARCHA:
			&searchAutom();
			cout << "object found" << endl;
			break;


		case SEARCHP:
			&searchPassen();
			cout << "object found" << endl;
			break;


		case SHOWA:
			ShowDriver();
			cout << "OK";
			break;
		}


}
