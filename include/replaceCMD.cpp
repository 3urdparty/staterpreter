#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "histogram.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"

using namespace std;
void replaceCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (tableLoaded) {
    int cols = currentTable.getNumberOfColumns();
    if (args.size() >= 2) {
      cout << "Please select a column to sort table by" << endl;
    } else if (args.size() == 2 + cols) {
      // string colHeader = args[1];

    } else {
      cout << "Please appropriate number of values for the new row" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
