#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <terminalcancer/terminalcancer.hpp>  // library of simple terminal helper functions to be used in program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
using namespace std;
void subCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 3) {
      cout << "Please enter two columns to be substract from one another"
           << endl;
    } else if (args.size() == 3) {
      string colHeader1 = args[2], colHeader2 = args[1];
      if (currentTable.columnExists(colHeader1)) {
        if (currentTable.columnExists(colHeader2)) {
          Column col1 = currentTable.getColumnByHeader(colHeader1);
          Column col2 = currentTable.getColumnByHeader(colHeader2);
          if (col1.getValueType() == ValueType::str ||
              col2.getValueType() == ValueType::str) {
            cout << colorfmt(fg::red) << "Error: " << clearfmt
                 << "The column you have selected contains values of type "
                 << colorfmt(fg::white) << "string" << clearfmt << endl
                 << "Please select another column." << endl;
          } else {
            cout << "Subtracting columns " << colorfmt(fg::cyan) << colHeader1
                 << clearfmt << " from " << colorfmt(fg::cyan) << colHeader2
                 << clearfmt << endl;
            auto [w, h] = getTerminalDimensions();

            cout << endl;
            cout << "+" << setfill('=') << setw(15) << "" << setw(1)
                 << setfill(' ') << "+" << endl;

            cout << "|" << bold << setw(8) << left << colorfmt(fg::green)
                 << col1.getHeader() << "-" << col2.getHeader() << "\t"
                 << clearfmt << "|" << endl;

            cout << left << setw(15) << setfill('-') << "|"
                 << " "
                 << "|" << endl
                 << clearfmt;

            vector<string> col1_rawValues = col1.getAllValues();
            vector<float> col1_values = convertStrToFloats(col1_rawValues);
            vector<string> col2_rawValues = col2.getAllValues();
            vector<float> col2_values = convertStrToFloats(col2_rawValues);

            float value;
            for (int y = 0; y < col1_values.size(); y++) {
              value = col1_values[y] - col2_values[y];
              cout << setw(8) << setfill(' ') << "|" << setprecision(0) << fixed
                   << value << "\t"
                   << "|";

              cout << endl;
            };
            cout << "+" << setfill('=') << setw(15) << "" << setw(1)
                 << setfill(' ') << "+" << endl;
          }
        } else {
          cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader2
               << clearfmt << " not found" << endl;
        }
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader1
             << clearfmt << " not found" << endl;
      }

    } else {
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
