#include <iostream>
#include <stack>
#include <string>

using namespace std;

class SecurityUndo {
private:
  stack<string> actions;

public:
  SecurityUndo();
  void addAction();
  void undoAction();
  void displayHistory();
  void loadSampleData();
  void menu();
};