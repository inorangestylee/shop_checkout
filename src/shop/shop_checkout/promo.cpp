#include "promo.h"

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "bundle.h"

namespace shop {
    
    std::string Promo::ToString() const {
        return name;
    }
    
    Promos Promos::InitDefault() {
        Promos res;
        
        res.data.emplace_back(1, "Milk discount - 33%", 33, &promo_milk);
        res.data.emplace_back(2, "Flour discount - 24%", 24, &promo_flour);
        res.data.emplace_back(3, "Most valued position - 50%", 50, &promo_mvp);
        
        return res;
    }

    std::tuple<unsigned, double> Promos::GetBestDiscount(const Bundle& b) const {
        unsigned best_discount_id = 0;
        double best_discount = 0;
        for (Promo x : data) {
            double d = x.f(x.discount, b);
            if (d > best_discount) {
                best_discount = d;
                best_discount_id = x.id;
            }
        }
        return std::tuple<unsigned, double>(best_discount_id, best_discount);
    }

    void Promos::Print() {
        std::cout << std::endl << "Promos:" << std::endl;
        if (data.empty()) {
            std::cout << "< EMPTY >" << std::endl;
            return;
        }
        for (unsigned i = 0; i < data.size(); ++i) {
            const auto& p = data[i];
            std::cout
                << p.id << ". "
                << p.name
                << std::endl;
        }
        return;
    }

    Promo Promos::Get(const unsigned id) const {
        for (Promo p : data) {
            if (p.id == id) {
                return p;
            }
        }
        throw std::exception("promo not found!");
    }

    double promo_milk(const double percent, const Bundle& b) {
        double res = 0;
        for (const auto& item : b.Get()) {
            if (item.type == ProductType::MILK) {
                res += (item.count * item.price) * percent / 100;
            }
        }
        return res;
    }

    double promo_flour(const double percent, const Bundle& b) {
        double res = 0;
        for (const auto& item : b.Get()) {
            if (item.type == ProductType::FLOUR) {
                res += (item.count * item.price) * percent / 100;
            }
        }
        return res;
    }

    double promo_mvp(const double percent, const Bundle& b) {
        double res = 0;
        double mvp = 0;
        for (const auto& item : b.Get()) {
            double position_subtotal = item.count * item.price;
            if (position_subtotal > mvp) {
                mvp = position_subtotal;
            }
        }
        res = mvp * percent / 100;
        return res;
    }
}
