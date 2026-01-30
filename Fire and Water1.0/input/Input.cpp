#include "input.h"
#include "../common.h"
#include <conio.h>

// 更新输入状态
void input_update(InputState* input) {
    if (!input) return;
    // 1. 火人控制（WASD中的 W/A/D，支持大小写）
    input->keyW = (GetAsyncKeyState('W') & 0x8000) || (GetAsyncKeyState('w') & 0x8000);
    input->keyA = (GetAsyncKeyState('A') & 0x8000) || (GetAsyncKeyState('a') & 0x8000);
    input->keyD = (GetAsyncKeyState('D') & 0x8000) || (GetAsyncKeyState('d') & 0x8000);

    // 2. 水人控制（方向键中的 上/左/右）
    input->keyUp = (GetAsyncKeyState(VK_UP) & 0x8000);
    input->keyLeft = (GetAsyncKeyState(VK_LEFT) & 0x8000);
    input->keyRight = (GetAsyncKeyState(VK_RIGHT) & 0x8000);

    // 3. 功能键（ESC、Enter）
    input->keyEsc = (GetAsyncKeyState(VK_ESCAPE) & 0x8000);
    input->keyEnter = (GetAsyncKeyState(VK_RETURN) & 0x8000);

    // TODO: 检测键盘状态并更新input结构体
    // input->keyW = (GetAsyncKeyState('W') & 0x8000) != 0;
    // 其他按键同理
}

// 检查指定按键是否按下
bool input_is_key_down(int key) {
    // TODO: 检查单个按键状态
    return false;
}