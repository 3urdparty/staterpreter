#include "textformat.hpp"

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

namespace fg {
int black = 30;
int red = 31;
int green = 32;
int yellow = 33;
int blue = 34;
int magenta = 35;
int cyan = 36;
int white = 37;

};  // namespace fg

namespace bg {
int black = 40;
int red = 41;
int green = 42;
int yellow = 43;
int blue = 44;
int magenta = 45;
int cyan = 46;
int white = 47;

};  // namespace bg

string clearfmt = "\x1b[0m";
string bold = "\e[1m";
string colorfmt(int fgcolor, int bgcolor) {
  string fmt; 
  if (bgcolor == 0) {
    fmt += "\x1b[" + to_string(fgcolor) + "m";
  } else {
    fmt = "\x1b[" + to_string(fgcolor) + ";" + to_string(bgcolor) + "m";
  }
  return fmt;
}
