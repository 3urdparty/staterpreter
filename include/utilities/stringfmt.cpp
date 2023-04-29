#include "utilities.hpp"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

string sanitizeString(string str) {
  str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());

  return str;
}

vector<string> sanitizeStrings(vector<string> strings) {
  for (int x = 0; x < strings.size(); x++) {
    strings[x] = sanitizeString(strings[x]);
  }
  return strings;
}
vector<string> splitString(string str, char delimiter) {
  vector<string> output;
  string buffer;
  for (int x = 0; x < str.length(); x++) {
    if (str[x] == delimiter) {
      output.push_back(buffer);
      buffer = "";
    } else {
      buffer += str[x];
    }
  }
  if (!cmpstr(buffer, "")) output.push_back(buffer);
  return output;
}

bool cmpstr(string str1, string str2) {
  return !strcmp(str1.c_str(), str2.c_str());
};



vector<string> convertToStrings(vector<int> numbers) {
  vector<string> strings;
  for (int num : numbers) {
    strings.push_back(to_string(num));
  };
  return strings;
}

vector<int> convertToInts(vector<string> strings) {
  vector<int> values;
  for (string str : strings) {
    values.push_back(stoi(str));
  };
  return values;
}

vector<float> convertStrToFloats(vector<string>& strings) {
  vector<float> values;
  for (string str : strings) {
    values.push_back(stof(str));
  };
  return values;
}

vector<string> convertFloatsToStrs(vector<float>& values) {
  vector<string> rawValues;
  for (float val : values) {
    rawValues.push_back(to_string(val));
  };
  return rawValues;
}

string join(vector<string>& strings, string delimiter) {
  string output;
  if (strings.size() == 0) {
    return output;
  } else {
    for (int x = 0; x < strings.size() - 1; x++) {
      output += strings[x] + delimiter;
    };
    output += strings[strings.size() - 1];
    return output;
  }
};



bool stringIsFloat(string str) {
  str = sanitizeString(str);
  istringstream iss(str);
  float f;
  iss >> noskipws >> f;
  return iss.eof() && !iss.fail();
};
// https://stackoverflow.com/questions/447206/c-isfloat-function