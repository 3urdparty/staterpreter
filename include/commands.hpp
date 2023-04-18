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
void addCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void subCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void corrCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void regressionCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded);
void titlesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void reportCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void hhistoCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void vhistoCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void columnsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void rowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
void sortCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
#endif