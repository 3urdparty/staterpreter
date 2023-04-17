#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/commands.hpp"
#include "include/file_operations.hpp"
#include "include/prompt.hpp"
#include "include/table.hpp"
#include "include/textformat.hpp"
#include "include/utilities.hpp"
using namespace std;

// Struct to store a single column, its data and header

// Struct to store table
int main(int argc, char const *argv[]) {
  Table currentTable;
  bool tableLoaded = false;
  system("clear");
  outputBanner();

  while (true) {
    cout << colorfmt(32) << "sttrprter" << clearfmt << " >> " << flush;
    string command;
    getline(cin, command);
    vector<string> args =
        parseArgs(command);  // list of arguments passed to the prompt

    if (args.size() >= 1)

    {
      if (!strcmp(args[0].c_str(), "exit")) {
        cout << "Bye!" << endl;
        return 0;
      } else {
        if (cmpstr(args[0], "load")) {
          loadFileCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "store")) {
          storeFileCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "clone")) {
          cloneFileCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "html")) {
          generateHTMLCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "help")) {
          outputHelpMessage();
        } else if (cmpstr(args[0], "clear")) {
          system("clear");
        } else if (cmpstr(args[0], "min")) {
          minCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "max")) {
          maxCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "median")) {
          medianCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "show")) {
          showCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "mean")) {
          meanCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "variance")) {
          varianceCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "stdv")) {
          stdvCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "add")) {
          addCMD(args, currentTable, tableLoaded);
        } else if (cmpstr(args[0], "sub")) {
          subCMD(args, currentTable, tableLoaded);
        } 
        else {
          cout << "Command not recognized. Enter 'help' for a list of commands."
               << endl;
        };
      };
    }
  }
}
