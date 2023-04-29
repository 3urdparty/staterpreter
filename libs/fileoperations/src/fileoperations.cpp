#include "fileoperations.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
#include <strfmt/strfmt.hpp>

// using namespace stat;

// Function to load file from input path and returns a vector including vector
// including all the data
void readLines(string& path, vector<string>& content) {
  fstream file;
  file.open(path, ios::in);

  if (!file) {
    cout << "File not found";
  } else {
    string line;
    while (getline(
        file, line)) {  // read data from file object and put it into string.
      content.push_back(line);
    };
  };
};

bool fileExists(string& path) {
  ifstream f(path.c_str());
  return f.good();
};

void parseCSV(vector<string>& content, vector<vector<string>>& csv) {
  for (string line : content) {
    vector<string> csv_entry = splitString(line, ',');
    for (int x = 0; x < csv_entry.size(); x++) {
      csv_entry[x] = sanitizeString(csv_entry[x]);
    };
    csv.push_back(csv_entry);
  }
};

void writeLinesToFile(string& path, vector<string>& lines) {
  fstream file;
  file.open(path, ios::out);

  for (string line : lines) {
    // string line = entry;
    file << line.c_str() << endl;
  };
};

void copyFile(string& path1, string& path2) {
  vector<string> lines;
  readLines(path1, lines);
  writeLinesToFile(path2, lines);
};