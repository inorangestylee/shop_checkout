#include "product.h"

#include <cmath>

using std::string;

namespace shop {
    
    Product::Product(unsigned int i, string n, string u, double p, double c, bool w, ProductType pt) {
        if (std::floor(c) != c && w) {
            throw std::exception("can't add a whole product with not a whole amount");
        }
        id = i;
        name = n;
        units = u;
        price = p;
        count = c;
        is_whole = w;
        type = pt;
        is_raw = false;
    }

}
