#include "../Headers/AlertLine.h"

AlertLine::AlertLine()
{
}

void AlertLine::loadSampleData()
{
	alerts.push("Failed Login Attempt");
	alerts.push("Port Scan Detected");
	alerts.push("Suspicious Download");
}

void AlertLine::addAlert()
{
	string alert;
	cin.ignore(1000, '\n');
	cout << "\nEnter Alert: ";
	getline(cin, alert);
	alerts.push(alert);
	cout << "Alert Added Successfully!\n";
}
void AlertLine::processAlert()
{
	if (alerts.empty())
	{
		cout << "\nNo Alerts To Process!\n";
		return;
	}
	cout << "\nProcessing Alert: "
		 << alerts.front() << endl;

	alerts.pop();
}
void AlertLine::displayAlerts()
{
	if (alerts.empty())
	{
		cout << "\nNo Alerts Available!\n";
		return;
	}
	queue<string> temp = alerts;
	cout << "\n===== Alert Queue =====\n";
	while (!temp.empty())
	{
		cout << temp.front() << endl;
		temp.pop();
	}
}
void AlertLine::menu()
{
	int choice;
	do
	{
		cout << "\n===== Alert Line =====\n";
		cout << "1. Add Alert\n";
		cout << "2. Process Alert\n";
		cout << "3. Display Alerts\n";
		cout << "4. Back\n";

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
			addAlert();
			break;
		case 2:
			processAlert();
			break;
		case 3:
			displayAlerts();
			break;
		case 4:
			cout << "\nReturning To Main Menu...\n";
			break;
		default:
			cout << "\nInvalid Choice!\n";
		}

	} while (choice != 4);
}