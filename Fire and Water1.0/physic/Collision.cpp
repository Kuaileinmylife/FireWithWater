#include "collision.h"
#include "../common.h"

// ¼ì²âÁ½¸ö¾ØÐÎÊÇ·ñÅö×²
bool collision_check(Rect a, Rect b) {
    // TODO: AABBÅö×²¼ì²â
    bool collisionX = a.x + a.width >= b.x && b.x + b.width >= a.x;
    bool collisionY = a.y + a.height >= b.y && b.y + b.height >= a.y;
    return collisionX && collisionY;
}

// ¼ì²âÍæ¼ÒÓë¾ØÐÎµÄÅö×²
bool collision_player_rect(const Player* player, Rect rect) {
    if (!player) return false;

    // TODO: »ñÈ¡Íæ¼Ò±ß½ç²¢¼ì²âÅö×²
    return false;
}

// »ñÈ¡Íæ¼ÒµÄÅö×²¿ò
Rect player_get_bounds(const Player* player) {
    Rect bounds = { 0, 0, PLAYER_WIDTH, PLAYER_HEIGHT };

    if (player) {
        bounds.x = player->position.x;
        bounds.y = player->position.y;
    }

    return bounds;
}