#include <iostream>
#include "iter.hpp"

template <typename T>
void iterft(T &n)
{
    n = n + 1;
}

template <typename T>
void iterft_const(const T &n)
{
    std::cout << "Const element: " << n << std::endl;
}

int main()
{
    const int numbers[] = {1, 2, 3, 4, 5};
    int numbers2[] = {10, 20, 30, 40, 50};

    std::cout << "Testing with const array:" << std::endl;
    iter(numbers, 5, iterft_const<int>);

    std::cout << "\nTesting with non-const array:" << std::endl;
    iter(numbers2, 5, iterft<int>);

    std::cout << "\nModified non-const array:" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "numbers2[" << i << "] = " << numbers2[i] << std::endl;

    std::cout << "\nOriginal const array (unchanged):" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

    return 0;
}