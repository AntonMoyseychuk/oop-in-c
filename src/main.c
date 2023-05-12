#include <stdio.h>

#include "wizzard.h"


int main() {
    CREATE_UNIT_INSTANCE(player);
    CREATE_WIZZARD_INSTANCE(enemy);

    player.construct(&player, 100.0f, 5.0f);
    enemy.construct(&enemy, 70.0f, 15.0f, 100.0f);
    
    while(player.is_alive(&player) && enemy.is_alive(&enemy)) {
        player.atack(&player, &enemy);
        enemy.atack(&enemy, &player);
    }

    printf_s("player is alive: %s\n", player.is_alive(&player) ? "true" : "false");
    printf_s("enemy is alive: %s\n", enemy.is_alive(&enemy) ? "true" : "false");

    player.destruct(&player);
    enemy.destruct(&enemy);
    return 0;
}