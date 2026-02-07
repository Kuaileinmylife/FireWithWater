#include "game.h"
#include "../common.h"
#include "../graphics/render.h"
#include "../graphics/texture.h"
#include "player.h"
#include "level.h"
#include "../physic/collision.h"
#include "../graphics/ui.h"
#include "../input/input.h"
#include "../game/Music.h"
#include <graphics.h>
#include <conio.h>
#include <windows.h>

bool g_musicEnabled = true;  // 音乐开关，默认开启
int g_volumeLevel = 80;  // 音量级别 0-100，默认80%

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

    // 播放菜单背景音乐
    if (g_musicEnabled) {  // 检查音乐开关
        music_menu_pause_play();
    }

    // TODO: 游戏主循环
    while (game->isRunning) {
        BeginBatchDraw();
        game_handle_input(game);
        game_update(game);
        game_draw(game);
        Sleep(16); // 控制帧率
    }
    
    // 游戏结束时关闭所有音乐
    music_all_close();
}

// 处理输入
void game_handle_input(Game* game) {
    // 1. 更新输入状态（检测哪些键被按下）
    input_update(&g_input);  // 调用输入模块

    // 获取当前时间
    DWORD currentTime = GetTickCount();
    bool canProcessInput = (currentTime - g_lastInputTime) > INPUT_COOLDOWN;

    // 2. 根据当前游戏状态处理不同输入
    switch (game->state) {
    case STATE_MENU:
        // 确保菜单音乐正在播放
        if (g_musicEnabled) {
            music_menu_pause_play();
        }
        
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
        if (g_input.keyEnter && canProcessInput) {
            if (game->menuSelection == 0) {
                game->state = STATE_GAME;  // 开始游戏
                g_lastInputTime = currentTime;
            }
            else if (game->menuSelection == 1) {
                game->isRunning = false;   // 退出游戏
                g_lastInputTime = currentTime;
            }
            else if (game->menuSelection == 2) {
                // 游戏设置
                game->state = STATE_SET;
                g_lastInputTime = currentTime;
            }
            else if (game->menuSelection == 3) {
                // 团队介绍
                game->state = STATE_TEAM;
                g_lastInputTime = currentTime;
            }
        }
        break;

    case STATE_GAME:
        // 游戏状态：控制玩家移动
        // 切换到游戏音乐
        if (g_musicEnabled) {
            music_menu_pause_pause();  // 暂停菜单音乐
            music_game_play_play();    // 播放游戏音乐
        }

        if (g_input.keyA) player_move(&game->firePlayer, -1);   // 火人左移
        if (g_input.keyD) player_move(&game->firePlayer, 1);    // 火人右移
        if (g_input.keyW) player_jump(&game->firePlayer);       // 火人跳跃

        if (g_input.keyLeft) player_move(&game->waterPlayer, -1);  // 水人左
        if (g_input.keyRight) player_move(&game->waterPlayer, 1);  // 水人右
        if (g_input.keyUp) player_jump(&game->waterPlayer);        // 水人跳

        // 游戏内功能键
        if (g_input.keyEsc && canProcessInput) {
            game->state = STATE_PAUSE;  // 暂停游戏
            g_lastInputTime = currentTime;
        }
        break;

    case STATE_SET:
        // 设置界面
        if (g_musicEnabled) {
            music_menu_pause_play();   // 播放菜单音乐
        }

        if ((currentTime - g_lastInputTime) > INPUT_COOLDOWN) {
            if (g_input.keyW) {
                game->pauseSelection--;
                g_lastInputTime = currentTime;
                if (game->pauseSelection < 0) {
                    game->pauseSelection = 1;  // 循环到最后一个
                }
            }
            if (g_input.keyS) {
                game->pauseSelection++;
                g_lastInputTime = currentTime;
                if (game->pauseSelection > 1) {
                    game->pauseSelection = 0;  // 循环到第一个
                }
            }
        }

        if (g_input.keyEsc && canProcessInput) {
            game->state = STATE_MENU;
            g_lastInputTime = currentTime;
        }
        if (g_input.keyEnter && canProcessInput) {
            g_lastInputTime = currentTime;  // 立即记录输入时间
            if (game->pauseSelection == 0) {
                // 音乐开关
                g_musicEnabled = !g_musicEnabled;  // 切换音乐开关

                // 根据开关状态播放或停止音乐
                if (g_musicEnabled && canProcessInput) {
                    music_menu_pause_play();  // 开启音乐
                    g_lastInputTime = currentTime;
                }
                else {
                    // 关闭所有音乐
                    mciSendString(_T("close ") MENU_PAUSE_ALIAS, NULL, 0, NULL);
                    mciSendString(_T("close ") GAME_PLAY_ALIAS, NULL, 0, NULL);
                    mciSendString(_T("close ") WIN_ALIAS, NULL, 0, NULL);
                    mciSendString(_T("close ") FAIL_ALIAS, NULL, 0, NULL);
                    g_lastInputTime = currentTime;
                }
            }
        }

        // 左右键调节音量（选中音量选项时）
        if (game->pauseSelection == 1 && canProcessInput) {
            if (g_input.keyA && canProcessInput) {
                g_volumeLevel -= 10;
                if (g_volumeLevel < 0) g_volumeLevel = 0;
                update_music_volume();  // 更新音量
                g_lastInputTime = currentTime;
            }
            if (g_input.keyD && canProcessInput) {
                g_volumeLevel += 10;
                if (g_volumeLevel > 100) g_volumeLevel = 100;
                update_music_volume();  // 更新音量
                g_lastInputTime = currentTime;
            }
        }
        break;

    case STATE_PAUSE:
        // 暂停状态：ESC返回游戏，回车选择菜单项
        // 暂停游戏音乐，播放菜单音乐
        if (g_musicEnabled) {
            music_game_play_pause();   // 暂停游戏音乐
            music_menu_pause_play();   // 播放菜单音乐
        }

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

        if (g_input.keyEsc && canProcessInput) { 
            game->state = STATE_GAME;
            g_lastInputTime = currentTime;
        }
        if (g_input.keyEnter && canProcessInput) {
            if (game->pauseSelection == 0) {
                game->state = STATE_GAME;  // 继续游戏
                g_lastInputTime = currentTime;
            }
            else {
                game->state = STATE_MENU;  // 返回主菜单
                g_lastInputTime = currentTime;
                game->currentLevel.currentMap = 0;
                game->currentLevelNum = 0;
                game->currentLevel.isinit = false;
                level_init(&game->currentLevel, game->currentLevelNum);
                game->currentLevel.isinit = true;
                player_init(&game->firePlayer, PLAYER_FIRE, game->currentLevel.fireStart.x, game->currentLevel.fireStart.y);
                player_init(&game->waterPlayer, PLAYER_WATER, game->currentLevel.waterStart.x, game->currentLevel.waterStart.y);
            }
        }
        break;
    case STATE_TEAM:
        // 确保菜单音乐正在播放
        if (g_musicEnabled) {
            music_menu_pause_play();
        }
        if (g_input.keyEsc) game->state = STATE_MENU;  // 返回菜单
        break;
    case STATE_WIN:
        // 播放胜利音乐
        if (g_musicEnabled) {
            music_win_play();          // 播放胜利音乐
        }

        if (g_input.keyEnter && canProcessInput) {
            game->currentLevelNum++;
            game->currentLevel.currentMap++;

            level_init(&game->currentLevel, game->currentLevelNum);
            player_init(&game->firePlayer, PLAYER_FIRE, game->currentLevel.fireStart.x, game->currentLevel.fireStart.y);
            player_init(&game->waterPlayer, PLAYER_WATER, game->currentLevel.waterStart.x, game->currentLevel.waterStart.y);

            if (game->currentLevelNum >= 3 && game->currentLevel.currentMap >= 3 && canProcessInput) {
                game->currentLevelNum=0;
                game->currentLevel.currentMap=0;
                game->state = STATE_MENU;

                level_init(&game->currentLevel, game->currentLevelNum);
                player_init(&game->firePlayer, PLAYER_FIRE, game->currentLevel.fireStart.x, game->currentLevel.fireStart.y);
                player_init(&game->waterPlayer, PLAYER_WATER, game->currentLevel.waterStart.x, game->currentLevel.waterStart.y);
                g_lastInputTime = currentTime;
                break;
            }
            game->state = STATE_GAME;
            g_lastInputTime = currentTime;
        }
        if (g_input.keyEsc) {
            game->state = STATE_MENU;
        }
        break;
    case STATE_LOSE:
        // 播放失败音乐
        if (g_musicEnabled) {
            music_fail_play();         // 播放失败音乐
        }

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
        game->currentLevel.trapstation2[8].isActive = false;

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
        ui_draw_win(game->currentLevelNum,&game->currentLevel);  // 胜利界面
        break;

    case STATE_LOSE:
        ui_draw_lose(&game->currentLevel);  // 失败界面
        break;
    case STATE_TEAM:
        ui_draw_team();  // 团队介绍界面
        break;
    case STATE_SET:
        ui_draw_set(game->pauseSelection);
    }

    // 3. 显示到屏幕
    render_present();
}

// 音量调节
void update_music_volume() {
    // MCI音量范围是0-1000，所以需要转换
    int mciVolume = g_volumeLevel * 10;

    if (g_musicEnabled) {
        // 如果有音乐在播放，更新音量
        TCHAR cmd[256];

        wsprintf(cmd, _T("setaudio ") MENU_PAUSE_ALIAS _T(" volume to %d"), mciVolume);
        mciSendString(cmd, NULL, 0, NULL);

        wsprintf(cmd, _T("setaudio ") GAME_PLAY_ALIAS _T(" volume to %d"), mciVolume);
        mciSendString(cmd, NULL, 0, NULL);

        wsprintf(cmd, _T("setaudio ") WIN_ALIAS _T(" volume to %d"), mciVolume);
        mciSendString(cmd, NULL, 0, NULL);

        wsprintf(cmd, _T("setaudio ") FAIL_ALIAS _T(" volume to %d"), mciVolume);
        mciSendString(cmd, NULL, 0, NULL);
    }
}