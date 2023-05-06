#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void hhistoCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the number of arguments is smaller than 1
    if (args.size() < 2) {
      // please enter a column
      cout << "Please enter a column to display the histogram for" << endl;
    } else if (args.size() == 2) {
      // gets the column header from the arguments
      string colHeader = args[1];

      // if the column exists in the table
      if (currentTable.columnExists(colHeader)) {
        // we get the column from the terminal
        Column col = currentTable.getColumnByHeader(colHeader);
        // we check that the value type of the column is not a string
        if (col.getValueType() == ValueType::str) {
          // if it was then we output an error message
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
        } else {
          // however, if everything is in order
          // we get all values in column and convert them to floats
          vector<string> rawValues = col.getAllValues();
          vector<float> y_values = convertToFloats(rawValues);

          // we then initiate a vector of x_values (indices)
          vector<string> x_values;
          for (int x = 0; x < y_values.size(); x++) {
            x_values.push_back(to_string(x));
          }

          // and then display the horizontal histogram using a histogram drawing
          // library we wrote
          displayHorizontalHistogram(x_values, y_values);
        }

      } else {
        // if the column does not exist...
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
             << clearfmt << " not found" << endl;
      }

    } else {
      // if the user inputs more than one column
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
