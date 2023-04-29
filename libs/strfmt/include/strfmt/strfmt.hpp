#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

vector<string> splitString(string str, char delimiter);
bool cmpstr(string str1, string str2);


string join(vector<string>& strings, string delimiter);
vector<string> convertFloatsToStrs(vector<float>& values);
vector<float> convertStrToFloats(vector<string>& strings);
bool stringIsFloat(string str);
string sanitizeString(string str);
vector<string> sanitizeStrings(vector<string> strings);
vector<string> convertToStrings(vector<int> numbers);
vector<int> convertToInts(vector<string> strings);

void readLines(string& path, vector<string>& content);

void parseCSV(vector<string>&, vector<vector<string> >&);
bool fileExists(string& path);
void writeLinesToFile(string& path, vector<string>& csv);
void copyFile(string& path1, string& path2);

extern string clearfmt;
extern string bold;
string colorfmt(int fgcolor, int bgcolor = 0);

namespace bg {
extern int black;
extern int red;
extern int green;
extern int yellow;
extern int blue;
extern int magenta;
extern int cyan;
extern int white;
};  // namespace bg

namespace fg {
extern int black;
extern int red;
extern int green;
extern int yellow;
extern int blue;
extern int magenta;
extern int cyan;
extern int white;

};  // namespace fg

#endif
