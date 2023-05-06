#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;

void insertRowCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // gets the number of columns from the current table
    int cols = currentTable.getNumberOfColumns();
    // if the user inputs at least 1 command line arguments
    if (args.size() >= 2) {
      // and the first argument is row
      if (cmpstr(args[1], "row")) {
        // and the number of arguments passed to insert is equal to 1 + the
        // number of columns in the table (including row)
        if (args.size() == 2 + cols) {
          // we then slice args to get all the new values
          vector<string> newValues(args.begin() + 2, args.end());
          // if those values can be inserted to this table (in terms of type
          // compatibility)
          if (currentTable.canBeInsertedIntoTable(newValues)) {
            // those values are inserted in row at index 0
            currentTable.insertRowAtIndex(newValues, 0);
            cout << "New row inserted" << endl;

          } else {
            // if the user values in columns that ar etype incompatible
            cout << "Please enter the appropriate Value type for each row"
                 << endl;
          }
          // however if the user inputted values that are not the exact same
          // amount
        } else {
          // we get the vlaues inputted by the user
          vector<string> valuesInputted(args.begin() + 2, args.end());
          // we see how many values are left to be inputted by the user
          int valuesLeft = cols - valuesInputted.size();
          // and inform the user of the number of values to input or that the
          // values are more than expected
          if (valuesLeft > 0) {
            cout << "Please appropriate number of values for the new row "
                 << bold << colorfmt(fg::magenta) << "(" << valuesLeft
                 << " more)" << endl;
          } else {
            cout << "Too much values. Please input only " << colorfmt(fg::cyan)
                 << cols << clearfmt << " values" << endl;
          }
        }
      } else {
        cout << "Please specify that you want to add a new row using:" << endl
             << "insert row [VALUES]" << endl;
      }
    } else {
      cout << "Please specify that you want to add a new row using:" << endl
           << colorfmt(fg::cyan) << "insert row [VALUES]" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
