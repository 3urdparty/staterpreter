#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

vector<string> splitString(string str);
bool cmpstr(string str1, string str2);
tuple<int, int> getTerminalDimensions();

float getMin(vector<float>& values);
float getMax(vector<float>& values);

vector<float> convertStrToFloats(vector<string>& strings);
float calculateMedian(vector<float> values);
float calculateSum(vector<float>& values);
float calculateMean(vector<float>& values);
float calculateVariance(vector<float>& values);
float calculateStandardDeviation(vector<float>& values);
float calculateCorrelation(vector<float>& col1_values,
                           vector<float>& col2_values);
tuple<float, float> calculateRegression(vector<float>& values);
string join(vector<string>& strings, string delimiter);
vector<string> convertFloatsToStrs(vector<float>& values);
#endif