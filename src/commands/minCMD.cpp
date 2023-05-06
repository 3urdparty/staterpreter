#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void minCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user has not inputted a command line argument
    if (args.size() == 1) {
      // we get the minimum of the entire table
      float min = currentTable.getMinimumValue();
      // we output the minimum value
      cout << fixed << setprecision(0) << "Minumum value is "
           << colorfmt(fg::cyan) << bold << min << clearfmt << endl;
      // however if the user has passed a command line argumnet
    } else if (args.size() == 2) {
      // we get the column header from args
      string colHeader = args[1];
      // if the column does not exist in the current table
      if (currentTable.columnExists(colHeader)) {
        // we then get that column
        Column col = currentTable.getColumnByHeader(colHeader);
        // if the type of column is string
        if (col.getValueType() == ValueType::str) {
          // we output an error message informing him that the column is of type
          // string and cannot perform mathematical functions on it
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
          // if not then...
        } else {
          // we get minimum of that column
          float minimum = col.getMinimumValue();

          // and output it
          cout << fixed << setprecision(0) << "Minumum value for column "
               << colorfmt(fg::magenta) << colHeader << clearfmt << " is "
               << colorfmt(fg::cyan) << bold << minimum << clearfmt << endl;
        }
        // if the user does not exist
      } else {
        // we output an appropriate message informing user
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }
      // if the user inputs more than one command line argument
    } else {
      // we inform user that he needs to enter one column header at atime
      cout << "Please enter one column at a time" << endl;
    };
    // if the user has not loaded a table first
  } else {
    // we prompt user to laod a table first
    cout << "Please load a table first" << endl;
  }
};
