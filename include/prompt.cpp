#include "prompt.hpp"

#include <unistd.h>

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;


vector<string> parseArgs(string str) {
  vector<string> output;
  string buffer = "";
  for (int x = 0; x <= str.length(); x++) {
    if (str[x] == ' ') {
      if (buffer != "") output.push_back(buffer);
      buffer = "";
    } else {
      buffer += str[x];
    }
  }
  output.push_back(buffer);
  return output;
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
