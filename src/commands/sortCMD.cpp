#include <iomanip>
#include <iostream>
#include <vector>

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>
#include "commands.hpp"

using namespace std;
void sortCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() < 2) {
      cout << "Please select a column to sort table by" << endl;
    } else if (args.size() == 2) {
      string colHeader = args[1];
      if (currentTable.columnExists(colHeader)) {
        currentTable.sortTableByColumn(colHeader);
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
