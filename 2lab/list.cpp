#include <string>
#include <iostream>
#include "list.h"
using namespace std;

List::List()
{
	n = 8;
	tsize = 0;
	mas = new Student[n];
}

List::~List() {
	delete[]mas;
}

List::List(const List& obj)
{
	mas = new Student[obj.tsize];
	for (int i = 0; i < tsize; i++)
		mas[i] = obj.mas[i];

	tsize = obj.tsize;

}

List& List::operator -=(int wnumber)
{
	int k = 0;

	if ((wnumber <= 0) || (wnumber > tsize)) {
		throw 123;
	}


	Student* tmp = new Student[tsize - 1];
	for (int i = 0; i < tsize; i++) {
		if (wnumber != mas[i].getNumber()) {
			tmp[k] = mas[i];
			k++;
		}
	}
	delete[] mas;
	mas = tmp;
	tsize--;

}

ostream& operator << (ostream& os, const List& com)
{
	if (com.tsize == 0) {
		cout << "List is empty" << endl;
	}
	else {
		cout << endl << "Number\t\t\tName\t\t\tSubject\t\t\tGroup\t\t\tEstimation" << endl;
		for (int i = 0; i < com.tsize; i++)
			cout << com.mas[i].getNumber() << "\t\t\t" << com.mas[i].getName() << "\t\t\t" << com.mas[i].getSubject() << "\t\t\t" << com.mas[i].getGroup() << "\t\t\t" << com.mas[i].getEstimation() << endl;
	}
	return os;
}


void List::sort() {
	int counter = 1;
	for (int i = 0; i < tsize; i++)
		for (int j = tsize - 1; j > i; j--) {
			if (mas[j - 1].getEstimation() > mas[j].getEstimation()) {
				Student tmp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = tmp;
			}
		}
	for (int i = 0; i < tsize; i++)
	{
		mas[i].setNumber(counter);
		counter++;
	}
}

void List::list_of_losers() {
	bool exists = false;
	for (int i = 0; i < tsize; i++) {
		if (mas[i].getEstimation() == 2) {
			cout << "Name: " << mas[i].getName() << "\t\t\tGroup: " << mas[i].getGroup() << endl;
			exists = true;
		}
	}

	if (exists == false) cout << "Losers are not detected" << endl;
}

void List::red()
{
	try
	{
		string sTmp;
		int iTmp;
		cout << endl;
		int choise1;
		cout << "Enter which student you want to change" << endl;
		cin >> choise1;
		if (choise1 < 0 || choise1 >tsize + 1)
		{
			throw (string)"Those student doesn't exist";
		}
		choise1--;
		int choise2;
		cout << "Enter what parametr do you want to redact" << endl
			<< "1. Name" << endl
			<< "2. Subject" << endl
			<< "3. Group" << endl
			<< "4. Estimation" << endl;
		cin >> choise2;
		if (choise2 < 1 || choise2 >4)
		{
			throw (string)"Those parametr doesn't exist";
		}
		if (choise2 == 1) {
			cout << "Enter new Name: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"student name cannot be empty";
			mas[choise1].setName(sTmp);
		}
		if (choise2 == 2) {
			cout << "Enter new Subject: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"student subject cannot be empty";
			mas[choise1].setSubject(sTmp);
		}
		if (choise2 == 3) {
			cout << "Enter new Group: ";
			cin.ignore(INT_MAX, '\n');
			cin >> iTmp;
			mas[choise1].setGroup(iTmp);
		}
		if (choise2 == 4) {
			cout << "Enter new Estimation: ";
			cin.ignore(INT_MAX, '\n');
			do{
			cin >> iTmp;
			} while (iTmp < 2 || iTmp > 5);
			mas[choise1].setEstimation(iTmp);
		}
		cout << "The element is successfully redact" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[ERROR] " + err << endl;
		system("pause");
	}
}

void List::sortGroup() {
	int counter = 1;
	for (int i = 0; i < tsize; i++)
		for (int j = tsize - 1; j > i; j--) {
			if (mas[j - 1].getGroup() > mas[j].getGroup()) {
				Student tmp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = tmp;
			}
		}
	for (int i = 0; i < tsize; i++)
	{
		mas[i].setNumber(counter);
		counter++;
	}
}