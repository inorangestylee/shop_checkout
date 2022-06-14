#pragma once

#include <vector>

#include "product.h"

namespace shop {

    class Bundle {
    public:
        static Bundle InitShelfDefault();

        void AddProduct(const Product& p);
        void RemoveProduct(Product& p);
        double GetSubtotal();
        void Print();
        const std::vector<Product>& Get() const;
        void Checkout(double discount);
        Product Pull(unsigned id, double count);
        void Move(Bundle& b, unsigned id, double count);

    private:
        bool is_client_ = true;
        std::vector<Product> products_;
    };

}
