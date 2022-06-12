#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <exception>

#include "product.h"


namespace shop {

    class Bundle {
    private:
        bool is_client = true;
    public:
        std::vector<Product> products;
        static Bundle Init();
        static Bundle InitShelfDefault();
        void AddProduct(Product* p);
        void RemoveProduct(Product* p);
        double GetSubtotal();
        void Print();
        void Checkout(double discount);
        Product Pull(unsigned int id, double count);
        void Move(Bundle* b, unsigned int id, double count);
    };

}
