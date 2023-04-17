#include<string>
#include<vector>
#include "utilities.hpp"
using namespace std;

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

bool cmpstr(string str1, string str2)
{
    return !strcmp(str1.c_str(), str2.c_str());
};