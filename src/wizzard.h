#pragma once
#include "unit.h"

struct __wizzard_private_section;

typedef struct _wizzard {
    struct __wizzard_private_section* _private_section;
    

    void (*default_construct)(struct _wizzard* self);
    void (*construct)(struct _wizzard* self, float health, float damage, float mana);
    void (*destruct)(struct _wizzard* self);

    void (*atack)(struct _wizzard* self, unit* enemy);
    void (*take_damage)(struct _wizzard* self, float damage);

    bool (*is_alive)(const struct _wizzard* self);
} wizzard;

void __init_wizzard_methods(wizzard *self);

#define CREATE_WIZZARD_INSTANCE(wizzard_ptr) __init_wizzard_methods(wizzard_ptr)