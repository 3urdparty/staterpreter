#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>


using namespace std;
void minCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      float min = currentTable.getMinimumValue();
      cout << fixed << setprecision(0) << "Minumum value is "
           << colorfmt(fg::cyan) << bold << min << clearfmt << endl;
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
          float minimum = col.getMinimumValue();
          string columnHeader = col.getHeader();

          cout << fixed << setprecision(0) << "Minumum value for column "
               << colorfmt(fg::magenta) << colHeader << clearfmt << " is "
               << colorfmt(fg::cyan) << bold << minimum << clearfmt << endl;
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
