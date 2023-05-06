#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void rowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the number of arguments is 0
    if (args.size() == 1) {
      // we
      cout << "The number of rows for this table is " << bold
           << colorfmt(fg::magenta) << currentTable.getNumberOfRows() << endl;
    } else {
      // we inform him that report does not take any command line argumnets
      cout << "Command `report` does not take any command line arguments"
           << endl;
    }
    // if the user has not loaded a table into memeory first
  } else {
    // we prompt the user to load a table first
    cout << "Please load a table first" << endl;
  }
};
