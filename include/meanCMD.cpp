#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void meanCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      float mean = currentTable.getMean();
      cout << fixed << setprecision(0) << "The Mean of the table is "
           << colorfmt(fg::cyan) << bold << mean << clearfmt << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        if (currentTable.columnExists(colHeader)) {
          Column col = currentTable.getColumnByHeader(colHeader);
          if (col.getValueType() == ValueType::str) {
            cout << colorfmt(fg::red) << "Error: " << clearfmt
                 << "The column you have selected contains values of type "
                 << colorfmt(fg::white) << "string" << clearfmt << endl
                 << "Please select another column." << endl;
          } else {
            float mean = col.getMean();
            string columnHeader = col.getHeader();

            cout << fixed << setprecision(0) << "The Mean value for column "
                 << colorfmt(fg::magenta) << colHeader << clearfmt << " is "
                 << colorfmt(fg::cyan) << bold << mean << clearfmt << endl;
          }
        } else {
          cout << "Sorry, column " << colorfmt(fg::magenta) << args[1]
               << clearfmt << " not found" << endl;
        }

      } else {
        cout << "Please enter one column at a time" << endl;
      };
    } else {
      cout << "Please load a table first" << endl;
    }
  };
};