#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct DeviceRisk
{
    string deviceName;
    int risk;
};
class PatchPlanner
{
private:
    vector<DeviceRisk> devices;
public:
    PatchPlanner();
    void loadSampleData();
    void addDevice();
    void generatePatchPlan();
    void displayDevices();
    void menu();
};