#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <array>

#include "table.cpp"
using namespace std;

void outputHelpMessage()
{
    cout << "Help message here" << endl;
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
    Table table(rows, columns);
    
    vector<string> headers = splitString(lines[2]);


    
    vector<vector<string>> rawValues;
    for(int x = 4; x < rows + 4; x++) {
        string line = lines[x];
        // cout << x - 3 << "=" << line << endl;
        vector<string> row = splitString(line);
        rawValues.push_back(row);
    }
    for(int x = 0; x < columns; x++) {
        string header = headers[x];
        vector<string> &newCol = table.createNewColumn(header);
        for (int y = 0; y < rows; y++){
            cout << newCol[0][1] << endl;
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
