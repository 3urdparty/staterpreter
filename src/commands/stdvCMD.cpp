#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <table/table.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>  // library of statistical functions to be used in program written by Mubarak
using namespace std;
void stdvCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      float stdv = currentTable.getStdDeviation();
      cout << fixed << setprecision(2) << showpoint
           << "The Standard deviation of the table is " << colorfmt(fg::cyan)
           << bold << stdv << clearfmt << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        if (currentTable.columnExists(colHeader)) {
          Column col = currentTable.getColumnByHeader(colHeader);
          if (col.getValueType() == ValueType::str) {
            cout << colorfmt(fg::red) << "Error: " << clearfmt
                 << "The column you have selected contains values of type "
                 << colorfmt(fg::white) << "string" << clearfmt << endl
                 << "Please select another column." << endl;
          } else {
            float stdv = col.getStdDeviation();
            string columnHeader = col.getHeader();

            cout << fixed << setprecision(3) << showpoint
                 << "The Standard deviation for column "
                 << colorfmt(fg::magenta) << colHeader << clearfmt << " is "
                 << colorfmt(fg::cyan) << bold << stdv << clearfmt << endl;
          }
        } else {
          cout << "Sorry, column " << colorfmt(fg::magenta) << args[1]
               << clearfmt << " not found" << endl;
        }

      } else {
        cout << "Please enter one column at a time" << endl;
      };
    } else {
      cout << "Please load a table first" << endl;
    }
  };
};