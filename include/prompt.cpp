#include "prompt.hpp"

#include <unistd.h>

#include <iomanip>
#include <iostream>
#include <vector>

#include "utilities.hpp"
using namespace std;

vector<string> parseArgs(string str) {
  vector<string> args = splitString(str, ' ');
  args = sanitizeStrings(args);
  int n = args.size();
  return args;
}

void outputBanner() {
  cout << R"(      __       __                       __         
  ___/ /____ _/ /____ _______  _______ / /____ ____
 (_-< __/ _ `/ __/ -_) __/ _ \/ __/ -_) __/ -_) __/
/___|__/\_,_/\__/\__/_/ / .__/_/  \__/\__/\__/_/   
                       /_/                         
)";
};

void outputLoadingIcon() {
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
