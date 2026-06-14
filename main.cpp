#include "Headers/SecurityUndo.h"
#include "Headers/AlertLine.h"
#include "Headers/IPBlocker.h"
#include "Headers/ThreatDictionary.h"
#include "Headers/DangerSorter.h"
#include "Headers/WeakestLink.h"
#include "Headers/PatchPlanner.h"

using namespace std;

int main()
{
	SecurityUndo undo;
	AlertLine alerts;
	IPBlocker blocker;
	DangerSorter sorter;
	NetworkMap network;
	WeakestLink weak;
	PatchPlanner planner;
	ThreatDictionary dictionary;

	undo.loadSampleData();
	alerts.loadSampleData();
	blocker.loadSampleData();
	sorter.loadSampleData();
	network.loadSampleData();
	planner.loadSampleData();
	dictionary.loadSampleData();

	int choice;

	do
	{
		cout << "\n====================================\n";
		cout << " SHIELDNET CYBERSECURITY SYSTEM\n";
		cout << "====================================\n";

		cout << "1. Security Undo\n";
		cout << "2. Alert Line\n";
		cout << "3. IP Blocker\n";
		cout << "4. Danger Sorter\n";
		cout << "5. Network Map\n";
		cout << "6. Weakest Link\n";
		cout << "7. Patch Planner\n";
		cout << "8. Threat Dictionary\n";
		cout << "9. Exit\n";

		cout << "\nEnter Choice: ";

		cin >> choice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "\nPlease Enter A Number!\n";
			continue;
		}

		switch (choice)
		{
		case 1:
			undo.menu();
			break;

		case 2:
			alerts.menu();
			break;

		case 3:
			blocker.menu();
			break;

		case 4:
			sorter.menu();
			break;

		case 5:
			network.menu();
			break;

		case 6:
			weak.menu(network);
			break;

		case 7:
			planner.menu();
			break;

		case 8:
			dictionary.menu();
			break;

		case 9:
			cout << "\nThank You For Using ShieldNet!\n";
			break;

		default:
			cout << "\nInvalid Choice!\n";
		}

	} while (choice != 9);

	return 0;
}