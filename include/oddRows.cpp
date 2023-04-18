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
    cout << "+" << setfill('=') << setw(16 * cols - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;

    cout << "|";

    for (string header : headers) {
      cout << bold << colorfmt(fg::green) << header << left << setw(8) << "\t"
           << "\t" << clearfmt;
    };
    cout << "|" << endl;

    for (int x = 0; x < rows; x += 2) {
      vector<string> rawValues = currentTable.getAllValuesInRow(x);
      cout << join(rawValues, "  |  ");
      cout << endl;
    };
    cout << "+" << setfill('=') << setw(16 * cols - 1) << "" << setw(1)
         << setfill(' ') << "+" << endl;
  }

  else {
    cout << "Please load a table first" << endl;
  }
};
