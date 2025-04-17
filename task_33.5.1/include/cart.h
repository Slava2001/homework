#pragma once

#include "product_storage.h"

class Cart {
public:
    /// @brief Construct a new Cart object.
    /// @param warehouse The warehouse to use.
    Cart(ProductStorage &warehouse);

    /// @brief Adds a product to the cart.
    /// @param key The article of the product.
    /// @param count The number of products to add.
    /// @throw std::runtime_error If the product is not found in the warehouse.
    /// @throw std::runtime_error If there are not enough products in the
    /// warehouse.
    /// @throw std::runtime_error If there is not enough space on the card for
    /// this product.
    void add(const std::string &key, unsigned count);

    /// @brief Removes a product to the cart.
    /// @param key The article of the product.
    /// @param count The number of products to remove.
    /// @throw std::runtime_error If the product is not found in the card.
    /// @throw std::runtime_error If there are not enough products in the card.
    /// @throw std::runtime_error If there is not enough space on the warehouse
    /// for this product.
    void remove(const std::string &key, unsigned count);

private:
    ProductStorage &_warehouse;
    ProductStorage _cart;
    
    /// @brief Moves a product from one storage to another.
    /// @param from The storage to move the product from.
    /// @param to The storage to move the product to.
    /// @param key The article of the product.
    /// @param count The number of products to move.
    void move_product(ProductStorage &from, ProductStorage &to, const std::string &key, unsigned count);

    friend std::ostream& operator<<(std::ostream& out, const Cart& storage);
};
std::ostream& operator<<(std::ostream& out, const Cart& storage);