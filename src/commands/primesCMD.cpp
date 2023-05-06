#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

void remove_duplicates(vector<string>& values) {
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());
};

using namespace std;
void primesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the user has not inputted a command line argumnet
    if (args.size() < 2) {
      // we prompt user to input a command line argumnet
      cout << "Please select a column to get the primes in" << endl;
      // if he has
    } else if (args.size() == 2) {
      // then we get the column header from args
      string colHeader = args[1];
      // if the specified column exist...
      if (currentTable.columnExists(colHeader)) {
        // we get it
        Column col = currentTable.getColumnByHeader(colHeader);
        // if that column has type string
        if (col.getValueType() == ValueType::str) {
          // we output an error message informing user the column is of type
          // string
          cout << "The type of data in this column is not numerical. Please "
                  "choose a different column"
               << endl;
          // if it is numeric instead
        } else {
          // we get the primes from the column
          vector<int> primes = col.getPrimes();
          // if the number of primes in that colunmn is 0
          if (primes.size() == 0) {
            // we output a message saying there is none
            cout << "No primes in column " << colorfmt(fg::yellow) << colHeader
                 << clearfmt << endl;
          } else {
            // however if primes were found
            // we convert the primes to strings
            vector<string> strings = convertToStrings(primes);

            // we remove the duplicates in that vector
            remove_duplicates(strings);

            // and output it
            cout << "The primes in column " << colorfmt(fg::magenta)
                 << colHeader << clearfmt << " are " << colorfmt(fg::yellow)
                 << join(strings, ", ") << clearfmt << endl;
          }
        }
        // if the column specified does not exist
      } else {
        // we output an appropriate message
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
             << clearfmt << " not found" << endl;
      }
    } else {
      // we prompt user to input one column at a tiem
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
