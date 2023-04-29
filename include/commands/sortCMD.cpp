#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include "../histogram/histogram.hpp"

#include "../table/table.hpp"

#include "../utilities/utilities.hpp"

using namespace std;
void sortCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 2) {
      cout << "Please select a column to sort table by" << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        currentTable.sortTableByColumn(colHeader);
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
             << clearfmt << " not found" << endl;
      }

    } else {
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
