#ifndef STATE_H
#define STATE_H

#include "entity.h"

#define PLAYER_HP  10
#define PLAYER_RAD 10
#define PLAYER_SPEED 4
#define PLAYER_COOLDOWN 8

#define MINION_HP   4
#define MINION_RAD 12
#define BRUTE_RAD  16
#define BRUTE_HP   12

#define BOSS_RAD  30
#define BOSS_HP   150
#define BOSS_SPEED 2

#define BULLET_DMG 3
#define BULLET_SPEED 16
#define BULLET_RAD   5


// ==== PLAYER DEFINITION
typedef struct {
    entity ent;
    // Cooldown of the player's weapon. The player can shoot when it is <=0.
    int cooldown;
} player;

// ==== ENEMY DEFINITION
// Agregue el enemigo BOOS y sus fases a la struct enemy, mi unica duda si al agregarlos aqui afectara al numero total de enemigos
typedef enum {MINION=0, BRUTE=1,BOSS=2, BOSS2=3, BOSS3=4 } enemykind;

typedef struct {
    entity ent;
    enemykind kind;
} enemy;

// ==== BULLET DEFINTION

typedef struct {
    entity ent;
    // TODO: We may want to add more fields...
} bullet;

// ==== STATE DEFINITION

#define MAX_ENEMIES 128
#define MAX_BULLETS 128

#define N_BUTTONS 5

// A state represents everything that's happening with the game objects at a given time.
typedef struct {
    // The player
    player pla;

    // An array of enemies:
    int n_enemies;
    enemy enemies[MAX_ENEMIES];

    // An array of bullets:
    int n_bullets;
    bullet bullets[MAX_BULLETS];

    // State of the controls, should be updated on each step.
    int button_state[N_BUTTONS];
    float aim_angle;

} state;

// Creates an empty state, allocating memory for it.
state *state_new();

// Updates the state of the game to the next frame.
void state_update(level *lvl, state *sta);

// Put enemies at random in the state until it has n_enemies enemies.
void state_populate_random(level *lvl, state *sta, int n_enemies);

// Deletes a state and the memory it requires.
void state_free(state *sta);



#endif
