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
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user inputs less than two command line arguments
    if (args.size() < 3) {
      // we prompt them to input 2
      cout << "Please enter two columns to be substract from one another"
           << endl;
      // however if the user inputs the right amount of command line arguments
      // (2)
    } else if (args.size() == 3) {
      // we get both column header1 and column header2
      string colHeader1 = args[2], colHeader2 = args[1];
      // if the first column exists inthe current table
      if (currentTable.columnExists(colHeader1)) {
        // if the second column exists in the current table
        if (currentTable.columnExists(colHeader2)) {
          // we get both columns 1 and 2
          Column col1 = currentTable.getColumnByHeader(colHeader1);
          Column col2 = currentTable.getColumnByHeader(colHeader2);

          // if either column 1 or column 2 have datatype string
          if (col1.getValueType() == ValueType::str ||
              col2.getValueType() == ValueType::str) {
            // we output an error message
            cout << colorfmt(fg::red) << "Error: " << clearfmt
                 << "The column you have selected contains values of type "
                 << colorfmt(fg::white) << "string" << clearfmt << endl
                 << "Please select another column." << endl;
          } else {
            // otherwise, we continue subtracting columns
            cout << "Subtracting columns " << colorfmt(fg::cyan) << colHeader1
                 << clearfmt << " from " << colorfmt(fg::cyan) << colHeader2
                 << clearfmt << endl;

            // we get the terminal dimensions
            auto [w, h] = getTerminalDimensions();

            // this section is responsible for displaying the table
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

            // we get all the values in column 1
            vector<string> col1_rawValues = col1.getAllValues();
            // we convert the string values to int
            vector<float> col1_values = convertToFloats(col1_rawValues);

            // we got all the values in column 2
            vector<string> col2_rawValues = col2.getAllValues();
            // we convert the string values to int
            vector<float> col2_values = convertToFloats(col2_rawValues);

            float value;
            // we iterate through every element in both column 1 and column 2...
            for (int y = 0; y < col1_values.size(); y++) {
              // we subtract the value in column2 from column1
              value = col1_values[y] - col2_values[y];

              // and then output it
              cout << setw(8) << setfill(' ') << "|" << setprecision(0) << fixed
                   << value << "\t"
                   << "|";
              cout << endl;
            };
            cout << "+" << setfill('=') << setw(15) << "" << setw(1)
                 << setfill(' ') << "+" << endl;
          }
          // if column 2 does not exist
        } else {
          // we output an appropriate message
          cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader2
               << clearfmt << " not found" << endl;
        }

        // if column 1 doe not exist
      } else {
        // we output an appropriate message
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader1
             << clearfmt << " not found" << endl;
      }

      // if the user has inputted more than one column
    } else {
      // we output an appropriate message

      cout << "Please enter one column at a time" << endl;
    };
    // if the user did not laod a table into the program
  } else {
    // we output an appropriate message

    cout << "Please load a table first" << endl;
  }
};
