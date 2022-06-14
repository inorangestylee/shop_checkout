#include "bundle.h"

#include <iostream>
#include <string>

namespace shop {
    
    const char kCurrency = '$';

    Bundle Bundle::InitShelfDefault() {
        
        auto bundle = Bundle();
        bundle.is_client_ = false;
        
        auto p1 = Product(1, "bread", "loaf", 0.9, 100, true, ProductType::FLOUR);
        auto p2 = Product(2, "white bread", "loaf", 1.1, 100, true, ProductType::FLOUR);
        auto p3 = Product(3, "milk", "pack", 1.3, 100, true, ProductType::MILK);
        auto p4 = Product(4, "butter", "kg", 3.6, 100, false, ProductType::MILK);
        auto p5 = Product(5, "sour cream", "pack", 1.8, 100, true, ProductType::MILK);
        auto p6 = Product(6, "meat", "kg", 16, 100, false);
        auto p7 = Product(7, "orange", "kg", 3, 100, false, ProductType::FRUITS);
        auto p8 = Product(8, "apple", "kg", 2.5, 100, false, ProductType::FRUITS);
        auto p9 = Product(9, "sugar", "kg", 2.05, 100, false);
        auto p10 = Product(10, "pasta", "kg", 1.29, 100, false, ProductType::FLOUR);

        bundle.AddProduct(p1);
        bundle.AddProduct(p2);
        bundle.AddProduct(p3);
        bundle.AddProduct(p4);
        bundle.AddProduct(p5);
        bundle.AddProduct(p6);
        bundle.AddProduct(p7);
        bundle.AddProduct(p8);
        bundle.AddProduct(p9);
        bundle.AddProduct(p10);

        return bundle;
    };
    

    void Bundle::AddProduct(const Product& p) {
        for (auto it = products_.begin(); it != products_.end(); ++it)
        {
            if ((*it).id == p.id && (*it).name == p.name) {
                (*it).count += p.count;
                return;
            }
        }
        products_.push_back(p);
    }

    void Bundle::RemoveProduct(Product& p) {
        
        for (auto it = products_.begin(); it != products_.end(); ++it)
        {
            if ((*it).id == p.id) {
                products_.erase(it--);
            }
        }
    }

    const std::vector<Product>& Bundle::Get() const {
        return products_;
    }

    double Bundle::GetSubtotal() {
        double subtotal = 0;
        for (unsigned i = 0; i < products_.size(); ++i) {
            const Product p = products_[i];
            double pos_subtotal = p.count * p.price;
            subtotal += pos_subtotal;
        }
        return subtotal;
    }

    void Bundle::Print() {
        std::string name = is_client_ ? "Client cart:" : "Shop shelf:";

        std::cout << std::endl << name << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        if (products_.empty()) {
            std::cout << "< EMPTY >" << std::endl;
            return;
        }
        for (unsigned i = 0; i < products_.size(); ++i) {
            const Product p = products_[i];
            std::cout
                << p.id << ". "
                << p.name << " - "
                << p.count << " " << p.units << " x "
                << kCurrency << p.price << " = "
                << kCurrency << p.price * p.count << std::endl;
        }

        double subtotal = GetSubtotal();
        std::cout
            << std::string(20, '.') << std::endl
            << "Subtotal: " << kCurrency << subtotal << std::endl;
    }
    
    Product Bundle::Pull(unsigned id, double count) {
        auto p = Product();
        auto it = products_.begin();
        for (; it != products_.end(); ++it) {
            if ((*it).id == id)
            {
                p = *it;
                break;
            }
        }

        if (p.is_raw) {
            throw std::exception("product not found");
        }
        
        if (count > p.count) {
            throw std::exception("can't take more product count than have");
        }

        if (count <= p.count) {
            if (p.is_whole && std::floor(count) != count) {
                throw std::exception("can't divide an indivisible product");
            }
            p.count -= count;
        }

        auto res = Product(p.id, p.name, p.units, p.price, count, p.is_whole, p.type);
        *it = p;
        if (p.count == 0) {
            products_.erase(it);
        }

        return res;
    }
    
    void Bundle::Move(Bundle& b, unsigned id, double count) {
        auto p = Bundle::Pull(id, count);
        b.AddProduct(p);
    }

    void Bundle::Checkout(double discount) {
        if (!is_client_) {
            throw std::exception("only client cart checkout is allowed!");
        }
        Print();
        std::cout
            << std::endl
            << "total (with discount): " << kCurrency << GetSubtotal() - discount
            << std::endl;
    }
}
