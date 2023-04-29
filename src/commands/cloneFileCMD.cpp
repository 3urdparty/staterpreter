#include <iostream>
#include <vector>

#include "commands.hpp"
#include <strfmt/strfmt.hpp>
#include <table/table.hpp>
#include <fileoperations/fileoperations.hpp>
#include <statistical/statistical.hpp>


using namespace std;
void cloneFileCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  if (args.size() == 3) {
    string path1 = args[1], path2 = args[2];
    if (fileExists(path1)) {
      copyFile(path1, path2);
      cout << "Cloned file " << colorfmt(fg::magenta) << args[1] << clearfmt
           << " to " << colorfmt(fg::magenta) << args[2] << clearfmt << endl;
    } else {
      cout << "File " << colorfmt(fg::yellow) << path1 << clearfmt
           << " not found" << endl;
    }
  } else {
    cout << "Please input two filenames to copy" << endl;
  }

};
