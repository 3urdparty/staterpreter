#include <string>
#include<vector>
using namespace std;

#ifndef COLUMN_H
#define COLUMN_H

enum Datatype
{
    str = 0,
    flt = 1
};

class Column // Class for column datastructure that stores 'float' values
{

public:
    Column(string columnName, Datatype type);
    ~Column();
    string getValueAt(unsigned int rowNo);            // gets value at row number 'rowNo'
    void setValueAt(unsigned int rowNo, float value); // sets the value of row at 'rowNo' to float value of 'value'
    string getHeader();
    // float getMin();                                   // finds the minimum value in the column and returns it
    // float getMax();                                   // finds the maxmimum value in the column and returns it
    // float getMedian();                                // finds the median value of the values in the column
    // float getMean();                                  // finds the mean of the values in the column
    // float getVariance();                              // finds the variance of the values in the column
    // float getStdDev();                                // Finds the value of standard deviation of the values in the column

private:
    string header;
    vector<string> rows;
    Datatype type;
};
#endif