#include "unit.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void __unit_private_block_constructor(struct __unit_private_section *self, float health, float damage) {
    self->health = health;
    self->damage = damage;
}

static void ___init_unit(unit *self, float health, float damage) {
    __unit_private_block_constructor(&self->_private_section, health, damage);
}

static void _unit_default_constructor(unit *self) {
    ___init_unit(self, 0.0f, 0.0f);
}

static void _unit_constructor(unit *self, float health, float damage) {
    ___init_unit(self, health, damage);
}

static void _unit_destructor(const unit *self) {
    
}

static void _unit_atack(unit *self, unit *enemy) {
    printf_s("Hello from unit attack method\n");
    enemy->_private_section.health -= self->_private_section.damage;
}

static void _unit_take_damage(unit *self, float damage) {
    self->_private_section.health -= damage;
}

static bool _unit_is_alive(const unit *self) {
    return self->_private_section.health > 0.0f;
}

void __init_unit_methods(unit *self) {
    self->default_construct = _unit_default_constructor;
    self->construct = _unit_constructor;        
    self->destruct = _unit_destructor;          
    self->atack = _unit_atack;
    self->take_damage = _unit_take_damage;
    self->is_alive = _unit_is_alive;
}