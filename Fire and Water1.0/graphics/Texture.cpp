#define _CRT_SECURE_NO_WARNINGS
#include "texture.h"
#include <stdio.h>
#include <string>
#include <iostream>

TextureManager g_textures;

//const char* TEXTURE_PATHS[TEX_COUNT] = {
//    // 玩家贴图
//    "firerunback4.png",        // 火人站立
//    "firerunback3.png",        // 火人行走1
//    "firerunback3.png",        // 火人行走2
//    "firejump3.png",           // 火人跳跃
//
//    "icerunback5.png",         // 水人站立
//    "icerunback4.png",         // 水人行走1
//    "icerunback4.png",         // 水人行走2
//    "icejump3.png",            // 水人跳跃
//
//    // 地图贴图
//    "groud2.png",              // 墙壁
//    "groud1.png",              // 地板
//    "groud1.png",              // 平台
//    "mainmenu.png",            // 背景
//
//    // 陷阱贴图
//    "groud4.png",              // 火陷阱
//    "groud5.png",              // 水陷阱
//    "exit1.png",               // 尖刺
//
//    // 门贴图
//    "exit1.png",               // 门关闭
//    "exit1.png",               // 门打开
//};

//// 创建替代贴图的函数定义
//void CreatePlaceholderTexture(IMAGE* img, int texId) {
//    if (!img) return;
//
//    img->Resize(100, 100);
//
//    // 设置工作图像为当前贴图
//    SetWorkingImage(img);
//
//    // 根据贴图ID设置不同颜色
//    COLORREF color;
//    const char* label;
//
//    // 根据贴图类型设置颜色
//    if (texId >= TEX_FIRE_IDLE && texId <= TEX_FIRE_JUMP) {
//        color = RGB(255, 100, 100); // 红色 - 火人
//        label = "FIRE";
//    }
//    else if (texId >= TEX_WATER_IDLE && texId <= TEX_WATER_JUMP) {
//        color = RGB(100, 100, 255); // 蓝色 - 水人
//        label = "WATER";
//    }
//    else if (texId == TEX_BACKGROUND) {
//        color = RGB(200, 230, 255); // 天蓝 - 背景
//        label = "BG";
//    }
//    else if (texId == TEX_WALL) {
//        color = RGB(100, 70, 30); // 棕色 - 墙壁
//        label = "WALL";
//    }
//    else if (texId == TEX_FLOOR || texId == TEX_PLATFORM) {
//        color = RGB(150, 120, 80); // 浅棕 - 地板/平台
//        label = "FLOOR";
//    }
//    else if (texId == TEX_TRAP_FIRE) {
//        color = RGB(255, 150, 50); // 橙色 - 火陷阱
//        label = "TRAP-F";
//    }
//    else if (texId == TEX_TRAP_WATER) {
//        color = RGB(50, 150, 255); // 蓝色 - 水陷阱
//        label = "TRAP-W";
//    }
//    else if (texId == TEX_DOOR_CLOSE || texId == TEX_DOOR_OPEN) {
//        color = RGB(50, 200, 50); // 绿色 - 门
//        label = "DOOR";
//    }
//    else {
//        color = RGB(100, 100, 100); // 灰色 - 默认
//        label = "TEX";
//    }
//
//    // 填充颜色
//    setfillcolor(color);
//    solidrectangle(0, 0, 50, 50);
//
//    // 添加文字标识
//    settextcolor(RGB(255, 255, 255));
//    setbkmode(TRANSPARENT);
//    settextstyle(10, 0, "Arial");
//    char text[20];
//    sprintf(text, "%s%d", label, texId);
//    outtextxy(5, 20, text);
//
//    // 恢复默认工作图像
//    SetWorkingImage(NULL);
//}

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

//// 在Texture.cpp中添加这个辅助函数
//const char* get_texture_name(int id) {
//    switch (id) {
//    case 0: return "火人站立";
//    case 1: return "火人行走1";
//    case 2: return "火人行走2";
//    case 3: return "火人跳跃";
//    case 4: return "水人站立";
//    case 5: return "水人行走1";
//    case 6: return "水人行走2";
//    case 7: return "水人跳跃";
//    case 8: return "墙壁";
//    case 9: return "地板";
//    case 10: return "平台";
//    case 11: return "背景";
//    case 12: return "火陷阱";
//    case 13: return "水陷阱";
//    case 14: return "尖刺";
//    case 15: return "关门";
//    case 16: return "开门";
//    default: return "未知";
//    }
//}
//// 获取贴图
//IMAGE* tex_get(TextureManager* tm, TextureID id) {
//    if (!tm || id < 0 || id >= TEX_COUNT) {
//        return NULL;
//    }
//    return &tm->images[id];
//}
//
//// 清理贴图资源
//void tex_cleanup(TextureManager* tm) {
//    if (!tm) return;
//    tm->loaded = false;
//}