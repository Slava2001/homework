#include "lake.h"
#include <iostream>

LakeException::LakeException(LakeItem item, unsigned try_count) {
    _message = std::string("You caught a ") + (item == LakeItem::Fish ? "fish" : "boot") 
               + " after " + std::to_string(try_count) + " tries";
}

const char* LakeException::what() const noexcept {
    return _message.c_str();
}

LakeExceptionFish::LakeExceptionFish(unsigned try_count): 
    LakeException(LakeItem::Fish, try_count) {
}

LakeExceptionBoot::LakeExceptionBoot(unsigned try_count): 
    LakeException(LakeItem::Boot, try_count) {
}

void Lake::place_item(LakeItem item, unsigned count) {
    const unsigned MAX_TRY_PER_ITEM = 100;
    int unsigned try_count = 0;
    while (count > 0) {
        unsigned sector = std::rand() % _sectors.size();
        if (_sectors[sector] == LakeItem::Empty) {   
            _sectors[sector] = item;
            count--;
        }
        try_count++;
        if (try_count > _sectors.size() * MAX_TRY_PER_ITEM) {
            throw std::runtime_error("The Random gods are not in spirit today");
        }
    }
}

Lake::Lake(unsigned sector_count, unsigned fish_count, unsigned boot_count) {
    if (sector_count < fish_count + boot_count) {
        throw std::invalid_argument("Too many items");
    }
    _try_count = 0;
    _sectors = std::vector<LakeItem>(sector_count, LakeItem::Empty);
    place_item(LakeItem::Fish, fish_count);
    place_item(LakeItem::Boot, boot_count);
}

void Lake::catch_item(unsigned sector) {
    _try_count++;
    if (sector >= _sectors.size()) {
        throw std::out_of_range("Sector out of range");
    }
    switch (_sectors[sector]) {
    case LakeItem::Fish:
        throw LakeExceptionFish(_try_count);
    case LakeItem::Boot:
        throw LakeExceptionBoot(_try_count);
    case LakeItem::Empty:
        break;
    }
}

void Lake::print() const {
    std::cout << "Lake: ("; 
    for (auto const& item : _sectors) {
        switch (item) {
        case LakeItem::Empty:
            std::cout << "_";
            break;
        case LakeItem::Fish:
            std::cout << "F";
            break;
        case LakeItem::Boot:
            std::cout << "B";
            break;
        }    
    } 
    std::cout << ")" << std::endl;
}