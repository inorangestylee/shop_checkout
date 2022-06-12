#pragma once

#include <iostream>
#include <string>

#include "bundle.h"
#include "promo.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

namespace cli {
    void motd();
    
    void about();
    void help();
    void print(shop::Bundle* b);
    void print(shop::Promos* p);
    void move(shop::Bundle* shop, shop::Bundle* client, unsigned int id, double count);
    void checkout(shop::Bundle* c, shop::Promos* p);
    void print_error(std::exception& ex);
    void print_error(const string& msg);
    void exit_program();
}
