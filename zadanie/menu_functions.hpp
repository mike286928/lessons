#pragma once

#include "menu.hpp"

namespace GMIKHAIL {

    const MenuItem* show_menu(const MenuItem* current);
    const MenuItem* exit(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);

    const MenuItem* travel_vladivostok(const MenuItem* current);
    const MenuItem* travel_sakhalin(const MenuItem* current);
    const MenuItem* travel_khabarovsk(const MenuItem* current);
    const MenuItem* region_not_filled(const MenuItem* current);

}
