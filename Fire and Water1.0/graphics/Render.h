#pragma once
#include "../common.h"

// 初始化图形窗口
// 负责人：意识1
// 功能:
// 1：创建窗口
// 2：设置背景颜色
// 3：窗口大小根据展示效果可以修改一下宏
// 4：清空一下屏幕
// 5：窗口的标题
// 6：将窗口设计到屏幕的中心(拓展)
void render_init();

// 清屏
// 负责人：意识2
//功能：
//1：清屏，准备画下一帧
void render_clear();

// 绘制矩形
//功能：小李1
//1：绘制矩形（主要是颜色一定要有区别，可以看看宏定义）包括：出口，冰火人，平台，陷阱，机关等(尺寸在common)
//2：绘制填充矩形
void render_rect(int x, int y, int w, int h, int color);

// 绘制文字
// 负责人：小李2
//功能：
//1：文字颜色，样式，大小，字体，指定的位置输出对应的文字，比如:显示关卡数，显示游戏标题，游戏各种界面的按钮文字等
void render_text(int x, int y, const char* text, int color);

// 显示画面
// 负责人：柯然3
// 功能：
//1:用easyx的批量绘图的函数
//2：将绘制好的内容显示到窗口上
void render_present();