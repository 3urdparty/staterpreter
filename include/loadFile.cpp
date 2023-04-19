#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void loadFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (args.size() == 2) {
    string path = args[1];
    if (fileExists(path)) {
      vector<string> lines;
      vector<vector<string>> csv;

      readLines(path, lines);
      parseCSV(lines, csv);
      currentTable.flushTable();
      currentTable.from_csv(csv);
      tableLoaded = true;
      cout << "Loaded " << colorfmt(fg::magenta) << path << clearfmt << endl;
    } else {
      cout << "File " << colorfmt(fg::yellow) << path << clearfmt
           << " not found" << endl;
    }
  } else {
    cout << "Please provide only one input file" << endl;
  }
};