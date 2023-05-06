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
    // gets the number of columns and rows in table
    int columns = currentTable.getNumberOfColumns(),
        rows = currentTable.getNumberOfRows();

    // gets the dimensions of the terminal
    auto [w, h] = getTerminalDimensions();

    // This section of the code is responsible for drawing out the table
    cout << endl;
    cout << "+" << setfill('=') << setw(16 * columns - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;

    cout << "|";

    // This outputs the table column headers
    for (int x = 0; x < columns; x++) {
      Column col = currentTable[x];
      cout << bold << colorfmt(fg::green) << col.getHeader() << left << setw(8)
           << "\t"
           << "\t" << clearfmt;
    };
    cout << "|" << endl;

    // This is responsible for populating the table with values
    for (int y = 0; y < rows; y = y + 2) {
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
    // decorative purposes
    cout << "+" << setfill('=') << setw(16 * columns - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;
  }

  else {
    // if the user has not loaded a table yet
    cout << "Please load a table first" << endl;
  }
};
