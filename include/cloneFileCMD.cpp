#include <iostream>
#include <vector>

#include "commands.hpp"
#include "file_operations.hpp"
#include "table.hpp"
#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;
void cloneFileCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (args.size() == 3) {
    copyFile(args[1], args[2]);
    cout << "Cloned file " << colorfmt(fg::magenta) << args[1] << clearfmt
         << " to " << colorfmt(fg::magenta) << args[2] << clearfmt << endl;
  } else {
    cout << "Please input two filenames to copy" << endl;
  }
  cloneFile();
};
