#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void maxCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // checks if the number of args is 0
    if (args.size() == 1) {
      // gets the maximum value in the table by using the getMaximumValue method
      // in class Table
      float max = currentTable.getMaxiumValue();
      // we output the value with not decimal places
      cout << fixed << setprecision(0) << "Maximum value is "
           << colorfmt(fg::cyan) << bold << max << clearfmt << endl;
    } else if (args.size() == 2) {
      // if the user has inputted a command line argument
      // we get the column header from args
      string colHeader = args[1];

      // if that column exists
      if (currentTable.columnExists(colHeader)) {
        // we get it from the current table
        Column col = currentTable.getColumnByHeader(colHeader);
        // and then check if the column is of type string
        if (col.getValueType() == ValueType::str) {
          // if it is we output a type error
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
        } else {
          // however if it isnt
          // we get the maximum value in that column
          float maximum = col.getMaximumValue();

          // we output the maximum value
          cout << fixed << setprecision(0) << "Maximum value for column "
               << showpoint << fixed << colorfmt(fg::magenta) << colHeader
               << clearfmt << " is " << colorfmt(fg::cyan) << bold << maximum
               << clearfmt << endl;
        }
      } else {
        // otherwise, if the column does not exist in the column
        // we inform the user
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }

    } else {
      // if the user inputs more than 1 arguments (column headers)
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    // if the user has not loaded a table first
    cout << "Please load a table first" << endl;
  }
};