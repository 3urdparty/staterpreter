#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void oddRowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    cout << endl;
    vector<string> headers = currentTable.getAllColumnHeaders();
    int cols = currentTable.getNumberOfColumns();
    int rows = currentTable.getNumberOfRows();
    cout << "+" << setfill('=') << setw(8) << "" << setw(1)
         << setfill(' ') << "+" << endl;

    cout << "|";

    for (string header : headers) {
      cout << bold << colorfmt(fg::green) << left << header << setw(8)
           << clearfmt << "\t"
           << "|";
    };
    cout << endl;
    for (int x = 0; x < rows; x += 2) {
      vector<string> rawValues = currentTable.getAllValuesInRow(x);
      cout << "|";
      for (int x = 0; x < rawValues.size(); x++) {
        cout << setw(8) << rawValues[x] << "\t" << "|";
      }
      cout << endl;
    };
    cout << "+" << setfill('=') << setw(8) << "" << setw(1)
         << setfill(' ') << "+" << endl;
  }

  else {
    cout << "Please load a table first" << endl;
  }
};
