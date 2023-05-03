// Used to prevent the compiler from compiling this header file along with its
// symbols again if already done so
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <filuzzy/filuzzy.hpp>
#include <histoguzzy/histoguzzy.hpp>
#include <statsi/statsi.hpp>  // library of statistical functions to be used in program written by Mubarak
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <string>
#include <tabluzzy/tabluzzy.hpp>  // library containing a class for the Table to be used in this Program written by Mustafa
using namespace std;

/// @brief function for the input validation of the `clone` command.
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void loadFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `clone` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void storeFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `clone` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void cloneFileCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `html` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void generateHTMLCMD(vector<string>& args, Table& currentTable,
                     bool& tableLoaded);

/// @brief function for the input validation of the `min` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void minCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `max` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void maxCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `show` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void showCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `median` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void medianCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `mean` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void meanCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `variance` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void varianceCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `stdv` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void stdvCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `add` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void addCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `sub` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void subCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `corr` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void corrCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `regression` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void regressionCMD(vector<string>& args, Table& currentTable,
                   bool& tableLoaded);

/// @brief function for the input validation of the `titles` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void titlesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `report` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void reportCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `hhisto` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void hhistoCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `vhisto` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void vhistoCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `columns` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void columnsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `rows` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void rowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `sort` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void sortCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `help` command
/// Written by Azi.
void helpCMD();

/// @brief function for the input validation of the `man` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void manCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `odd` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void oddRowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `even` command
/// Written by Azi.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void evenRowsCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `primes` command
/// Written by Mubarak.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void primesCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `delete` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void deleteCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `insert` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void insertRowCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);

/// @brief function for the input validation of the `replace` command
/// Written by Mustafa.
/// @param args - reference to the command line arguments passed from main
/// @param currentTable - reference to the current table loaded into memory. Could be empty.
/// @param tableLoaded - indicates wether a table has been loaded to memory or not
void replaceCMD(vector<string>& args, Table& currentTable, bool& tableLoaded);
#endif