#include <iostream>
#include <conio.h>
#include <string>
#include "student.h"
#include "list.h"

using namespace std;


int main() {

	List p;
	Student q;
	int minaf, houraf;
	int wnumber;

	int r;
	bool fl = true;
	while (fl) {
		cout << "0 - exit" << endl;
		cout << "1 - add objects" << endl;
		cout << "2 - delete object" << endl;
		cout << "3 - show objects" << endl;
		cout << "4 - finding losers" << endl;
		cout << "5 - editing" << endl;
		cout << "6 - sort by group" << endl;
		do {
			cin >> r;
		} while (r < 0 || r > 6);

		switch (r) {
		case 0:
			fl = false;
			break;
		case 1:
			system("cls");
			cout << "Write information about the student:" << endl;
			cout << endl;
			cin >> q;

			p += q;

			p.sort();
			system("cls");
			break;
		case 2:
			system("cls");
			cout << endl;
			p.sort();
			cout << p;
			cout << endl;
			cout << "Who do you want to expel? :" << endl;
			cin >> wnumber;
			try
			{
				p -= wnumber;
			}
			catch (int e)
			{
				cout << e << " Error! Wrong number" << endl;
			}
			catch (...)
			{
				cout << "Error" << endl;
			}
			system("cls");
			break;
		case 3:
			system("cls");
			p.sort();
			cout << p;
			cout << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << endl;
			p.list_of_losers();
			cout << endl;
			system("pause");
			break;
		case 5:
			p.sort();
			system("cls");
			cout << p;
			cout << endl;
			p.red();
			cout << endl;
			break;
		case 6:
			p.sortGroup();
			system("cls");
			cout << p;
			cout << endl;
			system("pause");
			break;
		}
		system("cls");
	}

	return 0;
}