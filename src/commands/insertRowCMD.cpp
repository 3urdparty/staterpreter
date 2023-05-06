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
    int cols = currentTable.getNumberOfColumns();
    if (args.size() >= 2) {
      if (cmpstr(args[1], "row")) {
        if (args.size() == 2 + cols) {
          vector<string> newValues(args.begin() + 2, args.end());
          if (currentTable.canBeInsertedIntoTable(newValues)) {
            currentTable.insertRowAtIndex(newValues, 0);
            cout << "New row inserted" << endl;

          } else {
            cout << "Please enter the appropriate Value type for each row"
                 << endl;
          }
        } else {
          vector<string> valuesInputted(args.begin() + 2, args.end());
          int valuesLeft = cols - valuesInputted.size();
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
