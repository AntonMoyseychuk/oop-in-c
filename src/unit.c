#include "unit.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#pragma region private
typedef struct __unit_private_section {
    float health;
    float damage;
} _unit_private_section;

static void ___alloc_unit_private_section(struct __unit_private_section** private_section) {
    *private_section = (struct __unit_private_section*)malloc(sizeof(struct __unit_private_section));
    assert(*private_section != NULL);
}

static void ___unit_private_section_constructor(_unit_private_section* self, float health, float damage) {
    self->health = health;
    self->damage = damage;
}
#pragma endregion private



static void _unit_default_constructor(unit *self) {
    ___alloc_unit_private_section(&self->_private_section);
    ___unit_private_section_constructor(self->_private_section, 0.0f, 0.0f);
}

static void _unit_constructor(unit *self, float health, float damage) {
    ___alloc_unit_private_section(&self->_private_section);
    ___unit_private_section_constructor(self->_private_section, health, damage);
}

static void _unit_destructor(const unit *self) {
    free(self->_private_section);
}

static void _unit_atack(unit *self, unit *enemy) {
    printf_s("Hello from unit attack method\n");
    enemy->take_damage(enemy, self->_private_section->damage);
}

static void _unit_take_damage(unit *self, float damage) {
    if (damage > 0.0f) {
        self->_private_section->health -= damage;
    }
}

static bool _unit_is_alive(const unit *self) {
    return self->_private_section->health > 0.0f;
}

void __init_unit_methods(unit *self) {
    self->default_construct = _unit_default_constructor;
    self->construct = _unit_constructor;        
    self->destruct = _unit_destructor;          
    self->atack = _unit_atack;
    self->take_damage = _unit_take_damage;
    self->is_alive = _unit_is_alive;
}