#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
using namespace std;
void showCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user has inputted more than one command line argument
    if (args.size() == 2) {
      // we get the column header from args
      string colHeader = args[1];
      // if the column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // we get the column from the table and call a method displayColumn in
        // class Column to display the values for that column
        currentTable.getColumnByHeader(colHeader).displayColumn();
        // if it does not exist
      } else {
        // we inform the user
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }
      // if the number of command line arguments is bigger than 1
    } else if (args.size() > 2) {
      // inform the user to input only one column header
      cout << "Please input one column at a time" << endl;
    } else {
      // otherwise display the table
      currentTable.displayTable();
    }
    // if the table has not been loaded into the program
  } else {
    // please input that
    cout << "Please load a table first" << endl;
  }
};
