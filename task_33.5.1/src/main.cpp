#include <iostream>
#include "product_storage.h"
#include "cart.h"

void get_product(std::string &article, unsigned &count) {
    try {
        std::cout << "Enter article: ";
        std::cin >> article;
        std::cout << "Enter count: ";
        std::cin >> count;
    } catch(...) {
        throw std::invalid_argument("Invalid input.");
    }
}

int unsafe_main() {
    std::cin.exceptions(std::ios_base::failbit);
    
    ProductStorage warehouse;    
    Cart cart(warehouse);

    std::cout << "Be careful, any mistake will cause the program to terminate XD" << std::endl;
    while(true) {
        std::cout << "Select option:" << std::endl
                  << "1. Add product to warehouse" << std::endl
                  << "2. Add product to cart" << std::endl
                  << "3. Remove product from cart" << std::endl
                  << "4. Show cart" << std::endl
                  << "5. Exit" << std::endl
                  << "Enter number (1-5): ";
        int option;
        std::cin >> option;
        std::string article;
        unsigned count;
        switch (option) {
        case 1: 
            std::cout << "Enter product to add to warehouse:" << std::endl;
            get_product(article, count);
            warehouse.addProduct(article, count);
            break;
        case 2: 
            std::cout << "Warehouse:" << std::endl << warehouse << std::endl;
            std::cout << "Enter product to add to cart:" << std::endl;
            get_product(article, count);
            cart.add(article, count);
            break;
        case 3:
            std::cout << "Enter product to remove from cart:" << std::endl;
            get_product(article, count);
            cart.remove(article, count);
            break;
        case 4:
            std::cout << "Cart:" << std::endl << cart << std::endl;
            break;
        case 5:
            return EXIT_SUCCESS;
        }
    }
    
    return EXIT_SUCCESS;
}

int main() {
    try {
        return unsafe_main();
    } catch(std::exception &e) {
        std::cout << "Some error happend!" << std::endl
                  << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}