#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void regressionCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        Column col1 = currentTable.getColumnByHeader(args[1]);

        vector<string> rawValues = col1.getAllValues();
        vector<float> values = convertStrToFloats(rawValues);

        auto [yIntercept, b] = calculateRegression(values);
        cout << "Linear regression formula for " << colorfmt(fg::blue)
             << colHeader << clearfmt << " is " << colorfmt(fg::yellow)
             << "y" << " = " << b << "x + " << yIntercept << endl;
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }
    } else {
      cout << "Please enter a column to calculate the regression for" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
