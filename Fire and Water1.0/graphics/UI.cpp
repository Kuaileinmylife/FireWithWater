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


// 绘制游戏界面
void ui_draw_game(Game* game, TextureManager* tm) {
    if (!game) return;

    // 1. 绘制背景
    render_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_BG);

    game->currentLevel.currentMap = game->currentLevelNum;                                                                
    // 2. 绘制当前关卡
    level_draw(&game->currentLevel,tm);

    // 5. 如果是第一关，显示操作提示
    if (game->currentLevelNum == 0) {
        render_text(500, 500, "火人: W A D", COLOR_FIRE);
        render_text(500, 530, "水人: ↑ ← →", COLOR_WATER);
    }

    // 3. 绘制玩家
    player_draw(&game->firePlayer, tm);
    player_draw(&game->waterPlayer, tm);


    // 4. 绘制UI信息（关卡数等）
    char levelText[32];
    sprintf(levelText, "关卡: %d", game->currentLevelNum+1);
    render_text(10, 10, levelText, RGB(255, 255, 255));
}

// 绘制暂停界面
void ui_draw_pause(int selection) {
    // TODO: 绘制暂停菜单
    setbkcolor(RGB(100, 100, 150));  // 深蓝色背景
    setbkmode(TRANSPARENT);
    cleardevice();
    IMAGE p;
    loadimage(&p, "setbackground.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    putimage(0, 0, &p);
    settextstyle(32, 0, _T("宋体"));

    if (selection == 0) {
        settextcolor(YELLOW);  // 选中时黄色
        outtextxy(475, 100, _T("> 继续游戏 <"));
    }
    else {
        settextcolor(WHITE);   // 未选中白色
        outtextxy(500, 100, _T("继续游戏"));
    }

    // 选项2：退出游戏（selection=1表示选中）
    if (selection == 1) {
        settextcolor(YELLOW);
        outtextxy(475, 150, _T("> 退回菜单 <"));
    }
    else {
        settextcolor(WHITE);
        outtextxy(500, 150, _T("退回菜单"));
    }

    // 4. 画操作提示
    settextstyle(20, 0, _T("宋体"));
    settextcolor(RGB(200, 200, 200));
    outtextxy(280, 550, _T("W/S: 选择  回车: 确认"));
}

// 绘制主菜单
void ui_draw_menu(int selection) {
    // TODO: 绘制主菜单界面
    // 1. 画背景（渐变或纯色）
    setbkcolor(RGB(100, 100, 150));  // 深蓝色背景
    setbkmode(TRANSPARENT);
    cleardevice();
    IMAGE p;
    loadimage(&p, "mainmenu.png", WINDOW_WIDTH, WINDOW_HEIGHT);
    putimage(0, 0, &p);

    // 3. 画菜单选项
    settextstyle(32, 0, _T("宋体"));

    // 选项1：开始游戏（selection=0表示选中）
    if (selection == 0) {
        settextcolor(YELLOW);  // 选中时黄色
        outtextxy(475, 100, _T("> 开始游戏 <"));
    }
    else {
        settextcolor(WHITE);   // 未选中白色
        outtextxy(500, 100, _T("开始游戏"));
    }

    // 选项2：退出游戏（selection=1表示选中）
    if (selection == 1) {
        settextcolor(YELLOW);
        outtextxy(475, 150, _T("> 退出游戏 <"));
    }
    else {
        settextcolor(WHITE);
        outtextxy(500, 150, _T("退出游戏"));
    }

    // 选项3：设置（selection=2表示选中）
    if (selection == 2) {
        settextcolor(YELLOW);
        outtextxy(475, 200, _T("> 游戏设置 <"));
    }
    else {
        settextcolor(WHITE);
        outtextxy(500, 200, _T("游戏设置"));
    }

    // 选项4：团队介绍（selection=3表示选中）
    if (selection == 3) {
        settextcolor(YELLOW);
        outtextxy(475, 250, _T("> 团队介绍 <"));
    }
    else {
        settextcolor(WHITE);
        outtextxy(500, 250, _T("团队介绍"));
    }

    // 4. 画操作提示
    settextstyle(20, 0, _T("宋体"));
    settextcolor(RGB(200, 200, 200));
    outtextxy(280, 550, _T("W/S: 选择  回车: 确认"));
}

// 绘制团队介绍界面
void ui_draw_team() {
    // 当按下esc的时候返回菜单界面
    // 背景先用setbackground.png
    // 提示按esc返回菜单
    IMAGE p;
    loadimage(&p, "teamback.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
    putimage(0, 0, &p);

    char name[20][50] = {
        "组长-柯然",
        "技术官-V07",
        "信息官-阿超",
        "产品经理-金闪闪",
        "记录官-奶黄包",
        "产品经理-Star",
        "技术官-小黄",
        "产品经理-小李",
        "监督官-意识",
        "副组长-立体纸片"
    };
    char avatar_path[10][50] = {
        "ke-ran.jpg",
        "V07.jpg",
        "A-chao.jpg",
        "jin-shan-shan.jpg",
        "nai-huang-bao.jpg",
        "Star.jpg",
        "xiao-huang.jpg",
        "xiao-li.jpg",
        "yi-shi.jpg",
        "zhi-pian.jpg"
    };
    settextstyle(50, 50, _T("宋体"));
    settextcolor(YELLOW);
    outtextxy(225, 25, "团队介绍");
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            render_text(75 + 100, (100) * (i + 1), name[i],WHITE);
        }
        else
        {
            render_text(75 + 100 + 350, (100) * (i - 4), name[i],WHITE);
        }
    }

    IMAGE img_mm[10];
    for (int i = 0; i < 10; i++)
    {
        loadimage(&img_mm[i], avatar_path[i], 75, 75);
    }

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            putimage(75, (100) * (i + 1), &img_mm[i]);
        }
        else
        {
            putimage(75 + 350, (100) * (i - 4), &img_mm[i]);
        }
    }
}


// 绘制胜利界面
void ui_draw_win(int levelNum) {
    render_clear();
    IMAGE img_win_bg;
    loadimage(&img_win_bg, "winback.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
    putimage(0, 0, &img_win_bg);

    char winText[128];
    sprintf(winText, "YOU WIN! 关卡 %d 通过", levelNum+1);

    render_text(400 - textwidth(winText) / 2, 200, winText, YELLOW);
    render_text(400 - textwidth("恭喜你通关！") / 2, 250, "恭喜你通关！", YELLOW);
    render_text(400 - textwidth("按 Enter 进入下一关") / 2, 350, "按 Enter 进入下一关", BLACK);
    render_text(400 - textwidth("按 Esc 返回菜单") / 2, 400, "按 Esc 返回菜单", BLACK);

    render_present();
}

// 绘制失败界面
void ui_draw_lose() {
    render_clear();

    IMAGE img_lose_bg;
    loadimage(&img_lose_bg, "loseback.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
    putimage(0, 0, &img_lose_bg);

    render_text(400 - textwidth("YOU LOSE") / 2, 200, "YOU LOSE", BLACK);
    render_text(400 - textwidth("你失败了") / 2, 250, "你失败了", BLACK);
    render_text(400 - textwidth("按 Enter 重新开始") / 2, 350, "按 Enter 重新开始", WHITE);
    render_text(400 - textwidth("按 Esc 返回菜单") / 2, 400, "按 Esc 返回菜单", WHITE);

    render_present();
}