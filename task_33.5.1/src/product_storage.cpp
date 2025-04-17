#include "product_storage.h"
#include <climits>

ProductStorage::ProductStorage() { _items = std::map<std::string, unsigned>(); }

void ProductStorage::addProduct(const std::string &key, unsigned count) {
    unsigned curent_count = _items[key];
    if (count > UINT_MAX - curent_count) {
       throw std::overflow_error("Failed to add product. Too many items.");
    }
    _items[key] += count;
}

void ProductStorage::removeProduct(const std::string &key, unsigned count) {
    if (_items[key] < count) {
        throw std::underflow_error("Failed to remove product. Not enough items.");
    }
    _items[key] -= count;
}

unsigned ProductStorage::getProductCount(const std::string &key) const {
    auto product = _items.find(key);
    if (product != _items.end()) {
        return product->second;
    }
    throw std::runtime_error("Product not found.");
}

std::ostream& operator<<(std::ostream& out, const ProductStorage& storage) {
    for (const auto& [key, count] : storage._items) {
        out << key << ": " << count << std::endl;
    }
    return out;
}