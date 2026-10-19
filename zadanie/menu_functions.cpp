#include <iostream>
#include <limits>
#include "menu_functions.hpp"

const GMIKHAIL::MenuItem* GMIKHAIL::show_menu(const MenuItem* current) {
    if (current->heading != nullptr) {
        std::cout << '\n' << current->heading << std::endl;
    }

    for (int i = 1; i < current->children_count; ++i) {
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Ваш выбор> ";

    int user_input = 0;
    if (!(std::cin >> user_input)) {
        if (std::cin.eof()) {
            return nullptr;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка: нужно ввести число" << std::endl;

        return current;
    }

    if (user_input < 0 || user_input >= current->children_count) {
        std::cout << "Нет такого пункта" << std::endl;
        return current;
    }

    return current->children[user_input];
}
const GMIKHAIL::MenuItem* GMIKHAIL::exit(const MenuItem*) {
    std::cout << "Путешествия завершены" << std::endl;
    return nullptr;
}

const GMIKHAIL::MenuItem* GMIKHAIL::go_back(const MenuItem* current) {
    if (current->parent != nullptr && current->parent->parent != nullptr) {
        return current->parent->parent;
    }

    if (current->parent != nullptr) {
        return current->parent;
    }

    return current;
}

const GMIKHAIL::MenuItem* GMIKHAIL::travel_vladivostok(const MenuItem* current) {
    std::cout << "Вы во Владивостоке" << std::endl;
    return current->parent;
}
const GMIKHAIL::MenuItem* GMIKHAIL::travel_sakhalin(const MenuItem* current) {
    std::cout << "Вы на Сахалине" << std::endl;
    return current->parent;
}
const GMIKHAIL::MenuItem* GMIKHAIL::travel_khabarovsk(const MenuItem* current) {
    std::cout << "Вы в Хабаровске" << std::endl;
    return current->parent;
}
const GMIKHAIL::MenuItem* GMIKHAIL::region_not_filled(const MenuItem* current) {
    std::cout << "Выберите другой вариант" << std::endl;
    return current->parent;
}
