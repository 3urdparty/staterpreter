
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
  string& operator[](size_t rowNo);
  string operator[](const size_t rowNo) const;

  string getValueAt(unsigned int rowNo);  // gets value at row number 'rowNo'
  void setValueAt(unsigned int rowNo,
                  string value);  // sets the value of row at 'rowNo' to float
                                  // value of 'value'

  void setHeader(string header);
  string getHeader();
  vector<int> getPrimes();
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
  void pushValue(string value);
  float getStdDeviation();
  tuple<float, float> getRegression();
  vector<string> getAllValues();
  void deleteOccurrenceInColumn(int value);
  void deleteOccurrenceInColumn(string value);
 private:
  int index;
  string header;
  vector<string> rows;
  ValueType type;
};

#endif