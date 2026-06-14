#include "../Headers/NetworkMap.h"

NetworkMap::NetworkMap()
{
}
void NetworkMap::loadSampleData()
{
	devices.push_back("Laptop");
	devices.push_back("Router");
	devices.push_back("Server");
	devices.push_back("Firewall");
	devices.push_back("Database");
	graph.resize(devices.size());
	graph[0].push_back({1, 4});
	graph[1].push_back({0, 4});

	graph[1].push_back({2, 2});
	graph[2].push_back({1, 2});

	graph[1].push_back({3, 5});
	graph[3].push_back({1, 5});

	graph[2].push_back({4, 1});
	graph[4].push_back({2, 1});
}
int NetworkMap::getDeviceIndex(string deviceName)
{
	for (int i = 0; i < devices.size(); i++)
	{
		if (devices[i] == deviceName)
		{
			return i;
		}
	}

	return -1;
}
void NetworkMap::addDevice()
{
	string device;

	cin.ignore(1000, '\n');

	cout << "\nEnter Device Name: ";
	getline(cin, device);

	devices.push_back(device);

	graph.push_back(vector<pair<int, int>>());

	cout << "Device Added Successfully!\n";
}
void NetworkMap::addConnection()
{
	string source;
	string destination;

	int cost;

	cin.ignore(1000, '\n');

	cout << "\nEnter Source Device: ";
	getline(cin, source);

	cout << "Enter Destination Device: ";
	getline(cin, destination);

	cout << "Enter Cost: ";
	cin >> cost;

	int srcIndex = getDeviceIndex(source);
	int destIndex = getDeviceIndex(destination);

	if (srcIndex == -1 || destIndex == -1)
	{
		cout << "\nDevice Not Found!\n";
		return;
	}

	graph[srcIndex].push_back({destIndex, cost});
	graph[destIndex].push_back({srcIndex, cost});

	cout << "Connection Added Successfully!\n";
}
void NetworkMap::displayNetwork()
{
	cout << "\n===== Network Map =====\n";

	for (int i = 0; i < devices.size(); i++)
	{
		cout << devices[i] << " -> ";

		for (auto connection : graph[i])
		{
			cout << devices[connection.first]
				 << "("
				 << connection.second
				 << ") ";
		}

		cout << endl;
	}
}
vector<string> NetworkMap::getDevices()
{
	return devices;
}
vector<vector<pair<int, int>>> NetworkMap::getGraph()
{
	return graph;
}
void NetworkMap::menu()
{
	int choice;

	do
	{
		cout << "\n===== Network Map =====\n";
		cout << "1. Add Device\n";
		cout << "2. Add Connection\n";
		cout << "3. Display Network\n";
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
			addDevice();
			break;

		case 2:
			addConnection();
			break;

		case 3:
			displayNetwork();
			break;

		case 4:
			cout << "\nReturning To Main Menu...\n";
			break;

		default:
			cout << "\nInvalid Choice!\n";
		}

	} while (choice != 4);
}