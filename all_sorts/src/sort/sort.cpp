#include "sort.hpp"
#include <utility>

void biv::bubble_sort_classic(int* arr, const int size) {
    for (int right = size - 1; right > 0; --right) {
        for (int i = 0; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void biv::bubble_sort_no_swaped_opt(int* arr, const int size) {
    for (int right = size - 1; right > 0; --right) {
        bool swapped = false;
        for (int i = 0; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
    }
}

void biv::bubble_sort_last_swap_opt(int* arr, const int size) {
    int right = size - 1;
    while (right > 0) {
        int last_swap = 0;
        for (int i = 0; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                last_swap = i;
            }
        }
        right = last_swap;
    }
}

void biv::shaker_sort(int* arr, const int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        bool swapped = false;
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
        --right;
        swapped = false;
        for (int i = right; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
        ++left;
    }
}

void biv::shaker_sort_last_swap_opt(int* arr, const int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int last_swap = left;
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                last_swap = i;
            }
        }
        right = last_swap;
        bool swapped = false;
        for (int i = right; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        if (!swapped) {
            return;
        }
        ++left;
    }
}

void biv::odd_even_sort(int* arr, const int size) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int parity = 0; parity < 2; ++parity) {
            for (int i = parity; i < size - 1; i += 2) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    sorted = false;
                }
            }
        }
    }
}

void biv::comb_sort(int* arr, const int size) {
    int gap = size;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = int(gap / 1.3);
        if (gap < 1) {
            gap = 1;
        }
        swapped = false;
        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void biv::selection_sort(int* arr, const int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

void biv::insertion_sort(int* arr, const int size) {
    for (int i = 1; i < size; ++i) {
        const int value = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > value) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = value;
    }
}

void biv::binary_insertion_sort(int* arr, const int size) {
    for (int i = 1; i < size; ++i) {
        const int value = arr[i];
        int left = 0;
        int right = i;
        while (left < right) {
            const int middle = left + (right - left) / 2;
            if (arr[middle] <= value) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
        for (int j = i; j > left; --j) {
            arr[j] = arr[j - 1];
        }
        arr[left] = value;
    }
}

void biv::shell_sort(int* arr, const int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            const int value = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > value) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = value;
        }
    }
}
