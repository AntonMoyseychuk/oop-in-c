#pragma once
#include <stdbool.h>

struct __unit_private_section;

typedef struct _unit {
    struct __unit_private_section* _private_section;
    

    void (*default_construct)(struct _unit* self);
    void (*construct)(struct _unit* self, float health, float damage);
    void (*destruct)(const struct _unit* self);

    void (*atack)(struct _unit* self, struct _unit* enemy);
    void (*take_damage)(struct _unit* self, float damage);

    bool (*is_alive)(const struct _unit* self);
} unit;

void __init_unit_methods(unit *self);

#define CREATE_UNIT_INSTANCE(unit_ptr) __init_unit_methods(unit_ptr)