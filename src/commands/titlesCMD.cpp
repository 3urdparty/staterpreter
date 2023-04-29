#include <iomanip>
#include <iostream>
#include <vector>

#include "commands.hpp"

#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>

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
