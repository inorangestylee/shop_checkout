#pragma once

#include <string>
#include <vector>
#include <tuple>

#include "bundle.h"

using std::string; using std::vector;

namespace shop {

    class Promo {
    public:
        unsigned int id;
        string name;
        double discount;
        double (*f)(const unsigned int percent, const Bundle* b);

        Promo(unsigned int i, string n, double d, double (*fu)(const unsigned int percent, const Bundle* b)) {
            id = i;
            name = n;
            discount = d;
            f = fu;
        };

        std::string ToString();
    };

    class Promos {
    public:
        vector<Promo> data;

        static Promos InitDefault();
        
        std::tuple<unsigned int, double> GetBestDiscount(const Bundle* b);
        void Print();

        Promo Get(unsigned int id);
    };

    double promo_milk(const unsigned int percent, const Bundle* b);
    double promo_flour(const unsigned int percent, const Bundle* b);
    double promo_mvp(const unsigned int percent, const Bundle* b);
}
