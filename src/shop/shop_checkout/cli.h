#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "cli_utils.h"
#include "bundle.h"

using std::cout; using std::cin; using std::endl; using std::getline;
using std::string; using std::vector;


namespace cli {
    
    void cli(shop::Bundle *s, shop::Bundle *c, shop::Promos* p);
    void prompt(shop::Bundle *s, shop::Bundle *c, shop::Promos* p);
    void interp(vector<string> *v, shop::Bundle *s, shop::Bundle *c, shop::Promos* p);

}
