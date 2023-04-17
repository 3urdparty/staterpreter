#ifndef FILE_OPERATION_HPP
#define FILE_OPERATION_HPP

#include <string>
#include <vector>

using namespace std;

void readLines(string& path, vector<string>& content);

void parseCSV(vector<string>&, vector<vector<string>>&);
bool fileExists(string& path);
void cloneFile();
void generateHTMLFile();
void writeLinesToFile(string& path, vector<string>& csv);
void copyFile(string& path1, string& path2);
#endif