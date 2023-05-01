#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <table/table.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>  // library of statistical functions to be used in program written by Mubarak


using namespace std;
void reportCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      currentTable.displayReport();
    } 
  } else {
    cout << "Please load a table first" << endl;
  }
};
