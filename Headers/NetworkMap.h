#include <iostream>
#include <vector>
#include <string>
using namespace std;
class NetworkMap
{
private:
    vector<string> devices;
    vector<vector<pair<int, int>>> graph;

public:
    NetworkMap();
    void loadSampleData();
    void addDevice();
    void addConnection();
    void displayNetwork();
    int getDeviceIndex(string deviceName);
    vector<string> getDevices();
    vector<vector<pair<int, int>>> getGraph();
    void menu();
};