#include<string>
#include "columns.hpp"
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
