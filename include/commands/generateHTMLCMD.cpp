#include <iostream>
#include <vector>

#include "commands.hpp"

#include "../table/table.hpp"
#include "../utilities/utilities.hpp"

using namespace std;
void generateHTMLCMD(vector<string>& args, Table& currentTable,
                     bool& tableLoaded) {
  if (args.size() == 2) {
    if (tableLoaded) {
      string htmlPath = "html/" + args[1];
      vector<string> html = currentTable.to_html();
      writeLinesToFile(htmlPath, html);
      cout << "Ouput stored in " << colorfmt(fg::magenta) << htmlPath
           << clearfmt << endl;

    } else {
      cout << "Please load a table first" << endl;
    }
  } else if (args.size() == 3) {
    string html_path = "html/" + args[2];
    string csv_path = args[1];
    if (fileExists(csv_path)) {
      vector<string> lines;
      vector<vector<string>> csv;

      readLines(csv_path, lines);
      parseCSV(lines, csv);
      currentTable.from_csv(csv);
      vector<string> html = currentTable.to_html();
      writeLinesToFile(html_path, html);

      cout << "CSV file " << colorfmt(fg::magenta) << csv_path << clearfmt
           << " stored in " << colorfmt(fg::magenta) << html_path << clearfmt
           << endl;
    } else {
      cout << "File " << colorfmt(fg::yellow) << csv_path << clearfmt
           << " not found" << endl;
    }
  } else {
    cout << "Please enter a valid file name." << endl;
  }
};
