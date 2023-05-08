// #include <curses.h>s
#include <filuzzy/filuzzy.hpp>
#include <histoguzzy/histoguzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>
#include <terminalcancer/terminalcancer.hpp>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter



using namespace std;
void vhistoCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // if the number of arguments is 0
    if (args.size() < 2) {
      // prompt the user to input a column to display
      cout << "Please enter a column to display the vertical Histogram for"
           << endl;
      // if the number of argumnets is 1
    } else if (args.size() == 2) {
      // get the column header from args
      string colHeader = args[1];

      // if the column exists in the current table
      if (currentTable.columnExists(colHeader)) {
        // we get the column
        Column col = currentTable.getColumnByHeader(colHeader);
        // if the column is of type string
        if (col.getValueType() == ValueType::str) {
          // we output an appropriate error message
          cout << colorfmt(fg::red) << "Error: " << clearfmt
               << "The column you have selected contains values of type "
               << colorfmt(fg::white) << "string" << clearfmt << endl
               << "Please select another column." << endl;
          // however if the column contains numerical values
        } else {
          // we get all the values in that column
          vector<string> rawValues = col.getAllValues();
          // we convert each value in that column to floats
          vector<float> y_values = convertToFloats(rawValues);

          // we then initialize an empty vector of string
          vector<string> x_values;
          // to store the text for each row
          for (int x = 1; x <= y_values.size(); x++) {
            string x_val = "Row " + to_string(x);
            x_values.push_back(x_val);
            cout << rawValues[x] << " ";
          }
          // display the vertical histogram
          int num_of_rows_in_page = 10;
          int max_pages = (y_values.size() / num_of_rows_in_page) +
                          (y_values.size() % num_of_rows_in_page == 0 ? 0 : 1);
          int current_page = 0;

          char input;
          while (input != 'q') {
            // char c;
            vector<string> page_headers(
                x_values.begin() + current_page * num_of_rows_in_page,
                x_values.begin() + (current_page + 1) * num_of_rows_in_page);
            vector<float> page_values(
                y_values.begin() + current_page * num_of_rows_in_page,
                y_values.begin() + (current_page + 1) * num_of_rows_in_page);
            displayVerticalHistogram(page_headers, page_values);
            cout << "[<-] previous page, [->] next page, [q] quit" << endl<< endl;
            input = getche();
string clear_terminal = R"(printf "\33c\e[3J")";
            system(clear_terminal);
            switch (input) {
              case 67:
                if (current_page < max_pages - 1) current_page++;
                break;
              case 68:
                if (current_page > 0) current_page--;
                break;
            }

            // char input = getch();
          }
        }
        // if the column does not exist
      } else {
        // we output an appropriate message
        cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
             << clearfmt << " not found" << endl;
      }
      // if the user inputs more than one column
    } else {
      // we output an appropriate message
      cout << "Please enter one column at a time" << endl;
    };
    // if the user inputs more than one column
  } else {
    // we output an appropriate message
    cout << "Please load a table first" << endl;
  }
};
