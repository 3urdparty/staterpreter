#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter



#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
using namespace std;
void regressionCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        Column col1 = currentTable.getColumnByHeader(args[1]);

        vector<string> rawValues = col1.getAllValues();
        vector<float> values = convertToFloats(rawValues);

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
