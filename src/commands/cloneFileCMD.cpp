// Azi
#include <iostream>
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <filuzzy/filuzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak


using namespace std;
// The
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
