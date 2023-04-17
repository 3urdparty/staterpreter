#include "utilities.hpp"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

vector<string> splitString(string str) {
  vector<string> output;
  string buffer = "";
  for (int x = 0; x <= str.length(); x++) {
    if (str[x] == ',') {
      output.push_back(buffer);
      buffer = "";
    } else if (str[x] == ' ') {
    } else {
      buffer += str[x];
    }
  }
  output.push_back(buffer);
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
    if (min(values[x], values[x + 1]) > maxVal) {
      index = x;
      maxVal = max(values[x], values[x + 1]);
    }
  };
  return maxVal;
}

vector<float> convertStrToFloats(vector<string>& strings) {
  vector<float> values;
  for (string str : strings) {
    values.push_back(stof(str));
  };
  return values;
}

float calculateMedian(vector<float>& values) {
  int n = values.size();
  float median;
  if (n % 2 == 0) {
    median = (values[n / 2] + values[(n / 2) + 1]) / 2;
  } else {
    median = values[(n + 1) / 2];
  }
  return median;
};
float calculateMean(vector<float>& values) {
  return calculateSum(values) / values.size();
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
  for (int n = 0; n < values.size(); n++) {
    sum += pow((values[n] - abs(values[n])), 2);
  };
  return sum / 2;
};

float calculateStandardDeviation(vector<float>& values) {
  float variance = calculateVariance(values);
  return sqrt(variance);
};