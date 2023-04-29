#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include "../table/table.hpp"
#include "../utilities/utilities.hpp"

using namespace std;
void columnsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      cout << "The number of columns for this table is " << bold
           << colorfmt(fg::magenta) << currentTable.getNumberOfColumns() << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
