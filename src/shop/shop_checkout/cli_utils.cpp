#include "cli_utils.h"

namespace cli {
    void motd() {
        cout
            << endl
            << "Welcome to Shop checkout emulation v0.1.0" << endl
            << "-----------------------------------------" << endl
            << "type 'help' for help" << endl
            << endl;

        return;
    }


    void about() {
        cout
            << endl
            << "Shop checkout emulation v0.1.0" << endl
            << "------------------------------" << endl
            << "2022 (c) Oleg Galushko" << endl 
            << endl;
        
        return;
    }

    void help() {
        cout
            << endl
            << "commands: " << endl
            << "help - help (this screen)" << endl
            << "about - about program and author" << endl
            << "quit - exit program" << endl
            << endl
            << "print cart - print client cart content" << endl
            << "print shop - print shop shelf content" << endl
            << "print promo - print shop promos" << endl
            << endl
            << "add <id> <count> - append product with id <id> and <count> to client's cart" << endl
            << "del <id> <count> - remove product with id <id> and <count> from client's cart" << endl
            << endl
            << "checkout - client's cart checkout (with discount)"
            << endl;

        return;
    }

    void print(shop::Bundle* b) {
        (*b).Print();
        
        return;
    }

    void print(shop::Promos* p) {
        (*p).Print();

        return;
    }

    void move(shop::Bundle* shop, shop::Bundle* client,  unsigned int id, double count) {
        (*shop).Move(client, id, count);
        return;
    }

    void checkout(shop::Bundle* c, shop::Promos* p) {
        auto discount = (*p).GetBestDiscount(c);
        (*c).Checkout(std::get<1>(discount));
        auto promo = (* p).Get(std::get<0>(discount));
        cout
            << "discount used: " << promo.ToString()
            << endl;
            
    }

    void print_error(std::exception& ex) {
        cout.flush();
        cout << "error: " << ex.what() << endl;
        return;
    }

    void print_error(const string& msg) {
        cout.flush();
        cout << "error: " << msg << endl;
        return;
    }

    void exit_program() {
        cout << "Cya! Have a good day!" << endl;
        exit(0);
    };
}
