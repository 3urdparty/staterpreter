

#include "fileoperations.hpp"  // header file for the `fileoperations` library functions

#include <fstream>
#include <iostream>
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <string>
#include <tuple>
#include <vector>
using namespace std;

void readLines(string& path, vector<string>& content) {
  // creates object fstream
  fstream file;

  // to open file at path to read from
  file.open(path, ios::in);

  // Checks if file exists
  if (file) {
    // Declares a string to store each line of file
    string line;

    // Continue as long as getline() returns a value that is not 0 (effectively
    // continuing until the end of the file and there is no more lines to read
    // from file)
    // if data is read, its stored in line
    while (getline(file, line)) {
      // If a line was read into line, then add it to the vector of strings
      // `content`
      content.push_back(line);
    };
  }
};

bool fileExists(string path) {
  // Creates an instance of object ifstream and use it to open file a path
  // We convert path to char * (Array of chars) using method c_str() since
  // ifstream object cannot be constructed using a string, but rather an array
  // of chars
  ifstream f(path.c_str());

  // Returns a boolean depending wether the file exists or not
  return f.good();
};

void parseCSV(vector<string>& content, vector<vector<string>>& csv) {
  // Iterates through every string in content
  for (string line : content) {
    // And splits each line based on the ',' delimiter using function
    // splitString found in out strfmt library
    vector<string> csv_entry = splitString(line, ',');

    // Iterates again through each string in the vector of split strings
    for (int x = 0; x < csv_entry.size(); x++) {
      // and sanitizes it (removes leading and trailing whitespaces)
      csv_entry[x] = sanitizeString(csv_entry[x]);
    };

    // After sanitizing it adds it to the 2D vector of strings `csv`
    csv.push_back(csv_entry);
  }
};

void writeLinesToFile(string& path, vector<string>& lines) {
  // Instantiates an object of type ofstream that opens the file at `path`
  ofstream file(path);

  // If the file is open..
  if (file.is_open()) {
    // function iterates though every line in lines
    for (string line : lines) {
      // and writes line to file (we first convert the string line to an array
      // of characters using the method c_str())
      file << line.c_str() << endl;
    };

    // Error checking not performed here, as it is a function that only writes
    // to a file file existence and other checks done by fileExists() and called
    // before writing to file by the main program
    file.close();
  };

  void copyFile(string & path1, string & path2) {
    // declare a vector of strings `lines`
    vector<string> lines;

    // using function readLines we read the lines from the file and add it to
    // lines
    readLines(path1, lines);

    // using writeLinesToFile we write the lines in lines to the file at the
    // second location
    writeLinesToFile(path2, lines);
  };