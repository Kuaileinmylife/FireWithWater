#pragma once
#include "../common.h"

// 按键状态
typedef struct {
    bool keyW, keyA, keyD;          // 火人控制
    bool keyUp, keyLeft, keyRight;  // 水人控制
    bool keyEsc, keyEnter;          // 功能键
} InputState;

// 更新输入状态
// 负责人；star2
// 功能；用easyx检测按下的键(一定要看定义）
// 1；火人wad(包括大写)
// 2; 水人的方向键
// 3；功能键(esc，enter)
void input_update(InputState* input);

// 检查按键是否按下
// 负责人；小李3
// 功能；检测指定的按键是否被按下(定义一个临时变量bool类型isDown来检测)
// 1；key可以是wadWAD方向键等
// 2；检测如果是大写，就转为小写
// 3；返回值需要为isDown
bool input_is_key_down(int key);
