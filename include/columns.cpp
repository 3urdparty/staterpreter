#include "columns.hpp"

#include <iomanip>
#include <iostream>
#include <string>

#include "textformat.hpp"
#include "utilities.hpp"
using namespace std;

Column::Column(string h, ValueType t) {
  header = h;
  type = t;
};

Column::~Column(){

};

void Column::setValueAt(unsigned int rowNo, string value) {
  rows.push_back(value);
};

void Column::displayColumn() {
  auto [w, h] = getTerminalDimensions();

  cout << endl;
  cout << "+" << setfill('=') << setw(15) << "" << setw(1) << setfill(' ')
       << "+" << endl;

  cout << "|";

  cout << bold << colorfmt(fg::green) << getHeader() << left << setw(8) << "\t"
       << clearfmt << " |" << endl;

  for (int y = 0; y < rows.size(); y++) {
    cout << "|";

    if (type == ValueType::flt) {
      cout << setw(8) << setfill(' ') << setprecision(0) << left << fixed
           << stof(rows[y]) << "\t"
           << "|";
    } else if (type == ValueType::str) {
      cout << setw(8) << setfill(' ') << setprecision(0) << left << fixed
           << rows[y] << "\t"
           << "|";
    }

    cout << endl;
  };
  cout << "+" << setfill('=') << setw(15) << "" << setw(1) << setfill(' ')
       << "+" << endl;
};

string Column::getHeader() { return header; };

string Column::getValueAt(unsigned int rowNo) { return rows[rowNo]; }

void Column::setValueType(ValueType dttype) { type = dttype; };

int Column::getIndex() { return index; };

void Column::setHeader(string h) { header = h; };
void Column::setIndex(unsigned int i) { index = i; };

ValueType Column::getValueType() { return type; };

float Column::getMinimumValue() {
  vector<float> rawValues = convertStrToFloats(rows);
  return getMin(rawValues);
};

float Column::getMaximumValue() {
  vector<float> rawValues = convertStrToFloats(rows);
  return getMax(rawValues);
};

float Column::getMedian() {
  vector<float> values = convertStrToFloats(rows);
  return calculateMedian(values);
};
float Column::getMean() {
  vector<float> values = convertStrToFloats(rows);
  return calculateMedian(values);
};
float Column::getVariance() {
  vector<float> values = convertStrToFloats(rows);
  return calculateVariance(values);
};
float Column::getStdDeviation() {
  vector<float> values = convertStrToFloats(rows);
  return calculateStandardDeviation(values);
};

vector<string> Column::getAllValues() {
  vector<string> values;
  for (int x = 0; x < rows.size(); x++) {
    values.push_back(rows[x]);
  };
  return values;
};
