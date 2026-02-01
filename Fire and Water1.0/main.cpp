#include "game/Game.h"
#include <direct.h>
#include <windows.h>
#include <stdio.h>

int main() {
    printf("=== 游戏启动调试信息 ===\n");

    // 获取并显示当前工作目录
    char currentDir[1024];
    GetCurrentDirectory(sizeof(currentDir), currentDir);
    printf("当前工作目录: %s\n", currentDir);

    // 检查贴图文件是否存在
    printf("\n检查贴图文件:\n");
    printf("1. 检查当前目录的PNG文件:\n");
    system("dir *.png 2>nul");

    printf("\n2. 检查Debug文件夹:\n");
    system("dir Debug\\*.png 2>nul || echo Debug文件夹不存在或无PNG文件");

    printf("\n3. 检查带Debug前缀的文件:\n");
    system("dir \"Debug\\*.png\" 2>nul || echo 找不到Debug\\*.png");

    printf("\n=== 开始游戏 ===\n");

    Game game;
    game_init(&game);
    game_run(&game);

    return 0;
}