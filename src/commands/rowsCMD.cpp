#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>

using namespace std;
void rowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  if (tableLoaded) {
    if (args.size() == 1) {
      cout << "The number of rows for this table is " << bold
           << colorfmt(fg::magenta) << currentTable.getNumberOfRows() << endl;
    };
  } else {
    cout << "Please load a table first" << endl;
  }
};
