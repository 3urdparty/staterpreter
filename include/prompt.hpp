#include<vector>
#include<string>

using namespace std;

#ifndef PROMPT_HPP
#define PROMPT_HPP
void outputHelpMessage();
vector<string> parseArgs(string str);
void outputBanner();
void outputLoadingIcon();
#endif
