#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "histogram.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"

using namespace std;

void insertRowCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (tableLoaded) {
    int cols = currentTable.getNumberOfColumns();
    if (args.size() >= 2) {
      if (cmpstr(args[1], "row")) {
        if (args.size() == 2 + cols) {
          vector<string> newValues(args.begin() + 2, args.end());
          if (currentTable.canBeInsertedIntoTable(newValues)) {
            currentTable.insertRowAtIndex(newValues, 0);
            cout << "New row inserted" << endl;

          } else {
            cout << "Please enter the appropriate Value type for each row"
                 << endl;
          }
        } else {
          vector<string> valuesInputted(args.begin() + 2, args.end());
          int valuesLeft = cols - valuesInputted.size();
          if (valuesLeft > 0) {
            cout << "Please appropriate number of values for the new row "
                 << bold << colorfmt(fg::magenta) << "(" << valuesLeft
                 << " more)" << endl;
          } else {
            cout << "Too much values. Please input only " << cols << " values"
                 << endl;
          }
        };

      } else {
        cout << "Please specify that you want to add a new row using:" << endl
             << colorfmt(fg::cyan) << "insert row [VALUES]" << endl;
      }
    } else {
      cout << "Please specify that you want to add a new row using:" << endl
           << colorfmt(fg::cyan) << "insert row [VALUES]" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
