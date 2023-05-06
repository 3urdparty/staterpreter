#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <iostream>
#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

void helpCMD() {
  // Outputs each line in the help.txt file
  vector<string> lines;
  for (string line : lines) {
    cout << line << endl;
  }
};
