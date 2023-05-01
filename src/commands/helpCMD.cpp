#include <fileoperations/fileoperations.hpp>
#include <iomanip>
#include <iostream>
#include <statistical/statistical.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <table/table.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

void helpCMD() {
  cout << "\nCore commands\n";
  cout << setw(20) << setfill('=') << "\n";
  cout << endl;
  cout << "File Operations" << endl;
  cout << setw(12) << setfill('-') << "\n";

  cout << bold << "load" << clearfmt << endl;
  cout << bold << "Usage: load [PATH]" << endl;
  cout << setw(70)
       << "Reads the file named filename and parses its contents and stores it "
          "into arrays or vectors. The interpreter handles one file only."
       << endl;
  cout << endl;

  cout << bold << "store" << clearfmt << endl;
  cout << bold << "Usage: store [PATH]" << endl;
  cout << setw(70)
       << "Save the active array or vectors into a csv formatted file with the "
          "name filename"
       << endl;
  cout << endl;

  cout << bold << "store" << clearfmt << endl;
  cout << bold << "Usage: clone [PATH1] [PATH2] " << endl;
  cout << setw(30)
       << "Create a copy of file1 and name it file2. You are not expected to "
          "handle multiple folders and switch folders."
       << endl;
  cout << endl;

  cout << bold << "html" << clearfmt << endl;
  cout << bold << "Usage: html [PATH]" << endl;
  cout << setw(70)
       << "Generates an HTML document for the loaded data and store it in a "
          "file “salary.html”. You must decide on the format. The file to be "
          "viewed by a web browser."
       << endl;
  cout << endl;

  cout << bold << "html [PATH] [PATH2]" << clearfmt << endl;
  cout << setw(70)
       << "The program should read the a.csv file and convert it to an html "
          "table with proper column titles and format."
       << endl;
  cout << endl;

  cout << bold << "min" << clearfmt << endl;
  cout << setw(70)
       << "The program should read the a.csv file and convert it to an html "
          "table with proper column titles and format."
       << endl;
  cout << endl;
};
