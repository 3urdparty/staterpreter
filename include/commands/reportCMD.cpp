#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include "../table/table.hpp"


using namespace std;
void reportCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      currentTable.displayReport();
    } 
  } else {
    cout << "Please load a table first" << endl;
  }
};
