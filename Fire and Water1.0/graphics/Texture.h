#pragma once
#include <graphics.h>

// 贴图ID枚举
typedef enum {
    // 玩家贴图
    TEX_FIRE_IDLE = 0,
    TEX_FIRE_WALK1,
    TEX_FIRE_WALK2,
    TEX_FIRE_JUMP,
    TEX_WATER_IDLE,
    TEX_WATER_WALK1,
    TEX_WATER_WALK2,
    TEX_WATER_JUMP,

    // 地图贴图
    TEX_MAP1,
    TEX_MAP2,
    TEX_MAP3,
    TEX_WALL,
    TEX_FLOOR,
    TEX_PLATFORM,
    TEX_BACKGROUND,

    // 陷阱贴图
    TEX_TRAP_FIRE,
    TEX_TRAP_WATER,
    TEX_TRAP_SPIKE,

    // 门贴图
    TEX_DOOR_OPEN,
    TEX_DOOR_CLOSE,

    // 总贴图数量
    TEX_COUNT
} TextureID;

// 贴图管理器
struct TextureManager {
    IMAGE images[TEX_COUNT];
    bool loaded;
};


// 函数声明
void tex_init(TextureManager* tm);
void tex_load_all(TextureManager* tm);
IMAGE* tex_get(TextureManager* tm, TextureID id);
void tex_cleanup(TextureManager* tm);
void CreatePlaceholderTexture(IMAGE* img, int texId);

extern TextureManager g_textures;