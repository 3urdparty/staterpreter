#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <terminalcancer/terminalcancer.hpp>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void oddRowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
if (tableLoaded) {
    int columns = currentTable.getNumberOfColumns(),
        rows = currentTable.getNumberOfRows();
    auto [w, h] = getTerminalDimensions();

    cout << endl;
    cout << "+" << setfill('=') << setw(16 * columns - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;

    cout << "|";

    for (int x = 0; x < columns; x++) {
      Column col = currentTable[x];
      cout << bold << colorfmt(fg::green) << col.getHeader() << left << setw(8)
           << "\t"
           << "\t" << clearfmt;
    };
    cout << "|" << endl;
    for (int y = 0; y < rows; y=y+2) {
      cout << "|";
      for (int x = 0; x < columns; x++) {
        Column col = currentTable[x];
        if (col.getValueType() == ValueType::flt) {
          cout << setw(8) << setfill(' ') << setprecision(0) << left << fixed
               << stof(col.getValueAt(y)) << "\t"
               << "|";

        } else if (col.getValueType() == ValueType::str) {
          cout << setw(8) << setfill(' ') << setprecision(0) << left << fixed
               << col.getValueAt(y) << "\t"
               << "|";
        }
      }
      cout << endl;
    };
    cout << "+" << setfill('=') << setw(16 * columns - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;
  }

  else {
    cout << "Please load a table first" << endl;
  }
};
