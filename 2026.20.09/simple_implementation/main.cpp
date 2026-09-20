#include <iostream>

void swap(int *a, int *b);
void my_sort(int *arr, const int size);

int main() {
    int size = 0;
    std::cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        std::cin>>arr[i];
    }
    for (int i = 0;i < size; i++) {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<'\n';
    my_sort(arr, size);
    for (int i = 0;i < size; i++) {
        std::cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void my_sort(int *arr, const int size) {
    for (int i = 0;i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}