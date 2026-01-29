#include "input.h"
#include "../common.h"
#include <conio.h>

// 更新输入状态
void input_update(InputState* input) {
    if (!input) return;

    // TODO: 检测键盘状态并更新input结构体
    // input->keyW = (GetAsyncKeyState('W') & 0x8000) != 0;
    // 其他按键同理
}

// 检查指定按键是否按下
bool input_is_key_down(int key) {
    // TODO: 检查单个按键状态
    return false;
}