#include "../Headers/SecurityUndo.h"

SecurityUndo::SecurityUndo() {}

void SecurityUndo::loadSampleData()
{
	actions.push("Grant Admin Access");
	actions.push("Grant Database Access");
	actions.push("Update Firewall Rule");
}

void SecurityUndo::addAction()
{
	string action;
	cin.ignore(1000, '\n');
	cout << "\nEnter Action: ";
	getline(cin, action);
	actions.push(action);
	cout << "Action Added Successfully!\n";
}

void SecurityUndo::undoAction()
{
	if (actions.empty())
	{
		cout << "\nNo Actions Available To Undo!\n";
		return;
	}
	cout << "\nLast Action Undone: " << actions.top() << endl;
	actions.pop();
}

void SecurityUndo::displayHistory()
{
	if (actions.empty())
	{
		cout << "\nNo Action History Available!\n";
		return;
	}
	stack<string> temp = actions;
	cout << "\n===== Action History =====\n";
	while (!temp.empty())
	{
		cout << temp.top() << endl;
		temp.pop();
	}
}

void SecurityUndo::menu()
{
	int choice;
	do
	{
		cout << "\n===== Security Undo =====\n";
		cout << "1. Add Action\n";
		cout << "2. Undo Action\n";
		cout << "3. Display History\n";
		cout << "4. Back\n";
		cout << "\nEnter Choice: ";
		cin >> choice;
		if(cin.fail())
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "\nPlease Enter A Number!\n";
    continue;
}
		switch (choice)
		{
		case 1:
			addAction();
			break;

		case 2:
			undoAction();
			break;

		case 3:
			displayHistory();
			break;

		case 4:
			cout << "\nReturning To Main Menu...\n";
			break;

		default:
			cout << "\nInvalid Choice!\n";
		}

	} while (choice != 4);
}