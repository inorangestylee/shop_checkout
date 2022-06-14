#pragma once

#include <vector>

#include "bundle.h"
#include "promo.h"

namespace cli {
    
    void cli(shop::Bundle& s, shop::Bundle& c, shop::Promos& p);
    void prompt(shop::Bundle& s, shop::Bundle& c, shop::Promos& p);
    void interp(const std::vector<std::string>& v, shop::Bundle& s, shop::Bundle& c, shop::Promos& p);

}
