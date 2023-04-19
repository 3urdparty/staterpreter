#include "utilities.hpp"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
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

tuple<int, int> getTerminalDimensions() {
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  return {w.ws_col, w.ws_row};
};

float getMin(vector<float>& values) {
  int index;
  float minVal = values[0];
  for (int x = 0; x < values.size() - 1; x++) {
    if (min(values[x], values[x + 1]) < minVal) {
      index = x;
      minVal = min(values[x], values[x + 1]);
    }
  };
  return minVal;
}

float getMax(vector<float>& values) {
  int index;
  float maxVal = values[0];
  for (int x = 0; x < values.size() - 1; x++) {
    if (max(values[x], values[x + 1]) > maxVal) {
      index = x;
      maxVal = max(values[x], values[x + 1]);
    }
  };
  return maxVal;
}

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
float calculateMedian(vector<float> values) {
  int n = values.size();
  float median;
  sort(values.begin(), values.end());

  if (n % 2 == 0) {
    median = (values[n / 2 - 1] + values[(n / 2)]) / 2.0f;
  } else {
    median = values[n / 2];
  }
  return median;
};
float calculateMean(vector<float>& values) {
  return calculateSum(values) / float(values.size());
};

float calculateSum(vector<float>& values) {
  float sum;
  for (int n = 0; n < values.size(); n++) {
    sum += values[n];
  }
  return sum;
};

float calculateVariance(vector<float>& values) {
  // σ2 = ∑ (x − x̅)^2 / n
  float sum;
  float mean = calculateMean(values);
  for (int n = 0; n < values.size(); n++) {
    sum += pow((values[n] - mean), 2);
  };
  return sum / 2.f;
};

float calculateStandardDeviation(vector<float>& values) {
  float variance = calculateVariance(values);
  return sqrt(variance);
};

float calculateCorrelation(vector<float>& col1_values,
                           vector<float>& col2_values) {
  float sum1;
  float sum2;
  float sum3;
  float mean1 = calculateMean(col1_values);
  float mean2 = calculateMean(col2_values);
  for (int i = 0; i < col1_values.size(); i++) {
    sum1 += ((col1_values[i] - mean1) * (col2_values[i] - mean2));
    sum2 += pow((col1_values[i] - mean1), 2);
    sum3 += pow((col2_values[i] - mean2), 2);
  };
  return ((sum1) / (sqrt(sum2 * sum3)));
}

tuple<float, float> calculateRegression(vector<float>& values) {
  vector<float> indices;
  for (int x = 0; x < values.size(); x++) {
    indices.push_back(x);
  };

  float r = calculateCorrelation(indices, values);
  float stdx = calculateStandardDeviation(indices);
  float stdy = calculateStandardDeviation(values);

  float b = r * (stdx / stdy);

  float meanx = calculateMean(indices);
  float meany = calculateMean(values);
  float yIntercept = meany - b * (meanx);

  return tuple(yIntercept, b);
};

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

bool isPrime(int number) {
  for (int x = 2; x < number / 2; x++) {
    if (number % x == 0) {
      return false;
    }
  }
  return true;
}

bool stringIsFloat(string str) {
  str = sanitizeString(str);
  istringstream iss(str);
  float f;
  iss >> noskipws >> f;
  return iss.eof() && !iss.fail();
};
// https://stackoverflow.com/questions/447206/c-isfloat-function