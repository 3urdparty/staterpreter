#include <filuzzy/filuzzy.hpp>
#include <iomanip>
#include <iostream>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
#include <vector>

#include "commands.hpp"  // Header file for all the interpreter commands for staterpreter

using namespace std;
void deleteCMD(vector<string>& args, Table& currentTable, bool& tableLoaded) {
  // Checks if the table has been loaded into the program
  if (tableLoaded) {
    // Checks if more than 1 command line argument has been passed to delete
    if (args.size() >= 2) {
      // If the first argument is "occurrence"
      if (cmpstr(args[1], "occurrence")) {
        // It will check if we passed 4 command line arguments
        if (args.size() == 4) {
          // It will get the column header as well as the value to be deleted
          // from the args
          string colHeader = args[2], value = args[3];

          // if the column exists in the current table object
          if (currentTable.columnExists(colHeader)) {
            // we initialize a variable that counts the number of rows deleted
            int rows_deleted = 0;
            // We initialize rowIndex to the the index of the first row to be
            // deleted that has the value the user has inputted
            int rowIndex = currentTable.getRowIndexOfFirstOccurrence(
                colHeader,
                value);  // Using this function which will return the index of
                         // the first match, -1 if there is none
                         // it will continue while there is more matches
            while (rowIndex != -1) {
              //  increment the number of rows deleted
              rows_deleted++;

              // delete the row at index rowIndex using the Table method
              // deleteRow
              currentTable.deleteRow(rowIndex);
              // it then gets the index of the next row to delete
              rowIndex =
                  currentTable.getRowIndexOfFirstOccurrence(colHeader, value);
            }
            // If the number of rows deleted is -
            if (rows_deleted == 0)
              // output an appropriate message to user
              cout << "No matches were found in " << colorfmt(fg::blue)
                   << colHeader << endl;
            cout << colorfmt(fg::magenta) << rows_deleted << clearfmt
                 << " rows deleted" << endl;

          } else {
            // However if the column was not found
            cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
                 << clearfmt << " not found" << endl;
          }
        } else if (args.size() > 4) {
          // if the user has inputted more than 3 command line arguments
          cout << "Please enter only one occurrence" << endl;
        } else {
          // if the user has inputted less than 3 command line arguments
          cout << "Please enter a column to delete matches in" << endl;
        }
      } else if (cmpstr(args[1], "row")) {
        // If the user has inputted 2 command line arguments
        if (args.size() == 3) {
          // we get the index of the row to be deleted and convert it to int
          int rowIndex = stoi(args[2]);
          // if the row index points to a row that exists in the current table
          if (rowIndex <= currentTable.getNumberOfRows()) {
            // it goes on to delete this row by its index using the deleteRow
            // method in the Table class
            currentTable.deleteRow(rowIndex);
            // ouptut appropriate message
            cout << "Row " << colorfmt(fg::yellow) << rowIndex << clearfmt
                 << " has been deleted" << endl;

          } else {
            // however if the row does not exist
            cout << "Row " << colorfmt(fg::yellow) << rowIndex << clearfmt
                 << " does not exist, please try again." << endl;
          }
          // if the user has inputted more than 2 command line arguments
        } else if (args.size() > 3) {
          // Output help message
          cout << "Please input one row at a time" << endl;
        } else {
          cout << "Please enter a row to delete" << endl;
        }
      } else if (cmpstr(args[1], "column")) {
        // however if the user has chosen to delete a whole column
        if (args.size() == 3) {
          // we get the column header from the list of arguments
          string colHeader = args[2];

          // if the colujmn exists in the table
          if (currentTable.columnExists(colHeader)) {
            // delete that column by its header
            currentTable.deleteColumn(colHeader);

            // output done message
            cout << "Column  " << colorfmt(fg::magenta) << colHeader << clearfmt
                 << " was successfully deleted" << endl;

            // However if it doesnt exist
          } else {
            // output appropriate message
            cout << "Sorry, column " << colorfmt(fg::magenta) << colHeader
                 << clearfmt << " not found" << endl;
          }

          // if the user has not inputted a column to be deleted
        } else if (args.size() < 3) {
          // output appropriate message

          cout << "Please input a column to be deleted" << endl;
          // if the user has input more arguments than expected
        } else {
          cout << "Please only input one column to be deleted" << endl;
        }
      } else {
        // ask user to select an instance to delete
        cout << "Please select an instance to delete (occurrence|row|column)"
             << endl;
      }
    } else {
      // if the user has not specified what he wants to delete
      cout << "Please specify what you want to to delete "
              "(Occurrence/Row/Column)"
           << endl;
    }
  } else {
    // if a tables has not been loaded into the program by user
    cout << "Please load a table first" << endl;
  };
}
