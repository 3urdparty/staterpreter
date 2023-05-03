#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak



using namespace std;
void deleteCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() >= 2) {
      if (cmpstr(args[1], "occurrence")) {
        if (args.size() == 4) {
          string colHeader = args[2], value = args[3];

          int rowIndex = currentTable.getRowIndexOfFirstOccurrence(colHeader, value);
          do {
            currentTable.deleteRow(rowIndex);
            rowIndex =
                currentTable.getRowIndexOfFirstOccurrence(colHeader, value);
          } while (rowIndex != -1);

        } else {
          cout << "Please enter a column" << endl;
        }
      } else if (cmpstr(args[1], "row")) {
        if (args.size() == 3) {
          int rowIndex = stoi(args[2]);
          if (rowIndex <= currentTable.getNumberOfRows()) {
            currentTable.deleteRow(rowIndex);
            cout << "Row " << colorfmt(fg::yellow) << rowIndex << clearfmt
                 << " has been deleted" << endl;

          } else {
            cout << "Row " << colorfmt(fg::yellow) << rowIndex << clearfmt
                 << " does not exist, please try again." << endl;
          }
        } else {
          cout << "Please enter a column" << endl;
        }
      } else if (cmpstr(args[1], "column")) {
        string colHeader = args[1];
        if (currentTable.columnExists(colHeader)) {
          currentTable.deleteColumn(colHeader);
        } else {
          cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
               << clearfmt << " not found" << endl;
        }
      } else {
        cout << "Wrong input detected" << endl;
      }
    } else {
      cout << "Please specify what you want to to delete "
              "(Occurrence/Row/Column)"
           << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  };
}
