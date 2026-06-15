#include "../Headers/DangerSorter.h"

DangerSorter::DangerSorter()
{
}

void DangerSorter::loadSampleData()
{
alerts.push({"Failed Login", 5});
alerts.push({"Port Scan", 3});
alerts.push({"Data Breach", 10});
alerts.push({"Ransomware", 9});
}

void DangerSorter::addAlert()
{
Alert alert;


cin.ignore(1000, '\n');

cout << "\nEnter Alert Message: ";
getline(cin, alert.message);

cout << "Enter Severity: ";
cin >> alert.severity;

if(cin.fail())
{
    cin.clear();
    cin.ignore(1000, '\n');

    cout << "\nInvalid Severity!\n";
    return;
}

alerts.push(alert);

cout << "Alert Added Successfully!\n";

}

void DangerSorter::displayAlerts()
{
if(alerts.empty())
{
cout << "\nNo Alerts Available!\n";
return;
}

priority_queue<
    Alert,
    vector<Alert>,
    CompareAlert> temp = alerts;

cout << "\n===== Alerts By Priority =====\n";

while(!temp.empty())
{
    Alert current = temp.top();

    cout
        << current.message
        << " | Severity: "
        << current.severity
        << endl;

    temp.pop();
}


}

void DangerSorter::menu()
{
int choice;


do
{
    cout << "\n===== Danger Sorter =====\n";

    cout << "1. Add Alert\n";
    cout << "2. Display Alerts By Priority\n";
    cout << "3. Back\n";

    cout << "\nEnter Choice: ";

    cin >> choice;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "\nInvalid Input!\n";

        continue;
    }

    switch(choice)
    {
        case 1:
            addAlert();
            break;

        case 2:
            displayAlerts();
            break;

        case 3:
            cout << "\nReturning To Main Menu...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
    }

} while(choice != 3);

}
