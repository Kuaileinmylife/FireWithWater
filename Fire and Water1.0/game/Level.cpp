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
        level->mapboundary_level1[0] = MapBoundary{ 13,9,19,560 };
        level->mapboundary_level1[1] = MapBoundary{ 10,582,780,7 };
        level->mapboundary_level1[2] = MapBoundary{ 770,31,23,537 };
        level->mapboundary_level1[3] = MapBoundary{ 34,9,733,20 };

        // 地图一的空气墙们
        level->platfrom_level1[0] = Platfrom{ 35.91,573.16,342.64,15 };
        level->platfrom_level1[1] = Platfrom{ 474.31,569.68,55.86,15 };
        level->platfrom_level1[2] = Platfrom{ 639.4,572.16,69.33,7 };
        level->platfrom_level1[3] = Platfrom{ 711.72,529.41,5.49,38.77 };
        level->platfrom_level1[4] = Platfrom{ 720,510.52,200.50,12.43 };
        level->platfrom_level1[5] = Platfrom{ 677.30,445.9,8.48,33.80 };
        level->platfrom_level1[6] = Platfrom{ 595.01,449.38,78.8,5 };
        level->platfrom_level1[7] = Platfrom{ 536.16,469.76,143.14,6 };
        level->platfrom_level1[8] = Platfrom{ 0,0,0,0.0 };
        level->platfrom_level1[9] = Platfrom{ 481.29,472.74,32.87,16.90 };
        level->platfrom_level1[10] = Platfrom{ 392.02,446.89,99.25,10 };
        level->platfrom_level1[11] = Platfrom{ 349.13,466.28,126.18,10 };
        level->platfrom_level1[12] = Platfrom{ 328.18,424.52,51.37,41.26 };
        level->platfrom_level1[13] = Platfrom{ 33.92,429,276.81,5 };
        level->platfrom_level1[14] = Platfrom{ 37.91,409,319.2,5 };
        level->platfrom_level1[15] = Platfrom{ 37.91,485.67,236.91,9.94 };
        level->platfrom_level1[16] = Platfrom{ 43.89,505.05,229.92,10 };
        level->platfrom_level1[17] = Platfrom{ 266.83,487.16,5.49,23.36 };
        level->platfrom_level1[18] = Platfrom{ 107.24,307.21,7.98,28.79 };
        level->platfrom_level1[19] = Platfrom{ 110.72,305.22,299.75,10 };
        level->platfrom_level1[20] = Platfrom{ 115.21,322.06,266.33,5.45 };
        level->platfrom_level1[21] = Platfrom{ 400.98,319.14,24.45,17.4 };
        level->platfrom_level1[22] = Platfrom{ 395.01,351.95,253.37,10 };
        level->platfrom_level1[23] = Platfrom{ 403.91,325.6,334.16,10 };
        level->platfrom_level1[24] = Platfrom{ 666.33,344.49,44.89,27.84 };
        level->platfrom_level1[25] = Platfrom{ 719.7,353.44,78.8,57.17 };
        level->platfrom_level1[26] = Platfrom{ 595.01,267.44,95.26,5.97 };
        level->platfrom_level1[27] = Platfrom{ 572.57,226.68,122.69,10 };
        level->platfrom_level1[28] = Platfrom{ 534.66,204.81,25.94,32.31 };
        level->platfrom_level1[29] = Platfrom{ 390.02,187.90,140.15,10 };
        level->platfrom_level1[30] = Platfrom{ 388,198.84,7.98,24.36 };
        level->platfrom_level1[31] = Platfrom{ 133.17,225.68,260.85,10 };
        level->platfrom_level1[32] = Platfrom{ 34.41,245.57,537.65,8.95 };
        level->platfrom_level1[33] = Platfrom{ 128.18,163.55,10,60.65 };
        level->platfrom_level1[34] = Platfrom{ 34.41,148.63,96.26,11.93 };
        level->platfrom_level1[35] = Platfrom{ 199,90.47,26.43,22.87 };
        level->platfrom_level1[36] = Platfrom{ 228.43,91.96,31.42,30.82 };
        level->platfrom_level1[37] = Platfrom{ 262.34,109.86,42.39,23.36 };
        level->platfrom_level1[38] = Platfrom{ 231.42,138.19,103.24,53.69 };
        level->platfrom_level1[39] = Platfrom{ 314.21,126.26,212.97,10 };
        level->platfrom_level1[40] = Platfrom{ 344.64,148.63,418.45,3.98 };
        level->platfrom_level1[41] = Platfrom{ 534.16,113.84,14.46,25.85 };
        level->platfrom_level1[42] = Platfrom{ 552.12,113.84,51.37,5 };
        level->platfrom_level1[43] = Platfrom{ 607.98,112.84,12.97,29.33 };
        level->platfrom_level1[44] = Platfrom{ 629.42,128.75,46.88,8.45 };
        level->platfrom_level1[45] = Platfrom{ 25,367,48,8 };
        level->platfrom_level1[46] = Platfrom{ 732,286,40,8 };
        level->platfrom_level1[47] = Platfrom{ 132,187,40,8 };
        level->platfrom_level1[48] = Platfrom{ 74,367,10,48 };
        level->platfrom_level1[49] = Platfrom{ 732,286,10,48 };
        level->platfrom_level1[50] = Platfrom{ 163,187,10,48 };
        
        // 设置空气墙的数量
        level->platfromCount = 51;
        

        // 地图一的各种陷阱和出口
        level->trapstation1[0] = Trapstation{ 378,565,77,9,0,false };
        level->trapstation1[1] = Trapstation{ 540.65,560,83,6.5,1,false };
        level->trapstation1[2] = Trapstation{ 504,454,67,6,2,false };
        level->trapstation1[3] = Trapstation{ 638.9,71.5,41,51.7,3,false };
        level->trapstation1[4] = Trapstation{ 698.25,76.55,46.88,46.23,4,false };
            
        // 设置陷阱和出口一共的数量
        level->trapCount = 5;

        // 设置起点
        level->fireStart.x = 92;  // 2列 * 40像素
        level->fireStart.y = 518; // 12行 * 40像素
        level->waterStart.x = 92;
        level->waterStart.y = 437;
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