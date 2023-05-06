#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
using namespace std;
void regressionCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user has inputted exactly one command line argument
    if (args.size() == 2) {
      // we get the column header from args
      string colHeader = args[1];
      // if the column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // we get that column
        Column col1 = currentTable.getColumnByHeader(args[1]);
        // we get all the values in that column
        vector<string> rawValues = col1.getAllValues();
        // and we convert each value from string to floats
        vector<float> values = convertToFloats(rawValues);

        // we then calculate the regression coefficient and y intercept for
        // those values destructure them from the tuple returned by function
        // calculateRegression
        auto [yIntercept, b] = calculateRegression(values);

        // then we output the formula for the line of regression
        cout << "Linear regression formula for " << setprecision(2) << showpoint
             << colorfmt(fg::blue) << colHeader << clearfmt << " is "
             << colorfmt(fg::yellow) << "y"
             << " = " << b << "x + " << setprecision(2) << showpoint
             << yIntercept << endl;

        // if the column was not found
      } else {
        // we output a message informing user it does not exist
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }
      // however if the number of command line arguments was more than 1
    } else if (args.size() > 2) {
      // we tell the suer to input only one column at a time
      cout << "Please only enter one column at a time" << endl;
    // if the user does not input a column
    } else {
      // we prompt him to do so
      cout << "Please enter a column to calculate the regression for" << endl;
    }
    // if the user has not loaded a table into memory
  } else {
    // we prompt him to do so
    cout << "Please load a table first" << endl;
  }
};
