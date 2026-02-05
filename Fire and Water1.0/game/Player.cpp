#include "player.h"
#include "../common.h"
#include "../graphics/texture.h"
#include "../graphics/render.h"
#include "../physic/Collision.h"
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

    p->position.width = 25; // 玩家的尺寸
    p->position.height = 25;
    p->iswin = false;  // 胜利判断的
}

// 更新玩家状态
void player_update(Player* p,Level* L) {
    if (!p || !p->isAlive) return;
    
    
    // 应用重力
    p->velocity.y += GRAVITY;
   

    // 限制最大下落速度
    if (p->velocity.y > 12.0f) {
        p->velocity.y = 12.0f;
    }

    // 更新位置
    if (p->facing != DIR_STAND) {
        p->position.x += p->velocity.x;
    }
    p->position.y += p->velocity.y;
    collision_check(p, L);

    if (L->info.shouldStopX || L->info.shouldStopY) {
        p->position.x -= p->velocity.x;
        L->info.shouldStopX = false;
        p->position.y -= GRAVITY;
        L->info.shouldStopY = false;
    }
}

// 移动玩家
void player_move(Player* p, float dx) {
    if (!p || !p->isAlive) return;

    // dx = -1：向左移动
    // dx = 0：停止移动  
    // dx = 1：向右移动

    // 设置水平速度
    p->velocity.x = dx * PLAYER_SPEED;

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

// 自定义透明贴图函数（替换没有transparentimage的情况）
void mytransparentimage(int x, int y, IMAGE* pimg, COLORREF transcolor)
{
    if (pimg == NULL) return;

    DWORD* pBuffer = GetImageBuffer();       // 屏幕缓冲区
    DWORD* pMem = GetImageBuffer(pimg);      // 图片缓冲区
    int imgWidth = pimg->getwidth();
    int imgHeight = pimg->getheight();
    int winWidth = getwidth();
    int winHeight = getheight();

    for (int i = 0; i < imgHeight; i++)
    {
        for (int j = 0; j < imgWidth; j++)
        {
            int bufX = x + j;
            int bufY = y + i;
            // 只绘制非透明色且在屏幕范围内的像素
            if (bufX >= 0 && bufX < winWidth && bufY >= 0 && bufY < winHeight)
            {
                if (pMem[i * imgWidth + j] != transcolor)
                {
                    pBuffer[bufY * winWidth + bufX] = pMem[i * imgWidth + j];
                }
            }
        }
    }
}

// 绘制玩家
void player_draw(Player* p, TextureManager* tm) {
    if (!p || !p->isAlive) return;
    IMAGE I;
    if (p->type == PLAYER_FIRE) {
        if (!p->isJumping && p->facing==DIR_STAND) {
            loadimage(&I, "firejump1.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
        }
        if (!p->isJumping && p->facing == DIR_RIGHT) {
            loadimage(&I, "firerunright.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
            p->facing = DIR_STAND;
        }
        if (!p->isJumping && p->facing == DIR_LEFT) {
            loadimage(&I, "firerunback2.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
            p->facing = DIR_STAND;
        }
        if (p->isJumping) {
            loadimage(&I, "firejump2.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
        }
    }
    else {
        if (!p->isJumping && p->facing == DIR_STAND) {
            loadimage(&I, "icejump1.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
        }
        if (!p->isJumping && p->facing == DIR_RIGHT) {
            loadimage(&I, "icerunright.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
            p->facing = DIR_STAND;
        }
        if (!p->isJumping && p->facing == DIR_LEFT) {
            loadimage(&I, "icerunback4.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
            p->facing = DIR_STAND;
        }
        if (p->isJumping) {
            loadimage(&I, "icejump2.png", p->position.width, p->position.height);
            mytransparentimage(p->position.x, p->position.y, &I,RGB(0,0,0));
        }
    }
}