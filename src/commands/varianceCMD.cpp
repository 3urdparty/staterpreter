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
    // if the user does not pass any command line arguments
    if (args.size() == 1) {
      // we get the variance of the entire table
      float variance = currentTable.getVariance();
      // and output it
      cout << fixed << setprecision(0) << "The Variance of the table is "
           << colorfmt(fg::cyan) << bold << variance << clearfmt << endl;

      // however if the user inputs a command line arguments
    } else if (args.size() == 2) {
      // we get the column header from args
      string colHeader = args[1];

      // if the column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // we get the column
        Column col = currentTable.getColumnByHeader(colHeader);

        // if the column is of type string
        if (col.getValueType() == ValueType::str) {
          // we output an appropraite error message
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
          // else if the column contains numerical values
        } else {
          // we get the variance of the column
          float variance = col.getVariance();

          // and output it
          cout << fixed << setprecision(3) << showpoint
               << "The Variance for column " << colorfmt(fg::magenta)
               << colHeader << clearfmt << " is " << colorfmt(fg::cyan) << bold
               << variance << clearfmt << endl;
        }
        // if the column does not exist in the current table
      } else {
        // output an error message
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      };
      //  if the user inputs more than one column
    } else {
      cout << "Please enter one column at a time" << endl;
    }
    // if the user did not load a table
  } else {
    cout << "Please load a table first" << endl;
  };
};