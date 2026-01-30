#include "ui.h"
#include "../common.h"
#include "../graphics/render.h"

// 绘制主菜单
void ui_draw_menu(int selection) {
    //render_clear();//调用 清屏 函数
    render_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, COLOR_BG);//调用 绘制矩形 函数
    const char* menu[4] = { "开始游戏","游戏设置","游戏介绍","团队介绍" };//游戏菜单选项

    const char* menuTitle = "冰火人";
    int titleX = WINDOW_WIDTH / 2 - 100;//标题的x坐标：向左偏移40，实现水平居中
    int titleY = WINDOW_HEIGHT / 2 - 150;//标题的y坐标：向上偏移150，实现水平居中
    render_text(titleX, titleY, menuTitle, COLOR_FIRE);//调用 绘制文字 函数，颜色暂时用火人红色

    int menuStarty = WINDOW_HEIGHT / 2 - 50;//第一个选项的起始Y坐标
    int menuItemGmp = 60;//选项之间的Y轴间距
    for (int i = 0; i < 4; i++)
    {
        int munuX = WINDOW_WIDTH / 2 - 40;//每个选项的x坐标：向左偏移40，实现水平居中
        int munuY = menuStarty + i * menuItemGmp;//每个选项的y坐标
        int textColor;//定义颜色变量
        if (selection == i) // 条件判断：选中项设为黄色，未选中设为白色
        {
            textColor = RGB(255, 255, 0);
        }
        else
        {
            textColor = RGB(255, 255, 255);
        }
        render_text(munuX, munuY, *(menu + i), textColor);//再次调用 绘制矩形 函数
    }

    render_present();//调用 批量绘图 函数
}

// 绘制游戏界面
void ui_draw_game(const Player* fire, const Player* water, int levelNum) {
   
}

// 绘制暂停界面
void ui_draw_pause() {
    // TODO: 绘制暂停菜单
}

// 绘制胜利界面
void ui_draw_win(int levelNum) {
    // TODO: 绘制胜利画面
    setbkcolor(WHITE);
    cleardevice();
    settextstyle(48, 0, _T("微软雅黑"));
    settextcolor(BROWN);
    outtextxy(320, 200, "YOU WIN");
    outtextxy(300, 250, "你已经通过了");
    outtextxy(280, 450, "按 Enter 进入下一关");
    outtextxy(290, 500, "按 Esc 返回菜单");
}

// 绘制失败界面
void ui_draw_lose() {
    // TODO: 绘制失败画面
    setbkcolor(RED);
    cleardevice();
    settextstyle(48, 0, _T("微软雅黑"));
    settextcolor(BLACK);
    outtextxy(320, 200, "YOU LOSE");
    outtextxy(340, 250, "你失败了");
    outtextxy(350, 300, "");
    outtextxy(280, 450, "按 Enter 重新开始");
    outtextxy(290, 500, "按 Esc 返回菜单");
}