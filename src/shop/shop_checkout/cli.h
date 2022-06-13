#pragma once

#include <vector>

#include "bundle.h"
#include "promo.h"

using std::vector;

namespace cli {
    
    void cli(shop::Bundle* s, shop::Bundle* c, shop::Promos* p);
    void prompt(shop::Bundle* s, shop::Bundle* c, shop::Promos* p);
    void interp(const vector<string>* v, shop::Bundle* s, shop::Bundle* c, shop::Promos* p);

}
