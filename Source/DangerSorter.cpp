#include "../Headers/DangerSorter.h"

DangerSorter::DangerSorter()
{
}
void DangerSorter::loadSampleData()
{
	alerts.push_back({"Failed Login", 5});
	alerts.push_back({"Port Scan", 3});
	alerts.push_back({"Data Breach", 10});
	alerts.push_back({"Ransomware", 9});
}
void DangerSorter::addAlert()
{
	Alert alert;

	cin.ignore(1000, '\n');

	cout << "\nEnter Alert Message: ";
	getline(cin, alert.message);

	cout << "Enter Severity: ";
	cin >> alert.severity;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "\nInvalid Severity!\n";
		return;
	}

	alerts.push_back(alert);

	cout << "Alert Added Successfully!\n";
}
void DangerSorter::displayAlerts()
{
	if (alerts.empty())
	{
		cout << "\nNo Alerts Available!\n";
		return;
	}
	cout << "\n===== Alerts =====\n";
	for (const Alert &alert : alerts)
	{
		cout << alert.message
			 << " | Severity: "
			 << alert.severity
			 << endl;
	}
}
void DangerSorter::merge(int left, int mid, int right)
{
	vector<Alert> temp;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (alerts[i].severity > alerts[j].severity)
		{
			temp.push_back(alerts[i]);
			i++;
		}
		else
		{
			temp.push_back(alerts[j]);
			j++;
		}
	}
	while (i <= mid)
	{
		temp.push_back(alerts[i]);
		i++;
	}
	while (j <= right)
	{
		temp.push_back(alerts[j]);
		j++;
	}
	for (int k = left; k <= right; k++)
	{
		alerts[k] = temp[k - left];
	}
}
void DangerSorter::mergeSort(int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
}
void DangerSorter::sortAlerts()
{
	if (alerts.empty())
	{
		cout << "\nNo Alerts To Sort!\n";
		return;
	}

	mergeSort(0, alerts.size() - 1);

	cout << "\nAlerts Sorted Successfully!\n";
}
void DangerSorter::menu()
{
	int choice;

	do
	{
		cout << "\n===== Danger Sorter =====\n";
		cout << "1. Add Alert\n";
		cout << "2. Sort Alerts\n";
		cout << "3. Display Alerts\n";
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
			addAlert();
			break;

		case 2:
			sortAlerts();
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