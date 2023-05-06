#include <filuzzy/filuzzy.hpp>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void storeFileCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 2) {
      cout << "Please enter a valid file name." << endl;
    } else if (args.size() == 2) {
      vector<string> csv = currentTable.to_csv();
      writeLinesToFile(args[1], csv);
    } else {
      cout << "Please enter one filename at a time." << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
