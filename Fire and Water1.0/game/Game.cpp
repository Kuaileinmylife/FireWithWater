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
    GameState state = game->state;
    if (state == STATE_WIN || state == STATE_LOSE) {
        closegraph();
    }
}

// 处理输入
void game_handle_input(Game* game) {
    // TODO: 更新输入状态
    // input_update(&g_input);

    // TODO: 根据游戏状态处理输入
    switch (game->state) {
    case STATE_MENU:
        // 处理菜单输入
        break;
    case STATE_GAME:
        // 处理游戏输入
        break;
    case STATE_PAUSE:
        // 处理暂停输入
        break;
    default:
        break;
    }
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
    // 1. 清屏（准备画新的一帧）
    render_clear();

    // 2. 根据游戏状态绘制不同界面
    switch (game->state) {
    case STATE_MENU:
        ui_draw_menu(0);  // 画主菜单
        break;

    case STATE_GAME:
        // 画游戏界面：玩家、关卡、UI
        ui_draw_game(&game->firePlayer, &game->waterPlayer, game->currentLevelNum);
        break;

    case STATE_PAUSE:
        ui_draw_game(&game->firePlayer, &game->waterPlayer, game->currentLevelNum);
        ui_draw_pause();  // 再画暂停界面（覆盖在上面）
        break;

    case STATE_WIN:
        ui_draw_win(game->currentLevelNum);  // 胜利界面
        break;

    case STATE_LOSE:
        ui_draw_lose();  // 失败界面
        break;
    }

    // 3. 显示到屏幕（双缓冲交换）
    render_present();
}
