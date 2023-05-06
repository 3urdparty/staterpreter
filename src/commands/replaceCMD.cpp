#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;

void replaceCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // we get the number of columns from the table
    int cols = currentTable.getNumberOfColumns();
    // if the number of commandline arguments is exactly 2
    if (args.size() == 3) {
      // we initialize a count variable
      int count = 0;

      // we then get the value to replace, and the value to replace it with from
      // args
      string toReplace = args[1], toReplaceWith = args[2];
      // for every column in columns
      for (int x = 0; x < currentTable.getNumberOfColumns(); x++) {
        // for every row in that column
        for (int y = 0; y < currentTable.getNumberOfRows(); y++) {
          // we get the datatype of the column
          ValueType dttype = currentTable[x].getValueType();
          // if that column has type string and the value to replace is the same
          // as a any value in that column
          if (dttype == ValueType::str &&
              cmpstr(currentTable[x][y], toReplace)) {
            // we replace it with the toReplaceWith value
            currentTable[x][y] = toReplaceWith;

            // for every replacement we increment count by 1
            count++;

            // if the datatype of that column is numerical
          } else if (dttype == ValueType::flt && stringIsFloat(toReplace) &&
                     (stof(currentTable[x][y]) == stof(toReplace))) {
            // we replace each value that matches the value toReplace in the
            // column with the value toReplaceWith
            currentTable[x][y] = toReplaceWith;

            // for every replacement we increment count by 1
            count++;
          }
        }
      }
      // we output the number of replacements made
      cout << "Changed " << colorfmt(fg::magenta) << count << " values" << endl;
      // if the user inputs 3 commandline arguments
    } else if (args.size() == 4) {
      // we get the column header, the value to replace, and the value to
      // replace it with from args
      string colHeaders = args[1], toReplace = args[2], toReplaceWith = args[3];

      // if the column exists in current table
      if (currentTable.columnExists(colHeaders)) {
        // we get the reference to that column
        Column& col = currentTable.getColumnByHeader(colHeaders);
        // we get the datatype of that column
        ValueType dttype = col.getValueType();

        // if that column is of type float and the user has inputted values of
        // wrong types
        if (dttype == ValueType::flt &&
            (!stringIsFloat(toReplace) || !stringIsFloat(toReplaceWith))) {
          // we inform the user to input appropriate values
          cout << "Please enter values of type " << colorfmt(fg::yellow)
               << "float" << clearfmt << endl;
          // however if the values inputted by user is of the right type
        } else {
          // we initialize a count variable
          int count = 0;

          // for every row in the specified column
          for (int y = 0; y < currentTable.getNumberOfRows(); y++) {
            // if the datatype is of type string we replace each string that
            // matches
            if (dttype == ValueType::str && cmpstr(col[y], toReplace)) {
              // with the value to replace with
              col[y] = toReplaceWith;
              // and increment the counter
              count++;
              // however if the datatype is of type float
              // we make sure each value the user has inputted represents a
              // float and check if there are any matches to the value toReplace
              // in the column
            } else if (dttype == ValueType::flt && stringIsFloat(toReplace) &&
                       (stof(col[y]) == stof(toReplace))) {
              // if there is a match, we replace each instance with value
              // toReplaceWith
              col[y] = toReplaceWith;

              // we then increment the counter
              count++;
            }
          }

          // we then output the number of values we changed
          cout << "Changed " << colorfmt(fg::magenta) << count << " values"
               << endl;
        }
      }
      // if the user has not inputted either of the values to replace and be
      // replaced by
    } else {
      // we prompt user to input them properly
      cout << "Please input the value to be replaced, and the value to replace "
              "it with"
           << endl;
    }
    // if the user has not laoded a table into the program
  } else {
    // we output an appropriate message
    cout << "Please load a table first" << endl;
  }
};
