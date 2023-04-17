
#ifndef COLUMN_H
#define COLUMN_H

#include <string>
#include <variant>
#include <vector>
using namespace std;

enum ValueType { str = 0, flt = 1 };

class Column {
 public:
  Column(string columnName, ValueType dttype);
  ~Column();

  string getValueAt(unsigned int rowNo);  // gets value at row number 'rowNo'
  void setValueAt(unsigned int rowNo,
                  string value);  // sets the value of row at 'rowNo' to float
                                  // value of 'value'

  void setHeader(string header);
  string getHeader();

  void setIndex(unsigned int i);
  int getIndex();

  void setValueType(ValueType);
  ValueType getValueType();

  void displayColumn();

  float getMinimumValue();
  float getMaximumValue();
  float getMedian();
  float getMean();
  float getVariance();
  float getStdDeviation();
  vector<string> getAllValues();

 private:
  int index;
  string header;
  vector<string> rows;
  ValueType type;
};

#endif