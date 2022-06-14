#pragma once

#include <string>
#include <vector>
#include <tuple>

#include "bundle.h"

namespace shop {

    class Promo {
    public:
        Promo(unsigned i, std::string n, double d, double (*fu)(const double percent, const Bundle& b))
            : id(i), name(n), discount(d), f(fu) {};

        std::string ToString() const;

        unsigned id;
        std::string name;
        double discount;
        double (*f)(const double percent, const Bundle& b);
    };

    class Promos {
    public:
        static Promos InitDefault();        
        std::tuple<unsigned, double> GetBestDiscount(const Bundle& b) const;
        void Print();
        Promo Get(unsigned id) const;

        std::vector<Promo> data;
    };

    double promo_milk(const double percent, const Bundle& b);
    double promo_flour(const double percent, const Bundle& b);
    double promo_mvp(const double percent, const Bundle& b);
}
