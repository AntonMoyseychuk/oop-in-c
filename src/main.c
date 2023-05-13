#include <stdio.h>

#include "wizzard.h"

int main() {
    unit _unit;
    CREATE_UNIT_INSTANCE(&_unit);

    wizzard _wizzard;
    CREATE_WIZZARD_INSTANCE(&_wizzard);

    _unit.construct(&_unit, 100.0f, 5.0f);
    _wizzard.construct(&_wizzard, 70.0f, 15.0f, 100.0f);

    // _wizzard.take_damage(&_wizzard, 300.0f);
    
    while(_unit.is_alive(&_unit) && _wizzard.is_alive(&_wizzard)) {
        _unit.atack(&_unit, &_wizzard);
        _wizzard.atack(&_wizzard, &_unit);
    }

    printf_s("\n_unit is alive: %s\n", _unit.is_alive(&_unit) ? "true" : "false");
    printf_s("_wizzard is alive: %s\n", _wizzard.is_alive(&_wizzard) ? "true" : "false");

    _unit.destruct(&_unit);
    _wizzard.destruct(&_wizzard);
    return 0;
}