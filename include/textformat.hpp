#ifndef TEXTFORMAT_HPP
#define TEXTFORMAT_HPP

#include <string>
using namespace std;

extern string clearfmt;
extern string bold;
string colorfmt(int fgcolor, int bgcolor = 0);

namespace bg {
extern int black;
extern int red;
extern int green;
extern int yellow;
extern int blue;
extern int magenta;
extern int cyan;
extern int white;
};  // namespace bg

namespace fg {
extern int black;
extern int red;
extern int green;
extern int yellow;
extern int blue;
extern int magenta;
extern int cyan;
extern int white;

};  // namespace fg
#endif