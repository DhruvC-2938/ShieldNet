#include "../Headers/IPBlocker.h"

IPBlocker::IPBlocker()
{
}

void IPBlocker::loadSampleData()
{
	blockedIPs.push_back("192.168.1.10");
	blockedIPs.push_back("192.168.1.25");
	blockedIPs.push_back("192.168.1.50");
	blockedIPs.push_back("192.168.1.100");

	sort(blockedIPs.begin(), blockedIPs.end());
}
void IPBlocker::addIP()
{
	string ip;
	cin.ignore(1000, '\n');
	cout << "\nEnter IP Address: ";
	getline(cin, ip);
	blockedIPs.push_back(ip);
	sort(blockedIPs.begin(), blockedIPs.end());
	cout << "IP Added Successfully!\n";
}
void IPBlocker::checkIP()
{
	string ip;
	cin.ignore(1000, '\n');
	cout << "\nEnter IP Address To Check: ";
	getline(cin, ip);
	int result = binarySearch(ip);
	if (result != -1)
	{
		cout << "\nIP BLOCKED\n";
	}
	else
	{
		cout << "\nIP NOT BLOCKED\n";
	}
}
void IPBlocker::displayIPs()
{
	if (blockedIPs.empty())
	{
		cout << "\nNo Blocked IPs Available!\n";
		return;
	}
	cout << "\n===== Blocked IPs =====\n";
	for (const string &ip : blockedIPs)
	{
		cout << ip << endl;
	}
}
int IPBlocker::binarySearch(string ip)
{
	int left = 0;
	int right = blockedIPs.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (blockedIPs[mid] == ip)
		{
			return mid;
		}
		if (blockedIPs[mid] < ip)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
void IPBlocker::menu()
{
	int choice;

	do
	{
		cout << "\n===== IP Blocker =====\n";
		cout << "1. Add Blocked IP\n";
		cout << "2. Check IP\n";
		cout << "3. Display Blocked IPs\n";
		cout << "4. Back\n";

		cout << "\nEnter Choice: ";
		cin >> choice;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "\nInvalid Input!\n";

			continue;
		}

		switch (choice)
		{
		case 1:
			addIP();
			break;

		case 2:
			checkIP();
			break;

		case 3:
			displayIPs();
			break;

		case 4:
			cout << "\nReturning To Main Menu...\n";
			break;

		default:
			cout << "\nInvalid Choice!\n";
		}

	} while (choice != 4);
}