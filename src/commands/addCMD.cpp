// Mustafa
// This is the code responsible for
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <string>
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa  // library containing a class for the Table to be used in this Program written by Mustafa
#include <terminalcancer/terminalcancer.hpp>  // library of simple terminal helper functions to be used in program written by Mustafa  // library of simple terminal helper functions to be used in program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter  // Header file for all the interpreter commands for staterpreter

using namespace std;

// Function for the `add` Command that takes two arguments, both of them the
// first and second columns to be added and displayed to the screen As with the
// rest of the prompt command functions, this function is passed a reference to
// the command line arguments passed at runtime, a reference to the currentTable
// object, and a reference to a flag that indicates wether the table has been
// loaded into the program or not
void addCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
if (tableLoaded) {  // Checks if a table has been loaded into the program
                      // using the `load` command

    // Checks if a user has inputted less that 3 commands
    if (args.size() < 3) {
      // If not, it requests user to input right amount of arguments
      cout << "Please enter two columns to be added together" << endl;
    } else if (args.size() == 3) {  // If user input is appropriate

      // program gets column names from args
      string colHeader1 = args[1], colHeader2 = args[2];

      // Check if `colHeader1` exists in currentTable
      if (currentTable.columnExists(colHeader1)) {
        // Check if `colHeader2` exists in currentTable
        if (currentTable.columnExists(colHeader2)) {
          // Get reference to both columns
          Column col1 = currentTable.getColumnByHeader(colHeader1);
          Column col2 = currentTable.getColumnByHeader(colHeader2);

          // Checks if the values of both columns are of type `float` to be
          // added Error message printed if not
          if (col1.getValueType() == ValueType::str ||
              col2.getValueType() == ValueType::str) {
            cout << colorfmt(fg::red) << "Error: " << clearfmt
                 << "The column you have selected contains values of type "
                 << colorfmt(fg::white) << "string" << clearfmt << endl
                 << "Please select another column." << endl;
          } else {
            cout << "Adding columns " << colorfmt(fg::cyan) << colHeader1
                 << clearfmt << " and " << colorfmt(fg::cyan) << colHeader2
                 << clearfmt << endl;

            // Calling function to get the dimensions of the current terminal
            auto [w, h] = getTerminalDimensions();

            // Displaying the column
            // Decorative stuff
            cout << endl;
            cout << "+" << setfill('=') << setw(15) << "" << setw(1)
                 << setfill(' ') << "+" << endl;

            // colorfmt() is a function that returns the right ANSII escaping to
            // output text To the terminal with color formatting
            // Clearfmt is an ANSII escape character that resets the color to
            // the default
            // getHeader() is a method to get the name of Column
            cout << "|" << bold << setw(8) << left << colorfmt(fg::green)
                 << col1.getHeader() << "/" << col2.getHeader() << "\t"
                 << clearfmt << "|" << endl;

            // Decorative stuff
            cout << left << setw(15) << setfill('-') << "|"
                 << " "
                 << "|" << endl
                 << clearfmt;

            // getAllValues() is a method that gets all values of column in a
            // vector of strings
            vector<string> col1_rawValues = col1.getAllValues();

            // We convert vector of strings to a vector of floats to add those
            // values Using function convertToFloats() in strfmt
            vector<float> col1_values = convertToFloats(col1_rawValues);

            // We do the same for the second column
            vector<string> col2_rawValues = col2.getAllValues();
            vector<float> col2_values = convertToFloats(col2_rawValues);

            // We then initialize a value to store the summation of each row in
            // column
            float value;

            // we iterate through every element in column using a counter-based
            // for-loop...
            for (int y = 0; y < col1_values.size(); y++) {
              cout << "|";

              // and sum the rows, storing it in values...
              value = col1_values[y] + col2_values[y];

              // then outputting it
              cout << setw(8) << setfill(' ') << setprecision(0) << left
                   << fixed << value << "\t"
                   << "|";
              cout << endl;
            };
            cout << "+" << setfill('=') << setw(15) << "" << setw(1)
                 << setfill(' ') << "+" << endl;
          }

          // Output message in case one of the columns are not found
        } else {
          cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader2
               << clearfmt << " not found" << endl;
        }
        // Output message in case one of the columns are not found
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader1
             << clearfmt << " not found" << endl;
      }
      // Output a message in case user inputs more than 2 columns
    } else {
      cout << "Please enter one column at a time" << endl;
    };
    // Output a message in case user does not load a table first
  } else {
    cout << "Please load a table first" << endl;
  }
};
