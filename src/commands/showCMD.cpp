#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>
using namespace std;
void showCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() >= 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        currentTable.getColumnByHeader(colHeader).displayColumn();
      } else {
        cout << "Sorry, column " << colorfmt(fg::magenta) << args[1] << clearfmt
             << " not found" << endl;
      }
    } else {
      currentTable.displayTable();
    }
  } else {
    cout << "Please load a table first" << endl;
  }
};
