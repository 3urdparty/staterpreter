#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
using namespace std;
void stdvCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // check if the user has inputted a command line argumnet
    if (args.size() == 1) {
      // get the standard deviation of the table
      float stdv = currentTable.getStdDeviation();

      // output the standard deviation
      cout << fixed << setprecision(2) << showpoint
           << "The Standard deviation of the table is " << colorfmt(fg::cyan)
           << bold << stdv << clearfmt << endl;

      // if the user has inputted a command line argument
    } else if (args.size() == 2) {
      // get the column header from args
      string colHeader = args[1];

      // if the column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // get the column from the current table
        Column col = currentTable.getColumnByHeader(colHeader);

        // if the column has datatype string
        if (col.getValueType() == ValueType::str) {
          // output an error informing user that the column has type string
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;

          // if it has a numerical type
        } else {
          // then we can get the standard deviation of that column
          float stdv = col.getStdDeviation();
          // and output it
          cout << fixed << setprecision(4) << showpoint
               << "The Standard deviation for column " << colorfmt(fg::magenta)
               << colHeader << clearfmt << " is " << colorfmt(fg::cyan) << bold
               << stdv << clearfmt << endl;
        }

        // if the column does not exist
      } else {
        // the inform the user that the column does not exist
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      };
      // if the user inputs more than one command line argument
    } else {
      // output appropriate message
      cout << "Please enter one column at a time" << endl;
    }
    // if the user has not loadede a table into the program
  } else {
    // prompt user to do so
    cout << "Please load a table first" << endl;
  };
};