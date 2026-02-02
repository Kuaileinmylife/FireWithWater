#include "level.h"
#include "../common.h"
#include "../graphics/Render.h"
#include "../graphics/Texture.h"

// 初始化关卡
void level_init(Level* level, int levelNum) {
    if (!level) return;

    level->width = 20;
    level->height = 15;
    level->trapCount = 0;
    level->currentMap = 0;

    // 初始化所有格子为空地
    for (int y = 0; y < level->height; y++) {
        for (int x = 0; x < level->width; x++) {
            level->tiles[y][x] = TILE_EMPTY;
        }
    }

    // 创建简单的地图 - 第一关
    if (level->currentMap == 0) {
        // 底部墙壁
        for (int x = 0; x < level->width; x++) {
            level->tiles[14][x] = TILE_WALL;
        }

        // 一些平台
        level->tiles[10][7] = TILE_PLATFORM;
        level->tiles[10][8] = TILE_PLATFORM;
        level->tiles[10][9] = TILE_PLATFORM;

        // 设置起点
        level->fireStart.x = 2 * 40;  // 2列 * 40像素
        level->fireStart.y = 12 * 40; // 12行 * 40像素
        level->waterStart.x = 4 * 40;
        level->waterStart.y = 12 * 40;

        // 设置门
        level->doorPosition.x = 17 * 40;  // 17列
        level->doorPosition.y = 5 * 40;   // 5行
        level->doorPosition.width = 3 * 40;  // 3格宽
        level->doorPosition.height = 4 * 40; // 4格高
    }
}

// 绘制关卡
void level_draw(const Level* level, TextureManager* tm) {
    if (!level) return;
    IMAGE p;
    switch (level->currentMap) {
    case 0:
        loadimage(&p, "map1.png", WINDOW_WIDTH, WINDOW_HEIGHT);
        putimage(0, 0, &p);
        break;
    case 1:

        break;
    case 2:

        break;
    }



    //
    //// 暂时先用纯色矩形绘制地图
    //const int TILE_SIZE = 16; // 每个格子的像素大小

    //for (int y = 0; y < level->height; y++) {
    //    for (int x = 0; x < level->width; x++) {
    //        int screenX = x * TILE_SIZE;
    //        int screenY = y * TILE_SIZE;

    //        switch (level->tiles[y][x]) {
    //        case TILE_WALL:
    //            render_rect(screenX, screenY, TILE_SIZE, TILE_SIZE, COLOR_WALL);
    //            break;
    //        case TILE_PLATFORM:
    //            render_rect(screenX, screenY, TILE_SIZE, TILE_SIZE, COLOR_PLATFORM);
    //            break;
    //        default:
    //            // 空地不绘制
    //            break;
    //        }
    //    }
    //}
    //// 绘制门
    //if (tm) {
    //    IMAGE* doorImg = tex_get(tm, TEX_DOOR_CLOSE);
    //    if (doorImg) {
    //        render_texture(level->doorPosition.x, level->doorPosition.y,
    //            level->doorPosition.width, level->doorPosition.height,
    //            doorImg);
    //    }
    //    else {
    //        render_rect(level->doorPosition.x, level->doorPosition.y,
    //            level->doorPosition.width, level->doorPosition.height,
    //            COLOR_DOOR);
    //    }
    //}
}

// 检查是否到达门口
bool level_check_door(const Level* level, Vector2 pos) {
    if (!level) return false;

    // 1. 简单的矩形检测：位置是否在门框内
    Rect door = level->doorPosition;

    // 检查 x 方向
    bool inX = (pos.x >= door.x) &&
        (pos.x <= door.x + door.width);

    // 检查 y 方向（考虑玩家高度）
    bool inY = (pos.y >= door.y) &&
        (pos.y + PLAYER_HEIGHT <= door.y + door.height);

    // 2. 返回结果
    return inX && inY;
}

// 检查陷阱碰撞
bool level_check_trap_collision(const Level* level, const Player* player) {
    if (!level || !player) return false;

    // TODO: 检查玩家是否碰到陷阱
    return false;
}