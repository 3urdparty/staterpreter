#include <filuzzy/filuzzy.hpp>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void generateHTMLCMD(vector<string>& args, Table& currentTable,
                     bool& tableLoaded) {
  if (args.size() == 2) {
    if (tableLoaded) {
      string html_path = args[1];
      if (cmpstr(splitString(html_path, '.')[1], "html")) {
        string html_path = "html/" + args[1];

        vector<string> html = currentTable.to_html();
        writeLinesToFile(html_path, html);
        cout << "Ouput stored in " << colorfmt(fg::magenta) << html_path
             << clearfmt << endl;
      } else {
        cout << "Please enter an output file with extension .html" << endl;
      }
    } else {
      cout << "Please load a table first" << endl;
    }
  } else if (args.size() == 3) {
    string html_path = "html/" + args[2];
    string csv_path = args[1];
    if (fileExists(csv_path)) {
      if (splitString(csv_path, '.').size() == 2) {
        if (cmpstr(splitString(csv_path, '.')[1], "csv")) {
          if (cmpstr(splitString(html_path, '.')[1], "html")) {
            vector<string> lines;
            vector<vector<string>> csv;

            readLines(csv_path, lines);
            parseCSV(lines, csv);
            currentTable.from_csv(csv);
            vector<string> html = currentTable.to_html();
            writeLinesToFile(html_path, html);

            cout << "CSV file " << colorfmt(fg::magenta) << csv_path << clearfmt
                 << " stored in " << colorfmt(fg::magenta) << html_path
                 << clearfmt << endl;

          } else {
            cout << "Please enter an output file with extension .html" << endl;
          }
        }
      }
    } else {
      cout << "File " << colorfmt(fg::yellow) << csv_path << clearfmt
           << " not found" << endl;
    }
  } else {
    cout << "Please enter a valid file name." << endl;
  }
};
