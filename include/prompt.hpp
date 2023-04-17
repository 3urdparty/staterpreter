#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>
#include <vector>

using namespace std;

void outputHelpMessage();
vector<string> parseArgs(string str);
void outputBanner();
void outputLoadingIcon();
#endif
