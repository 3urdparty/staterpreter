#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;

string loadMan = R"(
load - used to load a file in .csv format, parse the values in it and load it into a table to be used by the program
)";

void manCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // checks if user has possed a command line argument
  if (args.size() == 2) {
    // gets the command that the user would like the manual page for
    string cmd = args[1];

    // we determine the command using a chained if else if statement
    if (cmpstr(cmd, "load")) {
      // we output the appropriate man page
      cout << loadMan;
    };
  } else {
    // if the user has not inputted a command
    cout << "Please enter a command to display the manual for" << endl;
  }
};
