#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
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
