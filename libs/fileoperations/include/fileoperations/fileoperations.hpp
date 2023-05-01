#ifndef FILEOPERATIONS_HPP
#define FILEOPERATIONS_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>



using namespace std;

/// @brief Function that reads lines from a file at location `path` and adds
/// each line to vector `content`
/// @param path - The path of the file to read from
/// @param content - vector of strings representing the lines of the file
void readLines(string& path, vector<string>& content);

/// @brief Function that checks if file exists at path
/// @param path - The path of the file to check
/// @return a bool representing wether the file exists or not
bool fileExists(string& path);

/// @brief Function that parses a vector of lines of a file and parses each line
/// into a 2D vector of strings `csv`
/// @param content
/// @param csv
void parseCSV(vector<string>& content, vector<vector<string>>& csv);

/// @brief Function that writes each line in vector of strings `lines` to file
/// at `path`
/// @param path - The path of the file to write to
/// @param lines - The vector of lines to write
void writeLinesToFile(string& path, vector<string>& lines);

/// @brief Function that reads the file at `path1` and writes it to a new file
/// at `path2`
/// @param path1 - The path of the file to read from
/// @param path2 - The path of the file to write to
void copyFile(string& path1, string& path2);

#endif
