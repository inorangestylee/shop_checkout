#include "bundle.h"

namespace shop {
    const char CURRENCY = '$';

    Bundle Bundle::Init() {
        return Bundle{};
    }
    
    Bundle Bundle::InitShelfDefault() {
        
        Bundle bundle = Init();
        bundle.is_client = false;
        
        auto p1 = Product(1, "bread", "u", 0.9, 100, true, ProductType::FLOUR);
        auto p2 = Product(2, "white bread", "u", 1.1, 100, true, ProductType::FLOUR);
        auto p3 = Product(3, "milk", "l", 1.3, 100, false, ProductType::MILK);
        auto p4 = Product(4, "butter", "kg", 3.6, 100, false, ProductType::MILK);
        auto p5 = Product(5, "sour cream", "pack", 1.8, 100, true, ProductType::MILK);
        auto p6 = Product(6, "meat", "kg", 16, 100, false);
        auto p7 = Product(7, "orange", "kg", 3, 100, false, ProductType::FRUITS);
        auto p8 = Product(8, "apple", "kg", 2.5, 100, false, ProductType::FRUITS);
        auto p9 = Product(9, "sugar", "kg", 2.05, 100, false);
        auto p10 = Product(10, "pasta", "kg", 1.29, 100, false, ProductType::FLOUR);

        bundle.AddProduct(&p1);
        bundle.AddProduct(&p2);
        bundle.AddProduct(&p3);
        bundle.AddProduct(&p4);
        bundle.AddProduct(&p5);
        bundle.AddProduct(&p6);
        bundle.AddProduct(&p7);
        bundle.AddProduct(&p8);
        bundle.AddProduct(&p9);
        bundle.AddProduct(&p10);

        return bundle;
    };
    

    void Bundle::AddProduct(Product* p) {
        for (auto iter = products.begin(); iter != products.end(); ++iter)
        {
            if ((*iter).id == (*p).id && (*iter).name == (*p).name) {
                (*iter).count += (*p).count;
                return;
            }
        }
        products.push_back((*p));
    }

    void Bundle::RemoveProduct(Product* p) {
        
        for (auto it = products.begin(); it != products.end(); ++it)
        {
            if ((*it).id == (*p).id) {
                products.erase(it--);
            }
        }
    }

    double Bundle::GetSubtotal() {
        double subtotal = 0;
        for (unsigned int i = 0; i < products.size(); ++i) {
            const Product p = products[i];
            double pos_subtotal = p.count * p.price;
            subtotal += pos_subtotal;
        }
        return subtotal;
    }

    void Bundle::Print() {
        std::string name = (is_client) ? "Client cart:" : "Shop shelf:";

        std::cout << std::endl << name << std::endl;
        std::cout << std::string(40, '-') << std::endl;
        if (products.empty()) {
            std::cout << "< EMPTY >" << std::endl;
            return;
        }
        for (unsigned int i = 0; i < products.size(); ++i) {
            const Product p = products[i];
            std::cout
                << p.id << ". "
                << p.name << " - "
                << p.count << " x "
                << CURRENCY << p.price << " = "
                << CURRENCY << p.price * p.count << std::endl;
        }

        double subtotal = GetSubtotal();
        std::cout
            << std::string(20, '.') << std::endl
            << "Subtotal: " << CURRENCY << subtotal << std::endl;
    }
    
    Product Bundle::Pull(unsigned int id, double count) {
        Product p = Product();
        auto iter = products.begin();
        for (; iter != products.end(); ++iter) {
            if ((*iter).id == id)
            {
                p = *iter;
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
        *iter = p;
        if (p.count == 0) {
            products.erase(iter);
        }

        return res;
    }
    
    void Bundle::Move(Bundle* b, unsigned int id, double count) {
        auto p = Bundle::Pull(id, count);
        (*b).AddProduct(&p);
    }

    void Bundle::Checkout(double discount) {
        if (!is_client) {
            throw std::exception("only client cart checkout is allowed!");
        }
        Print();
        std::cout
            << ""
            << "checkout" << std::endl
            << "total: " << CURRENCY << GetSubtotal() - discount
            << std::endl;
    }
}
