#ifndef TERMINAL_HPP
#define TERMINAL_HPP
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include <tuple>
#include <utility>
#include <vector>
using namespace std;
tuple<int, int> getTerminalDimensions();
#endif
