#include <iostream>
#include <queue>
#include <string>

using namespace std;

class AlertLine
{
private:
    queue<string> alerts;

public:
    AlertLine();
    void loadSampleData();
    void addAlert();
    void processAlert();
    void displayAlerts();
    void menu();
};