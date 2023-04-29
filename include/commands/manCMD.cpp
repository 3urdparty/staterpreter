#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include "../table/table.hpp"


using namespace std;
void manCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 2) {
      string cmd = args[1];
      if (cmd == "") {
      };
    } else {
      cout << "Please enter a command to display the manual for" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
