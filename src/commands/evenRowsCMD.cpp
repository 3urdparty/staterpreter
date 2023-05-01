#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter


#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <table/table.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>  // library of statistical functions to be used in program written by Mubarak


using namespace std;
void evenRowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    cout << endl;
    vector<string> headers = currentTable.getAllColumnHeaders();
    int cols = currentTable.getNumberOfColumns();
    int rows = currentTable.getNumberOfRows();
    cout << "+" << setfill('=') << setw(16 * cols - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;

    cout << "|";

    for (string header : headers) {
      cout << bold << colorfmt(fg::green) << header << left << setw(8) << "\t"
           << "\t" << clearfmt;
    };
    cout << "|" << endl;

    for (int x = 0; x < rows; x += 2) {
      vector<string> rawValues = currentTable.getAllValuesInRow(x);
      cout << join(rawValues, "  |  ");
      cout << endl;
    };
    cout << "+" << setfill('=') << setw(16 * cols - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;
  }

  else {
    cout << "Please load a table first" << endl;
  }
};
