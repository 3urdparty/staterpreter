#include "prompt.hpp"  // Header file for all the prompt.cpp functions  // Header file for all the prompt.cpp functions

#include <unistd.h>

#include <iomanip>
#include <iostream>
#include <strfmt/strfmt.hpp>  // library of simple generic functions Mustafa and Azi wrote to be used in the main program. Source code found at libs/strfmt
#include <vector>
using namespace std;

vector<string> parseArgs(string str) {
  // Call the splitString() function from the strfmt library to split a string
  // based on the ' ' delimiter (into different command line args)
  vector<string> args = splitString(str, ' ');

  // Call function sanitizeStrings from the strfmt library
  // That rmeoves trailing and leading whitespaces of a word
  args = sanitizeStrings(args);
  return args;
}

void outputBanner() {
  // Function that outputs the `staterpreter` banner for brevity

  // Outputs the banner as a Raw string
  cout << R"(      __       __                       __         
  ___/ /____ _/ /____ _______  _______ / /____ ____
 (_-< __/ _ `/ __/ -_) __/ _ \/ __/ -_) __/ -_) __/
/___|__/\_,_/\__/\__/_/ / .__/_/  \__/\__/\__/_/   
                       /_/                         
)";
};
