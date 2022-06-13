#include "promo.h"

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "bundle.h"

using std::cout; using std::endl;
using std::string; using std::vector; using std::tuple;

namespace shop {
    
    string Promo::ToString() {
        return name;
    }
    
    Promos Promos::InitDefault() {
        Promos res;
        
        res.data.push_back(Promo(1, "Milk discount - 33%", 33, &promo_milk));
        res.data.push_back(Promo(2, "Flour discount - 24%", 24, &promo_flour));
        res.data.push_back(Promo(3, "Most valued position - 50%", 50, &promo_mvp));
        
        return res;
    }

    tuple<unsigned int, double> Promos::GetBestDiscount(const Bundle* b) {
        unsigned int best_discount_id = 0;
        double best_discount = 0;
        for (Promo x : data) {
            double d = x.f(x.discount, b);
            if (d > best_discount) {
                best_discount = d;
                best_discount_id = x.id;
            }
        }
        return tuple<unsigned int, double>(best_discount_id, best_discount);
    }

    void Promos::Print() {
        cout << endl << "Promos:" << endl;
        if (data.empty()) {
            cout << "< EMPTY >" << endl;
            return;
        }
        for (unsigned int i = 0; i < data.size(); ++i) {
            const auto& p = data[i];
            cout
                << p.id << ". "
                << p.name
                << endl;
        }
        return;
    }

    Promo Promos::Get(const unsigned int id) {
        for (Promo p : data) {
            if (p.id == id) {
                return p;
            }
        }
        throw std::exception("promo not found!");
    }

    double promo_milk(const double percent, const Bundle* b) {
        double res = 0;
        for (const auto& item : (* b).products) {
            if (item.type == ProductType::MILK) {
                res += (item.count * item.price) * percent / 100;
            }
        }
        return res;
    }

    double promo_flour(const double percent, const Bundle* b) {
        double res = 0;
        for (const auto& item : (*b).products) {
            if (item.type == ProductType::FLOUR) {
                res += (item.count * item.price) * percent / 100;
            }
        }
        return res;
    }

    double promo_mvp(const double percent, const Bundle* b) {
        double res = 0;
        double mvp = 0;
        for (const auto& item : (*b).products) {
            double position_subtotal = item.count * item.price;
            if (position_subtotal > mvp) {
                mvp = position_subtotal;
            }
        }
        res = mvp * percent / 100;
        return res;
    }
}
