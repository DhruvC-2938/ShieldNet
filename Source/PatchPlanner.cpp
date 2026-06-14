#include "../Headers/PatchPlanner.h"

PatchPlanner::PatchPlanner()
{
}
void PatchPlanner::loadSampleData()
{
	devices.push_back({"Database Server", 10});
	devices.push_back({"Firewall", 8});
	devices.push_back({"Router", 6});
	devices.push_back({"Employee Laptop", 3});
	devices.push_back({"Printer", 1});
}
void PatchPlanner::addDevice()
{
	DeviceRisk device;

	cin.ignore(1000, '\n');

	cout << "\nEnter Device Name: ";
	getline(cin, device.deviceName);

	cout << "Enter Risk Level: ";
	cin >> device.risk;

	if(cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "\nInvalid Risk Value!\n";
		return;
	}

	devices.push_back(device);

	cout << "Device Added Successfully!\n";
}
void PatchPlanner::displayDevices()
{
	if(devices.empty())
	{
		cout << "\nNo Devices Available!\n";
		return;
	}

	cout << "\n===== Devices =====\n";

	for(const DeviceRisk& device : devices)
	{
		cout << device.deviceName
			 << " | Risk: "
			 << device.risk
			 << endl;
	}
}
void PatchPlanner::generatePatchPlan()
{
    if(devices.empty())
    {
        cout << "\nNo Devices Available!\n";
        return;
    }

    vector<DeviceRisk> remaining = devices;

    cout << "\n===== Patch Priority =====\n";

    int priority = 1;

    while(!remaining.empty())
    {
        int maxIndex = 0;

        for(int i = 1; i < remaining.size(); i++)
        {
            if(remaining[i].risk > remaining[maxIndex].risk)
            {
                maxIndex = i;
            }
        }

        cout << priority
             << ". "
             << remaining[maxIndex].deviceName
             << " (Risk "
             << remaining[maxIndex].risk
             << ")"
             << endl;

        remaining.erase(remaining.begin() + maxIndex);

        priority++;
    }
}
void PatchPlanner::menu()
{
    int choice;

    do
    {
        cout << "\n===== Patch Planner =====\n";

        cout << "1. Add Device\n";
        cout << "2. Generate Patch Plan\n";
        cout << "3. Display Devices\n";
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

        switch(choice)
        {
            case 1:
                addDevice();
                break;

            case 2:
                generatePatchPlan();
                break;

            case 3:
                displayDevices();
                break;

            case 4:
                cout << "\nReturning To Main Menu...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);
}