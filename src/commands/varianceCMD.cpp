#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void varianceCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
if (tableLoaded) {
    if (args.size() == 1) {
      float variance = currentTable.getVariance();
      cout << fixed << setprecision(0) << "The Variance of the table is "
           << colorfmt(fg::cyan) << bold << variance << clearfmt << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        Column col = currentTable.getColumnByHeader(colHeader);
        if (col.getValueType() == ValueType::str) {
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
        } else {
          float variance = col.getVariance();
          string columnHeader = col.getHeader();

          cout << fixed << setprecision(3) << showpoint
               << "The Variance for column " << colorfmt(fg::magenta)
               << colHeader << clearfmt << " is " << colorfmt(fg::cyan) << bold
               << variance << clearfmt << endl;
        }

      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      };
    } else {
      cout << "Please enter one column at a time" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  };
};