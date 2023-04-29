#include <fileoperations/fileoperations.hpp>
#include <iomanip>
#include <iostream>
#include <statistical/statistical.hpp>
#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <vector>

#include "commands.hpp"

using namespace std;
void maxCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      float max = currentTable.getMaxiumValue();
      cout << fixed << setprecision(0) << "Maximum value is "
           << colorfmt(fg::cyan) << bold << max << clearfmt << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        Column col = currentTable.getColumnByHeader(colHeader);
        if (col.getValueType() == ValueType::str) {
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
        } else {
          float maximum = col.getMaximumValue();
          string columnHeader =
              currentTable.getColumnByHeader(colHeader).getHeader();

          cout << fixed << setprecision(0) << "Maximum value for column "
               << showpoint << fixed << colorfmt(fg::magenta) << colHeader
               << clearfmt << " is " << colorfmt(fg::cyan) << bold << maximum
               << clearfmt << endl;
        }
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }

    } else {
      cout << "Please enter one column at a time" << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};