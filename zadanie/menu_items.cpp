#include "menu_items.hpp"

#include "menu_functions.hpp"

const GMIKHAIL::MenuItem GMIKHAIL::VLADIVOSTOK = {
    "1 — Владивосток", GMIKHAIL::travel_vladivostok, &GMIKHAIL::DALNIY_VOSTOK
};

const GMIKHAIL::MenuItem GMIKHAIL::SAKHALIN = {
    "2 — Сахалин", GMIKHAIL::travel_sakhalin, &GMIKHAIL::DALNIY_VOSTOK
};

const GMIKHAIL::MenuItem GMIKHAIL::KHABAROVSK = {
    "3 — Хабаровск", GMIKHAIL::travel_khabarovsk, &GMIKHAIL::DALNIY_VOSTOK
};

const GMIKHAIL::MenuItem GMIKHAIL::ALTAI = {
    "2 — Алтай", GMIKHAIL::region_not_filled, &GMIKHAIL::REGION
};

const GMIKHAIL::MenuItem GMIKHAIL::GOLDEN_RING = {
    "3 — Золотое Кольцо России", GMIKHAIL::region_not_filled, &GMIKHAIL::REGION
};

const GMIKHAIL::MenuItem GMIKHAIL::REGION_BACK = {
    "0 — Выйти в главное меню", GMIKHAIL::go_back, &GMIKHAIL::REGION
};

const GMIKHAIL::MenuItem GMIKHAIL::DALNIY_VOSTOK_BACK = {
    "0 — Выйти в предыдущее меню", GMIKHAIL::go_back, &GMIKHAIL::DALNIY_VOSTOK
};

namespace {
const GMIKHAIL::MenuItem* const dalniy_vostok_children[] = {
    &GMIKHAIL::DALNIY_VOSTOK_BACK,
    &GMIKHAIL::VLADIVOSTOK,
    &GMIKHAIL::SAKHALIN,
    &GMIKHAIL::KHABAROVSK
};
const int dalniy_vostok_size = sizeof(dalniy_vostok_children) / sizeof(dalniy_vostok_children[0]);

const GMIKHAIL::MenuItem* const region_children[] = {
    &GMIKHAIL::REGION_BACK,
    &GMIKHAIL::DALNIY_VOSTOK,
    &GMIKHAIL::ALTAI,
    &GMIKHAIL::GOLDEN_RING
};
const int region_size = sizeof(region_children) / sizeof(region_children[0]);

const GMIKHAIL::MenuItem* const main_children[] = {
    &GMIKHAIL::EXIT,
    &GMIKHAIL::REGION
};
const int main_size = sizeof(main_children) / sizeof(main_children[0]);

}  // namespace

const GMIKHAIL::MenuItem GMIKHAIL::DALNIY_VOSTOK = {
    "1 - Дальний Восток",
    GMIKHAIL::show_menu,
    &GMIKHAIL::REGION,
    dalniy_vostok_children,
    dalniy_vostok_size,
    "Третий уровень Дальний Восток:"
};

const GMIKHAIL::MenuItem GMIKHAIL::REGION = {
    "1 - Путешествовать по России",
    GMIKHAIL::show_menu,
    &GMIKHAIL::MAIN,
    region_children,
    region_size,
    "Второй уровень меню:"
};

const GMIKHAIL::MenuItem GMIKHAIL::EXIT = {
    "0 - Закончить путешествия", GMIKHAIL::exit, &GMIKHAIL::MAIN
};

const GMIKHAIL::MenuItem GMIKHAIL::MAIN = {
    nullptr,
    GMIKHAIL::show_menu,
    nullptr,
    main_children,
    main_size,
    "Главное меню:"
};
