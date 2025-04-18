#include <iostream>

template <typename T, std::size_t L>
void input(T array[L]) {
    std::cout << "Fill the array (" << L << "):" << std::endl;
    for (size_t i = 0; i < L; ++i) {
        std::cout << "Elem #" << i << " : ";
        std::cin >> array[i];
    }
}

template <typename T, std::size_t L>
T average(T array[L]) {
    T sum = 0;
    for (size_t i = 0; i < L; ++i) {
        sum += array[i];
    }
    return sum / L;
}

int main() {
    std::cin.exceptions(std::ios_base::failbit);
    int int_array[8]; 
    input<int, 8>(int_array);
    std::cout << "Average int: " << average<int, 8>(int_array) << std::endl;

    double double_array[3];
    input<double, 3>(double_array);
    std::cout << "Average double: " << average<double, 3>(double_array) << std::endl;

    float float_array[5];
    input<float, 5>(float_array);
    std::cout << "Average float: " << average<float, 5>(float_array) << std::endl;
    return 0;
}