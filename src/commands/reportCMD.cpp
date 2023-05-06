#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void reportCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
      //if the  user has not inputted any unexpected command line arguments
    if (args.size() == 1) {
// we display the report for each column in the current table
      currentTable.displayReport();
      // if the user has inputted extra command line arguments
    } else {
      // we inform him that report does not take any command line argumnets
      cout << "Command `report` does not take any command line arguments"
           << endl;
    }
    // if the user has not loaded a table into memeory first
  } else {
    // we prompt the user to load a table firstƒ
    cout << "Please load a table first" << endl;
  }
};
