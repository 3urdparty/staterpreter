#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak

using namespace std;
void corrCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 3) {
      cout << "Please enter two columns to be computer correlation" << endl;
    } else if (args.size() == 3) {
      string colHeader1 = args[1], colHeader2 = args[2];
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
            vector<string> col1_rawValues = col1.getAllValues();
            vector<float> col1_values = convertToFloats(col1_rawValues);
            vector<string> col2_rawValues = col2.getAllValues();
            vector<float> col2_values = convertToFloats(col2_rawValues);

            float r = calculateCorrelation(col1_values, col2_values);
            cout << "The Correlation for columns " << colorfmt(fg::cyan)
                 << colHeader1 << clearfmt << " and " << colorfmt(fg::cyan)
                 << colHeader2 << clearfmt << " is " << colorfmt(fg::cyan)
                 << setprecision(2) << fixed << showpoint << r << clearfmt
                 << endl;
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
