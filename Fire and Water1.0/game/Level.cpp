#include "level.h"
#include "../common.h"

// 初始化关卡
void level_init(Level* level, int levelNum) {
    if (!level) return;

    // TODO: 根据关卡编号设置地图
    level->width = 20;
    level->height = 15;
}

// 绘制关卡
void level_draw(const Level* level) {
    if (!level) return;

    // TODO: 绘制地图、陷阱、门等
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