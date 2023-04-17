#include <string>
#include <variant>
#include "columns.hpp"

using namespace std;
// Namespace for use in this application
#ifndef TABLE_H
#define TABLE_H
// Class declaration for Table
class Table
{
private:
    unsigned int columns, rows;
    vector<Column> data;
    string getRawValueAt(unsigned int x, unsigned int y); // gets string representation of value at column x, row y
    vector<pair<string, int>> columnIndex;

public:
    Table(unsigned int columns, unsigned int rows);
    ~Table();
    void addNewNumColumn(string header); // Creates new column with header 'header' and appends it to the list of columns
    void removeColumn(string header);    // Removes column with header 'header'
    void insertNumberIntoColumn(string header, unsigned int rowNo, string val);
    void insertStringIntoColumn(string header, unsigned int rowNo, string value);
    float getNumValueAt(string header, unsigned int rowNo);
    string getStrValueAt(string header, unsigned int rowNo);
    int getColumnIndexFromHeader(string header);
    void displayTable();
    string convertToCSV();
};

#endif
