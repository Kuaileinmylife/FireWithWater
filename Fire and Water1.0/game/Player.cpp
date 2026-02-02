#include "player.h"
#include "../common.h"
#include "../graphics/texture.h"
#include "../graphics/render.h"
#include <math.h>
#include <stdio.h>
#include <graphics.h>

// 初始化玩家
void player_init(Player* p, PlayerType type, float x, float y) {
    if (!p) return;

    p->type = type;
    p->isAlive = true;
    p->isOnGround = false;
    p->isJumping = false;
    p->facing = DIR_STAND;
    p->position.x = x;
    p->position.y = y;
    p->velocity.x = 0;
    p->velocity.y = 0;
    p->bounds.x = x;
    p->bounds.y = y;
    p->bounds.width = PLAYER_WIDTH;
    p->bounds.height = PLAYER_HEIGHT;
}

// 更新玩家状态
void player_update(Player* p) {
    if (!p || !p->isAlive) return;


    // 应用重力
    p->velocity.y += GRAVITY;

    // 限制最大下落速度
    if (p->velocity.y > 20.0f) {
        p->velocity.y = 20.0f;
    }

    // 更新位置
    if (p->facing != DIR_STAND) {
        p->position.x += p->velocity.x;
        //p->facing = DIR_STAND;              // 这里有点问题
    }
    p->position.y += p->velocity.y;

    // 更新碰撞框
    p->bounds.x = p->position.x;
    p->bounds.y = p->position.y;

    // 简单的地面检测（假设窗口底部是地面）
    if (p->position.y + PLAYER_HEIGHT >= WINDOW_HEIGHT) {
        p->position.y = WINDOW_HEIGHT - PLAYER_HEIGHT;
        p->velocity.y = 0;
        p->isOnGround = true;
        p->isJumping = false;
    }
    else {
        p->isOnGround = false;
    }

    // 简单的墙壁检测（假设窗口边界是墙壁）
    if (p->position.x < 0) {
        p->position.x = 0;
    }
    if (p->position.x + PLAYER_WIDTH > WINDOW_WIDTH) {
        p->position.x = WINDOW_WIDTH - PLAYER_WIDTH;
    }
}

// 移动玩家
void player_move(Player* p, float dx) {
    if (!p || !p->isAlive) return;

    // dx = -1：向左移动
    // dx = 0：停止移动  
    // dx = 1：向右移动

    // 设置水平速度
    p->velocity.x = dx * PLAYER_SPEED;  // PLAYER_SPEED = 5.0f

    // 记录朝向（用于绘制和动画）
    if (dx < 0) {
        p->facing = DIR_LEFT;
    }
    else if (dx > 0) {
        p->facing = DIR_RIGHT;
    }
}

// 玩家跳跃
void player_jump(Player* p) {
    if (!p || !p->isAlive) return;

    // 只有在地面时才能跳跃
    if (p->isOnGround) {
        p->velocity.y = JUMP_FORCE;
        p->isJumping = true;
        p->isOnGround = false;
    }
}

// 绘制玩家
void player_draw(Player* p, TextureManager* tm) {
    if (!p || !p->isAlive) return;
    IMAGE I;
    if (p->type == PLAYER_FIRE) {
        if (!p->isJumping && p->facing==DIR_STAND) {
            loadimage(&I, "firejump1.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
        }
        if (p->facing == DIR_RIGHT) {
            loadimage(&I, "firerunback2.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
            p->facing = DIR_STAND;
        }
        if (p->facing == DIR_LEFT) {
            loadimage(&I, "firerunback2.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
            p->facing = DIR_STAND;
        }
        if (p->isJumping) {
            loadimage(&I, "firejump2.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
        }
    }
    else {
        if (!p->isJumping && p->facing == DIR_STAND) {
            loadimage(&I, "icejump1.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
        }
        if (p->facing == DIR_RIGHT) {
            loadimage(&I, "icerunback4.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
            p->facing = DIR_STAND;
        }
        if (p->facing == DIR_LEFT) {
            loadimage(&I, "icerunback4.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
            p->facing = DIR_STAND;
        }
        if (p->isJumping) {
            loadimage(&I, "icejump2.png", 20, 20);
            putimage(p->position.x, p->position.y, &I);
        }
    }
}

// 检查玩家与陷阱的碰撞
bool player_check_trap(const Player* p, TrapType trap) {
    if (!p) return false;

    // TODO: 根据陷阱类型判断
    return false;
}