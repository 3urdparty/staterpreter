#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>
#include <vector>

using namespace std;

/// @brief Function that takes a long command and parses it into seperate
/// command line arguments for input validation
/// @param str - long command
/// @return vector of strings representing all the command line args
vector<string> parseArgs(string str);

/// @brief Small function that outputs the banner of the program
void outputBanner();

#endif
