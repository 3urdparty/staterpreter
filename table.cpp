#include<iostream>
#include"table.h"
using namespace stat;
using namespace std;

Table::Table(unsigned int col, unsigned int row)
{
    columns = col;
    rows = row;
};

Table::~Table()
{
};