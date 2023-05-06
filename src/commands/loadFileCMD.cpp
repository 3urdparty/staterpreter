#include <filuzzy/filuzzy.hpp>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;

void loadFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // checks if a command line argument has been passed to load
  if (args.size() == 2) {
    // gets the path to read from from args
    string path = args[1];

    // checks if file exists
    if (fileExists(path)) {
      // checks if file has an extension
      if (splitString(path, '.').size() == 2) {
        // checks if file is of type csv
        if (cmpstr(splitString(path, '.')[1], "csv")) {
          // declares vector of strings to store lines
          vector<string> lines;

          // declares 2D vector of strings to store csv values
          vector<vector<string>> csv;

          // using readLines we read each line in the file at path and append it
          // to liens
          readLines(path, lines);

          // parse every line ine lines and add it to csv
          parseCSV(lines, csv);

          // before populating table with the new values we clear the values
          // from the last table (if any)
          currentTable.flushTable();

          // we then populate the now empty table with the new csv values
          currentTable.from_csv(csv);

          // change table loaded to true to tell other parts of the program that
          // a table has now been loaded
          tableLoaded = true;

          // output an appropriate message informing user that operation was
          // successfull
          cout << "Loaded " << colorfmt(fg::magenta) << path << clearfmt
               << endl;
        } else {
          // output the file
          cout << "Please input a file of type .csv" << endl;
        }

      } else {
        // prompt user to input a file with .csv file extension
        cout << "Please enter a file with a .csv file extension" << endl;
      }

      // inform user file at given path does not exist
    } else {
      cout << "File " << colorfmt(fg::yellow) << path << clearfmt
           << " not found" << endl;
    }
    // if the user provides more than one file path
  } else if (args.size() >= 2) {
    cout << "Please provide only one input file" << endl;
    // if the user does not provide an input file
  } else {
    cout << "Please provide a input file" << endl;
  }
};