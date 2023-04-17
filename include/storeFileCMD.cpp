#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void storeFileCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() >= 2) {
      vector<string> csv = currentTable.to_csv();
      writeLinesToFile(args[1], csv);
    } else {
      cout << "Please enter a valid file name." << endl;
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
