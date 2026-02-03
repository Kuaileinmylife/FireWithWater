#define _CRT_SECURE_NO_WARNINGS
#include "texture.h"
#include <stdio.h>
#include <string>
#include <iostream>

TextureManager g_textures;

void tex_init(TextureManager* tm) {
    if (!tm) return;

    tm->loaded = false;
    // 不需要memset，Resize会初始化
}

// 在 tex_load_all 函数中，修改加载部分：
void tex_load_all(TextureManager* tm) {
    if (!tm || tm->loaded) return;

    const char* realFilenames[TEX_COUNT] = {
        // 确保这些文件存在
        "firerunback1.png",    // TEX_FIRE_IDLE (0)
        "firerunback2.png",    // TEX_FIRE_WALK1 (1)
        "firerunback2.png",    // TEX_FIRE_WALK2 (2)
        "firejump2.png",       // TEX_FIRE_JUMP (3) - 使用实际存在的文件

        "icerunback1.png",     // TEX_WATER_IDLE (4)
        "icerunback4.png",     // TEX_WATER_WALK1 (5)
        "icerunback4.png",     // TEX_WATER_WALK2 (6)
        "icejump2.png",        // TEX_WATER_JUMP (7) - 使用实际存在的文件

        "groud2.png",          // TEX_WALL (8)
        "groud1.png",          // TEX_FLOOR (9)
        "groud1.png",          // TEX_PLATFORM (10)
        "mainmenu.png",        // TEX_BACKGROUND (11)

        "groud4.png",          // TEX_TRAP_FIRE (12)
        "groud5.png",          // TEX_TRAP_WATER (13)
        "exit1.png",           // TEX_TRAP_SPIKE (14)

        "exit1.png",           // TEX_DOOR_CLOSE (15)
        "exit1.png"            // TEX_DOOR_OPEN (16)
    };

    int successCount = 0;
    for (int i = 0; i < TEX_COUNT; i++) {
        const char* filename = realFilenames[i];

        // 检查文件是否存在
        WIN32_FIND_DATA findData;
        HANDLE hFind = FindFirstFile(filename, &findData);

        
        // 加载图片
        tm->images[i].Resize(1, 1); // 初始化

        loadimage(&tm->images[i], filename);
        int result = 0;


        tm->loaded = true;
    }
}