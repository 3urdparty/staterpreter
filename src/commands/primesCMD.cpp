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
    if (args.size() < 2) {
      cout << "Please select a column to get the primes in" << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        Column col = currentTable.getColumnByHeader(colHeader);
        if (col.getValueType() == ValueType::str) {
          cout << "The type of data in this column is not numerical. Please "
                  "choose a different column"
               << endl;
        } else {
          vector<int> primes = col.getPrimes();
          if (primes.size() == 0) {
            cout << "No primes in column " << colorfmt(fg::yellow) << colHeader
                 << clearfmt << endl;
          } else {
            vector<string> strings = convertToStrings(primes);
            remove_duplicates(strings);

            cout << "The primes in column " << colorfmt(fg::magenta)
                 << colHeader << clearfmt << " are " << colorfmt(fg::yellow)
                 << join(strings, ", ") << clearfmt << endl;
          }
        }
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
             << clearfmt << " not found" << endl;
      }
    } else {
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
