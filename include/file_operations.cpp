#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include "table.hpp"
#include "prompt.hpp"
#include "utilities.hpp"
// using namespace stat;

Table parseCSVIntoTable(vector<string> lines)
{   
    int columns = stoi(lines[0]), rows = stoi(lines[1]);
    Table table(0,0); // Create new table object

    vector<string> headers = splitString(lines[2]); // Split the line containing header names and storing into vector headers

    vector<vector<string>> rawValues;
    for (int x = 4; x < rows + 4; x++)
    {
        string line = lines[x];
        vector<string> row = splitString(line);
        rawValues.push_back(row);
    }


    for (int x = 0; x < size(rawValues); x++)
    {
        table.addNewNumColumn(headers[x]);
        for (int y = 0; y < size(rawValues[x]) ; y++)
        {
        // cout << x << ", " << y << endl;
        cout << rawValues[x][y] << "\t";
            table.insertNumberIntoColumn(headers[x], x, rawValues[x][y]);
        }
        cout << endl;
    }
    return table;
};

// Function to load file from input path and returns a vector including vector including all the data
vector<string> loadFile(string path)
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

    return lines;
};


string convertArrayToCSV(Table table)
{
    string csv = table.convertToCSV();
    return csv;
}

void storeFile(string filename, string content)
{
    fstream file;
    file.open(filename, ios::out);
    if (!file)
    {
        cout << "File not created!";
    }
    else
    {
        cout << "File created successfully!";
        file << content;
        file.close();
    }
};

void cloneFile(){

};

void generateHTMLFile(){

};