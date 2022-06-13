#pragma once

#include <string>

using std::string;

namespace shop {

    enum class ProductType {
        DEFAULT = 0x1,
        MILK = 0x2,
        FLOUR = 0x3,
        FRUITS = 0x4
    };

    class Product {
    public:
        unsigned int id;
        string name;
        string units;
        double price;
        double count;
        bool is_whole;
        bool is_raw = true;
        ProductType type;
        Product() = default;
        Product(unsigned int i, string n, string u, double p, double c, bool w, ProductType pt = ProductType::DEFAULT);
    };

}
