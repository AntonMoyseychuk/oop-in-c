#pragma once
#include <stdint.h>
#include <stdbool.h>


typedef struct __unit_private_section {
    float health;
    float damage;
} _private_section;

typedef struct _unit {
    _private_section _private_section;
    

    void (*default_construct)(struct _unit* self);
    void (*construct)(struct _unit* self, float health, float damage);
    void (*destruct)(const struct _unit* self);

    void (*atack)(struct _unit* self, struct _unit* enemy);
    void (*take_damage)(struct _unit* self, float damage);

    bool (*is_alive)(const struct _unit* self);
} unit;

void __init_unit_methods(unit *self);

#define CREATE_UNIT_INSTANCE(name) unit name; __init_unit_methods(&name)