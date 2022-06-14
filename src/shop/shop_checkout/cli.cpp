#include "cli.h"

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "cli_utils.h"
#include "bundle.h"
#include "promo.h"

namespace cli {

    void cli(shop::Bundle& s, shop::Bundle& c, shop::Promos& p) {
        motd();
        while (true) {
            prompt(s, c, p);
            std::cout << std::endl;
        }
    }

    void prompt(shop::Bundle& s, shop::Bundle& c, shop::Promos& p) {
        std::string command;

        std::cout << "command > ";
        std::cout.flush();

        getline(std::cin, command);
        std::istringstream iss(command);

        std::vector<std::string> cmdvec;
        std::string word;

        while (iss >> word) {
            cmdvec.push_back(word);
        }

        if (!cmdvec.empty()) {
            interp(cmdvec, s, c, p);
        }

        return;
    }

    void interp(const std::vector<std::string>& cmdvec, shop::Bundle& s, shop::Bundle& c, shop::Promos& p) {
        std::string cmd = cmdvec[0];

        if (cmd == "about") {
            about();
            return;
        }

        if (cmd == "help") {
            help();
            return;
        }

        if (cmd == "print") {
            if (cmdvec.size() > 1 && cmdvec[1] == "cart") {
                print(c);
                return;
            }
            else if (cmdvec.size() > 1 && cmdvec[1] == "shop") {
                print(s);
                return;
            }
            else if (cmdvec.size() > 1 && cmdvec[1] == "promo") {
                print(p);
                return;
            }
        }

        if (cmd == "add" || cmd == "a") {
            if (cmdvec.size() > 2) {
                try {
                    move(s, c, std::stoul(cmdvec[1]), std::stod(cmdvec[2]));
                }
                catch (const std::exception& e) {
                    print_error(e);
                }
                return;
            }
        }

        if (cmd == "del" || cmd == "d") {
            if (cmdvec.size() > 2) {
                try {
                    move(c, s, std::stoul(cmdvec[1]), std::stod(cmdvec[2]));
                }
                catch (const std::exception& e) {
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
