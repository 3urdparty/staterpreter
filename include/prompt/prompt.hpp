#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>
#include <vector>

using namespace std;

vector<string> parseArgs(string str);
void outputBanner();
void outputLoadingIcon();
string sanitizeString(string str);
#endif
