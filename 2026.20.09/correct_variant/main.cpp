#include <iostream>
#include "io.hpp"
#include "sortings.hpp"

int main() {
     int size = 0;
     std::cout << "Введите размер массива: ";
     std::cin >> size;
     int arr[size];
     for (int i = 0; i < size; i++) {
          std::cout << "Введите элемент #" << i+1 << ": ";
          std::cin >> arr[i];
     }
     const int arr_size = sizeof(arr) / sizeof(arr[0]);

     biv::print_array("До сортировки: ", arr, arr_size);
     biv::my_sort(arr, arr_size);
     biv::print_array("После сортировки: ", arr, arr_size);
}