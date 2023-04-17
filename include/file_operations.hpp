#include <vector>
#include <string>
#include "table.hpp"

using namespace std;

#ifndef FILE_OPERATION_HPP
#define FILE_OPERATION_HPP

Table parseCSVIntoTable(vector<string> lines);
vector<string> loadFile(string path);
string convertArrayToCSV(vector<int> array);
void storeFile(string filename);
void cloneFile();
void generateHTMLFile();

#endif