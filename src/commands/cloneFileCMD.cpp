// Azi
#include <filuzzy/filuzzy.hpp>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;

void cloneFileCMD(vector<string>& args, Table& currentTable,
                  bool& tableLoaded) {
  // Checks if 2 command line arguments have been passed to the `clone` command
  if (args.size() == 3) {
    // gets path1, and path2 from args, the path of the file to clone, and the
    // path to clone to
    string path1 = args[1], path2 = args[2];

    // check if the file at path exists
    if (fileExists(path1)) {
      // if so, then clone the file using the copyFile function
      copyFile(path1, path2);

      // Status message
      cout << "Cloned file " << colorfmt(fg::magenta) << args[1] << clearfmt
           << " to " << colorfmt(fg::magenta) << args[2] << clearfmt << endl;
    } else {
      // Message to tell user that the file has not been found
      cout << "File " << colorfmt(fg::yellow) << path1 << clearfmt
           << " not found" << endl;
    }
  } else {
    // Advise user to input the right amount of arguments
    cout << "Please input 2 filenames, one to copy from and one to copy to"
         << endl;
  }
};
