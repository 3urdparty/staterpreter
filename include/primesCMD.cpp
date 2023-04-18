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
void primesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 2) {
      cout << "Please select a column to sort table by" << endl;
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
          cout << "The primes in column " << colorfmt(fg::magenta) << colHeader
               << clearfmt << " are " << colorfmt(fg::yellow);
          for (int prime : primes) {
            cout << prime << " ";
          }
          cout << clearfmt << endl;
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
