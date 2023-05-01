#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

#include <string>
#include <vector>

#include <fileoperations/fileoperations.hpp>
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt

using namespace std;

float calculateScale(vector<float>& values, int& width);

int calculateNumberOfUnits(float& value, float& scale);

string createRect(int width, int bgColor = bg::white);

void addHorizontalBar(string& colHeader, int& units, float& value);

void displayVerticalHistogram(vector<string>& headers, vector<float>& values);

void displayHorizontalHistogram(vector<string>& headers, vector<float>& values);

#endif