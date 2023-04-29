#include <iostream>
#include <vector>

#include "commands.hpp"

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>

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
