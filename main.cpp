#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/commands/commands.hpp"
#include "include/prompt/prompt.hpp"
#include "include/table/table.hpp"
#include "include/utilities/utilities.hpp"

using namespace std;

// Struct to store table
int main(int argc, char const *argv[]) {
  // cout << stringIsFloat("   10   ");
  // return 0;
  // Table currentTable;
  bool tableLoaded = false;

  system("clear");
  outputBanner();

  while (true) {
    vector<string> args;
    // test

    // helpCMD();
    // return 0;
    // test

    cout << colorfmt(32) << "sttrprter" << clearfmt << " >> " << flush;
    string command;
    getline(cin, command);
    args = parseArgs(command);  // list of arguments passed to the prompt

    if (args.size() >= 1)

    {
      if (!strcmp(args[0].c_str(), "exit")) {
        cout << "Bye!" << endl;
        return 0;
      // } else {
        // if (cmpstr(args[0], "load")) {
        //   loadFileCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "store")) {
        //   storeFileCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "clone")) {
        //   cloneFileCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "html")) {
        //   generateHTMLCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "help")) {
        //   helpCMD();
        // } else if (cmpstr(args[0], "clear")) {
        //   system("clear");
        // } else if (cmpstr(args[0], "min")) {
        //   minCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "max")) {
        //   maxCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "median")) {
        //   medianCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "show")) {
        //   showCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "mean")) {
        //   meanCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "variance")) {
        //   varianceCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "stdv")) {
        //   stdvCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "add")) {
        //   addCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "sub")) {
        //   subCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "corr")) {
        //   corrCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "regression")) {
        //   regressionCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "titles")) {
        //   titlesCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "hhisto")) {
        //   hhistoCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "vhisto")) {
        //   vhistoCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "report")) {
        //   reportCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "rows")) {
        //   rowsCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "columns")) {
        //   columnsCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "sort")) {
        //   sortCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "oddrows")) {
        //   oddRowsCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "evenrows")) {
        //   evenRowsCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "primes")) {
        //   primesCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "delete")) {
        //   deleteCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "insert")) {
        //   insertRowCMD(args, currentTable, tableLoaded);
        // } else if (cmpstr(args[0], "replace")) {
        //   replaceCMD(args, currentTable, tableLoaded);
        // }

        // else {
        //   cout << "Command not recognized. Enter 'help' for a list of commands."
        //        << endl;
        // };
      };
    }
  }
}
