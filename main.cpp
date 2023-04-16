#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>
#include "textformat.cpp"
#include "table.cpp"
using namespace std;

void outputHelpMessage()
{
    cout << "\nCore commands\n";
    cout << setw(20) << setfill('=') << "\n";
};

// Struct to store a single column, its data and header

// Struct to store table

vector<string> splitString(string str)
{
    vector<string> output;
    string buffer = "";
    for (int x = 0; x <= str.length(); x++)
    {
        if (str[x] == ',')
        {
            output.push_back(buffer);
            buffer = "";
        }
        else if (str[x] == ' ')
        {
        }
        else
        {
            buffer += str[x];
        }
    }
    output.push_back(buffer);
    return output;
}

Table parseFile(vector<string> lines)
{
    int columns = stoi(lines[0]), rows = stoi(lines[1]);
    Table table(columns, rows); // Create new table object

    vector<string> headers = splitString(lines[2]); // Split the line containing header names and storing into vector headers

    vector<vector<string>> rawValues;
    for (int x = 4; x < rows + 4; x++)
    {
        string line = lines[x];
        // cout << x - 3 << "=" << line << endl;
        vector<string> row = splitString(line);
        rawValues.push_back(row);
    }
    for (int x = 0; x < columns; x++)
    {
        table.addNewNumColumn(headers[x]);
        for (int y = 0; y < rows; y++)
        {

            table.insertNumberIntoColumn(headers[x], 0, rawValues[y][x]);
        }
    }
    return table;
};

// Function to load file from input path and returns a vector including vector including all the data
Table loadFile(string path)
{
    fstream file;
    file.open("file.txt", ios::in);

    vector<string> lines;
    if (!file)
    {
        cout << "File not found";
    }
    else
    {
        string line;
        while (getline(file, line))
        { // read data from file object and put it into string.
            lines.push_back(line);
        };
    };
    Table table = parseFile(lines);
    return table;
};

string convertArrayToCSV(vector<int> array)
{
    string csv = "";
    return csv;
}

void storeFile(string filename){

};

void cloneFile(){

};

void generateHTMLFile(){

};

vector<string> parseArgs(string str)
{
    vector<string> output;
    string buffer = "";
    for (int x = 0; x <= str.length(); x++)
    {
        if (str[x] == ' ')
        {
            if (buffer != "")
                output.push_back(buffer);
            buffer = "";
        }
        else
        {
            buffer += str[x];
        }
    }
    output.push_back(buffer);
    return output;
}

bool cmpstr(string str1, string str2)
{
    return !strcmp(str1.c_str(), str2.c_str());
};

void outputBanner(){
    cout <<  R"(      __       __                       __         
  ___/ /____ _/ /____ _______  _______ / /____ ____
 (_-< __/ _ `/ __/ -_) __/ _ \/ __/ -_) __/ -_) __/
/___|__/\_,_/\__/\__/_/ / .__/_/  \__/\__/\__/_/   
                       /_/                         
)";
};

void outputLoadingIcon(){
  std::cout << '-' << std::flush;
    for (;;) {
        sleep(1);
        std::cout << "\b\\" << std::flush;
        sleep(1);
        std::cout << "\b|" << std::flush;
        sleep(1);
        std::cout << "\b/" << std::flush;
        sleep(1);
        std::cout << "\b-" << std::flush;
    }
}
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
                        // currentTable = loadFile(argv[2]);
                        cout << "Loaded " << colorfmt(fg::magenta) << args[1] << clearfmt << endl;

                        // printf("Loaded \e[1m\x1b[33m%s\e[0m\x1b[0m succesfully\n", args[1].c_str());
                    }
                }
                else if (cmpstr(args[0], "store"))
                {
                    storeFile(args[1]);
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

                else
                {
                    cout << "Command not recognized. Enter 'help' for a list of commands." << endl;
                };
            };
        }
    }
}
