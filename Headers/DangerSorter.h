#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Alert
{
    string message;
    int severity;
};

struct CompareAlert
{
    bool operator()(Alert a, Alert b)
    {
        return a.severity < b.severity;
    }
};

class DangerSorter
{
private:
    priority_queue<
        Alert,
        vector<Alert>,
        CompareAlert> alerts;

public:
    DangerSorter();

    void loadSampleData();

    void addAlert();

    void displayAlerts();

    void menu();
};