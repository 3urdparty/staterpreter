//@MubarakAhmad0, @3urdparty
#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;

void corrCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table is loaded in the program
  // Checks if the table has been loaded into the program
if (tableLoaded) {
    // checks if the number of arguments are less than the expected number of
    // arguments
    if (args.size() < 3) {
      // if so then output the appropriate help message
      cout << "Please enter two columns to be computer correlation" << endl;
      // But if the number of arguments is correct
    } else if (args.size() == 3) {
      // We get colHeader1, colHeader2 from the argument list
      string colHeader1 = args[1], colHeader2 = args[2];
      // if colHeader1 exists in the current table
      if (currentTable.columnExists(colHeader1)) {
        // and colHeader2 exists in the current table
        if (currentTable.columnExists(colHeader2)) {
          // gets the column object colHeader1
          Column col1 = currentTable.getColumnByHeader(colHeader1);
          // gets the column object colHeader2
          Column col2 = currentTable.getColumnByHeader(colHeader2);
          // if the type of column1 is string
          if (col1.getValueType() == ValueType::str ||
              // and column2 is the same as string
              col2.getValueType() == ValueType::str) {
            // then an error message is outputted stating that one of the
            // columns inputted contains values of type string
            cout << colorfmt(fg::red) << "Error: " << clearfmt
                 << "The column you have selected contains values of type "
                 << colorfmt(fg::white) << "string" << clearfmt << endl
                 << "Please select another column." << endl;
          } else {
            // however if everything is ok
            // we get all the values in column 1
            vector<string> col1_rawValues = col1.getAllValues();
            // and convert them to floats
            vector<float> col1_values = convertToFloats(col1_rawValues);

            // same for values of column 2
            vector<string> col2_rawValues = col2.getAllValues();
            vector<float> col2_values = convertToFloats(col2_rawValues);

            // we then calculate correlation by passing it to function
            // calculateCorrelation which will return to us karl pearson's
            // correlation coefficient
            float r = calculateCorrelation(col1_values, col2_values);

            // then output it appropriately
            cout << "The Correlation for columns " << colorfmt(fg::cyan)
                 << colHeader1 << clearfmt << " and " << colorfmt(fg::cyan)
                 << colHeader2 << clearfmt << " is " << colorfmt(fg::cyan)
                 << setprecision(4) << fixed << showpoint << r << clearfmt
                 << endl;
          }
        } else {
          // However if column 2 were not found
          cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader2
               << clearfmt << " not found" << endl;
        }
      } else {
        // or column 1 is not found
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader1
             << clearfmt << " not found" << endl;
      }

    } else {
      // If the user inputted more than 2 command line arguemnts to command
      // `corr`
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    // If user runs command without loading a table into the program
    cout << "Please load a table first" << endl;
  }
};
