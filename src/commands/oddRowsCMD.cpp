#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak

using namespace std;
void oddRowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    cout << endl;
    vector<string> headers = currentTable.getAllColumnHeaders();
    int cols = currentTable.getNumberOfColumns();
    int rows = currentTable.getNumberOfRows();
    cout << "+" << setfill('=') << setw(8) << "" << setw(1)
         << setfill(' ') << "+" << endl;

    cout << "|";

    for (string header : headers) {
      cout << bold << colorfmt(fg::green) << left << header << setw(8)
           << clearfmt << "\t"
           << "|";
    };
    cout << endl;
    for (int x = 0; x < rows; x += 2) {
      vector<string> rawValues = currentTable.getAllValuesInRow(x);
      cout << "|";
      for (int x = 0; x < rawValues.size(); x++) {
        cout << setw(8) << rawValues[x] << "\t" << "|";
      }
      cout << endl;
    };
    cout << "+" << setfill('=') << setw(8) << "" << setw(1)
         << setfill(' ') << "+" << endl;
  }

  else {
    cout << "Please load a table first" << endl;
  }
};
