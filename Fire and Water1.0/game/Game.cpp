#include "game.h"
#include "../common.h"
#include "player.h"
#include "level.h"
#include "../physic/collision.h"
#include "../graphics/render.h"
#include "../graphics/ui.h"
#include "../input/input.h"
#include <graphics.h>
#include <conio.h>
#include <windows.h>

// 全局输入状态
InputState g_input;

// 初始化游戏
void game_init(Game* game) {
    if (!game) return;

    // TODO: 初始化游戏状态
    game->state = STATE_MENU;
    game->currentLevelNum = 1;
    game->isRunning = true;

    // TODO: 初始化图形窗口
    // initgraph 等代码
}

// 运行游戏主循环
void game_run(Game* game) {
    if (!game) return;

    // TODO: 游戏主循环
    while (game->isRunning) {
        game_handle_input(game);
        game_update(game);
        game_draw(game);
        Sleep(16); // 控制帧率
    }

    // TODO: 关闭图形窗口
    // closegraph();
}

// 处理输入
void game_handle_input(Game* game) {
    // TODO: 更新输入状态
    // input_update(&g_input);

    // TODO: 根据游戏状态处理输入
}

// 更新游戏逻辑
void game_update(Game* game) {
    if (!game) return;

    // TODO: 根据游戏状态更新
    switch (game->state) {
    case STATE_GAME:
        // TODO: 更新玩家、检查碰撞等
        break;
    default:
        break;
    }
}

// 绘制游戏
void game_draw(Game* game) {
    if (!game) return;

    // TODO: 清屏
    // render_clear();

    // TODO: 根据状态绘制
    switch (game->state) {
    case STATE_MENU:
        // ui_draw_menu(...);
        break;
    case STATE_GAME:
        // ui_draw_game(...);
        break;
        // TODO: 其他状态
    }

    // TODO: 显示画面
    // render_present();
}