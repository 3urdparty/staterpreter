#include <iostream>
#include <vector>

#include "commands.hpp"

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>

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
  } else if (args.size() >= 2) {
  cout << "Please provide only one input file" << endl;
  }else {
    cout << "Please provide only one input file" << endl;
  }
};