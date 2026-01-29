#include "ui.h"
#include "../common.h"

// 绘制主菜单
void ui_draw_menu(int selection) {
    // TODO: 绘制菜单界面
    // 选项：开始游戏、设置、退出等
}

// 绘制游戏界面
void ui_draw_game(const Player* fire, const Player* water, int levelNum) {
    if (!fire || !water) return;

    // TODO: 绘制游戏中的元素
    // 1. 绘制背景
    // 2. 绘制关卡
    // 3. 绘制玩家
    // 4. 绘制UI信息（关卡数等）
}

// 绘制暂停界面
void ui_draw_pause() {
    // TODO: 绘制暂停菜单
}

// 绘制胜利界面
void ui_draw_win(int levelNum) {
    // TODO: 绘制胜利画面
}

// 绘制失败界面
void ui_draw_lose() {
    // TODO: 绘制失败画面
}