#include "menu.hpp"
#include "menu_items.hpp"

int main() {
    const GMIKHAIL::MenuItem* current = &GMIKHAIL::MAIN;
    do {
        current = current->func(current);
    } while (true);
    return 0;
}