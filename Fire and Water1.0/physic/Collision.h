// physics/collision.h
#pragma once
#include "../common.h"

// Åö×²º¯ÊıÉùÃ÷
bool collision_check(Rect a, Rect b);
bool collision_player_rect(const Player* player, Rect rect);
Rect player_get_bounds(const Player* player);