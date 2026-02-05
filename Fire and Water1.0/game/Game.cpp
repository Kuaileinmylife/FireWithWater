#include "game.h"
#include "../common.h"
#include "../graphics/render.h"
#include "../graphics/texture.h"
#include "player.h"
#include "level.h"
#include "../physic/collision.h"
#include "../graphics/ui.h"
#include "../input/input.h"
#include <graphics.h>
#include <conio.h>
#include <windows.h>

static DWORD g_lastInputTime = 0;
const DWORD INPUT_COOLDOWN = 200;

// 全局输入状态
InputState g_input;

extern TextureManager g_textures;

// 初始化游戏
void game_init(Game* game) {
    if (!game) return;
    game->currentLevel.isinit = false;

    // 1. 初始化图形窗口
    render_init();

    // 2. 初始化贴图管理器
    tex_init(&g_textures);
    tex_load_all(&g_textures);

    // 3. 初始化游戏状态
    game->state = STATE_MENU;
    game->currentLevelNum = 0;
    game->isRunning = true;
    game->menuSelection = 0;
    game->pauseSelection = 0;

    // 5. 初始化关卡
    game->currentLevelNum = level_init(&game->currentLevel, game->currentLevelNum);
    game->currentLevel.currentMap = 0;

    // 4. 初始化玩家
    player_init(&game->firePlayer, PLAYER_FIRE, game->currentLevel.fireStart.x, game->currentLevel.fireStart.y);
    player_init(&game->waterPlayer, PLAYER_WATER, game->currentLevel.waterStart.x, game->currentLevel.waterStart.y);

    game->currentLevel.isinit = true;
}

// 运行游戏主循环
void game_run(Game* game) {
    if (!game) return;
    // TODO: 游戏主循环
    while (game->isRunning) {
        BeginBatchDraw();
        game_handle_input(game);
        game_update(game);
        game_draw(game);
        Sleep(16); // 控制帧率
    }
    //GameState state = game->state;
    /*if (state == STATE_WIN || state == STATE_LOSE) {
        closegraph();
    }*/
}

// 处理输入
void game_handle_input(Game* game) {
    // 1. 更新输入状态（检测哪些键被按下）
    input_update(&g_input);  // 调用输入模块

    // 获取当前时间
    DWORD currentTime = GetTickCount();

    // 2. 根据当前游戏状态处理不同输入
    switch (game->state) {
    case STATE_MENU:
        // 菜单状态：W/S选择，回车确认
        if ((currentTime - g_lastInputTime) > INPUT_COOLDOWN) {
            if (g_input.keyW) {
                game->menuSelection--;
                g_lastInputTime = currentTime;
                if (game->menuSelection < 0) {
                    game->menuSelection = 3;  // 循环到最后一个
                }
            }
            if (g_input.keyS) {
                game->menuSelection++;
                g_lastInputTime = currentTime;
                if (game->menuSelection > 3) {
                    game->menuSelection = 0;  // 循环到第一个
                }
            }
        }

        // Enter 键确认
        if (g_input.keyEnter) {
            if (game->menuSelection == 0) {
                game->state = STATE_GAME;  // 开始游戏
            }
            else if (game->menuSelection == 1) {
                game->isRunning = false;   // 退出游戏
            }
            else if (game->menuSelection == 2) {
                // 游戏设置
                game->state = STATE_PAUSE;
            }
            else if (game->menuSelection == 3) {
                // 团队介绍
                game->state = STATE_TEAM;
            }
        }
        break;

    case STATE_GAME:
        // 游戏状态：控制玩家移动
        
        if (g_input.keyA) player_move(&game->firePlayer, -1);   // 火人左移
        if (g_input.keyD) player_move(&game->firePlayer, 1);    // 火人右移
        if (g_input.keyW) player_jump(&game->firePlayer);       // 火人跳跃

        if (g_input.keyLeft) player_move(&game->waterPlayer, -1);  // 水人左
        if (g_input.keyRight) player_move(&game->waterPlayer, 1);  // 水人右
        if (g_input.keyUp) player_jump(&game->waterPlayer);        // 水人跳

        // 游戏内功能键
        if (g_input.keyEsc) game->state = STATE_PAUSE;  // 暂停游戏
        break;

    case STATE_PAUSE:
        // 暂停状态：ESC返回游戏，回车选择菜单项

        if ((currentTime - g_lastInputTime) > INPUT_COOLDOWN) {
            if (g_input.keyW) {
                game->pauseSelection--;
                g_lastInputTime = currentTime;
                if (game->menuSelection < 0) {
                    game->menuSelection = 1;  // 循环到最后一个
                }
            }
            if (g_input.keyS) {
                game->pauseSelection++;
                g_lastInputTime = currentTime;
                if (game->menuSelection > 1) {
                    game->menuSelection = 0;  // 循环到第一个
                }
            }
        }

        if (g_input.keyEsc) game->state = STATE_GAME;
        if (g_input.keyEnter) {
            if (game->pauseSelection == 0) {
                game->state = STATE_GAME;  // 继续游戏
            }
            else {
                game->state = STATE_MENU;  // 返回主菜单
            }
        }
        break;
    case STATE_TEAM:
        if (g_input.keyEsc) game->state = STATE_MENU;  // 返回菜单
        break;
    case STATE_WIN:
        if (g_input.keyEnter) {
            game->currentLevelNum++;
            game->currentLevel.currentMap++;
            if (game->currentLevelNum >= 3 && game->currentLevel.currentMap >= 3) {
                game->state = STATE_MENU;
                break;
            }
            game->state = STATE_GAME;
             level_init(&game->currentLevel, game->currentLevelNum);
            player_init(&game->firePlayer, PLAYER_FIRE, game->currentLevel.fireStart.x, game->currentLevel.fireStart.y);
            player_init(&game->waterPlayer, PLAYER_WATER, game->currentLevel.waterStart.x, game->currentLevel.waterStart.y);
        }
        if (g_input.keyEsc) {
            game->state = STATE_MENU;
        }
        break;
    case STATE_LOSE:
        if (g_input.keyEnter) {
            game->state = STATE_GAME;
            player_init(&game->firePlayer, PLAYER_FIRE, game->currentLevel.fireStart.x, game->currentLevel.fireStart.y);
            player_init(&game->waterPlayer, PLAYER_WATER, game->currentLevel.waterStart.x, game->currentLevel.waterStart.y);
        }
        if (g_input.keyEsc) {
            game->state = STATE_MENU;
        }
        break;
    }
}

// 更新游戏逻辑
void game_update(Game* game) {
    if (!game) return;

    switch (game->state) {
    case STATE_GAME:
        // 更新玩家
        player_update(&game->firePlayer,&game->currentLevel);
        player_update(&game->waterPlayer,&game->currentLevel);


        // 检查玩家是否死亡
        if (!game->firePlayer.isAlive || !game->waterPlayer.isAlive) {
            game->state = STATE_LOSE;
            game->firePlayer.isAlive = true;
            game->waterPlayer.isAlive = true;
        }

        //检查是否胜利
        if (game->firePlayer.iswin && game->waterPlayer.iswin) {
            game->state = STATE_WIN;
        }
        break;
    default:
        break;
    }
}

// 绘制游戏
void game_draw(Game* game) {
    // 1. 清屏（准备画新的一帧）
    cleardevice();

    // 2. 根据游戏状态绘制不同界面
    switch (game->state) {
    case STATE_MENU:
        ui_draw_menu(game->menuSelection);  // 画主菜单
        break;

    case STATE_GAME:
        // 画游戏界面：玩家、关卡、UI
        render_clear();
        ui_draw_game(game, &g_textures);
        break;

    case STATE_PAUSE:
        render_clear();
        ui_draw_game(game, &g_textures);
        ui_draw_pause(game->pauseSelection);  // 再画暂停界面（覆盖在上面）
        break;

    case STATE_WIN:
        ui_draw_win(game->currentLevelNum);  // 胜利界面
        break;

    case STATE_LOSE:
        ui_draw_lose();  // 失败界面
        break;
    case STATE_TEAM:
        ui_draw_team();  // 团队介绍界面
        break;
    }

    // 3. 显示到屏幕
    render_present();
}
