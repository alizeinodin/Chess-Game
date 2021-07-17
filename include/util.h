#include <array>
#include "cell.h"
#ifndef _UTIL_H
#define _UTIL_H

bool iscell(std::string);
int get_num(std::string);
char * get_char(std::string);
Cell & search_cell(std::string , std::array<std::array<Cell, 8>, 8> & board);
#endif