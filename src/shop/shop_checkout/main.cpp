#include "bundle.h"
#include "cli.h"
#include "product.h"
#include "promo.h"

int main() {
    // init shop shelf and empty client cart
    auto shelf = shop::Bundle::InitShelfDefault();
    auto cart = shop::Bundle();

    // add some whisky and cola :)
    auto p1 = shop::Product(11, "whisky", "bottle", 45, 1, true);
    auto p2 = shop::Product(12, "cola", "bottle", 5, 1, true);
    shelf.AddProduct(p1);
    shelf.AddProduct(p2);

    // init promos
    auto promos = shop::Promos::InitDefault();

    cli::cli(shelf, cart, promos);

    return 0;
}
