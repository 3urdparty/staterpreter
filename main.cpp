#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>
#include <variant>
using namespace std;

void outputHelpMessage()
{
    cout << "Help message here" << endl;
};

// Struct to store a single column, its data and header
struct Column
{
    string header;
    vector<variant<float, string>> values;
};

// Struct to store table
struct Table
{
    vector<Column> columns;
};

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
    Table table;
    return table;
};

// Function to load file from input path and returns a vector including vector including all the data
Table loadFile(string path)
{
    Table table;
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
    return parseFile(lines);
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

int main(int argc, char const *argv[])
{
    // if (argc == 1) outputHelpMessage() ; return 0;

    if (!strcmp(argv[1], "load"))
    {
        if (argc == 3)
            loadFile(argv[2]);
        return 0;
        return -1;
    }
    if (!strcmp(argv[1], "store"))
    {
        storeFile(argv[2]);
        return 0;
    }
    if (!strcmp(argv[1], "clone"))
        cloneFile();
    return 0;
    if (!strcmp(argv[1], "html"))
        generateHTMLFile();
    return 0;

    cout << "Command not recognized!" << endl;
    return 1;
}
