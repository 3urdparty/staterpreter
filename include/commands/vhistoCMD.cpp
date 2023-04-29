#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include "../histogram/histogram.hpp"

#include "../table/table.hpp"
#include "../utilities/utilities.hpp"


using namespace std;
void vhistoCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 2) {
      cout << "Please enter a column to display the vertical Histogram for" << endl;
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
          vector<string> rawValues = col.getAllValues();
          vector<float> y_values = convertStrToFloats(rawValues);

          vector<string> x_values;
          for (int x = 0; x < y_values.size(); x++) {
            string x_val = "Row " + to_string(x); 
            x_values.push_back(x_val);
          }
          displayVerticalHistogram(x_values, y_values);
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