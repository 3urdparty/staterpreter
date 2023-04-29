#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>

using namespace std;

void replaceCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    int cols = currentTable.getNumberOfColumns();
    if (args.size() == 3) {
      int count = 0;
      string toReplace = args[1], toReplaceWith = args[2];
      for (int x = 0; x < currentTable.getNumberOfColumns(); x++) {
        for (int y = 0; y < currentTable.getNumberOfRows(); y++) {
          ValueType dttype = currentTable[x].getValueType();
          if (dttype == ValueType::str &&
              cmpstr(currentTable[x][y], toReplace)) {
            currentTable[x][y] = toReplaceWith;
            count++;
          } else if (dttype == ValueType::flt && stringIsFloat(toReplace) &&
                     (stof(currentTable[x][y]) == stof(toReplace))) {
            currentTable[x][y] = toReplaceWith;
            count++;
          }
        }
      }
      cout << "Changed " << colorfmt(fg::magenta) << count << " values" << endl;
    } else if (args.size() == 4) {
      string colHeaders = args[1], toReplace = args[2], toReplaceWith = args[3];
      if (currentTable.columnExists(colHeaders)) {
        Column& col = currentTable.getColumnByHeader(colHeaders);
        ValueType dttype = col.getValueType();
        if (dttype == ValueType::flt &&
            (!stringIsFloat(toReplace) || !stringIsFloat(toReplaceWith))) {
          cout << "Please enter values of type " << colorfmt(fg::yellow)
               << "float" << clearfmt << endl;
        } else {
          int count = 0;
          for (int y = 0; y < currentTable.getNumberOfRows(); y++) {
            if (dttype == ValueType::str && cmpstr(col[y], toReplace)) {
              col[y] = toReplaceWith;
              count++;
            } else if (dttype == ValueType::flt && stringIsFloat(toReplace) &&
                       (stof(col[y]) == stof(toReplace))) {
              col[y] = toReplaceWith;
              count++;
            }
          }
          cout << "Changed " << colorfmt(fg::magenta) << count << " values"
               << endl;
        }
      }
    } else {
      cout << "Please input the value to be replaced, and the value to replace "
              "it with" << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
