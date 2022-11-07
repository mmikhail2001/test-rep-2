#include <array>
#include <iostream>

template <typename T, size_t N, size_t... I>
void Print(std::array<T, N> const &arr, std::index_sequence<I...>)
{
    std::cout << "arr has " << N << " elements: <";
    (..., (std::cout << (I == 0 ? "" : ",") << arr[I]));
    std::cout << ">" << std::endl;
}

template <typename T, size_t N>
void Print(std::array<T, N> const &arr)
{
    Print(arr, std::make_index_sequence<N>{});
}

int main()
{
    std::array<size_t, 3> arr = {1, 2, 3};
    Print(arr);
}