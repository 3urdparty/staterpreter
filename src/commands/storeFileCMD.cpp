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
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user has inputted no command line arguments
    if (args.size() < 2) {
      // prompt user to input a file name
      cout << "Please enter a valid file name." << endl;
      // if the user inputs the right amount of command line arguments
    } else if (args.size() == 2) {
      // we conver the current table to csv using the to_csv method
      vector<string> csv = currentTable.to_csv();
      // we then get the path to store the table data in from args
      string path = args[1];
      // we then write each line of csv to the file at path `path`
      writeLinesToFile(path, csv);
      // if the user inputs more than one filename
    } else {
      // then we output appropriate message
      cout << "Please enter one filename at a time." << endl;
    }
    // if the user does not load a table into the program
  } else {
    // we prompt user to load a table into the program
    cout << "Please load a table first" << endl;
  }
};
