#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class IPBlocker
{
private:
    vector<string> blockedIPs;
    int binarySearch(string ip);
public:
    IPBlocker();
    void loadSampleData();
    void addIP();
    void checkIP();
    void displayIPs();
    void menu();
};