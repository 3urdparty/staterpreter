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
void deleteCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 2) {
      if (cmpstr(args[1], "occurrence")) {
      } else if (cmpstr(args[1], "row")) {
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
