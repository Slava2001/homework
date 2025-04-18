#pragma once

#include <vector>
#include <iostream>

template <typename K, typename V>
struct Pair {
    K key;
    V value;
};

template <typename K, typename V>
class Registry {
public:
    /// @brief Construct a new Registry object.
    Registry();

    /// @brief Add a new key-value pair to the registry.
    /// @param key The key to add.
    /// @param value The value to add.
    void add(K key, V value);

    /// @brief Remove all key-value pairs with the given key.
    /// @param key The key to remove.
    void remove(K key);

    /// @brief Print all key-value pairs in the registry in stdout.
    void print() const;

    /// @brief Find all values with the given key.
    /// @param key The key to find.
    /// @return std::vector<V> The values with the given key.
    std::vector<V> find(K key) const;
private:
    std::vector<Pair<K, V>> _data;
};

template <typename K, typename V>
Registry<K, V>::Registry(): _data() {
}

template <typename K, typename V>
void Registry<K, V>::add(K key, V value) {
    _data.push_back(Pair<K, V>(key, value));
}

template <typename K, typename V>
void Registry<K, V>::remove(K key) {
    std::erase_if(_data, [key](Pair<K, V> pair) { return pair.key == key; });
}

template <typename K, typename V>
void Registry<K, V>::print() const {
    std::cout << "Registry:" << std::endl;
    for (auto const& pair : _data) {
        std::cout << "  " << pair.key << ": " << pair.value << std::endl;
    }
}

template <typename K, typename V>
std::vector<V> Registry<K, V>::find(K key) const {
    std::vector<V> result;
    for (auto const& pair : _data) {
        if (pair.key == key) {
            result.push_back(pair.value);
        }
    }
    return result;
}