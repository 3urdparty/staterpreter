#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void meanCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the number of command line args is 0
    if (args.size() == 1) {
      // we get the mean from the entire tab;e
      float mean = currentTable.getMean();
      // setting the decimal precision to 2 we output the mean
      cout << fixed << setprecision(0) << "The Mean of the table is "
           << colorfmt(fg::cyan) << setprecision(2) << fixed << showpoint
           << bold << mean << clearfmt << endl;
    } else if (args.size() == 2) {
      // however if the user inputs a command line argument
      // we get the column header from args
      string colHeader = args[1];
      // if the column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // we get that column
        Column col = currentTable.getColumnByHeader(colHeader);
        // if the column type is of type string
        if (col.getValueType() == ValueType::str) {
          // we output an error informing user that the column is of type string
          // and we cannot calculate the mean for that column
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
        } else {
          // however we get the mean
          float mean = col.getMean();

          cout << "The Mean value for column " << colorfmt(fg::magenta)
               << colHeader << clearfmt << " is " << colorfmt(fg::cyan) << bold
               << setprecision(2) << fixed << showpoint << mean << clearfmt
               << endl;
        }
      } else {
        // however if the column does not exist we inform the user that it does
        // not exist
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }
    } else {
      // inform a user that he has to input one column at a time
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    // inform user that he needs to load a table first
    cout << "Please load a table first" << endl;
  };
}