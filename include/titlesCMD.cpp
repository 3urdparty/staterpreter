#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void titlesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      vector<string> headers = currentTable.getAllColumnHeaders();
      cout << "Titles: "<< bold << join(headers, ", ") << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
