#include "game/Game.h"
#include <direct.h>
#include <windows.h>
#include <stdio.h>

int main() {
    Game game;
    game_init(&game);
    game_run(&game);
    EndBatchDraw();
    return 0;
}