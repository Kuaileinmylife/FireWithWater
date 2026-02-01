#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"
#include "../common.h"
#include "../graphics/render.h"
#include "../graphics/texture.h"
#include "../game/Game.h"
#include "../game/Player.h"
#include "../game/Level.h"
#include <stdio.h>
#include <string>

// 绘制主菜单
void ui_draw_game(Game* game, TextureManager* tm) {
    if (!game) return;

    // 1. 绘制背景
    render_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_BG);

    // 2. 绘制当前关卡
    level_draw(&game->currentLevel, tm);

    // 3. 绘制玩家
    player_draw(&game->firePlayer, tm);
    player_draw(&game->waterPlayer, tm);

    // 添加调试信息 - 显示玩家位置
    char debugText[128];
    sprintf(debugText, "火人: (%.0f, %.0f)", game->firePlayer.position.x, game->firePlayer.position.y);
    render_text(10, 50, debugText, COLOR_FIRE);

    sprintf(debugText, "水人: (%.0f, %.0f)", game->waterPlayer.position.x, game->waterPlayer.position.y);
    render_text(10, 80, debugText, COLOR_WATER);

    // 4. 绘制UI信息（关卡数等）
    char levelText[32];
    sprintf(levelText, "关卡: %d", game->currentLevelNum);
    render_text(10, 10, levelText, RGB(255, 255, 255));

    // 5. 如果是第一关，显示操作提示
    if (game->currentLevelNum == 1) {
        render_text(500, 10, "火人: W A D", COLOR_FIRE);
        render_text(500, 40, "水人: ↑ ← →", COLOR_WATER);
    }
}

// 绘制游戏界面
void ui_draw_game(Game* game, TextureManager* tm) {
    if (!game) return;

    // 1. 绘制背景
    render_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_BG);

    // 2. 绘制当前关卡
    level_draw(&game->currentLevel,tm);

    // 3. 绘制玩家
    player_draw(&game->firePlayer, tm);
    player_draw(&game->waterPlayer, tm);

    // 4. 绘制UI信息（关卡数等）
    char levelText[32];
    sprintf(levelText, "关卡: %d", game->currentLevelNum);
    render_text(10, 10, levelText, RGB(255, 255, 255));

    // 5. 如果是第一关，显示操作提示
    if (game->currentLevelNum == 1) {
        render_text(500, 10, "火人: W A D", COLOR_FIRE);
        render_text(500, 40, "水人: ↑ ← →", COLOR_WATER);
    }
}

// 绘制暂停界面
void ui_draw_pause() {
    // TODO: 绘制暂停菜单
}

// 绘制胜利界面
void ui_draw_win(int levelNum) {
    render_clear();
    render_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, WHITE);

    char winText[128];
    sprintf(winText, "YOU WIN! 关卡 %d 通过", levelNum);
    render_text(320, 200, winText, BROWN);
    render_text(300, 250, "恭喜你通关！", BROWN);
    render_text(280, 450, "按 Enter 进入下一关", BLACK);
    render_text(290, 500, "按 Esc 返回菜单", BLACK);

    render_present();
}

// 绘制失败界面
void ui_draw_lose() {
    render_clear();
    render_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, RED);

    render_text(320, 200, "YOU LOSE", BLACK);
    render_text(340, 250, "你失败了", BLACK);
    render_text(280, 450, "按 Enter 重新开始", WHITE);
    render_text(290, 500, "按 Esc 返回菜单", WHITE);

    render_present();
}