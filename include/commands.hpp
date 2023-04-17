#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <string>

#include "table.hpp"
using namespace std;

void loadFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void storeFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void cloneFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void generateHTMLCMD(vector<string>& args, Table& currentTable,
                     bool& tableLoaded);
void minCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void maxCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void showCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void medianCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void meanCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void varianceCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void stdvCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

#endif