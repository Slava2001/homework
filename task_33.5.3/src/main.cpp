#include <iostream>
#include <functional>
#include <limits>

#include "registry.h"

/// @brief Safely input value from stdin.
/// @param msg Message to display before input.
/// @param predicate Predicate to check input value.
///                  Shuld return true if value is valid or return false and print error message.
template <typename Value>
Value safty_input(
    const char *msg,  
    std::function<bool(Value const&)>predicate = [](Value const&) {return true;}) 
{
    const int INPUT_TRY_COUNT = 3;
    Value value;
    std::cout << msg;
    for (int i = 0; i < INPUT_TRY_COUNT; i++) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (predicate(value)) {
            return value;
        }
        int try_number = i + 2;
        std::cout << "Invalid input. Try again (" 
                  << try_number << "/" << INPUT_TRY_COUNT << "): ";
    }
    throw std::runtime_error("user could not enter data");
}

template <typename K, typename V>
int template_main() {
    std::cout << "Key type: " << typeid(K).name() << std::endl
              << "Value type: " << typeid(V).name() << std::endl;
    Registry<K, V> registry;

    while (true) {
        std::cout << "Select option:" << std::endl
                  << "1. Add" << std::endl
                  << "2. Remove" << std::endl
                  << "3. Print" << std::endl
                  << "4. Find" << std::endl
                  << "5. Exit" << std::endl;
        int option = safty_input<int>("Enter number (1-5): ", [](int const& value) {
            return value >= 1 && value <= 5;
        });
        
        K key;
        V value;        
        switch (option) {
        case 1: 
            key = safty_input<K>("Enter key: ");
            value = safty_input<V>("Enter value: ");
            registry.add(key, value);
            break;
        case 2:
            key = safty_input<K>("Enter key: ");
            registry.remove(key);
            break;
        case 3:
            registry.print();
            break;
        case 4: {
            key = safty_input<K>("Enter key: ");
            auto values = registry.find(key);
            if (values.empty()) {
                std::cout << "Not found" << std::endl;
                break;
            }
            std::cout << "Found values:" << std::endl;
            for (auto const& value : values) {
                std::cout << "  " << value << std::endl;
            }
        }
        break;
        case 5:
            return EXIT_SUCCESS;
        }
    }
}

int main() {
    return template_main<int, std::string>();
}
