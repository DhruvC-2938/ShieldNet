#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Alert
{
    string message;
    int severity;
};

class DangerSorter
{
private:
    vector<Alert> alerts;

    void merge(int left, int mid, int right);

    void mergeSort(int left, int right);

public:
    DangerSorter();

    void loadSampleData();

    void addAlert();

    void sortAlerts();

    void displayAlerts();

    void menu();
};