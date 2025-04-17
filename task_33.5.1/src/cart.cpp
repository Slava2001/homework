#include "cart.h"

std::ostream& operator<<(std::ostream& out, const Cart& storage) {
    out << storage._cart; 
    return out;
}

void Cart::move_product(ProductStorage &from, ProductStorage &to,
                        const std::string &key, unsigned count) {
    if (from.getProductCount(key) < count) {
        throw std::runtime_error("Not enough items.");
    }
    from.removeProduct(key, count);
    try {
        to.addProduct(key, count);
    } catch (std::runtime_error &e) {
        // we return products taken `from`
        // if we were unable to add them `to`
        from.addProduct(key, count);
        throw e;
  }
}

Cart::Cart(ProductStorage &warehouse) : _warehouse(warehouse), _cart() {};

void Cart::add(const std::string &key, unsigned count) {
    move_product(_warehouse, _cart, key, count);
}

void Cart::remove(const std::string &key, unsigned count) {
    move_product(_cart, _warehouse, key, count);
}