#include "cli_utils.h"

#include <iostream>
#include <string>
#include <exception>
#include <tuple>

#include "bundle.h"
#include "promo.h"


namespace cli {
    void motd() {
        std::cout
            << std::endl
            << "Welcome to Shop checkout emulation v0.1.0" << std::endl
            << "-----------------------------------------" << std::endl
            << "type 'help' for help" << std::endl
            << std::endl;

        return;
    }


    void about() {
        std::cout
            << std::endl
            << "Shop checkout emulation v0.1.0" << std::endl
            << "------------------------------" << std::endl
            << "2022 (c) Oleg Galushko" << std::endl 
            << std::endl;
        
        return;
    }

    void help() {
        std::cout
            << std::endl
            << "commands: " << std::endl
            << "help - help (this screen)" << std::endl
            << "about - about program and author" << std::endl
            << "quit - exit program" << std::endl
            << std::endl
            << "print cart - print client cart content" << std::endl
            << "print shop - print shop shelf content" << std::endl
            << "print promo - print shop promos" << std::endl
            << std::endl
            << "add <id> <count> - append product with id <id> and <count> to client's cart" << std::endl
            << "del <id> <count> - remove product with id <id> and <count> from client's cart" << std::endl
            << std::endl
            << "checkout - client's cart checkout (with discount)"
            << std::endl;

        return;
    }

    void print(shop::Bundle& b) {
        b.Print();
        
        return;
    }

    void print(shop::Promos& p) {
        p.Print();

        return;
    }

    void move(shop::Bundle& shop, shop::Bundle& client,  unsigned id, double count) {
        shop.Move(client, id, count);
        return;
    }

    void checkout(shop::Bundle& c, shop::Promos& p) {
        auto discount = p.GetBestDiscount(c);
        c.Checkout(std::get<1>(discount));
        auto promo = p.Get(std::get<0>(discount));
        std::cout
            << "discount used: " << promo.ToString()
            << std::endl;
            
    }

    void print_error(const std::exception& ex) {
        std::cout.flush();
        std::cout << "error: " << ex.what() << std::endl;
        return;
    }

    void print_error(const std::string& msg) {
        std::cout.flush();
        std::cout << "error: " << msg << std::endl;
        return;
    }

    void exit_program() {
        std::cout << "Cya! Have a good day!" << std::endl;
        exit(0);
    };
}
