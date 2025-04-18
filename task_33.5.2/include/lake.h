#pragma once

#include <vector>
#include <stdexcept>

/// @brief Enum for items that can be caught in the lake.
enum class LakeItem {
    Fish,
    Boot,
    Empty
};

/// @brief Lake exeption.
class LakeException : public std::exception {
public:
    /// @brief Construct a new Lake Exception object.
    /// @param item The item that was caught.
    /// @param try_count The number of tries to catch the item.
    LakeException(LakeItem item, unsigned try_count);
    const char* what() const noexcept override;
private: 
    std::string _message;
};

/// @brief Lake fish exeption.
class LakeExceptionFish : public LakeException {
public:
    /// @brief Construct a new Lake Exception Fish object.
    /// @param try_count The number of tries to catch the fish.
    LakeExceptionFish(unsigned try_count);
};

/// @brief Lake boot exeption.
class LakeExceptionBoot : public LakeException {
public:
    /// @brief Construct a new Lake Exception Boot object.
    /// @param try_count The number of tries to catch the boot.
    LakeExceptionBoot(unsigned try_count);
};


/// @brief Class for lake.
class Lake {
public:
    /// @brief Construct a new Lake object.
    /// @param sector_count The number of sectors in the lake.
    /// @param fish_count The number of fish in the lake.
    /// @param boot_count The number of boots in the lake.
    Lake(unsigned sector_count, unsigned fish_count, unsigned boot_count);

    /// @brief Catch item in the lake.
    /// @param sector The sector to catch the item in.
    /// @throw LakeException If the fish or boot was caught.
    void catch_item(unsigned sector);

    /// @brief Print lake in stdout.
    void print() const;
private:
    unsigned _try_count;
    std::vector<LakeItem> _sectors;

    /// @brief Place items in lake.
    /// @param item The item to place.
    /// @param count The number of items to place.
    /// @throw std::runtime_error If the Random gods are not in spirit today.
    void place_item(LakeItem item, unsigned count);
};