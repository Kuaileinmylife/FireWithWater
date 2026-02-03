#pragma once
#include "../common.h"

typedef struct Game {
    GameState state;              // 当前状态
    Player firePlayer;            // 火人
    Player waterPlayer;           // 水人
    Level currentLevel;           // 当前关卡
    int currentLevelNum;          // 关卡编号(0-2)先三关
    bool isRunning;               // 游戏是否运行
    int menuSelection;            // 菜单选择(0-3)
    int pauseSelection;           // 暂停选择(0-1)
} Game;

// 游戏函数声明

// 游戏初始化
// 功能：
// 1：调用render_init();初始化窗口
// 2：设置游戏初始化状态(仔细看定义里面需要初始化的地方)
// 3：调用level_init()先初始化第一关
// 4：调用 player_init初始化冰火人
// 5；加载音乐图片等(拓展)
void game_init(Game* game);

// 游戏主循环
// 功能：
// 1；仔细观看定义设计循环while
// 2：调用game_handle_input处理输入
// 3：调用game_update更新游戏逻辑
// 4：调用game_draw绘制画
// 5：如果可以就控制一下帧率
// 6：游戏如果结束，退出要关闭窗口
void game_run(Game* game);

// 计算游戏变化
// 功能：
// 1：必须在游戏状态下才更新
// 2：调用player_update更新移动，重力等
// 3：调用check_wall_collision检查碰撞
// 4：调用check_trap_collision检测陷阱
// 5；检测游戏结束(仔细看定义)
// 6；调用check_door_collision检测是否到出口
// 7：调用update_mechanisms更新机关，平台等
void game_update(Game* game);

// 绘制游戏画面
// 功能：把游戏可视化到窗口上
// 1；清屏
// 2；详细看定义，根据游戏状态(界面)绘制，比如；调用ui_draw_menu绘制主菜单，调用ui_draw_game绘制游戏画面，调用ui_draw_game再调用ui_draw_pause实现暂停界面，调用ui_draw_win绘制胜利界面，调用ui_draw_lose绘制失败界面，最后调用render_present显示到屏幕
void game_draw(Game* game);

// 读取玩家的操作
// 功能：
// 1; 调用input_update更新输入状态(一定仔细看定义)
// 2：根据当前游戏状态(所处界面)switch处理不同的输入。比如：菜单状态，处理ws选择菜单栏，游戏状态，处理人物的移动(调player_move,player_jump),游戏内的按键，暂停等，最后还有暂停状态
void game_handle_input(Game* game);