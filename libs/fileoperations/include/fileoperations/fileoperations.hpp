#ifndef FILEOPERATIONS_HPP
#define FILEOPERATIONS_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "fileoperations.hpp"

using namespace std;


// using namespace stat;

// Function to load file from input path and returns a vector including vector
// including all the data
void readLines(string& path, vector<string>& content);

bool fileExists(string& path);

void parseCSV(vector<string>& content, vector<vector<string>>& csv);

void writeLinesToFile(string& path, vector<string>& lines);

void copyFile(string& path1, string& path2);

#endif
