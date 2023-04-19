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

  bool columnExists(string header);

  Column& operator[](size_t i);
  Column operator[](const size_t i) const;

  Column& getColumnByHeader(string i);

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

  void displayReport();
  int getNumberOfRows();
  int getNumberOfColumns();
  void displayVerticalHistogram();
  void displayHorizontalHistogram();
  bool canBeInsertedIntoTable(vector<string> values);

  void sortColumnsByColumn(string& colHeader);

  void deleteRow(int& rowNo);
  void deleteColumn(string& colHeader);
  void insertRowAtIndex(vector<string>& rawValues, int rowIndex);
  void replaceEveryInstance(string& valToBeReplaced, string& valToReplace);
  void replaceEveryInstanceInColumn(string& colHeader, string& valToBeReplaced,
                                    string& valToReplace);
  vector<string> to_html();
  void sortTableByColumn(string& colHeader);
  void swapTablRows(int rowIndex1, int rowIndex2);
  vector<string> getAllValuesInRow(int rowNo);
  int getRowIndexOfFirstOccurrence(string& colHeader, string value);
  int getRowIndexOfFirstOccurrence(string& colHeader, int value);
  void flushTable();
};
#endif
