#include "promo.h"

namespace shop {
    
    std::string Promo::ToString() {
        return name;
    }
    
    Promos Promos::InitDefault() {
        Promos res;
        
        res.data.push_back(Promo(1, "Milk discount - 33%", 33, &promo_milk));
        res.data.push_back(Promo(2, "Flour discount - 24%", 24, &promo_flour));
        res.data.push_back(Promo(3, "Most valued position - 50%", 50, &promo_mvp));
        
        return res;
    }

    std::tuple<unsigned int, double> Promos::GetBestDiscount(const Bundle* b) {
        unsigned int best_discount_id = 0;
        double best_discount = 0;
        for (auto x : data) {
            double d = x.f(x.discount, b);
            if (d > best_discount) {
                best_discount = d;
                best_discount_id = x.id;
            }
        }
        return std::tuple<unsigned int, double>(best_discount_id, best_discount);
    }

    void Promos::Print() {
        std::cout << std::endl << "Promos:" << std::endl;
        if (data.size() == 0) {
            std::cout << "< EMPTY >" << std::endl;
            return;
        }
        for (unsigned int i = 0; i < data.size(); ++i) {
            auto p = data[i];
            std::cout
                << p.id << ". "
                << p.name
                << std::endl;
        }
        return;
    }

    Promo Promos::Get(unsigned int id) {
        for (Promo p : data) {
            if (p.id == id) {
                return p;
            }
        }
        throw std::exception("promo not found!");
    }

    double promo_milk(const unsigned int percent, const Bundle* b) {
        double res = 0;
        for (auto item : (* b).products) {
            if (item.type == ProductType::MILK) {
                res += (item.count * item.price) * percent / 100;
            }
        }
        return res;
    }

    double promo_flour(const unsigned int percent, const Bundle* b) {
        double res = 0;
        for (auto item : (*b).products) {
            if (item.type == ProductType::FLOUR) {
                res += (item.count * item.price) * percent / 100;
            }
        }
        return res;
    }

    double promo_mvp(const unsigned int percent, const Bundle* b) {
        double res = 0;
        double mvp = 0;
        for (auto item : (*b).products) {
            double position_subtotal = item.count * item.price;
            if (position_subtotal > mvp) {
                mvp = position_subtotal;
            }
        }
        res = mvp * percent / 100;
        return res;
    }
}
