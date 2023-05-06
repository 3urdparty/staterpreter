#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void medianCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    if (args.size() == 1) {
      // if the number of command line args inputted by the user is 0
      // we get the median for the entire table
      float median = currentTable.getMedian();
      // and output it
      cout << fixed << setprecision(2) << showpoint
           << "The Median of the table is " << colorfmt(fg::cyan) << bold
           << median << clearfmt << endl;
      // however if the user has passed a command line argument
    } else if (args.size() == 2) {
      // we get the column header from args
      string colHeader = args[1];
      // if that column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // we get that column
        Column col = currentTable.getColumnByHeader(colHeader);
        // if the column holds values of type string
        if (col.getValueType() == ValueType::str) {
          // we output a error message informing the user that the column holds
          // values of type string
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
        } else {
          // however if it holds float values
          // we get the median of the column
          float median = col.getMedian();

          // then we output it
          cout << fixed << setprecision(0) << "The Median value for column "
               << colorfmt(fg::magenta) << colHeader << clearfmt << " is "
               << colorfmt(fg::cyan) << bold << median << clearfmt << endl;
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
