#include "render.h"
#include "../common.h"
#include <graphics.h>
#include <windows.h>

// 初始化渲染器
void render_init() {
      // 初始化图形窗口

        // 1. 创建图形窗口
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT,0);

    // 2. 设置窗口标题
    SetWindowText(GetHWnd(), "冰火人");

    // 3. 将窗口移动到屏幕中心
    int screen_width = GetSystemMetrics(SM_CXSCREEN);
    int screen_height = GetSystemMetrics(SM_CYSCREEN);
    SetWindowPos(
        GetHWnd(),
        NULL,
        (screen_width - WINDOW_WIDTH) / 2,
        (screen_height - WINDOW_HEIGHT) / 2, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    // 4. 设置背景色并清空屏幕
    setbkcolor(COLOR_BG);  // 可替换为需要的背景色
    cleardevice();
}

// 清屏
void render_clear() {
    // 1. 用背景色填充整个窗口
    cleardevice();
}

// 绘制矩形
void render_rect(int x, int y, int w, int h, int color) {
    // TODO: 绘制指定颜色的矩形
     setfillcolor(color);
     fillrectangle(x, y, x + w, y + h);

}

// 绘制文字
void render_text(int x, int y, const char* text, int color) {
    // TODO: 在指定位置绘制文字
    settextcolor(color);
    settextstyle(24, 0, "宋体");
    outtextxy(x, y, text);
   /* char str[] = "A W D分别为左_跳跃_右";
    outtextxy(500, 10, str);*/
}

// 显示画面
void render_present() {
    // TODO: 批量绘图
    FlushBatchDraw();
}

void render_texture(int x, int y, int w, int h, IMAGE* img) {
    if (!img) return;
    putimage(x, y, w, h, img, 0, 0);
}

void render_texture_clip(int x, int y, int w, int h,
    IMAGE* img, int srcX, int srcY, int srcW, int srcH) {
    if (!img) return;
    putimage(x, y, w, h, img, srcX, srcY);
}