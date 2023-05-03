#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak

using namespace std;
void storeFileCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() >= 2) {
      vector<string> csv = currentTable.to_csv();
      writeLinesToFile(args[1], csv);
    } else {
      cout << "Please enter a valid file name." << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
