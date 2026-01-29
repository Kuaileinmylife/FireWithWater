#include "render.h"
#include "../common.h"
#include <graphics.h>

// 初始化渲染器
void render_init() {
    // TODO: 初始化图形窗口
    // initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
}

// 清屏
void render_clear() {
    // TODO: 清除屏幕
    // cleardevice();
}

// 绘制矩形
void render_rect(int x, int y, int w, int h, int color) {
    // TODO: 绘制指定颜色的矩形
    // setfillcolor(color);
    // fillrectangle(x, y, x + w, y + h);
}

// 绘制文字
void render_text(int x, int y, const char* text, int color) {
    // TODO: 在指定位置绘制文字
    // settextcolor(color);
    // outtextxy(x, y, text);
}

// 显示画面
void render_present() {
    // TODO: 批量绘图
}