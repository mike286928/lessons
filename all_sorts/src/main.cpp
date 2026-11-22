#include "sort.hpp"
#include <chrono>
#include <cstdlib>
#include <fstream>

int main() {
    const int sizes[] = {10000, 100000};
    const int sort_cnt = 11;
    const char* names[] = {
        "Пузырёк классический",
        "Пузырёк с выходом без обменов",
        "Пузырёк с границей последнего обмена",
        "Шейкерная",
        "Шейкерная с оптимизацией правой границы",
        "Чёт-нечет",
        "Расчёска",
        "Выбором",
        "Вставками классическая",
        "Вставками с бинарным поиском",
        "Шелла"
    };

    void (*sorts[])(int*, const int) = {
        biv::bubble_sort_classic,
        biv::bubble_sort_no_swaped_opt,
        biv::bubble_sort_last_swap_opt,
        biv::shaker_sort,
        biv::shaker_sort_last_swap_opt,
        biv::odd_even_sort,
        biv::comb_sort,
        biv::selection_sort,
        biv::insertion_sort,
        biv::binary_insertion_sort,
        biv::shell_sort
    };

    std::ofstream report("results.md");
    if (!report) {
        return 1;
    }
    report << "# Результаты замеров\n\n";
    report << "| Сортировка | Размер | Время, мс |\n";
    report << "|---|---:|---:|\n";
    std::srand(42);
    for (int size_number = 0; size_number < 2; size_number++) {
        const int size = sizes[size_number];
        int* original = new int[size];
        for (int i = 0; i < size; i++) {
            original[i] = std::rand() % 100000 - 50000;
        }
        for (int sort_number = 0; sort_number < sort_cnt; sort_number++) {
            int* actual = new int[size];
            for (int i = 0; i < size; i++) {
                actual[i] = original[i];
            }
            const auto start = std::chrono::steady_clock::now();
            sorts[sort_number](actual, size);
            const auto finish = std::chrono::steady_clock::now();
            const double milliseconds = std::chrono::duration<double, std::milli>(finish - start).count();
            report << "| " << names[sort_number] << " | " << size << " | " << milliseconds << " |\n";
            delete[] actual;
        }
        delete[] original;
    }

    report.close();
    return report ? 0 : 1;
}