#pragma once
#include <easyx.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>

#include <string.h>
#include <stdbool.h>
#pragma comment(lib, "winmm.lib")


// ========== 地图代码块 =========

typedef struct {
    float x, y;       // 位置
    float width, height;  // 尺寸
}MapBoundary;// 地图边界

typedef struct {
    float x, y;
    float width, height;
}Platfrom;// 空气墙

typedef struct {
    float x, y;    // 位置
    float width, height;  // 尺寸
    int type;   // 0:火池，1：水池，2：毒池，3：火出口，4：水出口 ,5: 门  ,6: 按钮
    bool isActive;  // 是否在区域内
}Trapstation;// 陷阱和出口

typedef struct {
    bool shouldStopX;     // 是否需要停止水平移动
    bool shouldStopY;     // 是否需要停止垂直移动
    bool isOnGround;      // 是否在地面上
    float groundY;        // 地面的Y坐标（如果站在平台上）
} CollisionInfo;

typedef struct {
    float x, y;
    float width, height;
    int type;  // 0;红宝石  1；蓝宝石
    bool isGet;
}diamond;

// ========== 基础类型 ==========

typedef struct {
    float x, y, width, height;
}Vector2;

typedef struct {
    float x, y, width, height;
}Rect;

typedef enum {
    DIR_LEFT = -1,
    DIR_RIGHT = 1,
    DIR_STAND=0
}Direction;    // 朝向的定义

// ========== 枚举定义 ==========
typedef enum {
    PLAYER_FIRE = 0,    // 火人
    PLAYER_WATER = 1    // 水人
}PlayerType;

typedef enum {
    STATE_MENU = 0,      // 主菜单
    STATE_GAME = 1,      // 游戏中
    STATE_PAUSE = 2,     // 暂停
    STATE_WIN =  3,      // 胜利
    STATE_LOSE = 4,      // 失败
    STATE_TEAM= 5,       // 团队介绍界面
    STATE_SET= 6        // 设置界面
}GameState;

typedef enum {
    TILE_EMPTY = 0,     // 空地
    TILE_WALL = 1,      // 墙壁
    TILE_PLATFORM = 2   // 平台
}TileType;// 砖块类型

typedef enum {
    TRAP_NONE = 0,
    TRAP_FIRE = 1,      // 火池：火人过，水人死
    TRAP_WATER = 2,     // 水池：水人过，火人死
    TRAP_SPIKE = 3      // 尖刺：都死
}TrapType;// 陷阱类型

// ========== 结构体定义 ==========

// 玩家属性
typedef struct {
    Vector2 position;    // 位置
    Vector2 velocity;    // 速度
    PlayerType type;     // 类型
    Rect bounds;         // 碰撞框
    bool isOnGround;     // 是否在地面
    bool isAlive;        // 是否活着
    bool isJumping;      // 是否在跳跃
    Direction facing;    // 朝向
    bool iswin;          // 是否到达出口
} Player;

// 关卡属性
typedef struct {
    int width, height;            // 地图大小
    TileType tiles[20][20];       // 地图格子
    Vector2 fireStart;            // 火人起点
    Vector2 waterStart;           // 水人起点
    Rect doorPosition;            // 门的位置
    TrapType traps[10];           // 陷阱类型
    Rect trapRects[10];           // 陷阱位置

    int platfromCount;            // 空气墙数量
    int trapCount;                // 陷阱数量
    int diaCount;                 // 宝石数量
    int currentMap;               // 当前地图编号

    MapBoundary mapboundary_level1[4];  // 地图一的四个边界
    Platfrom platfrom_level1[100];  // 地图一的空气墙
    Trapstation trapstation1[100];   // 地图一的陷阱以及出口

    MapBoundary mapboundary_level2[4];  // 地图二的四个边界
    Platfrom platfrom_level2[100];  // 地图二的空气墙
    Trapstation trapstation2[100];   // 地图二的陷阱以及出口

    MapBoundary mapboundary_level3[4];  // 地图三的四个边界
    Platfrom platfrom_level3[200];  // 地图三的空气墙
    Trapstation trapstation3[100];   // 地图三的陷阱以及出口

    CollisionInfo info;

    diamond diamond1[10];
    diamond diamond2[10];
    diamond diamond3[10];

    bool isinit;

    int diacount1;
    int diacount2;
    int diacount3;
} Level;


// ========== 游戏常量 ==========

// 窗口设置
#define WINDOW_WIDTH   800
#define WINDOW_HEIGHT  600
#define WINDOW_TITLE   "森林冰火人"

// 玩家设置
#define PLAYER_WIDTH   40       // 玩家矩形的宽
#define PLAYER_HEIGHT  60       // 玩家矩形的高
#define PLAYER_SPEED   6.0f     // 玩家的速度
#define JUMP_FORCE    -12.0f    // 起跳的速度
#define GRAVITY        1.0f     // 重力
#define FRICTION       0.8f     // 水平摩擦力

// 按键定义(别忘了还有小写实现)
#define KEY_FIRE_UP    'W'
#define KEY_FIRE_LEFT  'A'  
#define KEY_FIRE_RIGHT 'D'
#define KEY_WATER_UP    VK_UP       // 水娃的跳跃键
#define KEY_WATER_LEFT  VK_LEFT     // 水娃的左移
#define KEY_WATER_RIGHT VK_RIGHT    // 水娃的右移
#define KEY_PAUSE       VK_ESCAPE   // 设置界面的按键
#define KEY_SELECT      VK_RETURN   // 回车键

// 颜色定义 (具体的根据实际情况来设)
#define COLOR_FIRE      RGB(255, 100, 100)   // 火人红色
#define COLOR_WATER     RGB(100, 100, 255)   // 水人蓝色
#define COLOR_WALL      RGB(100, 70, 30)     // 墙壁棕色
#define COLOR_PLATFORM  RGB(150, 120, 80)    // 平台浅棕
#define COLOR_TRAP_FIRE RGB(255, 150, 50)    // 火池橙色
#define COLOR_TRAP_WATER RGB(50, 150, 255)   // 水池蓝色
#define COLOR_TRAP_SPIKE RGB(100, 100, 100)  // 尖刺灰色
#define COLOR_DOOR      RGB(50, 200, 50)     // 门绿色
#define COLOR_BG        RGB(200, 230, 255)   // 背景天蓝色


// -------------------------- 音乐配置（自行修改相对路径） --------------------------
// 1. 菜单/暂停共用音乐
#define MENU_PAUSE_MUSIC  _T("menu.mp3")
#define MENU_PAUSE_ALIAS  _T("menu_bgm")

// 2. 游戏过程背景音乐
#define GAME_PLAY_MUSIC   _T("backmusic.mp3")
#define GAME_PLAY_ALIAS   _T("game_play_bgm")

// 3. 胜利场景音乐（单次播放）
#define WIN_MUSIC         _T("win.mp3")
#define WIN_ALIAS         _T("win_bgm")

// 4. 失败场景音乐（单次播放）
#define FAIL_MUSIC        _T("fail.mp3")
#define FAIL_ALIAS        _T("fail_bgm")
// ----------------------------------------------------------------------------------


// 音乐状态枚举
typedef enum {
    MUSIC_STOP,   // 停止
    MUSIC_PLAYING,// 播放中
    MUSIC_PAUSED  // 暂停中
} MusicState;

extern bool g_musicEnabled;  // 音乐开关，在 Game.cpp 中定义
extern int g_volumeLevel;      // 音量级别