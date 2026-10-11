#include <iostream>
void printer(const char* const comment);

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    int *a = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i + 1 << " элемент" << std::endl;
        std::cin >> a[i];
    }

    bool isIncrease = false;
    for (int i = 0; i < size - 1; i++) {
        if (a[i] <= a[i + 1]) {
            isIncrease = true;
        }else {
            isIncrease = false;
        }
    }

    if (isIncrease) {
        printer("Последовательность возрастающая");
    } else {
        printer("Последовательность не возрастающая");
    }

    return 0;
}

void printer(const char* const comment) {
    std::cout << comment << std::endl;
}