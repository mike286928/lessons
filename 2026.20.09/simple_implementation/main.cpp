#include <iostream>

void my_sort(int *arr, const int size);
void print_array(const char* const comment, int *arr, const int size);

int main() {
    int size = 0;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите элемент массива #" << i + 1 << ": ";
        std::cin>>arr[i];
    }
    print_array("Массив до сортировки: ",arr, size);
    my_sort(arr, size);
    print_array("Массив после сортировки: ",arr, size);
    delete[] arr;
    return 0;
}
void my_sort(int *arr, const int size) {
    for (int i = 0;i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void print_array(const char* const comment, int *arr, const int size) {
    std::cout << comment << std::endl;
    for (int i = 0;i < size; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<'\n';
}