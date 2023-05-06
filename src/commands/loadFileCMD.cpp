#include <filuzzy/filuzzy.hpp>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void loadFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (args.size() == 2) {
    string path = args[1];
    if (fileExists(path)) {
      if (splitString(path, '.').size() == 2) {
        if (cmpstr(splitString(path, '.')[1], "csv")) {
          vector<string> lines;
          vector<vector<string>> csv;

          readLines(path, lines);
          parseCSV(lines, csv);
          currentTable.flushTable();
          currentTable.from_csv(csv);
          tableLoaded = true;
          cout << "Loaded " << colorfmt(fg::magenta) << path << clearfmt
               << endl;
        } else {
          cout << "Please input a file of type .csv" << endl;
        }

      } else {
        cout << "Please enter a file with a .csv file extension" << endl;
      }
    } else {
      cout << "File " << colorfmt(fg::yellow) << path << clearfmt
           << " not found" << endl;
    }
  } else if (args.size() >= 2) {
    cout << "Please provide only one input file" << endl;
  } else {
    cout << "Please provide only one input file" << endl;
  }
};