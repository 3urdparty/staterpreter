// Azi
#include <filuzzy/filuzzy.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter  // Header file for all the interpreter commands for staterpreter

// Function for the `columns` Command that outputs the number of columns in
// table More info found in the `commands.hpp` header file
using namespace std;
void columnsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if a table is loaded in memory
  // Checks if the table has been loaded into the program
if (tableLoaded) {
    // if the right number of command line args passed (1)
    if (args.size() == 1) {
      // Output the number of columns in table
      cout << "The number of columns for this table is "
           << bold

           // By calling the getNumberOfColumns() method of the Table class
           << colorfmt(fg::magenta) << currentTable.getNumberOfColumns()
           << endl;
    } else {
      cout << "Command `column` does not need any command line arguments. "
              "Please retry again."
           << endl;
    }
  } else {
    // Otherwise request user to load a table into the program first
    cout << "Please load a table first" << endl;
  }
};
