#pragma once

#include <iostream>
#include <map>

/// @brief Class for storing products. It used to implement the warehouse and cart.
class ProductStorage {
public:
    /// @brief Construct a new Product Storage object.
    ProductStorage();

    /// @brief Add product to storage.
    /// @param key Product article.
    /// @param count Product count.
    /// @throw std::overflow_error If product count is too big.
    void addProduct(const std::string& key, unsigned count);

    /// @brief Remove product from storage.
    /// @param key Product article.
    /// @param count Product count.
    /// @throw std::underflow_error If product count is too small.
    void removeProduct(const std::string& key, unsigned count);

    /// @brief Get product count.
    /// @param key Product article.
    /// @return Product count.
    unsigned getProductCount(const std::string& key) const;
private:
    std::map<std::string, unsigned> _items;
    friend std::ostream& operator<<(std::ostream& out, const ProductStorage& storage);
};
std::ostream& operator<<(std::ostream& out, const ProductStorage& storage);
