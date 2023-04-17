#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <variant>

using namespace std;
// Namespace for use in this application

#include "columns.hpp"
// Class declaration for Table
class Table {
 private:
  unsigned int columns, rows;
  vector<Column> data;

 public:
  Table(unsigned int columns, unsigned int rows);
  Table();
  ~Table();

  void addColumn(string header,
                 ValueType dttype);  // Creates new column with header 'header'
                                     // and appends it to the list of columns
  void removeColumn(string header);  // Removes column with header 'header'

  bool columnExists(string header);

  Column& operator[](size_t i);
  Column operator[](const size_t i) const;

  Column& getColumnByHeader(string i);

  // void setValueAt(string header, unsigned int rowNo, string val);
  string getValueAt(string header, unsigned int rowNo);
  string getValueAt(int colIndex, unsigned int rowNo);

  vector<string> getAllColumnHeaders();

  void displayTable() const;
  vector<string> to_csv();

  void from_csv(vector<vector<string>>&);

  float getMinimumValue();
  float getMaxiumValue();
  float getMedian();
  float getMean();
  float getVariance();
  float getStdDeviation();
  vector<string> getAllValues();

  vector<string> to_html();
};

#endif
