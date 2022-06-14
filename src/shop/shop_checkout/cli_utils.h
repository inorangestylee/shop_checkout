#pragma once

#include <string>

#include "bundle.h"
#include "promo.h"

namespace cli {
    
    void motd();
    void about();
    void help();
    void print(shop::Bundle& b);
    void print(shop::Promos& p);
    void move(shop::Bundle& shop, shop::Bundle& client, unsigned id, double count);
    void checkout(shop::Bundle& c, shop::Promos& p);
    void print_error(const std::exception& ex);
    void print_error(const std::string& msg);
    void exit_program();

}
