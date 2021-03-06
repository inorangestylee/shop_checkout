#include "product.h"

#include <cmath>

namespace shop {
    
    Product::Product(unsigned i, std::string n, std::string u, double p, double c, bool w, ProductType pt) 
        :id(i), name(n), units(u), price(p), count(c), is_whole(w), is_raw(false), type(pt)
    {
        if (std::floor(c) != c && w) {
            throw std::exception("can't add a whole product with not a whole amount");
        }
    }

}
