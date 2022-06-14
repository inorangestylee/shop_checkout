#pragma once

#include <string>

namespace shop {

    enum class ProductType {
        DEFAULT = 0x1,
        MILK = 0x2,
        FLOUR = 0x3,
        FRUITS = 0x4
    };

    struct Product {      
        Product() = default;
        Product(unsigned i, std::string n, std::string u, double p, double c, bool w, ProductType pt = ProductType::DEFAULT);

        unsigned id;
        std::string name;
        std::string units;
        double price;
        double count;
        bool is_whole;
        bool is_raw = true;
        ProductType type;
    };

}
