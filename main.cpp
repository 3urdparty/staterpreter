#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>
#include "include/textformat.hpp"
#include "include/table.hpp"
#include "include/prompt.hpp"
#include "include/utilities.hpp"
#include "include/file_operations.hpp"
using namespace std;

// Struct to store a single column, its data and header

// Struct to store table
int main(int argc, char const *argv[])
{
    system("clear");
    Table currentTable = Table(0, 0);
    outputBanner();
    while (true)
    {
        cout << colorfmt(32) << "sttrprter"
             << clearfmt << " >> " << flush;
        string command;
        getline(cin, command);
        vector<string> args = parseArgs(command); // list of arguments passed to the prompt

        if (args.size() >= 1)

        {
            if (!strcmp(args[0].c_str(), "exit"))
            {
                cout << "Bye!" << endl;
                return 0;
            }
            else
            {
                if (cmpstr(args[0], "load"))
                {
                    if (args.size() >= 2)
                    {
                        vector<string> lines = loadFile(args[1]);
                        currentTable = parseCSVIntoTable(lines);
                        cout << "Loaded " << colorfmt(fg::magenta) << args[1] << clearfmt << endl;
                    }
                }
                else if (cmpstr(args[0], "store"))
                {
                    if (args.size() >= 2)
                    {
                        // string csv = convertArrayToCSV(currentTable);
                        // storeFile(args[1], csv);
                    }
                }
                else if (cmpstr(args[0], "clone"))
                {
                    cout << "Cloning file" << endl;
                    cloneFile();
                }
                else if (cmpstr(args[0], "html"))
                {
                    generateHTMLFile();
                }
                else if (cmpstr(args[0], "help"))
                {
                    outputHelpMessage();
                }
                else if (cmpstr(args[0], "clear"))
                {
                    system("clear");
                }
                else if (cmpstr(args[0], "show"))
                {
                    currentTable.displayTable();
                }
                else
                {
                    cout << "Command not recognized. Enter 'help' for a list of commands." << endl;
                };
            };
        }
    }
}
