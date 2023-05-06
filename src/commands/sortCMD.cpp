#include <iomanip>
#include <iostream>
#include <vector>

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void sortCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
if (tableLoaded) {
    if (args.size() < 2) {
      cout << "Please select a column to sort table by" << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        currentTable.sortTableByColumn(colHeader);
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
             << clearfmt << " not found" << endl;
      }

    } else {
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
