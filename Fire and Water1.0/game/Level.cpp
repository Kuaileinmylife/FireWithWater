#include "level.h"
#include "../common.h"
#include "../graphics/Render.h"
#include "../graphics/Texture.h"

// 初始化关卡
void level_init(Level* level, int levelNum) {
    if (!level) return;

    level->currentMap = 0;

    level->info.isOnGround = false;
    level->info.shouldStopX = false;
    level->info.shouldStopY = false;

    // 初始化所有格子为空地
    for (int y = 0; y < level->height; y++) {
        for (int x = 0; x < level->width; x++) {
            level->tiles[y][x] = TILE_EMPTY;
        }
    }

    // 创建地图 第一关
    if (level->currentMap == 0) {

        // level->info.groundY=多少       这个根据地图来定
         
        // 地图一的边界
        level->mapboundary_level1[0] = MapBoundary{ 0,0,0,0 };
        level->mapboundary_level1[1] = MapBoundary{ 0,0,0,0 };
        level->mapboundary_level1[2] = MapBoundary{ 0,0,0,0 };
        level->mapboundary_level1[3] = MapBoundary{ 0,0,0,0 };

        // 地图一的空气墙们
        level->platfrom_level1[0] = Platfrom{ 0,0,0,0 };
        level->platfrom_level1[1] = Platfrom{ 0,0,0,0 };
        level->platfrom_level1[2] = Platfrom{ 0,0,0,0 };
        level->platfrom_level1[3] = Platfrom{ 0,0,0,0 };

        // 地图一的各种陷阱和出口
        level->trapstation1[0] = Trapstation{ 0,0,0,0,0,false };
        level->trapstation1[1] = Trapstation{ 0,0,0,0,0,false };
        level->trapstation1[2] = Trapstation{ 0,0,0,0,0,false };
        level->trapstation1[3] = Trapstation{ 0,0,0,0,0,false };
            
        // 设置陷阱和出口一共的数量(这要初始化)
        level->trapCount = 0;

        // 设置起点                                     // 这有问题start根本没用上
        level->fireStart.x = 80;  // 2列 * 40像素
        level->fireStart.y = 480; // 12行 * 40像素
        level->waterStart.x = 4 * 40;
        level->waterStart.y = 12 * 40;
    }

    // 创建地图 第二关
    if (level->currentMap == 1) {

    }
    // 创建地图 第三关
    if (level->currentMap == 2) {

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
}

//// 检查是否到达门口
//bool level_check_door(const Level* level, Vector2 pos) {
//    if (!level) return false;
//
//    // 1. 简单的矩形检测：位置是否在门框内
//    Rect door = level->doorPosition;
//
//    // 检查 x 方向
//    bool inX = (pos.x >= door.x) &&
//        (pos.x <= door.x + door.width);
//
//    // 检查 y 方向（考虑玩家高度）
//    bool inY = (pos.y >= door.y) &&
//        (pos.y + PLAYER_HEIGHT <= door.y + door.height);
//
//    // 2. 返回结果
//    return inX && inY;
//}