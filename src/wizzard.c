#include "wizzard.h"

#include <stdio.h>
#include <assert.h>

#pragma region private
typedef struct __wizzard_private_section {
    unit base;
    float mana;
} _wizzard_private_section;

static void ___alloc_wizzard_private_section(struct __wizzard_private_section **private_section) {
    *private_section = (struct __wizzard_private_section*)malloc(sizeof(struct __wizzard_private_section));
    assert(*private_section != NULL);
}

static void ___wizzard_private_section_constructor(_wizzard_private_section* self, float health, float damage, float mana) {
    CREATE_UNIT_INSTANCE(&self->base);

    self->base.construct(&self->base, health, damage);

    self->mana = mana;
}
#pragma endregion private

static void _wizzard_default_constructor(wizzard *self) {
    ___alloc_wizzard_private_section(&self->_private_section);
    ___wizzard_private_section_constructor(self->_private_section, 0.0f, 0.0f, 0.0f);
}

static void _wizzard_constructor(wizzard *self, float health, float damage, float mana) {
    ___alloc_wizzard_private_section(&self->_private_section);
    ___wizzard_private_section_constructor(self->_private_section, health, damage, mana);
}

static void _wizzard_destructor(const wizzard *self) {
    self->_private_section->base.destruct(&self->_private_section->base);
    free(self->_private_section);
}

static void _wizzard_atack(wizzard *self, unit *enemy) {
    printf_s("Hello from wizzard attack method\n");
    self->_private_section->base.atack(&self->_private_section->base, enemy);
    
    if (self->_private_section->mana > 0.0f) {
        enemy->take_damage(enemy, 10.0f);
        self->_private_section->mana -= 20.0f;
    }
}

static void _wizzard_take_damage(wizzard *self, float damage) {
    self->_private_section->base.take_damage(&self->_private_section->base, damage);
}

static bool _wizzard_is_alive(const wizzard* self) {
    return self->_private_section->base.is_alive(&self->_private_section->base);
}

void __init_wizzard_methods(wizzard *self) {
    self->default_construct = _wizzard_default_constructor;
    self->construct = _wizzard_constructor;        
    self->destruct = _wizzard_destructor;          
    self->atack = _wizzard_atack;
    self->take_damage = _wizzard_take_damage;
    self->is_alive = _wizzard_is_alive;
}