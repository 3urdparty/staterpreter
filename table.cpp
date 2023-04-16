#include <iostream>
#include "table.h"
#include <variant>
#include <iomanip>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <tuple>
#include <utility>
using namespace stat;
using namespace std;

Column::Column(string h, Datatype t)
{
    header = h;
    type = t;
};

Column::~Column(){

};

void Column::setValueAt(unsigned int rowNo, float value)
{
    rows.push_back(to_string(value));
};

string Column::getHeader()
{
    return header;
};

string Column::getValueAt(unsigned int rowNo)
{
    return rows[rowNo];
}

Table::Table(unsigned int col, unsigned int row)
{
    columns = col;
    rows = row;
};

Table::~Table(){};

string Table::getRawValueAt(unsigned int x, unsigned int y)
{
    Column ncol = data[x];
    // string rawValue = ncol.getValueAt(y);
    string rawValue = "";
    return rawValue;
};

/// @brief Function that gets the index number of the column with the header 'header' from the columnindex
/// @param header
/// @return column_index
int Table::getColumnIndexFromHeader(string header)
{
    for (pair<string, int> entry : columnIndex)
    {
        if (entry.first == header)
        {
            return entry.second;
        };
    };
    return -1;
};

/// @brief Method that adds a new column to the table, and adds a record to the columnIndex
/// @param header
void Table::addNewNumColumn(string header)
{
    Column newCol(header, flt);

    pair<string, int> newColIndex(header, size(columnIndex));
    columnIndex.push_back(newColIndex);
    data.push_back(newCol);
};

/// @brief Removes column from table, including its data and their records
/// @param header
void Table::removeColumn(string header)
{
    int i = getColumnIndexFromHeader(header);
    // data.erase(i);
    // columnIndex.erase(columnIndex);
};

void Table::insertNumberIntoColumn(string header, unsigned int rowNo, string value)
{
    int index = getColumnIndexFromHeader(header);
    float num = stod(value);

    data[index].setValueAt(rowNo, num);
};

void Table::insertStringIntoColumn(string header, unsigned int rowNo, string value){
    // int index = getColumnIndexFromHeader(header);
    // data[index].set(rowNo, num);
};

float Table::getNumValueAt(string header, unsigned int rowNo)
{
    int colNo = getColumnIndexFromHeader(header);
    string rawValue = getRawValueAt(colNo, rowNo);
    return stof(rawValue);
};

string Table::getStrValueAt(string header, unsigned int rowNo)
{
    int colNo = getColumnIndexFromHeader(header);
    string rawValue = getRawValueAt(colNo, rowNo);
    return rawValue;
};

tuple<int, int> getTerminalDimensions()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row};
};

void Table::displayTable()
{
    auto [w, h] = getTerminalDimensions();


    cout << endl;
    for (int x = 0; x < 5; x++)
    {
        cout  << "\e[1m\x1b[32m" << data[x].getHeader() << left << setw(8) << setfill(' ') << "\t" << "\e[0m\x1b[0m" ;
    };
  
    cout << "" << endl;
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            cout << setw(8) << setfill(' ')
                 << setprecision(0) << left << fixed
                 << stof(data[x].getValueAt(y)) << "\t";
        }
        cout << endl;
    };
};
