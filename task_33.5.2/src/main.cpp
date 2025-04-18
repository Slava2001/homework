#include <iostream>
#include <ctime>
#include "lake.h"

#define SECTOR_COUNT 9
#define FISH_COUNT 1
#define BOOT_COUNT 3

int main() {
    std::cin.exceptions(std::ios_base::failbit);
    std::srand(std::time(nullptr));
    
    Lake lake(SECTOR_COUNT, FISH_COUNT, BOOT_COUNT);
    lake.print();
    
    while (true) {
        std::cout << "Enter sector index: ";
        unsigned sector;
        std::cin >> sector;
        try {
            lake.catch_item(sector);
        } catch(LakeExceptionFish &e) {
            std::cout << "You Win!!! " << e.what() << std::endl;
            return EXIT_SUCCESS;
        } catch(LakeExceptionBoot &e) {
            std::cout << "You Lose!!! " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
        std::cout << "You didn't catch anything" << std::endl;
    }
}