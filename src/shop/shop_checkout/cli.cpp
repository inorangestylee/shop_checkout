#include "cli.h"

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "cli_utils.h"
#include "bundle.h"
#include "promo.h"

using std::cout; using std::endl;
using std::vector; using std::string;

namespace cli {

    void cli(shop::Bundle* s, shop::Bundle* c, shop::Promos* p) {
        motd();
        while (true) {
            prompt(s, c, p);
            cout << endl;
        }
    }

    void prompt(shop::Bundle* s, shop::Bundle* c, shop::Promos* p) {
        string command;

        cout << "command > ";
        cout.flush();

        getline(std::cin, command);
        std::istringstream iss(command);

        vector<string> cmdvec;
        string word;

        while (iss >> word) {
            cmdvec.push_back(word);
        }

        if (!cmdvec.empty()) {
            interp(&cmdvec, s, c, p);
        }

        return;
    }

    void interp(const vector<string>* cmdvec, shop::Bundle* s, shop::Bundle* c, shop::Promos* p) {
        vector<string> cv = *cmdvec;
        string cmd = cv[0];

        if (cmd == "about") {
            about();
            return;
        }

        if (cmd == "help") {
            help();
            return;
        }

        if (cmd == "print") {
            if (cv.size() > 1 && cv[1] == "cart") {
                print(c);
                return;
            }
            else if (cv.size() > 1 && cv[1] == "shop") {
                print(s);
                return;
            }
            else if (cv.size() > 1 && cv[1] == "promo") {
                print(p);
                return;
            }
        }

        if (cmd == "add" || cmd == "a") {
            if (cv.size() > 2) {
                try {
                    move(s, c, std::stoul(cv[1]), std::stod(cv[2]));
                }
                catch (std::exception& e) {
                    print_error(e);
                }
                return;
            }
        }

        if (cmd == "del" || cmd == "d") {
            if (cv.size() > 2) {
                try {
                    move(c, s, std::stoul(cv[1]), std::stod(cv[2]));
                }
                catch (std::exception& e) {
                    print_error(e);
                }
                return;
            }
        }
            
        if (cmd == "q" || cmd == "quit" || cmd == "exit") {
            exit_program();
            return;
        }

        if (cmd == "checkout") {
            checkout(c, p);
            return;
        }
        
        print_error("Unknown command");
        
        return;
    }
}
