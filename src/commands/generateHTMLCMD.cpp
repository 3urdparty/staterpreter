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
    // Checks if the table has been loaded into the program
    if (tableLoaded) {
      // gets the path of the html file to be outputted
      string html_path = args[1];
      // checks if the extension of the file to be outputted to
      if (cmpstr(splitString(html_path, '.')[1], "html")) {
        // if the file to be outputted had .html extension
        // the directory to be outputted in
        string html_path = "html/" + args[1];
        // output the table in html format
        vector<string> html = currentTable.to_html();
        // output this to a file
        writeLinesToFile(html_path, html);
        // status message
        cout << "Ouput stored in " << colorfmt(fg::magenta) << html_path
             << clearfmt << endl;
      } else {
        cout << "Please enter an output file with extension .html" << endl;
      }
    } else {
      cout << "Please load a table first" << endl;
    }
    // checks if the user has inputted 3 words
  } else if (args.size() == 3) {
    // path of the file to save the output of the conversion to
    string html_path = "html/" + args[2];
    // path of the csv file to read from
    string csv_path = args[1];

    // checks if the csv file exists in the path specified
    if (fileExists(csv_path)) {
      // if so, then it checks if it actually has a file extension in the
      // filename
      if (splitString(csv_path, '.').size() == 2) {
        // if so, then it checks if the extension is of type csv
        if (cmpstr(splitString(csv_path, '.')[1], "csv")) {
          // if so, then it checks if it actually has a file extension in the
          // filename for the html path
          if (splitString(html_path, '.').size() == 2) {
            // if it does, then check if the file extension is of type html
            if (cmpstr(splitString(html_path, '.')[1], "html")) {
              // if all that is fulfulled
              // it starts the conversion process
              vector<string> lines;
              vector<vector<string>> csv;

              // first lines are read from the csv file and outputted to
              // variable lines
              readLines(csv_path, lines);

              // it parses every line in lines from csv to a 2D vector of values
              parseCSV(lines, csv);

              // data is loaded into the current table object
              currentTable.from_csv(csv);
              // the contents of the current table is outputted in html format
              // using the to_html method
              vector<string> html = currentTable.to_html();

              // writes lines to a file
              writeLinesToFile(html_path, html);

              // staus message outputted
              cout << "CSV file " << colorfmt(fg::magenta) << csv_path
                   << clearfmt << " stored in " << colorfmt(fg::magenta)
                   << html_path << clearfmt << endl;

            } else {
              // prompt user to input a filename with .html extension
              cout << "Please enter an output file with extension .html"
                   << endl;
            }
          }
        }
      }
    } else {
      // inform user that the csv file was not found
      cout << "File " << colorfmt(fg::yellow) << csv_path << clearfmt
           << " not found" << endl;
    }
  } else {
    // prompt user to retry with a valid file name
    cout << "Please enter a valid file name." << endl;
  }
};
