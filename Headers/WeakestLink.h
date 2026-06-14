#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "NetworkMap.h"

using namespace std;
class WeakestLink
{
public:
	WeakestLink();

	void findShortestPath(NetworkMap& network);

	void menu(NetworkMap& network);
};