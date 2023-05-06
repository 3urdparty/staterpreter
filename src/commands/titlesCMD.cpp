#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void titlesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user has inputted no command line arguments
    if (args.size() == 1) {
      // we get all the column headers in the table
      vector<string> headers = currentTable.getAllColumnHeaders();
      // and output them
      cout << "Titles: " << bold << join(headers, ", ") << endl;
      // if the user passes extra command line arguments
    } else {
      // we output an appropriate message

      cout << "Command `titles` does not expect any command line arguments"
           << endl;
    };
    // if the user did not load a table
  } else {
    // we output an appropriate message
    cout << "Please load a table first" << endl;
  }
};
