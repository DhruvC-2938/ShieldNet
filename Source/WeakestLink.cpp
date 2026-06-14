#include "../Headers/WeakestLink.h"

string toLower(string text)
{
	for(int i = 0; i < text.length(); i++)
	{
		text[i] = tolower(text[i]);
	}

	return text;
}

WeakestLink::WeakestLink()
{
}

void WeakestLink::findShortestPath(NetworkMap &network)
{
	vector<string> devices = network.getDevices();

	vector<vector<pair<int, int>>> graph =
		network.getGraph();

	string sourceDevice;
	string destinationDevice;

	cin.ignore(1000, '\n');

	cout << "\nAvailable Devices:\n";

	for(string device : devices)
	{
		cout << "- " << device << endl;
	}

	cout << "\nEnter Source Device: ";
	getline(cin, sourceDevice);

	cout << "Enter Destination Device: ";
	getline(cin, destinationDevice);

	int source = -1;
	int destination = -1;

	for(int i = 0; i < devices.size(); i++)
	{
		if(toLower(devices[i]) == toLower(sourceDevice))
		{
			source = i;
		}

		if(toLower(devices[i]) == toLower(destinationDevice))
		{
			destination = i;
		}
	}

	if(source == -1 || destination == -1)
	{
		cout << "\nDevice Not Found!\n";
		return;
	}

	vector<int> distance(devices.size(), 1000000);

	vector<int> parent(devices.size(), -1);

	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
	> pq;

	distance[source] = 0;

	pq.push({0, source});

	while(!pq.empty())
	{
		int currentNode = pq.top().second;

		pq.pop();

		for(auto edge : graph[currentNode])
		{
			int nextNode = edge.first;

			int cost = edge.second;

			if(distance[currentNode] + cost
			   < distance[nextNode])
			{
				distance[nextNode]
					= distance[currentNode] + cost;

				parent[nextNode]
					= currentNode;

				pq.push(
				{
					distance[nextNode],
					nextNode
				});
			}
		}
	}

	if(distance[destination] == 1000000)
	{
		cout << "\nNo Path Found!\n";
		return;
	}

	vector<int> path;

	int current = destination;

	while(current != -1)
	{
		path.push_back(current);

		current = parent[current];
	}

	cout << "\n===== Weakest Link Analysis =====\n";

	cout << "\nShortest Attack Path:\n";

	for(int i = path.size() - 1; i >= 0; i--)
	{
		cout << devices[path[i]];

		if(i != 0)
		{
			cout << " -> ";
		}
	}

	cout << "\n\nTotal Cost = "
		 << distance[destination]
		 << endl;
}

void WeakestLink::menu(NetworkMap &network)
{
	int choice;

	do
	{
		cout << "\n===== Weakest Link Analysis =====\n";

		cout << "1. Find Shortest Path\n";
		cout << "2. Back\n";

		cout << "\nEnter Choice: ";

		cin >> choice;

		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');

			cout << "\nPlease Enter A Number!\n";

			continue;
		}

		switch(choice)
		{
			case 1:
				findShortestPath(network);
				break;

			case 2:
				cout << "\nReturning To Main Menu...\n";
				return;

			default:
				cout << "\nInvalid Choice!\n";
		}

	} while(true);
}