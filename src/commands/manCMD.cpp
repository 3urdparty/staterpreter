#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak


using namespace std;
void manCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
if (tableLoaded) {
    if (args.size() == 2) {
      string cmd = args[1];
      if (cmd == "") {
      };
    } else {
      cout << "Please enter a command to display the manual for" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
