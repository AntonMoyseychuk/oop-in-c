#include "wizzard.h"

#include <stdio.h>

static void ___init_wizzard(wizzard *self, float health, float damage, float mana) {
    __init_unit_methods(&self->_private_section.base);
    self->_private_section.base.construct(&self->_private_section.base, health, damage);
    self->_private_section.mana = mana;
}

static void _wizzard_default_constructor(wizzard *self) {
    ___init_wizzard(self, 0.0f, 0.0f, 0.0f);
}

static void _wizzard_constructor(wizzard *self, float health, float damage, float mana) {
    ___init_wizzard(self, health, damage, mana);
}

static void _wizzard_destructor(const wizzard *self) {
    self->_private_section.base.destruct(&self->_private_section.base);
}

static void _wizzard_atack(wizzard *self, unit *enemy) {
    printf_s("Hello from wizzard attack method\n");
    self->_private_section.base.atack(&self->_private_section.base, enemy);
    
    if (self->_private_section.mana > 0.0f) {
        enemy->_private_section.health -= 10.0f;
        self->_private_section.mana -= 20.0f;
    }
}

static void _wizzard_take_damage(wizzard *self, float damage) {
    self->_private_section.base.take_damage(&self->_private_section.base, damage);
}

static bool _wizzard_is_alive(const wizzard* self) {
    return self->_private_section.base.is_alive(&self->_private_section.base);
}

void __init_wizzard_methods(wizzard *self) {
    self->default_construct = _wizzard_default_constructor;
    self->construct = _wizzard_constructor;        
    self->destruct = _wizzard_destructor;          
    self->atack = _wizzard_atack;
    self->take_damage = _wizzard_take_damage;
    self->is_alive = _wizzard_is_alive;
}